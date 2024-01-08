#include "main.h"

pros::Controller master (pros::E_CONTROLLER_MASTER);

#define FR_MOTOR 12
#define MR_MOTOR 3
#define BR_MOTOR 1
#define FL_MOTOR 16
#define ML_MOTOR 18
#define BL_MOTOR 6
#define INERTIAL 20

#define INTAKE 17
#define FLYWHEEL 7

#define BACKROTATE 11
#define LEFTROTATE 12

pros::Motor FRight(FR_MOTOR, MOTOR_GEAR_BLUE, true);
pros::Motor MRight(MR_MOTOR, MOTOR_GEAR_BLUE, false);
pros::Motor BRight(BR_MOTOR, MOTOR_GEAR_BLUE, true); //stacked

pros::Motor FLeft(FL_MOTOR, MOTOR_GEAR_BLUE, false);
pros::Motor MLeft(ML_MOTOR, MOTOR_GEAR_BLUE,  true);
pros::Motor BLeft(BL_MOTOR, MOTOR_GEAR_BLUE, true); //stacked

pros::Motor Intake(INTAKE, MOTOR_GEAR_BLUE);
pros::Motor Flywheel(FLYWHEEL, MOTOR_GEAR_BLUE);

pros::Rotation backRotate(BACKROTATE); //pos is right
pros::Rotation leftRotate(LEFTROTATE); //neg is forward

pros::ADIDigitalOut endgame ('A'); //1 is out, 0 is inside
pros::ADIDigitalOut wings('H');
pros::ADIDigitalOut blockerblocker('C');

pros::IMU Inertial (INERTIAL);
 
double leftTrackDia = 2.75;
double rightTrackDia = 2.75;
double sideTrackDia = 2.75;