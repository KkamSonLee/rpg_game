
#include "Character.h"

Character::Character(const Status i_status)
{
    this->status = i_status;
    //this->status.set_money(�κ��丮.get.money())�� ���κ��� ���� �ٲپ� �����
}

Character::~Character()
{}

void Character::show_stat() {
    this->status.show();
}

void Character::attack(Monster& mon, const int& i_mp) {
    int use_mp = i_mp;
    if (this->get_nmp() < i_mp) {
        cout << "MP�� �����մϴ�."
    }
    int damage = mon.get_nhp() - (this->get_atk()); // ��������� ������ ������ ����hp - ���ݷ� �� �������� �� ������ ���� hp��� ���°��� �����մϴ�.
    mon.set_nhp(damage);
    this->set_nmp(this->get_nmp() - i_mp); //mp �Ҹ� 20
}

void Character::check_level() {
    while (100 < this->get_exp()) { // ������ �䱸 ����ġ 100���� ������ ������ ���� �ݺ�
        this->set_exp(this->get_exp() - 100);
        this->set_level(get_level() + 1);
    }
}

///get
Status Character::get_stat(){
    return this->status;
}
int Character::get_nhp() {
    return this->status.get_nhp();
}
int Character::get_nmp() {
    return this->status.get_nmp();
}
int Character::get_mhp() {
    return this->status.get_mhp();
}
int Character::get_mmp(){
    return this->status.get_mmp();
 }
int Character::get_atk() {
    return this->status.get_atk();
}
int Character::get_exp() {
    return this->status.get_exp();
}
int Character::get_level() {
    return this->status.get_level();
}
int Character::get_location() {
    return this->status.get_location();
}

int Character::get_money() {
    return this->status.get_money(); 
}


///set
void Character::set_stat(int& i_max_HP, int& i_max_MP, int& i_now_HP, int& i_now_MP, int& i_atk, int& i_exp, int& i_level, int& i_location, int& i_money) {
    this->status.set_status(i_max_HP, i_max_MP, i_now_HP, i_now_MP, i_atk, i_exp, i_level, i_location, i_money);
}
void Character::set_nhp(int i_hp){
    this->status.set_nhp(i_hp);
}
void Character::set_nmp(int i_mp) {
    this->status.set_nmp(i_mp);
}
void Character::set_mhp(int i_hp) {
    this->status.set_mhp(i_hp);
}
void Character::set_mmp(int i_mp) {
    this->status.set_mmp(i_mp);
}
void Character::set_atk(int i_atk) {
    this->status.set_atk(i_atk);
}

void Character::set_exp(int i_exp) {
    this->status.set_exp(i_exp);
}
void Character::set_level(int i_level) {
    this->status.set_level(i_level);
}
void Character::set_location(int i_location) {
    this->status.set_location(i_location);
}
void Character::set_money(int i_money) {
    this->status.set_money(i_money);
}





//Inventory open