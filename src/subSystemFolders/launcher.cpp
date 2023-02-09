#include "main.h"
#include "pros/misc.h"
#include "pros/rtos.hpp"

//HELPER FUNCTION
void setLauncher(){
   if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)){
        pnA.set_value(true);
        pros::delay(90);
        pnA.set_value(false);
        pros::delay(77);
    }
}

