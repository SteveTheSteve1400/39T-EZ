
#include "main.h"
#include "pros/misc.h"

//HELPER FUNCTION
void setIntake(int power){
    intake = power;
}

//DRIVER CONTROL FUNCTION
void setIntakeMotors(){
    int intakePower;
    //if doesn't work, change L1 to L2;
    //top triggers intake, buttom triggers outake;
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        intakePower = 127*(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1));
    }
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        intakePower = -127*(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
    }
    else{
        intakePower = 0;
    }
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        intakePower = -90;
    }
    
    setIntake(intakePower);
}