#include "main.h"
#include "pros/misc.h"
#include "pros/rtos.hpp"

int i__ = 0;
//HELPER FUNCTION
void setLauncher(){
   if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
        pnA.set_value(true);
        pros::delay(90);
        pnA.set_value(false);
        pros::delay(77);
    }
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
        if (i__ %2 == 0){
            pnE.set_value(true);
        }
        else pnE.set_value(false);
        i__++;
        pros::delay(100);
    }
}

