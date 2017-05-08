/*
 * AirPortClass.cpp
 *
 *  Created on: Apr 25, 2017
 *      Author: Dillah
 */

#include "AirPortClass.h"

AirPortClass::AirPortClass() {
	// TODO Auto-generated constructor stub
	AirPortName = "\0";
	//ND.clear();
	prev = NULL;
	temp.arrtime=0;
    temp.deptime=0;
    temp.Dest=NULL;
	temp.a =0;
}

AirPortClass::~AirPortClass() {
	// TODO Auto-generated destructor stub
}

