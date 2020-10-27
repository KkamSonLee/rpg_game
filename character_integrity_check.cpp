#include "character_integrity_check.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
character_integrity_check::character_integrity_check() {

}

character_integrity_check::~character_integrity_check() {

}

bool character_integrity_check::load_set(string s) {
	int check_value_1[7] = { 0, };
	int check_value_2[7] = { 0, };
	char datas[100];
	vector<string> check_list;

	int list_size;
	char* temp;
	ifstream ifs;
	ifs.open(s);
	ifs.getline(datas, 100);
	ifs.close();
	temp = strtok(datas, "\t");
	while (temp != NULL) {
		check_list.push_back(temp);
		temp = strtok(NULL, "\t");
	}
	list_size = check_list.size();
	if (list_size < 7 || list_size >14) {
		return false;
	}
	for (int i = 0; i < size(check_value_1); i++) {
		try {
			check_value_1[i] = stoi(check_list[i]);
		}
		catch (...) {
			return false;
		}
	}
	for (int i = 0; i < list_size-7; i++) {
		try {
			check_value_2[i] = stoi(check_list[i]);
		}
		catch (...) {
			return false;
		}
	}
	for (int i = 0; i < size(check_value_1); i++) {
		if (i == 1 || i == 4 || i == 5) {
			if (check_value_1[i] < 0) {
				check_value_1[i] = 0;
			}
		}
		else {
			if (check_value_1[i] <= 0) {
				check_value_1[i] = 1;
			}
		}
	}
	if (check_value_1[0] > 99) {
		check_value_1[0] = 99;
	}
	if (check_value_1[2] < check_value_1[4]) {
		check_value_1[4] = check_value_1[2];
	}
	if (check_value_1[3] < check_value_1[5]) {
		check_value_1[5] = check_value_1[3];
	}

	for (int i = (list_size-7); i < size(check_value_2); i++)
		check_value_2[i] = 0;

	ofstream sfile(s);

	if (sfile.is_open()) {
		for (int i = 0; i < size(check_value_1); i++) {
			sfile << check_value_1[i];
			sfile << "\t";
		}
		for (int i = 0; i < size(check_value_2); i++) {
			sfile << check_value_2[i];
			sfile << "\t";
		}
		sfile.close();

	}
	return true;
}
