//============================================================================
// Name        : Shortest.cpp
// Author      : abdillahwahab
// Version     :
// Copyright   : Trial
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>


using namespace std;
#include "FindItinerary.h"

using namespace std;
int main() {

	/*
	 * Membaca file beerisi list penerbangan dari bandara satu ke bandara lain
	 * Menulisnya kedalam data struct graph
	 * Bandar disimpan di class, dan rutenya disimpan di struct
	 * */
	fstream afile;
	afile.open("maps.txt");
	if(!afile){
		cout << "ERROR: "  << "file tidak dapat dibuka" << endl;
		afile.close();
		return 0;
	}
	string aa, bb, cc;
	int ii, jj;
	Find_Itinerary ooo;
	while (getline(afile,aa)){
		istringstream ss(aa);
		ss >> bb;
		ss >> ii;
		ss >> cc;
		ss >> jj;
		ooo.created(bb,ii,cc,jj);
	}
	ooo.Summary("KPWT","KFHR");
    cout << "+++++++++++++++++++++++" << endl;
	ooo.Summary("KCLM","KFHR");
    cout << "+++++++++++++++++++++++" << endl;
    ooo.Summary("KBFI","KBLI");
    cout << "+++++++++++++++++++++++" << endl;
    ooo.Summary("KBLI","KBFI");
	return 0;
}
