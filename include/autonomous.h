#include "main.h"
#include "driveTrain.h"
driveTrain perry(4,13.5);
//Over side
/*void OverPreload(){
    flywheelSpeed = 600;
    turnPID(perry.degToTicks(45),perry.turnKP,perry.turnKI,perry.turnKD);
    stopDriveMotors();
    intakeDirection=1;
    intakeSpeed = 500;
    pros::delay(1000);
    flywheelSpeed=0;
    intakeSpeed=0;
}
void testAuton(){
    autonTurning(180,2.8,0.0003,0.55);
}
void OverAWP(){
    turnPID(perry.degToTicks(-53),perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(300);
    stopDriveMotors();
    drivePID(perry.distToTicks(25),perry.driveKP,perry.driveKI,perry.driveKD);
    pros::delay(300);
    stopDriveMotors();
    turnPID(perry.degToTicks(46),perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(100);
    stopDriveMotors();
    drivePID(perry.distToTicks(5),perry.driveKP,perry.driveKI,perry.driveKD);
    pros::delay(100);
    stopDriveMotors();
    intakeDirection=1;
    intakeSpeed=500;
    pros::delay(500);
    intakeSpeed = 0;
    drivePID(perry.distToTicks(-4),perry.driveKP,perry.driveKI,perry.driveKD);
    pros::delay(200);
    stopDriveMotors();
    turnPID(perry.degToTicks(-220),perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(400);
    stopDriveMotors();
    driveMotors(perry.distToTicks(-13),200);
    pros::delay(500);
    stopDriveMotors();
    drivePID(perry.distToTicks(5),perry.driveKP,perry.driveKI,perry.driveKD);
    tareDriveMotors();
    pros::delay(300);
    stopDriveMotors();
    turnPID(perry.degToTicks(-70),perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(300);
    stopDriveMotors();
    drivePID(perry.distToTicks(6),perry.driveKP,perry.driveKI,perry.driveKD);
    stopDriveMotors();
}

//Under side
void UnderPreload(){
    intakeDirection=-1;
    intakeSpeed = 500;
    pros::delay(2000);
    intakeSpeed=0;
}

void UnderAWP(){
    pros::delay(100);
    turnPID(perry.degToTicks(50),perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(500);
    stopDriveMotors();
    drivePID(perry.distToTicks(27),perry.driveKP,perry.driveKI,perry.driveKD);
    pros::delay(300);
    stopDriveMotors();
    turnPID(perry.degToTicks(-50),perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(400);
    stopDriveMotors();
    drivePID(perry.distToTicks(3),perry.driveKP,perry.driveKI,perry.driveKD);
    pros::delay(300);
    intakeDirection=1;
    intakeSpeed=500;
    pros::delay(500);
    stopDriveMotors();
    intakeSpeed = 0;
    drivePID(perry.distToTicks(3),perry.driveKP,perry.driveKI,perry.driveKD);
    pros::delay(100);
    stopDriveMotors();
    drivePID(perry.distToTicks(-10),perry.driveKP,perry.driveKI,perry.driveKD);
    pros::delay(200);
    turnPID(perry.degToTicks(220),perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(400);
    stopDriveMotors();
    driveMotors(perry.distToTicks(-12),1100);
    pros::delay(200);
    stopDriveMotors();
    drivePID(perry.distToTicks(5),perry.driveKP,perry.driveKI,perry.driveKD);
    pros::delay(200);
    stopDriveMotors();
    turnPID(perry.degToTicks(50),perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(200);
    stopDriveMotors();
    drivePID(perry.distToTicks(34),perry.driveKP,perry.driveKI,perry.driveKD);
    pros::delay(300);
}

void UnderAWP5Points(){
    drivePID(perry.distToTicks(70), perry.driveKP, perry.driveKI,perry.driveKD);
    pros::delay(300);
    turnPID(perry.degToTicks(90),perry.turnKP, perry.turnKI,perry.turnKD);
    pros::delay(300);
    intakeDirection=-1;
    intakeSpeed = 500;
    pros::delay(400);
    intakeSpeed = 0;
    driveMotors(perry.distToTicks(5),800);
    pros::delay(400);
    drivePID(perry.distToTicks(-6), perry.driveKP, perry.driveKI, perry.driveKD);
    turnPID(perry.degToTicks(180),perry.turnKP, perry.turnKI,perry.turnKD);
    intakeDirection=1;
    intakeSpeed = 500;
    drivePID(perry.distToTicks(15),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(800);
    intakeSpeed=0;
    turnPID(perry.degToTicks(-180),perry.turnKP, perry.turnKI,perry.turnKD);
    drivePID(perry.distToTicks(10),perry.driveKP, perry.driveKI, perry.driveKD);
    intakeDirection=1;
    intakeSpeed = 500;
    pros::delay(400);
    intakeSpeed=0;
    driveMotors(perry.distToTicks(5),800);
    pros::delay(400);
    turnPID(perry.degToTicks(-45),perry.turnKP, perry.turnKI,perry.turnKD);
    pros::delay(400);
    drivePID(perry.distToTicks(-55),perry.driveKP, perry.driveKI, perry.driveKD);
}*/

void OverAWP(){
    /*wings.set_value(1);
    pros::delay(100);
    autonTurning(-75,3,perry.turnKI,perry.turnKD);
    pros::delay(300);
    autonTurning(30,3,perry.turnKI,perry.turnKD);
	wings.set_value(0);
    pros::delay(100);
    drivePID(perry.distToTicks(-12),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(500);
    autonTurning(-83,3,perry.turnKI,perry.turnKD);
    pros::delay(300);
    drivePID(perry.distToTicks(-10),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(300);
    blockerblocker.set_value(0);*/
   
   //==========================================

    wings.set_value(1);
    drivePID(perry.distToTicks(-18),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(200);
    autonTurning(45,3,perry.turnKI,perry.turnKD);
    wings.set_value(0);
    pros::delay(100);
    drivePID(perry.distToTicks(-10),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(100);
    autonTurning(-96,3,perry.turnKI,perry.turnKD);
    pros::delay(100);
    drivePID(perry.distToTicks(50),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(100);
    autonTurning(15,3,perry.turnKI,perry.turnKD);
    blockerblocker.set_value(1);

    //==========================================

   /* wings.set_value(0);
    pros::delay(100);
    autonTurning(-45,3,perry.turnKI,perry.turnKD);
    pros::delay(200);
    autonTurning(45,3,perry.turnKI,perry.turnKD);
    wings.set_value(1);
    pros::delay(200);
    drivePID(perry.distToTicks(28),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(200);
    autonTurning(135,3,perry.turnKI,perry.turnKD);
    pros::delay(200);
    intakeDirection=-1;
    intakeSpeed=600;
    pros::delay(150);
    driveMotors(perry.distToTicks(14),1000);
    pros::delay(150);
    drivePID(perry.distToTicks(-10),perry.driveKP, perry.driveKI, perry.driveKD);*/

    /*drivePID(perry.distToTicks(25),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(200);
    autonTurning(45,3,perry.turnKI,perry.turnKD);
    pros::delay(200);
    intakeDirection=-1;
    intakeSpeed=600;
    pros::delay(150);
    driveMotors(perry.distToTicks(14),1000);
    pros::delay(150);
    intakeSpeed=0;
    drivePID(perry.distToTicks(-14),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(200);
    autonTurning(-45,3,perry.turnKI,perry.turnKD);
    pros::delay(200);
    drivePID(perry.distToTicks(-23),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(200);
    autonTurning(-135,3,perry.turnKI,perry.turnKD);*/
}

void OverAWP5Points(){
    drivePID(perry.distToTicks(25),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(200);
    autonTurning(45,3,perry.turnKI,perry.turnKD);
    pros::delay(200);
    intakeDirection=-1;
    intakeSpeed=600;
    pros::delay(150);
    driveMotors(perry.distToTicks(14),1000);
    pros::delay(150);
    intakeSpeed=0;
    drivePID(perry.distToTicks(-10),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(200);
    autonTurning(-45,3,perry.turnKI,perry.turnKD);
    pros::delay(200);
    wings.set_value(1);
    drivePID(perry.distToTicks(-24),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(200);
    autonTurning(-45,3,perry.turnKI,perry.turnKD);
    pros::delay(100);
    autonTurning(-45,3,perry.turnKI,perry.turnKD);
}
void testAuton(){
    drivePID(perry.distToTicks(12), perry.driveKP, perry.driveKI, perry.driveKD);
}

void UnderAWP(){
    /*autonTurning(53,perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(100);
    drivePID(perry.distToTicks(28),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(200);
    autonTurning(-42,perry.turnKP,perry.turnKI,perry.turnKD);
    intakeDirection=-1;
    intakeSpeed=500;
    pros::delay(400);
    driveMotors(perry.distToTicks(12),1500);
    pros::delay(200);
    intakeSpeed=0;
    pros::delay(100);
    drivePID(perry.distToTicks(-10),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(50);
    autonTurning(55,perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(50);
    drivePID(perry.distToTicks(-36),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(50);
    autonTurning(27,perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(150);
    drivePID(perry.distToTicks(-20),perry.driveKP, perry.driveKI, perry.driveKD);
    drivePID(perry.distToTicks(-10),perry.driveKP, perry.driveKoikoI, perry.driveKD);*/
    drivePID(perry.distToTicks(47),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(50);
    autonTurning(90,perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(100);
    intakeDirection=-1;
    intakeSpeed=500;
    pros::delay(300);
    driveMotors(perry.distToTicks(19),1600);
    pros::delay(100);
    drivePID(perry.distToTicks(-10),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(100);
    driveMotors(perry.distToTicks(16),1600);
    pros::delay(100);
    drivePID(perry.distToTicks(-10),perry.driveKP, perry.driveKI, perry.driveKD);
    intakeSpeed=0;
}

void UnderAWP5Points(){
    drivePID(perry.distToTicks(53),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(50);
    autonTurning(90,perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(100);
    intakeDirection=-1;
    intakeSpeed=500;
    pros::delay(300);
    driveMotors(perry.distToTicks(12),300);
    pros::delay(100);
    intakeSpeed=0;
    pros::delay(100);
    drivePID(perry.distToTicks(-10),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(100);
    autonTurning(160,perry.turnKP,perry.turnKI,perry.turnKD);
    intakeDirection=1;
    intakeSpeed=500;
    pros::delay(100);
    drivePID(perry.distToTicks(30),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(200);
    intakeSpeed=0;
    drivePID(perry.distToTicks(-10),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(100);
    autonTurning(160,perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(100);
    drivePID(perry.distToTicks(10),perry.driveKP, perry.driveKI, perry.driveKD);
    pros::delay(100);
    autonTurning(20,perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(150);
    intakeDirection=-1;
    intakeSpeed=500;
    pros::delay(300);
    driveMotors(perry.distToTicks(16),1500);
    pros::delay(200);
    intakeSpeed=0;
    pros::delay(100);
    drivePID(perry.distToTicks(-10),perry.driveKP, perry.driveKI, perry.driveKD);
}


void progSkills(){
    driveMotors(-25,1500);
    pros::delay(100);
    drivePID(perry.distToTicks(10),perry.driveKP, perry.driveKI, perry.driveKD);
    autonTurning(-90,perry.turnKP,perry.turnKI,perry.turnKD);
    pros::delay(50);
    driveMotors(-6,500);
    pros::delay(50);
    holdMotors();
    flywheelSpeed = 600;
    for(int i = 0; i < 40; i++){
        FLeft.move_velocity(0);
        MLeft.move_velocity(0);
        BLeft.move_velocity(0);
        FRight.move_velocity(0);
        MRight.move_velocity(0);
        BRight.move_velocity(0);
        pros::delay(1000);
    }
}


/*ADVANCED PROG*/
pros::Motor lift(1);
pros::Rotation liftRotation(2);
void moveLift(double targetDegrees){
    lift.set_brake_mode(MOTOR_BRAKE_HOLD);
    double degrees = liftRotation.get_position()/36000 * 360;
    
    if(targetDegrees >= degrees){
        while(targetDegrees >= degrees){
            lift.move_velocity(80);
        }
    }
    if(targetDegrees<degrees){
        while(targetDegrees < degrees){
            lift.move_velocity(-25);
        }
    }
    pros::delay(10);
    
    lift.brake();
}