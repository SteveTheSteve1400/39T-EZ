#include "main.h"
#include "pros/imu.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motors.h"
#include "pros/rotation.hpp"
#include "pros/motors.hpp"
//motor
pros::Motor flywheel(18,pros::E_MOTOR_GEARSET_06, true);
pros::Motor intake(11,pros::E_MOTOR_GEARSET_06, false);
//pnuematics 
pros::ADIDigitalOut pnA('A');
pros::ADIDigitalOut pnC('C');

//controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

///various variable
int powerdrawn = 95;
int jello = 9000;
bool eight = false;
int designatedspeed = 400;