//
//  TuringTransition.h
//  UniTM
//
//  Created by Philipp Günther on 07.01.13.
//  Copyright (c) 2013 Dewellop. All rights reserved.
//

#ifndef __UniTM__TuringTransition__
#define __UniTM__TuringTransition__

#include <iostream>

class TuringTransition {
public:
	TuringTransition(char _input, char _write, char _action, char _state);
	char getInput();
	char getWrite();
	char getAction();
	char getState();
private:
	char input;
	char write;
	char action;
	char state;
};

#endif /* defined(__UniTM__TuringTransition__) */
