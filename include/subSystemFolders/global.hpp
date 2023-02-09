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

//controller
extern pros::Controller controller;

//various variable 
extern int selectSpeed;
extern int jello;