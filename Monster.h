#pragma once
#include<iostream>
#include <vector>

#include "Status.h"


class Monster{
    private:
        Status monsetrStatus();
        int MonsterNum;
        vector<int> MonsterAttribute;
    public:
        Monster(const Status status, const int& MonsterNum);
        ~Monster();
        void attack();
};