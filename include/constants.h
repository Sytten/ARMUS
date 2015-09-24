/*
============================================================================
 Name : constants.h
 Author : fuge2701 & fouj1807
 Version : V0.1
 Created on: 2015-09-24
 Description : Constants for the robot
============================================================================
*/

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define PI_VAL 3.1416

/*****Wheel specifications*****/
#define WHEEL_DIAMETER 7.5
#define HOLES_QTY 32
#define WHEEL_CIRC (WHEEL_DIAMETER * PI_VAL)

#define WHEEL_AXE_DIAM 14
#define WHEEL_AXE_DIAM_MODIFIER 7
#define WHEEL_AXE_DIAM_MODIFIED (WHEEL_AXE_DIAM + WHEEL_AXE_DIAM_MODIFIER)
#define WHEEL_AXE_CIRC (WHEEL_AXE_DIAM_MODIFIED * PI_VAL)

/*****Spin function*****/
#define SPIN_LEFT 0
#define SPIN_RIGHT 1
#define MOTOR_DEFAULT_SPEED 35
#define READING_CYCLE_DELAY 250

/*****Roll Function****/
#define SLAVE_STARTING_SPEED 49
#define MASTER_STARTING_SPEED 50
#define INSTANT_PROPORTIONALITY 0.25
#define LONG_PROPORTIONALITY 0.2

#endif /* CONSTANTS_H_ */