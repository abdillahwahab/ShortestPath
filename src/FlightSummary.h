/*
 * FlightSummary.h
 *
 *  Created on: Apr 11, 2017
 *      Author: Dillah
 */

#ifndef FLIGHTSUMMARY_H_
#define FLIGHTSUMMARY_H_
#include "FindItinerary.h"
#include "AirPortClass.h"
#include "Rute.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Flight_Summary {
public:
	void setSummary(AirPortClass &arr, AirPortClass &des);	// mencari rute dari A-B
	Flight_Summary(vector<Rute*> listOfRute);
	virtual ~Flight_Summary();
private:
	AirPortClass *Arrival;
	AirPortClass *Destiny;
	vector<AirPortClass*> dontCek;
    vector<Rute*> listOfRute;

    bool Cek(AirPortClass &awal);							// Untuk mengecek, apakah bandara ini sudah di cek rutenya atau belum.
	void readRute(AirPortClass &awal);						// mengidentifikasi rute dari A-B
	void readBack(AirPortClass &akhir, ostringstream &out);	// membaca kembali dari Tujuan ke Awal

	// param for time;
	int waktusebelumnya;
	struct Waktu{
		int hari;
		int jam;
		int menit;
	} infligh, layover;
	void writeSum(int a, int b);						// Menulis dalam variable untuk menyimpan waktu yang digunakan
	void outSum();										// menulis ke display untuk rute yang didapatkan
};

#endif /* FLIGHTSUMMARY_H_ */
