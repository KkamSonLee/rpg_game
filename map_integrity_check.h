#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
class map_integrity_check {
public:
	map_integrity_check();
	~map_integrity_check();
	void save_change(string, vector<int>, vector<int>);
	int load_set(string s);

};


