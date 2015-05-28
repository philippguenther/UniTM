//
//  TuringTape.cpp
//  UniTM
//
//  Created by Philipp Günther on 06.01.13.
//  Copyright (c) 2013 Dewellop. All rights reserved.
//

#include "TuringTape.h"

TuringTape* TuringTape::index = nullptr;
long TuringTape::length = 0;
long TuringTape::maxLength = -1;
char TuringTape::tape0 = '#';
bool TuringTape::connected = false;
std::vector<char> *TuringTape::validv = new std::vector<char>();

TuringTape::TuringTape() {
	TuringTape::length++;
	this->value = TuringTape::tape0;
	this->left = nullptr;
	this->right = nullptr;
}

TuringTape::TuringTape(char _tape0, long _tapem, std::vector<char> *_tapev, long _tapei, std::vector<char> *_validv) {
	TuringTape::length++;
	this->value = TuringTape::tape0;
	this->left = nullptr;
	this->right = nullptr;
	if (TuringTape::index == nullptr) {
		TuringTape::maxLength = _tapem;
		TuringTape::tape0 = _tape0;
		TuringTape::validv = _validv;
		
		if (_tapev->size() > 0) {
			this->value = _tapev->at(0);
			int i = 1;;
			TuringTape* tt = this;
			TuringTape* tt2;
			while (i < _tapev->size()) {
				tt2 = new TuringTape();
				tt->right = tt2;
				tt2->left = tt;
				tt2->value = _tapev->at(i);
				if (_tapei == i)
					TuringTape::index = tt2;
				tt = tt2;
				i++;
			}
		} else {
			this->value = TuringTape::tape0;
		}
		if (TuringTape::index == nullptr)
			TuringTape::index = this;
	} else {
		std::cerr << "wrong tape constructor\n";
	}
}

void TuringTape::goRight() {
	if (TuringTape::index->right != nullptr) {
		TuringTape::index = TuringTape::index->right;
	} else {
		if (TuringTape::length == TuringTape::maxLength && TuringTape::maxLength > 0) {
			TuringTape *tt = TuringTape::index;
			while (tt->left != nullptr) {
				tt = tt->left;
			}
			TuringTape::index->right = tt;
			tt->left = TuringTape::index;
			TuringTape::index = tt;
			TuringTape::connected = true;
		} else {
			TuringTape *tt = new TuringTape();
			tt->left = TuringTape::index;
			TuringTape::index->right = tt;
			TuringTape::index = tt;
		}
	}
}

void TuringTape::goLeft() {
	if (TuringTape::index->left != nullptr) {
		TuringTape::index = TuringTape::index->left;
	} else {
		if (TuringTape::length == TuringTape::maxLength && TuringTape::maxLength > 0) {
			TuringTape *tt = TuringTape::index;
			while (tt->right != nullptr) {
				tt = tt->right;
			}
			TuringTape::index->left = tt;
			tt->right = TuringTape::index;
			TuringTape::index = tt;
			TuringTape::connected = true;
		} else {
			TuringTape *tt = new TuringTape();
			tt->right = TuringTape::index;
			TuringTape::index->left = tt;
			TuringTape::index = tt;
		}
	}
}

void TuringTape::write(char _write) {
	TuringTape::index->value = _write;
}

char TuringTape::get() {
	return TuringTape::index->value;
}

long TuringTape::getLength() {
	return TuringTape::length;
}

std::vector<char>* TuringTape::getValidv() {
	return TuringTape::validv;
}

void TuringTape::print() {
	TuringTape* tt = TuringTape::index;
	if (!TuringTape::connected) {
		while (tt->left != nullptr) {
			tt = tt->left;
		}
		
		std::cout << "[";
		while (tt->right != nullptr) {
			if (tt == TuringTape::index)
				std::cout << "|" << tt->value << "|";
			else
				std::cout << tt->value;
			tt = tt->right;
		}
		if (tt == TuringTape::index)
			std::cout << "|" << tt->value << "|" << "]";
		else
			std::cout << tt->value << "]";
	} else {
		std::cout << "]";
		int i = 0;
		while (i <= TuringTape::length) {
			if (tt == TuringTape::index)
				std::cout << "|" << tt->value << "|";
			else
				std::cout << tt->value;
			tt = tt->right;
			i++;
		}
		std::cout << "[";
	}
}
