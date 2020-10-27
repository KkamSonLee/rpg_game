#include "Town.h"
#include "Character.h"
#include "Inventory.h"
#include "Item.h"
#include "Shop.h"
#include "Status.h"
#include "battle.h"
#include "Monster.h"
#include "character_Integrity_Check.h"
#include "warningMessage.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "windows.h"
using namespace std;

int max_slot = 10;//캐릭터 파일 최대 슬롯 10으로 설정

Town::Town() {}
Town::~Town() {}

void Town::choice() {
	Character* character;
	Status* charstat;
	Inventory* myinventory;
	Item* charitem = new Item();
	battle* charbattle = new battle();
	Shop* myshop;
	character_Integrity_Check* charcheck = new character_Integrity_Check();
	warningMessage* warning = new warningMessage();

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
			warning.printWarning(6);
			endl;
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
			warning.printWarning(6);//캐릭터 파일 최대 슬롯 초과 오류 메세지
			endl;
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
		warning.printWarning(0);//문법에 맞지 않는 오류메세지
		endl;
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

void Town::save(int snum) {//캐릭터 파일의 숫자 인자로 받아서 캐릭터 정보를 파일에 입력하고 save
	string snumstr = to_string(snum);
	string sstr = "character" + snumstr;
	stringstream sss;
	sss << sstr << ".txt";
	string sfilename = sss.str();
	char savefilename[20];
	strcpy(savefilename, sfilename.c_str());

	vector<int> sitem;
	sitem = myinventory.getSlot();
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
		sfile << "/";
		for (vector<int>::iterator iter = sitem.begin;iter != sitem.end();++iter) {
			if (sitem.end() == ++iter) {
				sfile << *iter;
				sfile << "/";
				break;
			}
			else {
				sfile << *iter << "\t";
			}
		}
		sfile.close();
	}
	
	charcheck.check(sfilename);
	if (true) {
		cout << "현재 데이터를 세이브합니다." << endl;
		choice();
	}
	else {
		warning.printWarning(4);//파일 저장 실패 오류 메세지
		endl;
		choice();
	}
}

void Town::quit() {
	delete(charstat);
	delete(character);
	delete(myinventory);
	delete(myshop);
	delete(charitem);
	delete(charbattle);
	delete(charcheck);
	delete(warning);
	cout << "게임을 종료합니다." << endl;
	exit(0);
}

void Town::load(int lnum) {//캐릭터 파일의 숫자를 인자로 받아 파일 읽어서 캐릭터 정보에 load
	
	string numstr = to_string(lnum);
	string str = "character" + numstr;
	stringstream ss;
	ss << str << ".txt";
	string filename = ss.str();
	char charfilename[20];
	strcpy(charfilename, filename.c_str());
	
	int level;
	int exp;
	int mhp;
	int mmp;
	int nhp;
	int nmp;
	int atk;
	int location;
	int money;

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
				level = atoi(ptr);
				ptr = strtok(NULL, "\t");
				exp = atoi(ptr);
				ptr = strtok(NULL, "\t");
				mhp = atoi(ptr);
				ptr = strtok(NULL, "\t");
				mmp = atoi(ptr);
				ptr = strtok(NULL, "\t");
				nhp = atoi(ptr);
				ptr = strtok(NULL, "\t");
				nmp = atoi(ptr);
				ptr = strtok(NULL, "\t");
				atk = atoi(ptr);
				ptr = strtok(NULL, "\t");
				location = atoi(ptr);
				ptr = strtok(NULL, "\t");
				money = atoi(ptr);
				ptr = strtok(NULL, "/");
				while (ptr != "/") {
					myinventory.addSlot(ptr);
					ptr = strtok(NULL, "\t");
				}

				charstat = new Status(mhp, mmp, nhp, nmp, atk, exp, level, location, money);
				character = new Character(charstat);
			}
		}
		file.close();
		cout << "Load가 완료되었습니다." << endl;
		choice();
	}
	else {
		warning.printWarning(3);//불러오려는 파일 문법 오류 메세지
		endl;
		choice();
	}
}

void Town::inventory() {
	myinventory = new Inventory(character);
	choice();
}

void Town::move(string place) {//monster를 어떻게 해야할지 몰라 일단 주석처리하였습니다
	if (place == "dungeon") {
		character.set_location(2);
		charbattle.Battle(character, inventory, /*monster*/, 2);
		if (1) {
			choice();
		}
	}
	else if (place == "boss") {
		character.set_location(3);
		charbattle.Battle(character, inventory, /*monster*/, 3);
		if (1) {
			choice();
		}
	}
	else {//move town
		character.set_location(1);
		choice();
	}
}

void Town::shop() {
	myshop = new Shop(character, inventory);
	choice();
}

void Town::stat() {
	cout << "level : " << charstat.get_level() << endl;
	cout << "HP : " << charstat.get_nhp() << "/" << charstat.get_mhp() << endl;
	cout << "MP : " << charstat.get_nmp() << "/" << charastat.get_mmp() << endl;
	cout << "exp : " << charstat.get_exp() << endl;
	cout << "Atk : " << charstat.get_atk() << endl;
	cout << "money : " << charstat.get_money() << "메소" << endl;
	if (!myinventory.getSlot().empty()) {
		cout << "item : ";
		for (vector<int>::iterator iter = mtinventory.getSlot().begin();iter != myinventory.getSlot().end();iter++) {
			cout << charitem().get_itemName(*(iter));
		}
		endl;
		choice();
	}
	else {
		choice();
	}
}

bool is_digit(string str) {
	return atoi(str.c_str()) != 0 || str.compare("0") == 0;
}
