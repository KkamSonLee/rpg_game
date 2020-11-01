#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "warningMessage.h"
#include <vector>
#include "warningMessage.h"
using namespace std;
class map_integrity_check {
public:
	map_integrity_check();
	~map_integrity_check();
	void save_change(string, vector<int>, vector<int>);
	vector<int> load_set(string s);

};


