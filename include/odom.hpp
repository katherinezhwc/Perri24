#include "main.h"
#include "motorSetup.h"

pros::Rotation sideRotate(2);
pros::Rotation rightRotate(3);
pros::IMU inertial(4);

double xPosition = 0; //
double yPosition = 0; // <- GLOBAL variables so that they can be used elsewhere in the code

void odom(){
    //Keep track of wheel rotation values
    int prevLeft = leftRotate.get_position();
    int prevRight = rightRotate.get_position();
    int prevSide = sideRotate.get_position();
    double prevAngle = 0;
    //If using inetial sensor: double prevAngle = inertial.get_rotation();

    //Distances from wheels to the tracking center
    double leftDistance = 1.75;
    double rightDistance = 1.63;
    double sideDistance = 2.37;

    while(true){
        //Distance that the wheels have moved in each interation
        double deltaLeft = leftRotate.get_position() - prevLeft;
        double deltaRight = rightRotate.get_position() - prevRight;
        double deltaSide = sideRotate.get_position() - prevSide;
        // Using inertial: double deltaInertial = inertial.get_rotation() - prevAngle;

        //convert ticks to inches (ticks - > turns - > inches) NOTES: atan(1) * 4 = pi; divide by 36000 to get the # of turns
        deltaLeft *= (atan(1)*4 * leftTrackDia)/36000;
        deltaRight *= (atan(1)*4 * rightTrackDia)/36000;
        deltaSide *= (atan(1)*4 * sideTrackDia)/36000;
        //Using inertial: 

        //Calculate how much the robot has turned (without using an inertial)

        double deltaTheta = (deltaLeft - deltaRight)/(rightDistance + leftDistance);
        //Using the inertial sensor:

       //Calculating LOCAL OFFSET (relative to the robot's movement)

        double localDeltaX;
        double localDeltaY;

        if(deltaTheta == 0){ //The robot DID NOT turn
            localDeltaX = deltaSide; //deltaSide tracks how much the robot moved left / right
            localDeltaY = deltaLeft; // deltaLeft OR deltaRight track how much the robot moved forwards / backwards
        } else { //robot DID turn
            double radiusFront = deltaLeft/deltaTheta - leftDistance;
            double radiusSide = deltaSide/deltaTheta - sideDistance;

            localDeltaX = 2 * radiusSide * sin(deltaTheta/2);
            localDeltaY = 2 *  radiusFront * sin(deltaTheta/2);
        }

        //Convert LOCAL -> GLOBAL change (relative to the field itself)

        //Method 1(Polar Coordinates)
        double distance = sqrt(localDeltaX * localDeltaX + localDeltaY * localDeltaY); //Distance formula to get hte total distance for the coordinates
        xPosition += distance * cos(atan(localDeltaY/localDeltaX) - prevAngle - deltaTheta/2);
        yPosition += distance * sin(atan(localDeltaY/localDeltaX) - prevAngle - deltaTheta/2);

        /*Method 2
        xPosition += localDeltaX * sin(prevAngle + deltaTheta/2) + localDeltaY * cos(prevAngle + deltaTheta/2);
        yPosition += localDeltaX * cos(prevAngle + deltaTheta/2) - localDeltaY * sin(prevAngle + deltaTheta/2);
        */

        prevLeft = leftRotate.get_position();
        prevRight = rightRotate.get_position();
        prevSide = sideRotate.get_position();
        prevAngle = prevAngle + deltaTheta;
        //Using inertial: anglePrev = inertial.get_rotation();

    }
}