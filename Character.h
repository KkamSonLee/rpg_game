#pragma once
#include<iostream>
#include <vector>
#include "Monster.h"
#include "Status.h"


class Character
{ 
    private:
        Status status;
    
    public:
        Character(Status status);
        ~Character();
        void show_stat();
        Status get_stat();
        void set_stat(int& i_max_HP, int& i_max_MP, int& i_now_HP,int& i_now_MP, int& i_atk, int& i_exp, int& i_level, int& i_location);
        void set_atk(int i_atk);
        int get_atk;
        void attack(Monster mon);
        
        //Inventory.open();


};