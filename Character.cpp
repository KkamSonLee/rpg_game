
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

int Character::get_nhp()
{
    return this->status.get_nhp();
}
void Character::set_nhp(int i_hp)
{
    this->status.set_nhp(i_hp);
}


int Character::get_atk()
{
    return this->status.get_atk();
}



void Character::attack(Monster& mon)
{   
    int use_mp = 20; 
    int damage = mon.get_nhp() - (this->status.get_atk()); // 데미지라고 하지만 몬스터의 현재hp - 공격력 즉 데미지가 들어간 이후의 몬스터 hp라고 보는것이 적절합니다.
    mon.set_nhp(damage);
    this->status.set_nmp(this->status.get_nmp() - use_mp); //mp 소모량 20
}

void Character::check_level()
{       
    while(this->status.get_level()*100 < this->status.get_exp()){ // 레벨당 요구 경험치 100설정 레벌업 끝날때 까지 반복
        this->status.set_exp(this->status.get_exp() - 100);
        this->status.set_level(status.get_level() + 1);
    }
}

//Inventory open