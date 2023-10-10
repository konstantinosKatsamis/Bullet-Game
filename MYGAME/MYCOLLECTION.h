#pragma once
#include "GAMEOBJECT.h"
#include "TERATAKI.h"
#include <iostream>
#include <vector>
using namespace std;
template <class TERATAKI>

class MYCOLLECTION{

public:
	vector<TERATAKI*> AGELH;

	void add(TERATAKI* x) {
		AGELH.push_back(x);
	}
	int count() {
		return AGELH.size();
	}
	void clear() {
		AGELH.clear();
	}

	bool isEmpty() {
		return AGELH.empty();
	}

	TERATAKI* operator [](int ItemKey) {
		return AGELH[ItemKey];
	}


};