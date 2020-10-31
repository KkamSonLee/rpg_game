#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Town.h"
#include "windows.h"

using namespace std;

character_integrity_check *charcheck;
//map_integrity_check *mapcheck = new map_integrity_check();
warningMessage *warning;

Town::Town(Character &myCharacter, Inventory &myInventory) : myCharacter(myCharacter), myInventory(myInventory) {
//battle *charbattle=new battle();
    int max_slot = 10;//캐릭터 파일 최대 슬롯 10으로 설정

}

Town::~Town() {}

void Town::choice() {
    bool loop = true;

    while (loop) {
        string select;
        string mselect;
        string nselect;
        cout << "Mainp>\n";
        cin.clear();
        getline(cin, select);
        istringstream ss(select);
        ss >> mselect >> nselect;
        if (mselect == "help" && is_digit(nselect) == 0 && nselect.empty() == true) {
            help();
        } else if (mselect == "save" && is_digit(nselect) == 1) {
            int i = std::stoi(nselect);
            if (i <= max_slot) {
                save(i);
            } else {
//                warning->printWarning(0, 6);
                cout << endl;

            }
        } else if (mselect == "quit" && is_digit(nselect) == 0 && nselect.empty() == true) {
            quit();
            loop = false;
        } else if (mselect == "inventory" && is_digit(nselect) == 0 && nselect.empty() == true) {
            inventory();
        } else if (mselect == "move" && is_digit(nselect) == 0 && nselect.empty() == true) {
            loop = move();
        } else if (mselect == "shop" && is_digit(nselect) == 0 && nselect.empty() == true) {
            shop();
        } else if (mselect == "stat" && is_digit(nselect) == 0 && nselect.empty() == true) {
            stat();
        } else {
            //warning.printWarning(0, 0);//문법에 맞지 않는 오류메세지
        }
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

}

void Town::save(int snum) {//캐릭터 파일의 숫자 인자로 받아서 캐릭터 정보를 파일에 입력하고 save
    string snumstr = to_string(snum);
    string sstr = "character" + snumstr;
    stringstream sss;
    Item item;
    sss << sstr << ".txt";
    string sfilename = sss.str();
    char savefilename[20];
    strcpy(savefilename, sfilename.c_str());

    vector<int> sitem;

    sitem = myInventory.getSlot();

    ofstream sfile(savefilename);

    if (sfile.is_open()) {
        sfile << myCharacter.get_level();
        sfile << "\t";
        sfile << myCharacter.get_exp();
        sfile << "\t";
        sfile << myCharacter.get_mhp();
        sfile << "\t";
        sfile << myCharacter.get_mmp();
        sfile << "\t";
        sfile << myCharacter.get_nhp();
        sfile << "\t";
        sfile << myCharacter.get_nmp();
        sfile << "\t";
        if (myInventory.getSlot().empty()) {
            sfile << myCharacter.get_atk();
        } else {
            if (item.get_item(myInventory.getSlot()[0])[0] == 0) {
                sfile << myCharacter.get_atk();
            } else if (item.get_item(myInventory.getSlot()[0])[0] == 1) {
                sfile << (myCharacter.get_atk() - item.get_item(myInventory.getSlot()[0])[1]);
            }
        }
        sfile << "\t";
        sfile << myCharacter.get_location();
        sfile << "\t";
        sfile << myCharacter.get_money();
        sfile << "\t";
        if (!sitem.empty()) {
            for (vector<int>::iterator iter = sitem.begin(); iter != sitem.end(); iter++) {
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
//        warning->printWarning(0, 4);//파일 저장 실패 오류 메세지
        cout << endl;
        choice();
    }
}

void Town::quit() {
    /*
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

bool Town::move() {
    Map admin[4];
    string mapName[4] = {"town", "dungeon", "boss", "myhouse"};
    admin[0].load_map("map1.txt");
    admin[1].load_map("map2.txt");
    admin[2].load_map("map3.txt");
    admin[3].load_map("map4.txt");

    vector<int> linked_mapList = admin[myCharacter.get_location()].get_linked_map();

    int type[4];
    type[0] = admin[0].get_map_type();
    type[1] = admin[1].get_map_type();
    type[2] = admin[2].get_map_type();
    type[3] = admin[3].get_map_type();
    bool is = false;
    int moveto;

    for (vector<int>::iterator iter = linked_mapList.begin(); iter != linked_mapList.end(); iter++) {
        //if(moveto == mapName[type[(*iter) - 1] - 1]){
        // is = true;
        // }
        cout << admin[(*iter) - 1].get_map_num() << "." << mapName[type[(*iter) - 1] - 1] << " ";
    }

    cout << "insert : ";
    cin >> moveto;
    myCharacter.set_location(moveto);
    cout << myCharacter.get_location();
    return false;
    if (is) {
    }
    /*string map2 = "map2";
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
        warningMessage dunwarn;
        *warning = dunwarn;
        myCharacter.set_location(2);
        charbattle->Battle(character, myinventory, dungeonmonster, 2, dunwarn);
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
        warningMessage bosswarn;
        *warning = bosswarn;
        myCharacter.set_location(3);
        charbattle->Battle(character, myinventory, bossmonster, 3, bosswarn);
        if (1) {
            choice();
        }
    } else {
        choice();
    }
} else {
    myCharacter.set_location(1);
}*/
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
