#include "map_integrity_check.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
#define MAP_NUM 10
#define MONSTER_NUM 3
#define ITEM_NUM 4

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

void map_integrity_check::save_change(string s,vector<int> val1, vector<int> val2)
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


vector<int> map_integrity_check::load_set(string s)
{

	warningMessage warn;
	string msg;
	vector<int> check_value_1;
	vector<int> check_value_2;
	char datas_1[100];
	char datas_2[100];
	char t_map[100];
	int Flag;
	vector<string> check_list_1;
	vector<string> check_list_2;
	vector<int> result;
	vector<string> map_list;

	char* temp;

	ifstream ifs2;
	ifs2.open("total_map.txt");
	ifs2.getline(t_map, 100);
	ifs2.close();
	temp = strtok(t_map, "\t");
	while (temp != NULL) {
		map_list.push_back(temp);
		temp = strtok(NULL, "\t");
	}

	int list_size_1;
	int list_size_2;

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
		result.push_back(1);
		return result;
	}
	if (list_size_2 < 4 || list_size_2 >9) {
		result.push_back(1);
		return result;
	}

	//오류 문자 존재하는지 체크
	for (int i = 0; i < list_size_1; i++) {
		try {
			if (i >= 1) {
				if (check_value_1[i - 1] == stoi(check_list_1[i])) {
					result.push_back(1);
					return result;
				}
			}
			check_value_1.push_back(stoi(check_list_1[i]));
		}
		catch (...) {
			result.push_back(ERROR);
			msg = "올바르지 않은 데이터가 있습니다.";
			warn.printWarning(0, msg);
			return result;
		}
	}
	//오류 문자 존재하는지 체크
	for (int i = 0; i < list_size_2; i++) {
		try {
			check_value_2.push_back(stoi(check_list_2[i]));
		}
		catch (...) {
			result.push_back(ERROR);
			msg = "올바르지 않은 데이터가 있습니다.";
			warn.printWarning(0, msg);
			return result;
		}
	}
	//맵번호>총맵수
	if (check_value_1[0] > map_list.size()+1) {
		result.push_back(ERROR);
		msg = "맵번호가 총 맵의 개수보다 큽니다.";
		warn.printWarning(0, msg);
		return result;
	}
	
	//중복 맵 존재
	for (int i = 0; i < map_list.size(); i++) {
		if (check_value_1[0] == stoi(map_list[i])) {
			msg = "맵번호가 중복되었습니다.";
			warn.printWarning(0, msg);
		}
	}
	//아이템 개수 안맞음
	if (check_value_2[3] != (list_size_2 - 4)) {
		result.push_back(ERROR);
		msg = "아이템 판매 정보가 개수랑 맞지 않습니다.";
		warn.printWarning(0, msg);
		return result;
	}
	//맵종류가 1,2,3 모두 아닌 경우
	if ((check_value_2[1] != 1) && (check_value_2[1] != 2) && (check_value_2[1] != 3)) {
		result.push_back(ERROR);
		msg = "하나 이상의 맵종류 맵이 존재하지 않습니다";
		warn.printWarning(0, msg);
		return result;
	}
	//랩 제한 오류
	if (check_value_2[0] <= 0) {
		result.push_back(ERROR);
		msg = "올바르지 않은 데이터가 있습니다.";
		warn.printWarning(0, msg);
		return result;
	}

    // 몬스터 최대번호 검사
    if (check_value_2[2] > MONSTER_NUM) { // 맵파일의 몬스터 번호가 최대를 넘어갈 경우 오류
        result.push_back(ERROR);
        return result;
    }

	//몬스터 없는 경우
	if (((check_value_2[1] == 2) || (check_value_2[1] == 3)) && (check_value_2[2] == 0)) {
		result.push_back(ERROR);
		msg = "몬스터 정보가 없습니다.";
		warn.printWarning(0, msg);
		return result;
	}


	// 몬스터 최대번호 검사
	if (check_value_2[2] > MONSTER_NUM) { // 맵파일의 몬스터 번호가 최대를 넘어갈 경우 오류
		result.push_back(ERROR);
		msg = "최대 몬스터 번호를 넘는 데이터가 있습니다.";
		warn.printWarning(0, msg);
		return result;
	}

	//아이템 번호 오류 검사
	if (check_value_2[3] != 0) { // 아이템 개수가 0인지 확인
		for (int it = 0; it < list_size_2 - 4; it++) { // 아이템 번호들만 뽑음
			if (ITEM_NUM < check_value_2.at(it + 4)) { // 아이템번호 이더레이터중 아이템 최대번호(4) 넘으면 오류
				result.push_back(ERROR);
				msg = "최대 아이템 번호를 넘는 데이터가 있습니다.";
				warn.printWarning(0, msg);
				return result;
			}
		}
	}
	//마을에 몬스터 존재
	if (check_value_2[1] == 1 && check_value_2[2] != 0) {
		check_value_2[2] = 0;

		save_change(s, check_value_1, check_value_2);
		result.push_back(WARNING);
		result.push_back(list_size_1);
		result.push_back(list_size_2);
		for (int i = 0; i < list_size_1; i++) {
			result.push_back(check_value_1[i]);
		}
		for (int i = 0; i < list_size_2; i++) {
			result.push_back(check_value_2[i]);
		}

		msg = "몬스터 정보가 입력되어 있습니다.";
		warn.printWarning(0, msg);

		return result;
	}
	//던전에 아이템 존재
	if (((check_value_2[1] == 2) || (check_value_2[1] == 3)) && (check_value_2[3] != 0)) {
		check_value_2[3] = 0;

		save_change(s, check_value_1, check_value_2);
		result.push_back(WARNING);
		result.push_back(list_size_1);
		result.push_back(list_size_2);
		for (int i = 0; i < list_size_1; i++) {
			result.push_back(check_value_1[i]);
		}
		for (int i = 0; i < list_size_2; i++) {
			result.push_back(check_value_2[i]);
		}

		msg = "아이템 관련 정보가 입력되어 있습니다.";
		warn.printWarning(0, msg);

		return result;
	}

	result.push_back(SUCCESS);
	result.push_back(list_size_1);
	result.push_back(list_size_2);
	for (int i = 0; i < list_size_1; i++) {
		result.push_back(check_value_1[i]);
	}
	for (int i = 0; i < list_size_2; i++) {
		result.push_back(check_value_2[i]);
	}
	map_list.push_back(check_list_1[0]);

	ofstream sfile("total_map.txt");
	if (sfile.is_open()) {
		for (int i = 0; i < map_list.size(); i++) {
			sfile << map_list[i];
			sfile << "\t";

		}
		return result;
	}
}
