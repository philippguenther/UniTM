//
//  TuringState.h
//  UniTM
//
//  Created by Philipp Günther on 07.01.13.
//  Copyright (c) 2013 Dewellop. All rights reserved.
//

#ifndef __UniTM__TuringState__
#define __UniTM__TuringState__

#include <iostream>
#include <vector>
#include "TuringTransition.h"
#include "TuringMachine.h"

class TuringState {
public:
	TuringState(char _name);
	static TuringState* getIndex();
	static void setIndex(char _name);
	static void print();
	char getName();
	void addTransition(TuringTransition* _transistion);
	TuringTransition* getTransition(char _input);
private:
	static TuringState* root;
	static TuringState* index;
	TuringState* next;
	char name;
	std::vector<TuringTransition*> *transitions;
};

#endif /* defined(__UniTM__TuringState__) */
