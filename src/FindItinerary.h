/*
 * FindItinerary.h
 *
 *  Created on: Apr 11, 2017
 *      Author: Dillah
 */

#ifndef FINDITINERARY_H_
#define FINDITINERARY_H_
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include "AirPortClass.h"
#include "FlightSummary.h"
#include "Rute.hpp"

using namespace std;

class Find_Itinerary {
public:
	map<string, AirPortClass*> maps;
    vector<Rute*> Edge;
    
    void showmaps();													// mencetak semua list penerbangan
	void Summary(string arrival, string destination);					// mengirim ke fligSummary untuk membaca rute terpendek penerbangan

	void created(string Arr, int arrTime, string dest, int destTime);	// menulis rute penerbangan
	Find_Itinerary();
	virtual ~Find_Itinerary();

private:
	AirPortClass* findAirport(string nameAirPort);						// mencari bandara dengan parameter nama
};

#endif /* FINDITINERARY_H_ */
