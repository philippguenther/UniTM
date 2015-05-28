//
//  TuringMachine.h
//  UniTM
//
//  Created by Philipp Günther on 06.01.13.
//  Copyright (c) 2013 Dewellop. All rights reserved.
//

#ifndef __UniTM__TuringMachine__
#define __UniTM__TuringMachine__

#include <iostream>
#include "TuringTape.h"
#include "TuringTransition.h"
#include "TuringState.h"

class TuringMachine {
public:
	TuringMachine(long _logging, long _logTape, char _stateF);
	static void start();
	static char getStateF();
private:
	static void step();
	static long logStep;
    static long logTape;
	static char stateF;
};

#endif /* defined(__UniTM__TuringMachine__) */
