//
//  main.cpp
//  UniTM
//
//  Created by Philipp Günther on 06.01.13.
//  Copyright (c) 2013 Dewellop. All rights reserved.
//

#include <iostream>
#include <vector>
#include "TuringMachine.h"
#include "TuringState.h"
#include "TuringTape.h"
#include "TuringTransition.h"

int main(int argc, const char * argv[]) {
	
	//standard values;
	long logStep = 1;
    long logTape = 0;
	char state0 = 'A';
	char stateF = 'H';
	long tapei = 0;
	long tapem = -1;
	char tape0 = '#';
	std::vector<char>* tapev = new std::vector<char>();
	std::vector<char>* validv = new std::vector<char>();
	
	//parsing argv
	int i = 0;
	while (i < argc) {
		std::string argvi = argv[i];
		if (argc <= 1 || argvi.compare("-h") == 0 || argvi.compare("help") == 0 || argvi.compare("--help") == 0) {
			std::cout << "STATE\n";
			std::cout << "   -s0  (default: A) set state to begin\n";
			std::cout << "   -sH  (default: H) set state to halt\n";
			std::cout << "   -s   add new state\n";
			std::cout << "           STATE [ INPUT WRITE l|r|h STATE ]+\n";
			std::cout << "TAPE\n";
			std::cout << "   -t0  (default: #) set standard tape sign\n";
			std::cout << "   -ti  (default: 0) set initial tape index\n";
			std::cout << "   -tm  (default:-1) set maximal length of tape\n";
			std::cout << "   -t   (default: #) set initial tape\n";
			std::cout << "OUTPUT\n";
			std::cout << "   -ls  (default: 1) set step logging\n";
            std::cout << "   -lt  (default: 0) set tape logging\n";
			exit(0);
			
		} else if (argvi.compare("-s0") == 0) {
			state0 = argv[i+1][0];
			
		} else if (argvi.compare("-sH") == 0) {
			stateF = argv[i+1][0];
			
		} else if (argvi.compare("-ti") == 0) {
			std::sscanf(argv[i+1], "%ld", &tapei);
			
		} else if (argvi.compare("-t0") == 0) {
			tape0 = argv[i+1][0];
			
		} else if (argvi.compare("-tm") == 0) {
			std::sscanf(argv[i+1], "%ld", &tapem);
			
		} else if (argvi.compare("-t") == 0) {
			std::string t = argv[i+1];
			int j = 0;
			while (j < t.size()) {
				tapev->push_back(t.at(j));
				j++;
			}
			
		} else if (argvi.compare("-s") == 0) {
			TuringState *ts = new TuringState(argv[i+1][0]);
			std::string *s = new std::string(argv[i+1]);
			int j = 1;
			while (j < s->length()) {
				ts->addTransition(new TuringTransition(s->at(j), s->at(j+1), s->at(j+2), s->at(j+3)));
				int k = 0;
				bool found = false;
				while (k < validv->size()) {
					if (validv->at(k) == s->at(j))
						found = true;
					k++;
				}
				if (!found) {
					validv->push_back(s->at(j));
				}
				j += 4;
			}
			
		} else if (argvi.compare("-ls") == 0 || argvi.compare("-l") == 0) {
			std::sscanf(argv[i+1], "%ld", &logStep);
            logTape = 0;
		
        } else if (argvi.compare("-lt") == 0) {
			std::sscanf(argv[i+1], "%ld", &logTape);
            logStep = 0;
		}
		i++;
	}
	
	//initialization
	TuringState::setIndex(state0);
	new TuringState(stateF);
	new TuringTape(tape0, tapem, tapev, tapei, validv);
	new TuringMachine(logStep, logTape,  stateF);
	TuringMachine::start();
	
    return 0;
}
