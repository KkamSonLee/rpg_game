
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
    this -> money = 0;            
    // 기획서상 level은 1이상의 숫자 나머지는 0이상의 숫자
}

Status::Status(int& max_HP, int& max_MP, int& now_HP,int& now_MP, int& atk, int& exp, int& level, int& location, int& money)
    :max_HP(max_HP),max_MP(max_MP),now_HP(now_HP),now_MP(now_MP),atk(atk),exp(exp),level(level),location(location), money(money) 
{
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
    cout << max_HP << max_MP << now_HP << now_MP << atk << exp << level << money << endl;
}

vector<int> Status::getstatus()
{
   

    return this->stat_list;
}