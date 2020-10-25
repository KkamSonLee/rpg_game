#pragma once
#include<iostream>
#include <vector>
#include "Status.h"


class Character
{ 
    private:
        Status status();
        int slot[10];
    
    public:
        Character(Status status);
        ~Character();
        void show_stat();
        void attack();

        Status get_stat();
        void set_stat();
        int get_slot();
        void set_slot(int num);
        void sort_slot();
        
        //Inventory.open();
        // get set ÇÔ¼öµé
        // 


};