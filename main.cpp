#include "Status.h"
#include "Character.h"
#include "Inventory.h"
#include "Monster.h"
#include "Town.h"
//#include "character_integrity_check.h"
#include "Shop.h"
#include "Map.h"
#include <sstream>
#include <string>
#include <cstring>


Status stat;
vector<int> invList;
vector<Map> mapAdmin;
void load(int inum);


int main() {
    Monster mon(1);
    load(1);
    Character ch(stat);
    Inventory inventory(ch);
    inventory.addSlotArr(invList);
    Town myTown(ch, inventory);
    mapAdmin.push_back(Map().load_map("map1.txt"));
    mapAdmin.push_back(Map().load_map("map2.txt"));
    mapAdmin.push_back(Map().load_map("map3.txt"));

    return 0;
}

void load(int inum) {
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
    //charcheck.load_set(filename);
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

        stat.set_status(mhp, mmp, nhp, nmp, atk, exp, level, location, money);
    } else {
        char buffer[100];
        char *value;
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
            ptr = strtok(NULL, "\t");
            while (ptr != NULL) {
                if(!atoi(ptr)==0){
                    invList.push_back(atoi(ptr));
                }
                ptr = strtok(NULL, "\t");
            }
            stat.set_status(mhp, mmp, nhp, nmp, atk, exp, level, location, money);
            file.close();
        }
    }
    stat.show();
    cout << "Load complete" << endl;
    //warning->printWarning(0, 3);//불러오려는 파일 문법 오류 메세지
    //return Character(Status());
}