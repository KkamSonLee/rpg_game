#include "map_integrity_check.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
#define MAP_NUM 10


enum {
	SUCCESS,
	ERROR,
	WARNING
};


map_integrity_check::map_integrity_check()
{
}

map_integrity_check::~map_integrity_check()
{
}

void map_integrity_check::save_change(string s, vector<int> val1, vector<int> val2)
{
	ofstream sfile(s);

	if (sfile.is_open()) {
		for (int i = 0; i < val1.size(); i++) {
			if (val1[i] < 0) {
				break;
			}
			sfile << val1[i];
			sfile << "\t";

		}
		sfile << "\n";
		for (int i = 0; i < val2.size(); i++) {
			if (val2[i] < 0) {
				break;
			}
			sfile << val2[i];
			sfile << "\t";

		}
		sfile.close();

	}
}


int map_integrity_check::load_set(string s)
{
	vector<int> check_value_1;
	vector<int> check_value_2;
	char datas_1[100];
	char datas_2[100];
	int Flag;
	vector<string> check_list_1;
	vector<string> check_list_2;

	int map_list[10] = { 1,2,3,4,5,6,7,-1,-1,-1 };

	int list_size_1;
	int list_size_2;

	char* temp;
	ifstream ifs;
	ifs.open(s);
	ifs.getline(datas_1, 100);
	ifs.getline(datas_2, 100);
	ifs.close();
	temp = strtok(datas_1, "\t");
	while (temp != NULL) {
		check_list_1.push_back(temp);
		temp = strtok(NULL, "\t");
	}
	temp = strtok(datas_2, "\t");
	while (temp != NULL) {
		check_list_2.push_back(temp);
		temp = strtok(NULL, "\t");
	}
	list_size_1 = check_list_1.size();
	list_size_2 = check_list_2.size();

	if (list_size_1 < 2 || list_size_1 >10) {
		return ERROR;
	}
	if (list_size_2 < 4 || list_size_2 >9) {
		return ERROR;
	}

	//오류 문자 존재하는지 체크
	for (int i = 0; i < list_size_1; i++) {
		try {
			if (i >= 1) {
				if (check_value_1[i - 1] == stoi(check_list_1[i])) {
					return ERROR;
				}
			}
			check_value_1.push_back(stoi(check_list_1[i]));
		}
		catch (...) {
			return ERROR;
		}
	}
	//오류 문자 존재하는지 체크
	for (int i = 0; i < list_size_2; i++) {
		try {
			check_value_2.push_back(stoi(check_list_2[i]));
		}
		catch (...) {
			return ERROR;
		}
	}
	//중복 맵 존재
	int cnt = 0;
	for (int i = 0; i < MAP_NUM; i++) {
		if (check_value_1[0] == map_list[i]) {
			cnt++;
		}
		if (cnt == 2) {
			return ERROR;
		}
	}
	//아이템 개수 안맞음
	if (check_value_2[3] != (list_size_2 - 4)) {
		return ERROR;
	}
	//맵종류가 1,2,3 모두 아닌 경우
	if ((check_value_2[1] != 1) && (check_value_2[1] != 2) && (check_value_2[1] != 3)) {
		return ERROR;
	}
	//랩 제한 오류
	if (check_value_2[0] <= 0) {
		return ERROR;
	}
	//몬스터 없는 경우
	if ((check_value_2[1] == 2) || (check_value_2[1] == 3) && (check_value_2[2] == 0)) {
		return ERROR;
	}
	//마을에 몬스터 존재
	if (check_value_2[1] == 1 && check_value_2[2] != 0) {
		check_value_2[2] = 0;

		save_change(s, check_value_1, check_value_2);

		return WARNING;
	}
	//던전에 아이템 존재
	if (((check_value_2[1] == 2) || (check_value_2[1] == 3)) && (check_value_2[3] != 0)) {
		check_value_2[3] = 0;

		save_change(s, check_value_1, check_value_2);

		return WARNING;
	}

	return SUCCESS;
}

