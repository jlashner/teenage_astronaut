//
//  Timer.h
//  Teenage_Astronaut
//
//  Created by Jacob Lashner on 8/5/15.
//  Copyright (c) 2015 Teenage_Astronaut. All rights reserved.
//

#ifndef __Teenage_Astronaut__Timer__
#define __Teenage_Astronaut__Timer__

#include <iostream>

class Timer
{
    // Methods
public:
    Timer();
    ~Timer();
    
    // This returns the number of milliseconds since this object was created.
    float timeSinceCreation();
    
    // This method returns the number of milliseconds that have passed since it was last called.
    float timeSinceLastFrame();
    
    // Data
private:
    // This stores the time of that last call to timeSinceLastFrame().
    float m_timeOfLastCall;
};

#endif /* defined(__Teenage_Astronaut__Timer__) */
