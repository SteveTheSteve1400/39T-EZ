#include "main.h"
#include "okapi/api/units/RQuantity.hpp"
#include "pros/misc.h"
#include <cmath>
#include <ratio>
#include "okapi/api.hpp"


okapi::EmaFilter velocityfilter(0.7);
okapi::EmaFilter derivativefilter(0.87);
//HELPER FUNCTION
void setFlywheel(double power){
    flywheel.move_voltage((int)94.488*power);
}

double PP = 3;
double II = 0.7; //there is slight oscilation, not much
double DD = 1.2;	//dampening oscilation, also holds back the flywheel
double errorr;
double preverror;
double dspeed;
double haha;

double factor = 94.4881889764;
double targetspeed = 450; 
double estimatedpower = 95;


double current_flywheel_speed;


int toggle = false;
int choice(){
	//use eight and designated speed and if jello == that speed change the designated speed
	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
		jello = jello + 1000;
		pros::delay(150);
	}
	if ((controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN))){
		jello = jello - 1000;
		pros::delay(150);
	}
	if(jello == 8000){
		designatedspeed = 400;
  		powerdrawn = 83;
	}
	if(jello == 9000){
		designatedspeed = 450;
  		powerdrawn = 90;
	}
	if(jello == 10000){
		designatedspeed = 480;
  		powerdrawn = 97;
	}
	if(jello == 11000){
		designatedspeed = 540;
  		powerdrawn = 110;
	}
	//if L2 is pressed flywheel = on, make it toggle(off at first on at second)
	if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
		if(toggle == false){
			toggle = true;
			eight = true;
		}
		else{
			toggle = false;
			eight = false;
		}
		pros::delay(300);
	}

	return jello;
}

double integralerror;
void setFlywheelSpeedAuton(){
	while(true){
		while(eight){
			//EMA filter
			//current_flywheel_speed = velocityfilter.filter((double) flywheel.get_actual_velocity());
			current_flywheel_speed  = velocityfilter.filter((double) flywheel.get_actual_velocity());
			if(current_flywheel_speed<0.93*designatedspeed){
				setFlywheel(127);
			}
			else{
			//error
				errorr = designatedspeed - current_flywheel_speed;


				//Integral factor
				integralerror += errorr*1;

			//cap for power input
				if (powerdrawn+integralerror >127){
					integralerror = 127 - powerdrawn;
				}
				
				if (std::signbit(preverror)!=std::signbit(errorr)){
					integralerror = 0;
				}

				setFlywheel(powerdrawn+integralerror);

				preverror = errorr;
			}
			pros::delay(10);
		}
		setFlywheel(0);
		errorr = 0;
		preverror = 0;
		pros::delay(10);
	}
}			
