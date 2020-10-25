#pragma once
#include<iostream>
#include <vector>

using namespace std;

class Status{

    private:
        vector<int> status;
        int max_HP;
        int max_MP;
        int now_HP;
        int now_MP;
        int atk;
        int exp;
        int level;
        int location;
        int money;
        vector<int>stat_list;

    public:
        Status();
        Status(int& max_HP, int& max_MP, int& now_HP,int& now_MP, int& atk, int& exp, int& level, int& location, int& money);
        ~Status();
        void show();
        vector<int> getstatus();
};