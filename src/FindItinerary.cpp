/*
 * FindItinerary.cpp
 *
 *  Created on: Apr 11, 2017
 *      Author: Dillah
 */

#include "FindItinerary.h"


void Find_Itinerary::Summary(string arrival, string destination){
	AirPortClass *destin = NULL;
	AirPortClass *origin = NULL;
	origin = findAirport(arrival);
	destin = findAirport(destination);
	if(!origin){
        cout << "ERROR : bandara awal tidak ada"; return;}
	if(!destin){
        cout << "ERROR : Bandara akhir tidak ada"; return;}

	map<string, AirPortClass*>::iterator aa;
    for(aa = maps.begin(); aa != maps.end(); aa++){
        aa->second->prev = NULL;
        aa->second->temp.arrtime = 0;
        aa->second->temp.deptime = 0;
        aa->second->temp.Dest = NULL;
        aa->second->temp.a = 0;
    }
	Flight_Summary fligh(Edge);
	fligh.setSummary(*origin, *destin);

}

void Find_Itinerary::created(string arr, int arrTime, string dest, int destTime){

	AirPortClass *destin = NULL;
	AirPortClass *origin = NULL;

	destin = findAirport(dest);
	if(!destin){
		destin = new AirPortClass;
		destin->AirPortName = dest;
		//destin->ND.clear();
		maps.insert(make_pair(dest, destin));
	}
	origin = findAirport(arr);
	if(!origin){
		//ada =0;
		origin = new AirPortClass;
		origin->AirPortName = arr;
		//origin->ND.clear();
        maps.insert(make_pair(arr, origin));
	}

	Rute *jadwal = NULL;
	if (!Edge.empty()){
		for(unsigned i=0;i<Edge.size();i++){
			if (Edge[i]->Origin->AirPortName == origin->AirPortName && Edge[i]->arrtime == arrTime)
				return;
		}
	}
	jadwal = new Rute;
	jadwal->arrtime = arrTime;
	jadwal->deptime = destTime;
	jadwal->Destiny = destin;
    jadwal->Origin = origin;
    Edge.push_back(jadwal);

}

AirPortClass* Find_Itinerary::findAirport( string nameAirPort){
	AirPortClass *aa = NULL;
	map<string, AirPortClass*>::iterator cc;
	for(cc = maps.begin(); cc != maps.end(); cc++){
		if(cc->first == nameAirPort){
			aa = cc->second;
			break;
		}
	}
	return aa;
}

void Find_Itinerary::showmaps(){
	cout << "+++++++++++++++++++++++" << endl;
	for(unsigned i =0; i < Edge.size();i++){
        cout << Edge[i]->Origin->AirPortName << " ";
        cout << Edge[i]->arrtime << " ";
        cout << Edge[i]->Destiny->AirPortName << " ";
        cout << Edge[i]->deptime << endl;
	}
}
Find_Itinerary::Find_Itinerary() {
	// TODO Auto-generated constructor stub
	maps.clear();
	//root=NULL;
}

Find_Itinerary::~Find_Itinerary() {
	// TODO Auto-generated destructor stub
}

