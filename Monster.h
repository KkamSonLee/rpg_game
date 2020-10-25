#pragma once
#include<iostream>
#include <vector>
#include "Character.h"
#include "Status.h"


class Monster{
    private:
        Status monsetrStatus;
        int MonsterNum;
        vector<int> MonsterAttribute;
    
    public:
        Monster(const Status i_status, const int& MonsterNum);
        ~Monster();
        int getMonsterNum();
        void setMonsterNum(const int& num);
        void set_Nowhp(int n_hp);
        void attack(Character ch);
};