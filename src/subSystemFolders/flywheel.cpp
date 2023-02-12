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




void setFlywheelSpeed9000(){
	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
		//EMA filter
		current_flywheel_speed = velocityfilter.filter((double) flywheel.get_actual_velocity());
		if(current_flywheel_speed<0.95*450){
			setFlywheel(127);
		}
		else{
			//error
				errorr = 450 - current_flywheel_speed;


				//Integral factor
				estimatedpower += errorr*II;

				//derivative factor
				dspeed = derivativefilter.filter(errorr - preverror);

				//cap for power input
				if (estimatedpower >127){
					estimatedpower = 127;
				}
				
				if (std::signbit(preverror)!=std::signbit(errorr)){
					estimatedpower = 95;
				}

				setFlywheel(estimatedpower);

				preverror = errorr;
			}
	}
	else {
		setFlywheel(0);
		errorr = 0;
		preverror = 0;
		estimatedpower = 95;
	}
}

double estimatedpower_5 = 8000/factor;
void setFlywheelSpeed8000(){
	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
		//EMA filter
		current_flywheel_speed = velocityfilter.filter((double) flywheel.get_actual_velocity());
		if(current_flywheel_speed<0.93*400){
			setFlywheel(127);
		}
		else{
			//error
			errorr = 400 - current_flywheel_speed;


			//Integral factor
			estimatedpower_5 += errorr*II;

			//derivative factor
			dspeed = derivativefilter.filter(errorr - preverror);

			//cap for power input
			if (estimatedpower_5 >127){
				estimatedpower_5 = 127;
			}
			 
			if (std::signbit(preverror)!=std::signbit(errorr)){
				estimatedpower_5 = 10000/factor;
			}

			setFlywheel(estimatedpower_5);

			preverror = errorr;
		}
	}
	else {
		setFlywheel(0);
		errorr = 0;
		preverror = 0;
		estimatedpower = 11000/factor;
	}
}

double estimatedpower_0 = 10000/factor;
void setFlywheelSpeed10000(){
	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
		//EMA filter
		current_flywheel_speed = velocityfilter.filter((double) flywheel.get_actual_velocity());
		if(current_flywheel_speed<0.95*480){
			setFlywheel(127);
		}
		else{
			//error
			errorr = 480 - current_flywheel_speed;


			//Integral factor
			estimatedpower_0 += errorr*II;

			//derivative factor
			dspeed = derivativefilter.filter(errorr - preverror);

			//cap for power input
			if (estimatedpower_0 >127){
				estimatedpower_0 = 127;
			}
			 
			if (std::signbit(preverror)!=std::signbit(errorr)){
				estimatedpower_0 = 10000/factor;
			}

			setFlywheel(estimatedpower_0);

			preverror = errorr;
		}
	}
	else {
		setFlywheel(0);
		errorr = 0;
		preverror = 0;
		estimatedpower = 10000/factor;
	}
}

double estimatedpower_1 = 11000/factor;
void setFlywheelSpeed11000(){
	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
		//EMA filter
		current_flywheel_speed = velocityfilter.filter((double) flywheel.get_actual_velocity());
		if(current_flywheel_speed<0.95*540){
			setFlywheel(127);
		}
		else{
			//error
			errorr = 540 - current_flywheel_speed;


			//Integral factor
			estimatedpower_1 += errorr*II;

			//derivative factor
			dspeed = derivativefilter.filter(errorr - preverror);

			//cap for power input
			if (estimatedpower_1 >127){
				estimatedpower_1 = 127;
			}
			 
			if (std::signbit(preverror)!=std::signbit(errorr)){
				estimatedpower_1 = 10000/factor;
			}

			setFlywheel(estimatedpower_1);

			preverror = errorr;
		}
	}
	else {
		setFlywheel(0);
		errorr = 0;
		preverror = 0;
		estimatedpower = 11000/factor;
	}
}

void setFlywheelSpeed12000(){
	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
		setFlywheel(127);
	}
	else setFlywheel(0);
}


int choice(){
	if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
		jello = jello + 1000;
		pros::delay(150);
	}
	if ((controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN))){
		jello = jello - 1000;
		pros::delay(150);
	}
	if (jello == 7000){
		setFlywheel(74);
	}
	else if (jello == 8000) {
		setFlywheelSpeed8000();
	}
	else if (jello == 9000) {
		setFlywheelSpeed9000();
	}
	else if (jello == 10000){
		setFlywheelSpeed10000();	
	} 
	else if (jello == 11000) {
		setFlywheelSpeed11000();
	}
	else if (jello == 12000) {
		setFlywheelSpeed12000();
	}
	return jello;
}




/*void setFlywheelSpeedAuton12000(bool twelve){
	if (twelve){
		setFlywheel(127);
	}
	else setFlywheel(0);
}
*/

void setFlywheelSpeedAuton11000(bool eleven){
	if (eleven){
		//EMA filter
		current_flywheel_speed = velocityfilter.filter((double) flywheel.get_actual_velocity());
		if(current_flywheel_speed<0.95*540){
			setFlywheel(127);
		}
		else{
			//errors
			errorr = 540 - current_flywheel_speed;


			//Integral factor
			estimatedpower_1 += errorr*II;

			//derivative factor
			dspeed = derivativefilter.filter(errorr - preverror);

			//cap for power input
			if (estimatedpower_1 >127){
				estimatedpower_1 = 127;
			}
			 
			if (std::signbit(preverror)!=std::signbit(errorr)){
				estimatedpower_1 = 10000/factor;
			}

			setFlywheel(estimatedpower_1);

			preverror = errorr;
		}
	}
	else {
		setFlywheel(0);
		errorr = 0;
		preverror = 0;
		estimatedpower = 11000/factor;
	}
}

void setFlywheelSpeedAuton10000(bool ten){
	if (ten){
		//EMA filter
		current_flywheel_speed = velocityfilter.filter((double) flywheel.get_actual_velocity());
		if(current_flywheel_speed<0.95*480){
			setFlywheel(127);
		}
		else{
			//error
			errorr = 480 - current_flywheel_speed;


			//Integral factor
			estimatedpower_0 += errorr*II;

			//derivative factor
			dspeed = derivativefilter.filter(errorr - preverror);

			//cap for power input
			if (estimatedpower_0 >127){
				estimatedpower_0 = 127;
			}
			 
			if (std::signbit(preverror)!=std::signbit(errorr)){
				estimatedpower_0 = 10000/factor;
			}

			setFlywheel(estimatedpower_0);

			preverror = errorr;
		}
	}
	else {
		setFlywheel(0);
		errorr = 0;
		preverror = 0;
		estimatedpower = 10000/factor;
	}
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
		setFlywheel(-35);
		errorr = 0;
		preverror = 0;
		pros::delay(10);
	}
}			
//top triggers flywheel;
    //
    //
    //
    //
    //function
    /*double k; //concavity of function
    double maxrpm; //crossmap rpm required
    double minrpm; //point blank rpm required
    double absvaluedist = sqrt(pow(xintinialposition,2)+pow(yintinialposition,2));
    double voltagerpm = (127*(maxrpm-minrpm)*(pow(((absvaluedist-2.76557)/9.71122),k)+minrpm))/3600;
    int flywheelPower;
    */
    /**
    if(resetDriveSensor){
		motor_Left.tare_position();
		motor_Right.tare_position();
	}
	int leftFPosition = driveLeftFront.get_position();
	int leftBPosition = driveLeftBack.get_position();
	int RightFPosition = driveRightFront.get_position();
	int RightBPosition = driveRightBack.get_position();
	int leftAvg = (leftBPosition + leftBPosition)/2;
	int rightAvg = (RightBPosition+ RightFPosition)/2;
	int avgPos = (leftAvg+rightAvg)/2;

	error = avgPos - targetPosition;
	derivate = error - prevError;
	totalError += error;

	double lateralMotion = kP*error + kI*totalError + kD*derivate;

	int turnDifference = leftAvg - rightAvg;
	turn_error = turnDifference - turn_targetPosition;
	turn_derivate = turn_error - turn_prevError;
	turn_totalError += turn_error;
	double turnMotor = turn_kP*turn_error + turn_kI*turn_totalError + turn_kD*turn_derivate;
	motor_Left.move_voltage(lateralMotion + turnMotor);
	motor_Right.move_voltage(lateralMotion- turnMotor); 
	prevError = error;	
	turn_prevError = turn_error;
	return 0;
    */