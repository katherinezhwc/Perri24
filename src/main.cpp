#include "main.h"
#include "autonomous.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize() {
	pros::Task intake_task(intake_t);
	Flywheel.set_brake_mode(MOTOR_BRAKE_COAST);
	Intake.set_brake_mode(MOTOR_BRAKE_HOLD);
	endgame.set_value(0);
	blockerblocker.set_value(0);
	wings.set_value(0);
	leftRotate.reset_position();
	backRotate.reset_position();
	Inertial.reset();
	autonSelector();
	//turnPID(perry.degToTicks(45), perry.turnKP,perry.turnKI,perry.turnKD);
	//drivePID(perry.distToTicks(24), perry.driveKP,perry.driveKI,perry.driveKD); //fix dist to ticks function
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	switch (selectedAuton){
		case 0:
			OverAWP5Points();
			break;
		case 1:
			OverAWP();
			break;
		case 2:
			//progSkills();
			break;
		case 3:
			UnderAWP();
			break;
		case 4:
			UnderAWP5Points();
			break;
	}
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */


void opcontrol() {
	pros::Task flywheel_task(flywheel_t);
	
	while (true) {
		
		//Multitasking
		//Movement
		driveFunc(master.get_analog(ANALOG_LEFT_Y),master.get_analog(ANALOG_RIGHT_X));
		//------------Mechanisms---------------//
		//Intake
		
		if(master.get_digital_new_press(DIGITAL_L1)){
			intakeDirection = 1;
			if(intakeSpeed == 300){
				intakeSpeed = 0;
			} else if(intakeSpeed == 0){
				intakeSpeed = 300;
			}
		} else if(master.get_digital_new_press(DIGITAL_L2)){
			intakeDirection = -1;
			if(intakeSpeed == 300){
				intakeSpeed = 0;
			} else if(intakeSpeed == 0){
				intakeSpeed = 300;
			}
		}

		//Flywheel
		if(master.get_digital_new_press(DIGITAL_R1)){
			if (abs(flywheelSpeed) == 600){
				flywheelSpeed = 0;
			} else if (flywheelSpeed == 0){
				flywheelSpeed = 600*highArc;
			}
		}

		if(master.get_digital_new_press(DIGITAL_R2)){
			if (highArc == 1){
				highArc = -1;
			} else if (highArc == -1){
				highArc = 1;
			}
		}

		//Blocker blocker
		if(master.get_digital_new_press(DIGITAL_UP)){ //Matchload mode
			blockerblocker.set_value(1);
		} else if (master.get_digital_new_press(DIGITAL_DOWN)){ //Ingame mode
			blockerblocker.set_value(0);
		}

		//Wings
		if(master.get_digital_new_press(DIGITAL_RIGHT)){
			wings.set_value(1);
			
		} else if (master.get_digital_new_press(DIGITAL_LEFT)){
			
			wings.set_value(0);
		}

		if(master.get_digital_new_press(DIGITAL_Y)){
			if(holdingMotors){
				coastMotors();
				holdingMotors = false;
			} else if (holdingMotors == false){
				holdMotors();
				holdingMotors = true;
			}
		}	

		if(master.get_digital_new_press(DIGITAL_X)){
			endgame.set_value(1);
		} else if (master.get_digital_new_press(DIGITAL_B)){
			endgame.set_value(0);
		}
		
		if(master.get_digital_new_press(DIGITAL_A)){
			/*switch (selectedAuton){
				case 0:
					OverPreload();
					break;
				case 1:
					OverAWP();
					break;
				case 2:
					UnderPreload();
					break;
				case 3:
					UnderAWP();
					break;
				case 4:
					UnderAWP5Points();
					break;
			}*/
			switch (selectedAuton){
				case 0:
					OverAWP5Points();
					break;
				case 1:
					OverAWP();
					break;
				case 2:
					progSkills();
					break;
				case 3:
					UnderAWP();
					break;
				case 4:
					UnderAWP5Points();
					break;
			}
		}
		pros::delay(10);
		
	}
}
