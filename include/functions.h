#include "main.h"
#include "odom.hpp"

//Mathematics

double degToRad(int deg){
    double rad = deg * M_PI /180;
    return rad;
}

//Variables
int intakeSpeed = 0;
int intakeDirection = 1; //Pos = intake, neg = outtake
int flywheelSpeed = 0;
int highArc = 1;
double holdingMotors = false;


//AUton Selector
int numAutons = 5;
int selectedAuton=0;
std::string autons[5]={"Over AWP 5","Over AWP","Progskills", "Under AWP", "Under AWP 5"};
void autonSelector(){
    while(master.get_digital_new_press(DIGITAL_A)==0){
        master.print(2,0,"valve");
        master.print(0,0,"%s", autons[selectedAuton]);
        if(master.get_digital_new_press(DIGITAL_RIGHT)){
            master.clear_line(1);
            pros::delay(60);
            selectedAuton = (selectedAuton + 1 + numAutons) % numAutons;
        } else if (master.get_digital_new_press(DIGITAL_LEFT)){
            master.clear_line(1);
            pros::delay(60);
            selectedAuton = (selectedAuton - 1 + numAutons) % numAutons;
        }
        master.print(0,0,"%s", autons[selectedAuton]);
    }
    master.clear();
    pros::delay(2000);
}

//Movement


void driveFunc(double power, double turn){
    double left;
    double right;
    left = power + (turn*0.7);
    right = power - (turn*0.7);
    //Plugging this into a cubed function (600x^3)/(127^3)
    double leftCubed = 600*left*left*left;
    leftCubed /= (127*127*127);
    double rightCubed = 600*right*right*right;
    rightCubed /= (127*127*127);

    FLeft.move_velocity(leftCubed);
    MLeft.move_velocity(leftCubed);
    BLeft.move_velocity(leftCubed);
    FRight.move_velocity(rightCubed);
    MRight.move_velocity(rightCubed);
    BRight.move_velocity(rightCubed);
}

void driveMotors(double ticks, int time){
    FLeft.tare_position();
    MLeft.tare_position();
    BLeft.tare_position();
    FRight.tare_position();
    MRight.tare_position();
    BRight.tare_position();
    FLeft.move_relative(ticks,600);
    MLeft.move_relative(ticks,600);
    BLeft.move_relative(ticks,600);
    FRight.move_relative(ticks,600);
    MRight.move_relative(ticks,600);
    BRight.move_relative(ticks,600);
    pros::delay(time);
    FLeft.move_velocity(0);
    MLeft.move_velocity(0);
    BLeft.move_velocity(0);
    FRight.move_velocity(0);
    MRight.move_velocity(0);
    BRight.move_velocity(0);
}


void tareDriveMotors(){
    FLeft.tare_position();
    MLeft.tare_position();
    BLeft.tare_position();
    FRight.tare_position();
    MRight.tare_position();
    BRight.tare_position();
}

void stopDriveMotors(){
    FLeft.move_velocity(0);
    MLeft.move_velocity(0);
    BLeft.move_velocity(0);
    FRight.move_velocity(0);
    MRight.move_velocity(0);
    BRight.move_velocity(0);
}

void holdMotors(){
    FLeft.set_brake_mode(MOTOR_BRAKE_HOLD);
    BLeft.set_brake_mode(MOTOR_BRAKE_HOLD);
    MLeft.set_brake_mode(MOTOR_BRAKE_HOLD);
    FRight.set_brake_mode(MOTOR_BRAKE_HOLD);
    BRight.set_brake_mode(MOTOR_BRAKE_HOLD);
    MRight.set_brake_mode(MOTOR_BRAKE_HOLD);
}

void coastMotors(){
    FLeft.set_brake_mode(MOTOR_BRAKE_COAST);
    BLeft.set_brake_mode(MOTOR_BRAKE_COAST);
    MLeft.set_brake_mode(MOTOR_BRAKE_COAST);
    FRight.set_brake_mode(MOTOR_BRAKE_COAST);
    BRight.set_brake_mode(MOTOR_BRAKE_COAST);
    MRight.set_brake_mode(MOTOR_BRAKE_COAST);
}

void drivePID (double target, double Kp, double Ki, double Kd){
    tareDriveMotors();
    double threshold = 300;
    double integral = 0;
    double output;
    double prevError = 0;
    double error=6;
    while (true){
            double leftSideMotors = (FLeft.get_position() + MLeft.get_position() + BLeft.get_position())/3;
            double rightSideMotors = (FRight.get_position() + MRight.get_position() + BRight.get_position())/3;
            double avgMotors = (leftSideMotors+rightSideMotors)/2;

            error = target - avgMotors;

            integral += error;

            if(fabs(error) > threshold){
                integral = 0;
            }

            output = error * Kp + integral * Ki + (error-prevError) * Kd;

            FLeft.move_velocity(output);
            MLeft.move_velocity(output);
            BLeft.move_velocity(output);
            FRight.move_velocity(output);
            MRight.move_velocity(output);
            BRight.move_velocity(output);

            prevError = error;
            master.print(1,0,"%d,%d,%d", (int)FRight.get_position(), (int) MRight.get_position(), (int)BRight.get_position());
            if(fabs(prevError)-fabs(error)<2 && fabs(error)<5){
                break;
            }
            pros::delay(20);
    }
    /*FLeft.move_velocity(0);
    MLeft.move_velocity(0);
    BLeft.move_velocity(0);
    FRight.move_velocity(0);
    MRight.move_velocity(0);
    BRight.move_velocity(0);*/
}

void intake_t (void *param){
	while(true){
		Intake.move_velocity(intakeSpeed*intakeDirection);
		pros::delay(10);
	}
}

void flywheel_t (void *param){
	while(true){
		Flywheel.move_velocity(flywheelSpeed);
		pros::delay(10);
	}
}


void autonTurning(double target, double Kp, double Ki, double Kd){
    Inertial.set_rotation(0);
    double error = target-Inertial.get_rotation();
    double prevError = 0;
    double integral = 0;
    double threshold = 20;

    while(true){
        error = target-Inertial.get_rotation();
        integral += error;
        if(fabs(error)>threshold){
            integral = 0;
        }

        double power = error * Kp + integral * Ki + prevError * Kd;
        FRight.move_velocity(-1*power);
        MRight.move_velocity(-1*power);
        BRight.move_velocity(-1*power);
        FLeft.move_velocity(power);
        MLeft.move_velocity(power);
        BLeft.move_velocity(power);

        prevError = error;
        master.print(0,3,"rotation: %f\n", Inertial.get_rotation());
        pros::delay(10);
        if(fabs(error)<0.1){
            break;
        }
        if(fabs(prevError)-fabs(error)<0.05 && fabs(error)<0.4){
            break;
        }
    }
}


void turnPID (double target, double Kp, double Ki, double Kd){
    FLeft.tare_position();
    MLeft.tare_position();
    BLeft.tare_position();
    FRight.tare_position();
    MRight.tare_position();
    BRight.tare_position();
    int right;
    if(target<0){
        right = -1;
    } else if (target>0){
        right = 1;
    }
    target = fabs(target);
    double threshold = 50;
    double integral = 0;
    double output;
    double prevError = 0;
    double leftSideMotors = (FLeft.get_position() + MLeft.get_position() + BLeft.get_position())/3;
    double rightSideMotors = (FRight.get_position() + MRight.get_position() + BRight.get_position())/3;
    double avgMotors = (leftSideMotors+rightSideMotors)/2;
    double error = target - avgMotors;
    while (fabs(error)>5){
            leftSideMotors = (FLeft.get_position() + MLeft.get_position() + BLeft.get_position())/3;
            rightSideMotors = (FRight.get_position() + MRight.get_position() + BRight.get_position())/3;
            avgMotors = (abs(leftSideMotors)+abs(rightSideMotors))/2;

            error = target - avgMotors;

            integral += error;

            if(fabs(error) > threshold){
                integral = 0;
            }

            output = error * Kp + integral * Ki + (error-prevError) * Kd;

            FLeft.move_velocity(output*right);
            MLeft.move_velocity(output*right);
            BLeft.move_velocity(output*right);
            FRight.move_velocity(-output*right);
            MRight.move_velocity(-output*right);
            BRight.move_velocity(-output*right);

            prevError = error;
            master.print(1,0,"%d,  %d", (int)target,(int)avgMotors);
            pros::delay(20);
    }
   /* FLeft.move_velocity(0);
    MLeft.move_velocity(0);
    BLeft.move_velocity(0);
    FRight.move_velocity(0);
    MRight.move_velocity(0);
    BRight.move_velocity(0);*/
}


/*ADVANCED PROGRAMMING*/

void drivingPID(double targetInches, double Kp, double Ki, double Kd){
    pros::Motor leftDrive(1,MOTOR_GEAR_GREEN);
    pros::Motor rightDrive(2,MOTOR_GEAR_GREEN,true);
    pros::Rotation rotation(4);
    rotation.reset();
    double wheelDia = 2.75;
    double error = targetInches;
    double integral=0;
    double prevError = error;

    tareDriveMotors();
    
    while(true){
        double measuredInches = (2.75 * 3.14 * rotation.get_position())/36000;
        error = targetInches - measuredInches;

        if(fabs(error) > 5){
            integral = 0;
        }
        
        leftDrive.move_velocity(error*Kp + integral*Ki + (error-prevError)*Kd);
        rightDrive.move_velocity(error*Kp + integral*Ki + (error-prevError)*Kd);

        prevError = error;

        pros::delay(10);
    }
}

void turnPidHeading (double targetRotation, double Kp, double Ki, double Kd){
    Inertial.set_rotation(0);
    double error = targetRotation - Inertial.get_rotation();
    double prevError = error;
    double integral=0;
    tareDriveMotors();
    while(fabs(error)>25){
        error = targetRotation - Inertial.get_rotation();
        integral += error;
    
        if(fabs(integral) > 300){
            integral = (integral/fabs(integral))*300;
        }

        int output = error * Kp + integral * Ki + (error-prevError) * Kd;

        FLeft.move_velocity(output);
        MLeft.move_velocity(output);
        BLeft.move_velocity(output);
        FRight.move_velocity(-1*output);
        MRight.move_velocity(-1*output);
        BRight.move_velocity(-1*output);

        prevError = error;
        pros::delay(10);
    }
}

//Multitasking
int targetVelocity = 0;
void accelerateMotor(){
    int motorVel = 0;
    pros::Motor motor(1);
    while(true){
        if(motorVel < targetVelocity){
            motorVel+=fmin(5, targetVelocity-motorVel);
        } else if (motorVel >= targetVelocity){
            motorVel-=fmin(5,motorVel-targetVelocity);
        }
        motor.move_velocity(motorVel);
        pros::delay(10);
    }
}

pros::Task accelerateMotorTask(accelerateMotor);

int flywheelTarget;
void flywheelPID(){
    int Kp=15;
    int Ki=3;
    int Kd=5;
    double error = flywheelTarget - Flywheel.get_actual_velocity();
    double integral = 0;
    double prevError = error;
    while(true){
        error = flywheelTarget - Flywheel.get_actual_velocity();
        integral += error;
        if(fabs(error)>100){
            integral = 0;
        }
        double output = error * Kp + integral * Ki + (error-prevError)*Kd;
        Flywheel.move_voltage(output);
        prevError = error;
        pros::delay(10);
    }
}
pros::Task flywheelPidTask(flywheelPID);