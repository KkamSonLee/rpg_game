
#include "Status.h"

Status::Status()
{
    this->max_HP = 0;
    this->max_HP = 0;
    this->max_MP = 0;
    this->now_HP = 0;
    this->now_MP = 0;
    this->atk = 0;
    this->exp = 0;
    this->level = 1;
    this->location = 0;
    this->money = 0;
    // 기획서상 level은 1이상의 숫자 나머지는 0이상의 숫자
}


Status::Status(int& i_max_HP, int& i_max_MP, int& i_now_HP, int& i_now_MP, int& i_atk, int& i_exp, int& i_level, int& i_location, int i_money) {
    this->max_HP = i_max_HP;
    this->max_MP = i_max_MP;
    this->now_HP = i_now_HP;
    this->now_MP = i_now_MP;
    this->atk = i_atk;
    this->exp = i_exp;
    this->level = i_level;
    this->location = i_location;
    this->money = i_money;

    stat_list.push_back(max_HP);
    stat_list.push_back(max_MP);
    stat_list.push_back(now_HP);
    stat_list.push_back(now_MP);
    stat_list.push_back(atk);
    stat_list.push_back(exp);
    stat_list.push_back(level);
    stat_list.push_back(location);
    stat_list.push_back(money);
}

Status::~Status()
{

}

void Status::show()
{
    cout << max_HP << "," << max_MP << "," << now_HP << "," << now_MP << "," << atk << "," << exp << "," << level << endl;
}

void Status::set_status(int& i_max_HP, int& i_max_MP, int& i_now_HP, int& i_now_MP, int& i_atk, int& i_exp, int& i_level, int& i_location, int& i_money)
{
    this->max_HP = i_max_HP;
    this->max_HP = i_max_MP;
    this->now_HP = i_now_HP;
    this->now_MP = i_now_MP;
    this->atk = i_atk;
    this->exp = i_exp;
    this->level = i_level;
    this->location = i_location;
    this->money = i_money;
}

void Status::set_atk(int i_atk){
    this->atk = i_atk;
}
void Status::set_mhp(int i_hp){
    this->max_HP = i_hp;
}

void Status::set_mmp(int i_mp){
    this->max_MP = i_mp;
}

void Status::set_nhp(int i_hp){
    this->now_HP = i_hp;
}

void Status::set_nmp(int i_mp){
    this->now_MP = i_mp;
}

void Status::setn_mhp(int i_hp, int i_mp){
    this->now_HP = i_hp;
    this->now_MP = i_mp;
}

void Status::set_level(int i_level){
    this->level = i_level;
}

void Status::set_exp(int i_exp){
    this->exp = i_exp;
}

void Status::set_location(int i_location) {
    this->location = i_location;
}

void Status::set_money(int i_money) {
    this->money = i_money;
}

////get
int Status::get_mhp(){
    return this->max_HP;
}

int Status::get_mmp(){
    return this->max_MP;
}

int Status::get_nhp(){
    return this->now_HP;
}

int Status::get_nmp(){
    return this->now_MP;
}

int Status::get_atk(){
    return this->atk;
}

int Status::get_level(){
    return this->level;
}

int Status::get_exp(){
    return this->exp;
}

int Status::get_location(){
    return this->location;
}

int Status::get_money() {
    return this->money;
}

vector<int> Status::getstatus() {
    return this->stat_list;
}
