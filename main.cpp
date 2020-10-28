#include "Status.h"
#include "Character.h"
#include "Inventory.h"
#include "Shop.h"
#include <conio.h>
#include <sstream>


Character load(int inum);
Inventory* myInventory;
//battle.cpp battle.h warningMessage.cpp warningMessage.h Town.cpp Town.h character_integrity_check.cpp character_integrity_check.h map_integrity_check.cpp map_integrity_check.h
character_integrity_check charcheck;
int main() {
    int select = 1;
    Character ch(load(select));
    Town mytown(ch);
    int use_mp = 20;
    int num = 1;
    int hp = 3;
    int mp = 100;
    int money = 4000;
    vector<int> invList;
    invList.push_back(1);
    invList.push_back(2);
    invList.push_back(3);
    invList.push_back(4);
    Status st(hp, mp, hp, mp, num, num, num, num, money); //money ����
    Monster mon(st, 1);
    ch.show_stat();// ���� ���� ���

    ch.attack(mon, mp);
    cout << mon.get_nhp() << endl; //// hp = 3 , atk = 1 �̱⶧���� ������ �ѹ� �Ѵٸ� hp 2�� �Ǿ�� �� �� �Դϴ�.

    ch.attack(mon, mp);
    mon.attack(ch, mp);
    mon.attack(ch, mp);
    // ĳ���Ϳ� ������ status�� �Ȱ��� mp �Ҹ𷮵� 20�̱� ������ 
    //ĳ���Ϳ� ������ hp mp�� �ι� �������� �� 1 -37�� ���;� �մϴ�. 
    cout << mon.get_nhp() << "," << mon.get_nmp() << endl;
    cout << ch.get_nhp() << "," <<ch.get_nmp()<<endl;

    cout << mon.get_name(3) << endl; // �̸� ������ status�� ���� ������ Ŭ�������ο��� ���ϴ� ������� �������־����ϴ�.
    cout << mon.get_money() << endl;
    mon.set_money(2000);
    cout << mon.get_money() << endl;

    //Shop shop(ch, inv);
    return 0;

}

Character load(int inum){
    string numstr = to_string(inum);
    string str = "character" + numstr;
    stringstream ss;
    ss << str << ".txt";
    Status stat;
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
    charcheck.load_set(filename);
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

            stat.set_status(mhp, mmp, nhp, nmp, atk, exp, level, location, money);
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
                    myInventory->addSlot(atoi(ptr));
                    ptr = strtok(NULL, "\t");
                }

                stat.set_status(mhp, mmp, nhp, nmp, atk, exp, level, location, money);
            }
        }
        file.close();
        cout << "Load�� �Ϸ�Ǿ����ϴ�." << endl;
        Character ch(stat);
        return ch;
    } else {
        //warning->printWarning(0, 3);//�ҷ������� ���� ���� ���� �޼���
        cout << endl;
        //return Character(Status());
    }
}