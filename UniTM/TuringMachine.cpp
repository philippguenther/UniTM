//
//  TuringMachine.cpp
//  UniTM
//
//  Created by Philipp Günther on 06.01.13.
//  Copyright (c) 2013 Dewellop. All rights reserved.
//

#include "TuringMachine.h"

long TuringMachine::logStep = 1;
long TuringMachine::logTape = 0;
char TuringMachine::stateF = 'H';

TuringMachine::TuringMachine(long _logStep, long _logTape, char _stateF) {
	TuringMachine::logStep = _logStep;
	TuringMachine::stateF = _stateF;
    TuringMachine::logTape = _logTape;
}

void TuringMachine::start() {
	TuringTape::print();
	std::cout << "\n";
	TuringState::print();
	long steps = 0;
	while (TuringState::getIndex()->getName() != TuringMachine::stateF) {
		if (TuringMachine::logStep > 0 && steps % TuringMachine::logStep == 0) {
			std::cout << "\r" << TuringState::getIndex()->getName() << " " << steps;
		}
        if (TuringMachine::logTape > 0 && steps % TuringMachine::logTape == 0) {
            std::cout << "\r";
            TuringTape::print();
		}
		TuringMachine::step();
		steps++;
	}
    if (TuringMachine::logStep <= 0 && TuringMachine::logTape > 0) {
        std::cout << "\r";
        TuringTape::print();
        std::cout << "\n" << TuringState::getIndex()->getName() << " " << steps << "\n";
    } else {
        std::cout << "\r" << TuringState::getIndex()->getName() << " " << steps << "\n";
        TuringTape::print();
        std::cout << "\n";
    }
}

void TuringMachine::step() {
	if (TuringState::getIndex()->getName() == TuringMachine::stateF) {
		TuringState::setIndex(TuringMachine::stateF);
		return;
	}
	
	TuringTransition* transition;
	transition = TuringState::getIndex()->getTransition(TuringTape::get());
	
	if (transition == nullptr) {
		TuringState::setIndex(TuringMachine::stateF);
		std::cerr << "\nreached undefined transition\n";
		return;
	} else {
		TuringTape::write(transition->getWrite());
		
		if (transition->getAction() == 'r')
			TuringTape::goRight();
		else if (transition->getAction() == 'l')
			TuringTape::goLeft();
		else {
			TuringState::setIndex(TuringMachine::stateF);
		return;
		}
	}
		
	TuringState::setIndex(transition->getState());
}

char TuringMachine::getStateF() {
	return TuringMachine::stateF;
}
