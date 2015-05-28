//
//  TuringTape.h
//  UniTM
//
//  Created by Philipp Günther on 06.01.13.
//  Copyright (c) 2013 Dewellop. All rights reserved.
//

#ifndef __UniTM__TuringTape__
#define __UniTM__TuringTape__

#include <iostream>
#include <vector>

class TuringTape {
public:
	TuringTape();
	TuringTape(char _tape0, long _tapem, std::vector<char> *_tapev, long _tapei, std::vector<char> *_validv);
	static void goRight();
	static void goLeft();
	static void write(char _write);
	static char get();
	static void print();
	static long getLength();
	static std::vector<char>* getValidv();
private:
	TuringTape *right;
	TuringTape *left;
	char value;
	static char tape0;
	static long maxLength;
	static long length;
	static bool connected;
	static std::vector<char> *validv;
	static TuringTape *index;
};

#endif /* defined(__UniTM__TuringTape__) */
