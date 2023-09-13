/*
 * TimeCalc.c
 *
 *  Created on: Sep 10, 2023
 *      Author: M
 */


#include "STD_TYPES.h"
#include "timer.h"
#include "TimeCalc.h"

void AddOneSecond(timestamp * CurrentTimePtr){
	if(CurrentTimePtr->seconds + 1 == 60){  //seconds overflow --> reset seconds and add one minute
		CurrentTimePtr->seconds = 0;
		if(CurrentTimePtr->minutes + 1 == 60){  //minutes overflow
			CurrentTimePtr->minutes = 0;
			if(CurrentTimePtr->hours + 1 == 24){  //hours overflow
				CurrentTimePtr->hours = 0;
			}
			else {
				(CurrentTimePtr->hours)++;
			}
		}
		else {
			(CurrentTimePtr->minutes)++;
		}
	}
	else {
		(CurrentTimePtr->seconds)++;
	}
}

void SpotEnteringTime(spotInfo * SpotPtr, timestamp * CurrentTimePtr){
	SpotPtr->EnteringTime.hours = CurrentTimePtr->hours;
	SpotPtr->EnteringTime.minutes = CurrentTimePtr->minutes;
	SpotPtr->EnteringTime.seconds = CurrentTimePtr->seconds;
}

void SpotLeavingTime(spotInfo * SpotPtr, timestamp * CurrentTimePtr){
	SpotPtr->LeavingTime.hours = CurrentTimePtr->hours;
	SpotPtr->LeavingTime.minutes = CurrentTimePtr->minutes;
	SpotPtr->LeavingTime.seconds = CurrentTimePtr->seconds;
}

void CalcParkingDuration(spotInfo * SpotPtr){
	timestamp * Parking_local = &(SpotPtr->ParkingDuration);
	timestamp * Entering_local = &(SpotPtr->EnteringTime);
	timestamp * Leaving_local = &(SpotPtr->LeavingTime);
	//calculate parking hours
	if(Leaving_local->hours - Entering_local->hours < 0){
		Parking_local->hours = Leaving_local->hours - Entering_local->hours + 24;
	}
	else {
		Parking_local->hours = Leaving_local->hours - Entering_local->hours;
	}
	//calculate parking minutes
	if(Leaving_local->minutes - Entering_local->minutes  < 0){
		(Parking_local->hours)--;
		Parking_local->minutes = Leaving_local->minutes - Entering_local->minutes + 60;
	}
	else {
		Parking_local->minutes =Leaving_local->minutes - Entering_local->minutes;
	}
	//calculate parking seconds
	if(Leaving_local->seconds - Entering_local->seconds  < 0){
		(Parking_local->minutes)--;
		Parking_local->seconds = Leaving_local->seconds - Entering_local->seconds + 60;
	}
	else {
		Parking_local->seconds = Leaving_local->seconds - Entering_local->seconds;
	}
}
