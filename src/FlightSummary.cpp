/*
 * FlightSummary.cpp
 *
 *  Created on: Apr 11, 2017
 *      Author: Dillah
 */

#include "FlightSummary.h"

void Flight_Summary::outSum(){
	Waktu enrote;
	enrote.hari = infligh.hari + layover.hari;
	enrote.jam = infligh.jam + layover.jam;
	enrote.menit = infligh.menit + layover.menit;

	if(enrote.menit > 59){
		enrote.jam += enrote.menit/60;
		enrote.menit = enrote.menit % 60;
	}
	if(enrote.jam > 23){
		enrote.hari += enrote.jam/23;
		enrote.jam = enrote.jam % 23;
	}

	cout << "Enroute Time: "<< enrote.hari <<" days  "<< enrote.jam <<" hours "<< enrote.menit <<" minutes" << endl;
	cout << "In-Flight Time: "<< infligh.hari <<" days  "<< infligh.jam <<" hours "<< infligh.menit <<" minutes" << endl;
	cout << "Layover Time: "<< layover.hari <<" days  "<< layover.jam <<" hours "<< layover.menit <<" minutes" << endl;
}
void Flight_Summary::writeSum(int a, int b){
	int D1,D2,J1,J2,M1,M2;
	D1 = (a / 10000);
	D2 = (b / 10000);
	infligh.hari +=  D2 - D1;
	J1 = (a % 10000) / 100;
	J2 = (b % 10000) / 100;
	M1 = a % 100;
	M2 = b % 100;
	if(M2 >= M1)
		infligh.menit += M2 - M1;
	else{
		infligh.jam -= 1;
		infligh.menit += (M2 + 60) - M1;
	}
	if(J2 >= J1)
	infligh.jam += J2 - J1;
	else{
		infligh.hari -= 1;
		infligh.jam += (J2 + 24) - J1;
	}

	if(infligh.menit > 59){
		infligh.jam += infligh.menit/60;
		infligh.menit = infligh.menit % 60;
	}
	if(infligh.jam > 23){
		infligh.hari += infligh.jam/24;
		infligh.jam = infligh.jam % 24;
	}

	if(waktusebelumnya != 0){
		layover.hari += (waktusebelumnya /10000) - (b/10000);
		J1 = (b % 10000) / 100;
		J2 = (waktusebelumnya % 10000) / 100;
		M1 = b % 100;
		M2 = waktusebelumnya % 100;

		if(M2 >= M1)
			layover.menit += M2 - M1;
		else{
			layover.jam -= 1;
			layover.menit += (M2 + 60) - M1;
		}
		if(J2 >= J1)
			layover.jam += J2 - J1;
		else{
			layover.hari -= 1;
			layover.jam += (J2 + 24) - J1;
		}

		if(layover.menit > 59){
			layover.jam += layover.menit/60;
			layover.menit = layover.menit % 60;
		}
		if(layover.jam > 23){
			layover.hari += layover.jam/24;
			layover.jam = layover.jam % 24;
		}
	}
	waktusebelumnya = a;

}
void Flight_Summary::readBack(AirPortClass &akhir, ostringstream &out){
	if(akhir.prev){
		string outTemp ="";
		outTemp = out.str();
		out.str("");
		out << akhir.prev->AirPortName <<" at ";
		out << akhir.temp.arrtime <<" to ";
		out << akhir.temp.deptime <<" in ";
		out << akhir.AirPortName << endl;
		out << outTemp;
		writeSum(akhir.temp.arrtime,akhir.temp.deptime);
		akhir.temp.a =0;
		akhir.temp.arrtime= 0;
        akhir.temp.deptime= 0;
        akhir.temp.Dest= NULL;
		readBack(*akhir.prev,out);
	}
}
bool Flight_Summary::Cek(AirPortClass &awal){
	bool ret = 0;
	for(unsigned i=0;i<dontCek.size();i++){
		if(dontCek[i] == &awal){
			ret = 1;
			break;
		}
	}
	return ret;
}

void Flight_Summary::readRute(AirPortClass &awal){
	bool ada = 0, berlanjut = 0;
	dontCek.push_back(&awal);

	for (unsigned i=0; i < listOfRute.size(); i++){
        if(listOfRute[i]->Origin != &awal)
            continue;
        
        if(Cek(*listOfRute[i]->Destiny))
			continue;

		berlanjut =1;
		if(listOfRute[i]->Destiny == Destiny){
			int b = awal.temp.deptime ;
			if( b < listOfRute[i]->arrtime){
				int a = listOfRute[i]->deptime - listOfRute[i]->arrtime;
				int transit = listOfRute[i]->arrtime - b;
				a += transit;
				if(Destiny->temp.a == 0 || Destiny->temp.a + awal.temp.a > a){
					Destiny->temp.a = a;
                    Destiny->temp.arrtime = listOfRute[i]->arrtime;
                    Destiny->temp.deptime = listOfRute[i]->deptime;
                    Destiny->temp.Dest = listOfRute[i]->Destiny;
					Destiny->prev = &awal;
				}
				ada = 1;
			}
		}else{
			int b = awal.temp.deptime;
			if(b < listOfRute[i]->arrtime){
				int a = listOfRute[i]->deptime - listOfRute[i]->arrtime;
				int transit = listOfRute[i]->arrtime - b;
				a += transit;
				if(listOfRute[i]->Destiny->temp.a == 0 || listOfRute[i]->Destiny->temp.a + awal.temp.a > a){
					listOfRute[i]->Destiny->temp.a = a;
                    listOfRute[i]->Destiny->temp.arrtime = listOfRute[i]->arrtime;
                    listOfRute[i]->Destiny->temp.deptime = listOfRute[i]->deptime;
                    listOfRute[i]->Destiny->temp.Dest = listOfRute[i]->Destiny;
					listOfRute[i]->Destiny->prev = &awal;
				}
			}
		}
	}
	if(berlanjut)
		if(!ada){
			for (unsigned i=0; i < listOfRute.size(); i++){
				if(!Cek(*listOfRute[i]->Destiny))
					readRute(*listOfRute[i]->Destiny);
			}
		}
}
void Flight_Summary::setSummary(AirPortClass &arr, AirPortClass &des){
	Arrival = &arr;
	Destiny = &des;
	dontCek.clear();
	Arrival->temp.a = 0;
	Arrival->temp.a = 0;
	Arrival->prev = NULL;
	readRute(*Arrival);
	ostringstream aa;
	readBack(*Destiny,aa);
    if(aa.str() == ""){
        cout << arr.AirPortName << " to "<< des.AirPortName << endl;
        cout << "Tidak ada rute yang ditemukan" << endl;
        return;
    }
	cout << aa.str() << endl;
	outSum();
}
Flight_Summary::Flight_Summary(vector<Rute*> list) {
	// TODO Auto-generated constructor stub
	Arrival = NULL;
	Destiny = NULL;

	waktusebelumnya = 0;
	infligh.hari =0;
	infligh.jam =0;
	infligh.menit =0;
	layover.hari =0;
	layover.jam =0;
	layover.menit =0;
    listOfRute.clear();
    listOfRute = list;
    
}

Flight_Summary::~Flight_Summary() {
	// TODO Auto-generated destructor stub
}

