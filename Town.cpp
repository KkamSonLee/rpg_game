#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Town.h"
#include "windows.h"

using namespace std;

character_integrity_check *charcheck = new character_integrity_check();
//map_integrity_check *mapcheck = new map_integrity_check();
warningMessage *warning = new warningMessage();

Town::Town(Character &myCharacter, Inventory &myInventory) : myCharacter(myCharacter), myInventory(myInventory) {
    int max_slot = 10;//캐릭터 파일 최대 슬롯 10으로 설정

    choice();
}

Town::~Town() {}

void Town::choice() {
    bool loop = true;

    while (loop) {
        string select;
        string mselect;
        string nselect;
        cout << "Mainp>\n";
        getline(cin, select);
        istringstream ss(select);
        ss >> mselect >> nselect;
        if (mselect == "help" && is_digit(nselect) == 0) {
            help();
        } else if (mselect == "save" && is_digit(nselect) == 1) {
            int i = std::stoi(nselect);
            if (i <= max_slot) {
                save(i);
            } else {
                warning->printWarning(0, 6);
                cout << endl;

            }
        } else if (mselect == "quit" && is_digit(nselect) == 0) {
            quit();
        } else if (select == "inventory" && is_digit(nselect) == 0) {
            inventory();
        } else if (select == "move" && (nselect == "dungeon" || nselect == "boss" || nselect == "town")) {
            move(nselect);
        } else if (select == "shop" && is_digit(nselect) == 0) {
            shop();
        } else if (select == "stat" && is_digit(nselect) == 0) {
            stat();
        } else {
            warning->printWarning(0, 0);//문법에 맞지 않는 오류메세지
            cout << endl;
        }
        ss.clear();
        ss.str("");
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
    vector<int> sstat;
    sitem = myInventory.getSlot();
    sstat = myCharacter.get_stat().getstatus();
    ofstream sfile(savefilename);

    if (sfile.is_open()) {
        for (vector<int>::iterator iter = sstat.begin(); iter != sstat.end(); ++iter) {
            if (sstat.end() == ++iter) {
                sfile << *iter;
                sfile << "\t";
                sfile << "/";
                break;
            } else {
                sfile << *iter << "\t";
            }
        }

        for (vector<int>::iterator iter = sitem.begin(); iter != sitem.end(); ++iter) {
            if (sitem.end() == ++iter) {
                sfile << *iter;
                sfile << "/";
                break;
            } else {
                sfile << *iter << "\t";
            }
        }
        sfile.close();
    }

    charcheck->load_set(sfilename);
    if (true) {
        cout << "현재 데이터를 세이브합니다." << endl;
    } else {
        warning->printWarning(0, 4);//파일 저장 실패 오류 메세지
        cout << endl;
    }
}

void Town::quit() {
    /*delete (charstat);
    delete (character);
    delete (myinventory);
    delete (myshop);
    delete (charitem);
    delete (charbattle);
    delete (dungeonmonster);
    delete (bossmonster);
    delete (charcheck);
    delete (mapcheck);
    delete (warning);
    cout << "게임을 종료합니다." << endl;*/
    exit(0);
}

void Town::inventory() {
    myInventory.openInv();
}

void Town::move(string place) {/*
    if (place == "dungeon") {
        string map2 = "map2";
        mapcheck->load_set(map2);
        if (1 || 3) {
            char mapinfo[100];
            char mapinfo2[100];
            int dmonNum;
            ifstream mf;
            mf.open(map2);
            mf.getline(mapinfo, 100);
            mf.getline(mapinfo2, 100);
            char *mptr = strtok(mapinfo2, "\t");
            mptr = strtok(NULL, "\t");
            mptr = strtok(NULL, "\t");
            dmonNum = atoi(mptr);
            Monster dm;
            dungeonmonster = new Monster(dm.get_MonsterInfo(dmonNum), dmonNum);
            character->set_location(2);
            charbattle.Battle(character, myinventory, dungeonmonster, 2);
        }
    } else if (place == "boss") {
        string map3 = "map3";
        mapcheck->load_set(map3);
        if (1 || 3) {
            char bmapinfo[100];
            char bmapinfo2[100];
            int bmonNum;
            ifstream bmf;
            bmf.open(map3);
            bmf.getline(bmapinfo, 100);
            bmf.getline(bmapinfo2, 100);
            char *bmptr = strtok(bmapinfo2, "\t");
            bmptr = strtok(NULL, "\t");
            bmptr = strtok(NULL, "\t");
            bmonNum = atoi(bmptr);
            Monster bm;
            bossmonster = new Monster(bm.get_MonsterInfo(bmonNum), bmonNum);
            character->set_location(3);
            charbattle->Battle(character, myinventory, bossmonster, 3);

        }
    } else {
        myCharacter.set_location(1);
    }
*/
}

void Town::shop() {
    Shop shop(myCharacter, myInventory);
}

void Town::stat() {
    cout << "level : " << myCharacter.get_level() << endl;
    cout << "HP : " << myCharacter.get_nhp() << "/" << myCharacter.get_mhp() << endl;
    cout << "MP : " << myCharacter.get_nmp() << "/" << myCharacter.get_mmp() << endl;
    cout << "exp : " << myCharacter.get_exp() << endl;
    cout << "Atk : " << myCharacter.get_atk() << endl;
    cout << "money : " << myCharacter.get_money() << "메소" << endl;
    myInventory.printInvList();
}

bool Town::is_digit(string str) {
    return (atoi(str.c_str()) != 0) || (str.compare("0") == 0);
}
