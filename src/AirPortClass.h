/*
 * AirPortClass.h
 *
 *  Created on: Apr 25, 2017
 *      Author: Dillah
 */

#ifndef AIRPORTCLASS_H_
#define AIRPORTCLASS_H_
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class AirPortClass {
public:
	struct nodetemp{
		int a;
        int arrtime;
        int deptime;
        AirPortClass *Dest;
	} temp;
	AirPortClass *prev;
    string AirPortName;
    
    
//	vector<node*> ND;

	AirPortClass();
	virtual ~AirPortClass();
private:

};

#endif /* AIRPORTCLASS_H_ */
