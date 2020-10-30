
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Town.h"
#include "windows.h"

using namespace std;


character_integrity_check *charcheck = new character_integrity_check();
map_integrity_check *mapcheck = new map_integrity_check();
warningMessage *warning = new warningMessage();

int max_slot = 10;//캐릭터 파일 최대 슬롯 10으로 설정

Town::Town(Character& myCharacter):myCharacter(myCharacter){
    choice();
}
Town::~Town() {}

void Town::choice() {
    string select;
    string mselect;
    string nselect;
    cout << "Mainp>";
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
            choice();
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
        choice();
    }
}

void Town::help() {
    cout << "명령어 도움말\n";
    cout << "help : 도움말\n";
    cout << "save : 저장\n";
    cout << "quit : 종료\n";
    cout << "load : 불러오기\n";
    cout << "inventory : Inventory\n";
    cout << "move : 맵 이동\n";
    cout << "shop : 상점\n";
    cout << "stat : 상태창\n";

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
        choice();
    } else {
        warning->printWarning(0, 4);//파일 저장 실패 오류 메세지
        cout << endl;
        choice();
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
/*
void Town::load(Character &character, Status &charstat, Inventory &myInventory,
                int inum) {//캐릭터 파일의 숫자를 인자로 받아 파일 읽어서 캐릭터 정보에 load

    string numstr = to_string(inum);
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

    charcheck->load_set(filename);
    if (true) {
        ifstream file(charfilename);
        if (!file.is_open()) {
            string basicstat = "1\t0\t100\t50\t100\t50\t10\t0\t0";
            ofstream newfile(charfilename);
            if (newfile.is_open()) {
                newfile << basicstat;
                newfile.close();
            }
            level = 1;
            exp = 0;
            mhp = 100;
            mmp = 50;
            nhp = 100;
            nmp = 50;
            atk = 10;
            location = 0;
            money = 0;

            charstat.set_status(mhp, mmp, nhp, nmp, atk, exp, level, location, money);
            character.set_stat(mhp, mmp, nhp, nmp, atk, exp, level, location, money);
        } else {
            char buffer[100];
            while (!file.eof()) {
                file.getline(buffer, 100);

                char *ptr = strtok(buffer, "\t");
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
                    myinventory.addSlot(atoi(ptr));
                    ptr = strtok(NULL, "\t");
                }

                charstat.set_status(mhp, mmp, nhp, nmp, atk, exp, level, location, money);
                character.set_stat(mhp, mmp, nhp, nmp, atk, exp, level, location, money);
            }
        }
        file.close();
        cout << "Load가 완료되었습니다." << endl;
        choice();
    } else {
        warning->printWarning(0, 3);//불러오려는 파일 문법 오류 메세지
        cout << endl;
        choice();
    }
}*/

void Town::inventory() {
    myInventory.openInv();
    choice();
}

void Town::move(string place) {
    /*if (place == "dungeon") {
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
            if (1) {
                choice();
            }
        } else {
            choice();
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
            if (1) {
                choice();
            }
        } else {
            choice();
        }
    } else {
        myCharacter.set_location(1);
        choice();
    }
*/
}

void Town::shop() {
    Shop shop(myCharacter, myInventory);
    choice();
}

void Town::stat() {
    cout << "level : " << myCharacter.get_level() << endl;
    cout << "HP : " << myCharacter.get_nhp() << "/" << myCharacter.get_mhp() << endl;
    cout << "MP : " << myCharacter.get_nmp() << "/" << myCharacter.get_mmp() << endl;
    cout << "exp : " << myCharacter.get_exp() << endl;
    cout << "Atk : " << myCharacter.get_atk() << endl;
    cout << "money : " << myCharacter.get_money() << "메소" << endl;
    myInventory.printInvList();
    choice();
}

bool is_digit(string str) {
    return atoi(str.c_str()) != 0 || str.compare("0") == 0;
}
