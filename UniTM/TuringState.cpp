//
//  TuringState.cpp
//  UniTM
//
//  Created by Philipp Günther on 07.01.13.
//  Copyright (c) 2013 Dewellop. All rights reserved.
//

#include "TuringState.h"

TuringState* TuringState::root = nullptr;
TuringState* TuringState::index = nullptr;

TuringState::TuringState(char _name) {
	this->name = _name;
	this->next = nullptr;
	
	if (TuringState::root == nullptr) {
		TuringState::root = this;
		TuringState::index = this;
	} else {
		TuringState* ts = TuringState::root;
		while (ts->next != nullptr)
			ts = ts->next;
		ts->next = this;
	}
	if (this->transitions == nullptr) {
		this->transitions = new std::vector<TuringTransition*>;
	}
}

char TuringState::getName() {
	return this->name;
}

void TuringState::addTransition(TuringTransition* _transistion) {
	this->transitions->push_back(_transistion);
}

TuringTransition* TuringState::getTransition(char _input) {
	int i = 0;
	while (i < this->transitions->size()) {
		if (transitions->at(i)->getInput() == _input)
			return transitions->at(i);
		i++;
	}
	return nullptr;
}

TuringState* TuringState::getIndex() {
	return TuringState::index;
}

void TuringState::setIndex(char _name) {
	TuringState* ts = TuringState::root;
	while (ts->next != nullptr) {
		if (ts->getName() == _name) {
			TuringState::index = ts;
			return;
		}
		ts = ts->next;
	}
	TuringState::index = ts;
}

void TuringState::print() {
	TuringState* ts = TuringState::root;
	while (ts->next != nullptr && ts->next->getName() != TuringMachine::getStateF()) {
		std::cout << "+-----";
		ts = ts->next;
	}
	std::cout << "+-----+-----+\n";
	
	ts = TuringState::root;
	std::cout << "|     |";
	while (ts->next != nullptr && ts->next->getName() != TuringMachine::getStateF()) {
		std::cout << "  " << ts->getName() << "  |";
		ts = ts->next;
	}
	std::cout << "  " << ts->getName() << "  |\n";
	
	ts = TuringState::root;
	while (ts->next != nullptr && ts->next->getName() != TuringMachine::getStateF()) {
		std::cout << "+-----";
		ts = ts->next;
	}
	std::cout << "+-----+-----+\n";
	
	int i = 0;
	while (i < TuringTape::getValidv()->size()) {
		ts = TuringState::root;
		char validvi = TuringTape::getValidv()->at(i);
		std::cout << "|  " << validvi << "  |";
		TuringTransition *tt = ts->getTransition(validvi);
		while (ts->next != nullptr && ts->next->getName() != TuringMachine::getStateF()) {
			if (tt != nullptr)
				std::cout << " " << tt->getWrite() << tt->getAction() << tt->getState() << " |";
			else
				std::cout << "     |";
			ts = ts->next;
			tt = ts->getTransition(validvi);
		}
		if (tt != nullptr)
			std::cout << " " << tt->getWrite() << tt->getAction() << tt->getState() << " |\n";
		else
			std::cout << "     |\n";
		ts = TuringState::root;
		while (ts->next != nullptr && ts->next->getName() != TuringMachine::getStateF()) {
			std::cout << "+-----";
			ts = ts->next;
		}
		std::cout << "+-----+-----+\n";
		i++;
	}
}
