//
//  Rute.hpp
//  Shortest Path
//
//  Created by mohammad abdillah wahab on 4/26/17.
//  Copyright © 2017 mohammad abdillah wahab. All rights reserved.
//

#ifndef Rute_hpp
#define Rute_hpp

#include <stdio.h>
#include <iostream>
#include "AirPortClass.h"

using namespace std;
class Rute{
public:
    int arrtime;
    int deptime;
    AirPortClass *Origin;
    AirPortClass *Destiny;

    Rute();
    virtual ~Rute();
    
private:
    
};

#endif /* Rute_hpp */
