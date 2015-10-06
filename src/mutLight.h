//
//  mutLight.h
//  MUTSimulation
//
//  Created by Martin Widyanata on 03.10.14.
//
//

#ifndef __MUTSimulation__mutLight__
#define __MUTSimulation__mutLight__


#include <iostream>
#include "ofMain.h"

class mutLight : public ofLight{
public:
    long mutLightID;
    bool active;
};

#endif /* defined(__MUTSimulation__mutLight__) */
