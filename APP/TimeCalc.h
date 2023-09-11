/*
 * TimeCalc.h
 *
 *  Created on: Sep 10, 2023
 *      Author: M
 */

#ifndef APP_TIMECALC_H_
#define APP_TIMECALC_H_

#include "TimeCalc.h"
#include "../MCAL/Timer/timer.h"
#include "../LIB/STD_TYPES.h"

/*************CONFIGURATIONS*************/
typedef struct timestamp{
	u8 hours;
	u8 minutes;
	u8 seconds;
} timestamp;

typedef struct spotInfo{
	u8 SpotNum;
	timestamp EnteringTime;
	timestamp LeavingTime;
	timestamp ParkingDuration;
} spotInfo;

/*************PROTOTYPES*************/
void AddOneSecond(timestamp * CurrentTimePtr);
void SpotEnteringTime(spotInfo * SpotPtr, timestamp * CurrentTimePtr);
void SpotLeavingTime(spotInfo * SpotPtr, timestamp * CurrentTimePtr);
void CalcParkingDuration(spotInfo * SpotPtr);

#endif /* APP_TIMECALC_H_ */
