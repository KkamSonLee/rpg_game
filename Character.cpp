
#include "Character.h"

Character::Character(const Status i_status)
{
    this->status = i_status;
}

Character::~Character()
{

}

void Character::show_stat()
{
    this->status.show();
}

Status Character::get_stat()
{
    return this->status;
}

void Character::set_stat(int& i_max_HP, int& i_max_MP, int& i_now_HP, int& i_now_MP, int& i_atk, int& i_exp, int& i_level, int& i_location)
{
    this->status.setstatus(i_max_HP, i_max_MP, i_now_HP, i_now_MP, i_atk, i_exp, i_level, i_location);
}


void Character::set_atk(int i_atk)
{
    this->status.set_atk(i_atk);
}

int Character::getn_hp()
{
    return this->status.getn_hp();
}
void Character::setn_hp(int i_hp)
{
    this->status.setn_hp(i_hp);
}


int Character::get_atk()
{
    return this->status.get_atk();
}



void Character::attack(const int& i_monnum)
{
    Status Mon = Monster().get_Monsterstat(i_monnum);
    this->status.setn_mp(this->status.getn_mp() - 20); // mp 20 소모
    Mon.setn_hp(Mon.getn_hp() - this->get_atk());

    //이후 배틀에서 전투 끝날때 해당 몬스터의 mp hp 재설정을 해주어야함
}


//Inventory open