#pragma once
#include<iostream>
#include <vector>
#include "Character.h"
#include "Status.h"

class Character; //식별자 오류 방지

class Monster {
private:
    static Status Monsterlist[99];
    Status monsetrStatus;
    int MonsterNum;
    //vector<Status> Monsterattribute; 

public:

    Monster();
    Monster(const Status i_status, const int& MonsterNum);
    ~Monster();
    int getMonsterNum();
    void setMonsterNum(int num);
    void set_Nowhp(int n_hp);
    Status get_Monsterstat(const int& num);
    Status get_Monsterstat();
    void attack(Character ch);

};