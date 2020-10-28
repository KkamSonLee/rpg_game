#include "map_integrity_check.h"

using namespace std;
#define MAP_NUM 10


enum {
	SUCCESS,
	ERROR,
	WARNING
};
map_integrity_check::map_integrity_check(){

}
map_integrity_check::~map_integrity_check()
{
}

int map_integrity_check::load_set(string s)
{
	int check_value_1[10] = { -1, };
	int check_value_2[9] = { -1, };
	char datas_1[100];
	char datas_2[100];
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

	//���� ���� �����ϴ��� üũ
	for (int i = 0; i < list_size_1; i++) {
		try {
			if (i >= 1) {
				if (check_value_1[i - 1] == stoi(check_list_1[i])) {
					return ERROR;
				}
			}
			check_value_1[i] = stoi(check_list_1[i]);
		}
		catch (...) {
			return ERROR;
		}
	}
	//���� ���� �����ϴ��� üũ
	for (int i = 0; i < list_size_2; i++) {
		try {
			check_value_2[i] = stoi(check_list_2[i]);
		}
		catch (...) {
			return ERROR;
		}
	}
	//�ߺ� �� ����
	for (int i = 0; i < MAP_NUM; i++) {
		if (check_value_1[0] == map_list[i]) {
			return ERROR;
		}
	}
	//������ ���� �ȸ���
	if (check_value_2[3] != (list_size_2 - 4)) {
		return ERROR;
	}
	//�������� 1,2,3 ��� �ƴ� ���
	if ((check_value_2[1] != 1) && (check_value_2[1] != 1) && (check_value_2[1] != 1)) {
		return ERROR;
	}
	//�� ���� ����
	if (check_value_2[0] <= 0) {
		return ERROR;
	}
	//���� ���� ���
	if ((check_value_2[1] == 2) || (check_value_2[1] == 3) && (check_value_2[2] == 0)) {
		return ERROR;
	}
	//������ ���� ����
	if (check_value_2[1] == 1 && check_value_2[2] != 0) {
		return WARNING;
	}
	//������ ������ ����
	if ((check_value_2[1] == 2) || (check_value_2[1] == 3) && (check_value_2[3] != 0)) {
		return WARNING;
	}

	return SUCCESS;
}
