#pragma once
#include<iostream>
#include <vector>
#include "Monster.h"
#include "Status.h"


class Character
{
private:
    Status status;
    //Inventory(money,slot);

public:
    Character(const Status i_status);
    ~Character();
    void show_stat();
    Status get_stat();
    int get_atk();
    int getn_hp();
    void setn_hp(int i_hp);
    void set_stat(int& i_max_HP, int& i_max_MP, int& i_now_HP, int& i_now_MP, int& i_atk, int& i_exp, int& i_level, int& i_location);
    void set_atk(int i_atk);
    void attack(const int& mon_num);

    //Inventory.open();


};
