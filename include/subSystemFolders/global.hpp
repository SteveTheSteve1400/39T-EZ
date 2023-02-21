#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"
//motor
extern pros::Motor flywheel;
extern pros::Motor intake;
//pneumatics
extern pros::ADIDigitalOut pnA;
extern pros::ADIDigitalOut pnC;
extern pros::ADIDigitalOut pnE;

//controller
extern pros::Controller controller;

//various variable 
extern int jello;
extern bool eight;
extern int designatedspeed;
extern int powerdrawn;