#include "Monster.h"

Monster::Monster(const Status i_status, const int& i_MonsterNum)
    :MonsterNum(0)
{
    this->monsetrStatus = i_status;
    this->MonsterNum = i_MonsterNum;
}

Monster::~Monster()
{

}

int Monster::getMonsterNum()
{
    return this->MonsterNum;
}

void Monster::setMonsterNum(const int& num)
{
    this->MonsterNum = num;
}

void Monster::set_Nowhp(int i_hp)
{   
    this->monsetrStatus.setn_hp(i_hp);
}

void Monster::attack(Character i_ch)
{
    int use_mp = 20;
    int use_hp = this ->monsetrStatus.getn_hp() - (i_ch.get_atk());

    this->monsetrStatus.setn_mhp(use_hp, use_mp);

}
