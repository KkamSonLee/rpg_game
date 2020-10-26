#include "Town.h"
#include "Character.h"
#include "Inventory.h"
#include "Shop.h"
#include "Status.h"
#include "character_Integrity_Check.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "windows.h"
using namespace std;

int max_slot = 10;//캐릭터 파일 최대 슬롯 10으로 설정

Character* character;
Status* charstat;
Inventory inventory;
Battle charbattle;
Shop shop;
character_Integrity_Check charcheck;

Town::Town() {}
Town::~Town() {}

void Town::choice() {
	string select;
	string mselect;
	string nselect;
	cout << "Mainp>";
	getline(cin, select);
	istringstream ss(select);
	ss >> mselect >> nselect;
	if (mselect == "help"&&is_digit(nselect)==0) {
		help();
	}
	else if (mselect=="save"&&is_digit(nselect)==1) {
		int i = std::stoi(nselect);
		if (i <= max_slot) {
			save(i);
		}
		else {
			cout << "캐릭터 파일의 최대 슬롯을 초과하였습니다." << endl;
			choice();
		}
	}
	else if (mselect == "quit"&& is_digit(nselect) == 0) {
		quit();
	}
	else if (mselect == "load"&& is_digit(nselect) == 1) {
		int j = std::stoi(nselect);
		if (j <= max_slot) {
			load(j);
		}
		else {
			cout << "캐릭터 파일의 최대 슬롯을 초과하였습니다." << endl;
			choice();
		}
	}
	else if (select == "inventory"&& is_digit(nselect) == 0) {
		inventory();
	}
	else if (select == "move"&&(nselect=="dungeon"||nselect=="boss"||nselect=="town")) {
		move(nselect);
	}
	else if (select == "shop"&& is_digit(nselect) == 0) {
		shop();
	}
	else if (select == "stat"&& is_digit(nselect) == 0) {
		stat();
	}
	else {
		cout << "문법에 맞지 않습니다." << endl;
		choice();
	}
}

void Town::help() {
	cout << "명령어 도움말" << endl;
	cout << "help : 도움말" << endl;
	cout << "save : 저장" << endl;
	cout << "quit : 종료" << endl;
	cout << "load : 불러오기" << endl;
	cout << "inventory : Inventory" << endl;
	cout << "move : 맵 이동" << endl;
	cout << "shop : 상점" << endl;
	cout << "stat : 상태창" << endl;

	choice();
}

void Town::save(int snum) {
	string snumstr = to_string(snum);
	string sstr = "character" + snumstr;
	stringstream sss;
	sss << sstr << ".txt";
	string sfilename = sss.str();
	char savefilename[20];
	strcpy(savefilename, sfilename.c_str());

	ofstream sfile(savefilename);

	if (sfile.is_open()) {
		sfile << character.get_level();
		sfile << "\t";
		sfile << character.get_exp();
		sfile << "\t";
		sfile << character.get_mhp();
		sfile << "\t";
		sfile << character.get_mmp();
		sfile << "\t";
		sfile << character.get_nhp();
		sfile << "\t";
		sfile << character.get_nmp();
		sfile << "\t";
		sfile << character.get_atk();
		sfile << "\t";
		sfile << character.get_location();
		sfile << "\t";
		sfile << character.get_money();
		sfile << "\t";

		//sfile<<character.get_slot().. item 부분 추가예정

		sfile.close();
	}
	
	charcheck.check(sfilename);
	if (true) {
		cout << "현재 데이터를 세이브합니다." << endl;
		choice();
	}
	else {
		//오류메세지 or 경고메세지 출력
		choice();
	}
	
}

void Town::quit() {
	delete(charstat);
	delete(character);

	cout << "게임을 종료합니다." << endl;
	exit(0);
}

void Town::load(int lnum) {
	
	string numstr = to_string(lnum);
	string str = "character" + numstr;
	stringstream ss;
	ss << str << ".txt";
	string filename = ss.str();
	char charfilename[20];
	strcpy(charfilename, filename.c_str());
	
	int islot[10];

	charcheck.check(filename);
	if (true) {
		ifstream file(charfilename);
		if (!file.is_open()) {
			string basicstat = "1\t0\t100\t50\t100\t50\t10\t0\t0";
			ofstream newfile(charfilename);
			if (newfile.is_open()) {
				newfile << basicstat;
				newfile.close();
			}
			charstat = new Status(100, 50, 100, 50, 10, 0, 1, 0, 0);
			character = new Character(charstat);
		}
		else {
			char buffer[100];
			while (!file.eof()) {
				file.getline(buffer, 100);

				char* ptr = strtok(buffer, "\t");
				int level = atoi(ptr);
				ptr = strtok(NULL, "\t");
				int exp = atoi(ptr);
				ptr = strtok(NULL, "\t");
				int mhp = atoi(ptr);
				ptr = strtok(NULL, "\t");
				int mmp = atoi(ptr);
				ptr = strtok(NULL, "\t");
				int nhp = atoi(ptr);
				ptr = strtok(NULL, "\t");
				int nmp = atoi(ptr);
				ptr = strtok(NULL, "\t");
				int atk = atoi(ptr);
				ptr = strtok(NULL, "\t");
				int location = atoi(ptr);
				ptr = strtok(NULL, "\t");
				int money = atoi(ptr);

				/*
				for (int i = 0;i < 10;i++) {
					ptr = strtok(NULL, "\t");
					if (ptr != NULL) {
						islot[i] = atoi(ptr);
					}
					else
						break;
				}
				*/

				charstat = new Status(mhp, mmp, nhp, nmp, atk, exp, level, location, money);
				character = new Character(charstat);
				//character.setSlot(islot);

				//item 부분 수정예정

			}
		}
		
		file.close();
		cout << "Load가 완료되었습니다." << endl;
		choice();
	}
	else {
		
		cout << "파일이 문법에 맞지 않습니다." << endl;
		choice();
	}
}

void Town::inventory() {
	
	inventory.openInv();
}

void Town::move(string place) {
	if (place == "dungeon") {
		character.set_location(2);
		charbattle.battle();
	}
	else if (place == "boss") {
		character.set_location(3);
		charbattle.battle();
	}
	else {//move town
		character.set_location(1);
		choice();
	}
}

void Town::shop() {
	
	Shop shop = Shop(
	        .showShop();
}

void Town::stat() {
	cout << "level : " << charstat.get_level() << endl;
	cout << "HP : " << charstat.get_nhp() << "/" << charstat.get_mhp() << endl;
	cout << "MP : " << charstat.get_nmp() << "/" << charastat.get_mmp() << endl;
	cout << "exp : " << charstat.get_exp() << endl;
	cout << "Atk : " << charstat.get_atk() << endl;
	cout << "money : " << charstat.get_money() << "메소" << endl;
	//cout << "item : ";
	//item 부분 추가예정
	
	choice();
}

bool is_digit(string str) {
	return atoi(str.c_str()) != 0 || str.compare("0") == 0;
}