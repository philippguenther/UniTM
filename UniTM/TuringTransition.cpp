//
//  TuringTransition.cpp
//  UniTM
//
//  Created by Philipp Günther on 07.01.13.
//  Copyright (c) 2013 Dewellop. All rights reserved.
//

#include "TuringTransition.h"

TuringTransition::TuringTransition(char _input, char _write, char _action, char _state) {
	this->input = _input;
	this->write = _write;
	if (_action == 'l' || _action == 'r' || _action == 'h')
		this->action = _action;
	else
		std::cerr << "wrong Action\n";
	this->state = _state;
}

char TuringTransition::getInput() {
	return this->input;
}

char TuringTransition::getWrite() {
	return this->write;
}

char TuringTransition::getAction() {
	return this->action;
}

char TuringTransition::getState() {
	return this->state;
}
