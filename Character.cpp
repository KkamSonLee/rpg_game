#include "Character.h"

Character::Character(Status i_status)
{   
    this ->status = i_status;
}

Character::~Character()
{ 

}

Status Character::get_stat()
{
    return this->status;
}

void Character::set_stat(int& i_max_HP, int& i_max_MP, int& i_now_HP,int& i_now_MP, int& i_atk, int& i_exp, int& i_level, int& i_location)
{
    this->status.setstatus(i_max_HP,i_max_MP, i_now_HP,i_now_MP,  i_atk, i_exp, i_level, i_location);
}


void Character::set_atk(int i_atk)
{
    this->status.set_atk(i_atk);
}


void Character:: show_stat()
{
    this->status.show();
}

        
        

void Character:: attack(Monster mon)
{
    
}


 //Inventory open