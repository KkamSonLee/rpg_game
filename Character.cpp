
#include "Character.h"

Character::Character(const Status i_status)
{
    this->status = i_status;
    //this->status.set_money(인벤토리.get.money())로 돈부분은 따로 바꾸어 줘야함
}

Character::~Character()
{}

void Character::show_stat() {
    this->status.show();
}


Status Character::get_stat(){
    return this->status;
}

void Character::set_stat(int& i_max_HP, int& i_max_MP, int& i_now_HP, int& i_now_MP, int& i_atk, int& i_exp, int& i_level, int& i_location, int& i_money){
    this->status.set_status(i_max_HP, i_max_MP, i_now_HP, i_now_MP, i_atk, i_exp, i_level, i_location, i_money);
}


void Character::set_atk(int i_atk){
    this->status.set_atk(i_atk);
}

int Character::get_nhp(){
    return this->status.get_nhp();
}

int Character::get_money() {

    return this->status.get_money(); 
    //현재만 객체에서 받아오고 이후에는 인벤토리.getmoney로 해주어야 한다. 
}

void Character::set_nhp(int i_hp){
    this->status.set_nhp(i_hp);
}



void Character::set_money(int i_money) {
    this->status.set_money(i_money);
    //이후에 인벤토리랑 연관 시켜줘야 한다. 
}

int Character::get_atk(){
    return this->status.get_atk();
}

void Character::attack(Monster& mon){   
    int use_mp = 20; 
    int damage = mon.get_nhp() - (this->status.get_atk()); // 데미지라고 하지만 몬스터의 현재hp - 공격력 즉 데미지가 들어간 이후의 몬스터 hp라고 보는것이 적절합니다.
    mon.set_nhp(damage);
    this->status.set_nmp(this->status.get_nmp() - use_mp); //mp 소모량 20
}

void Character::check_level(){       
    while(this->status.get_level()*100 < this->status.get_exp()){ // 레벨당 요구 경험치 100설정 레벌업 끝날때 까지 반복
        this->status.set_exp(this->status.get_exp() - 100);
        this->status.set_level(status.get_level() + 1);
    }
}

//Inventory open