#include "character_integrity_check.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>

#define ITEM_NUM 4 // 아이템 번호의 최대 숫자

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
	for (int i = 0; i < sizeof(check_value_1)/sizeof(int); i++) {
		try {
			check_value_1[i] = stoi(check_list[i]);
		}
		catch (...) {
			return false;
		}
	}
    for (int i = 7; i < list_size; i++) {
        try {
            check_value_2[i-7] = stoi(check_list[i]);
        }
        catch (...) {
            return false;
        }
    }


    //아이템 번호 오류 검사
    if(sizeof(check_value_2)/sizeof(int) >= 3) { // 캐릭터 텍스트파일에 아이템이 있는 경우 체크
        for (int i = 2; i < sizeof(check_value_2)/sizeof(int); i++) {
            if (check_value_2[i] > ITEM_NUM) { // 캐릭터 파일중 최대 아이템 번호(4)를 넘어간다면 오류
                return false;
            }
        }
    }


    for (int i = 0; i < sizeof(check_value_1)/sizeof(int); i++) {
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

	for (int i = (list_size-7); i < sizeof(check_value_2)/sizeof(int); i++)
		check_value_2[i] = 0;

	ofstream sfile(s);

	if (sfile.is_open()) {
		for (int i = 0; i < sizeof(check_value_1)/sizeof(int); i++) {
			sfile << check_value_1[i];
			sfile << "\t";
		}
		for (int i = 0; i < sizeof(check_value_2)/sizeof(int); i++) {
			sfile << check_value_2[i];
			sfile << "\t";
		}
		sfile.close();

	}
	return true;
}
