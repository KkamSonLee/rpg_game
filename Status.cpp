
#include "Status.h"

Status::Status()
{
    this->max_HP = 0;
    this-> max_HP = 0;
    this -> max_MP = 0;
    this -> now_HP = 0;
    this -> now_MP = 0;
    this -> atk = 0;
    this -> exp = 0;
    this -> level = 1;
    this -> location = 0;
    // 기획서상 level은 1이상의 숫자 나머지는 0이상의 숫자
}

Status::Status(int& i_max_HP, int& i_max_MP, int& i_now_HP,int& i_now_MP, int& i_atk, int& i_exp, int& i_level, int& i_location)
{
    this->max_HP = i_max_HP;
    this-> max_HP = i_max_MP;
    this -> now_HP = i_now_HP;
    this -> now_MP = i_now_MP;
    this -> atk = i_atk;
    this -> exp = i_exp;
    this -> level = i_level;
    this -> location = i_location;     

    stat_list.push_back(max_HP);
    stat_list.push_back(max_MP);
    stat_list.push_back(now_HP);
    stat_list.push_back(now_MP);
    stat_list.push_back(atk);
    stat_list.push_back(exp);
    stat_list.push_back(level);
    stat_list.push_back(location);
}

Status::~Status()
{

}

void Status::show()
{
    cout << max_HP << max_MP << now_HP << now_MP << atk << exp << level << endl;
}

void Status::setstatus(int& i_max_HP, int& i_max_MP, int& i_now_HP,int& i_now_MP, int& i_atk, int& i_exp, int& i_level, int& i_location)
{
    this->max_HP = i_max_HP;
    this-> max_HP = i_max_MP;
    this -> now_HP = i_now_HP;
    this -> now_MP = i_now_MP;
    this -> atk = i_atk;
    this -> exp = i_exp;
    this -> level = i_level;
    this -> location = i_location;
}

vector<int> Status::getstatus()
{
    return this->stat_list;
}

void Status::set_atk(int i_atk)
{
    this->atk = i_atk;
}
void Status::setn_hp(int i_hp)
{
    this -> now_HP = i_hp;
}

void Status::setn_mp(int i_mp)
{
    this -> now_MP = i_mp;
}

void Status::setn_mhp(int i_hp, int i_mp)
{
    this -> now_HP = i_hp;
    this -> now_MP = i_mp;
}

int Status::getn_hp()
{   
    return this->now_HP;
}

int Status::getn_mp()
{
    return this->now_MP;
}

int Status::getn_mp()
{
    return this->atk;
}