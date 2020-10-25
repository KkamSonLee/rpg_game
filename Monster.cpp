#include "Monster.h"

//vector<vector<Status>> Monster::Monsterlist;
Status Monster::Monsterlist[99];
Monster::Monster()
    :MonsterNum(0)
{


}

Monster::Monster(const Status i_status, const int& i_MonsterNum)
    :MonsterNum(0)
{
    this->monsetrStatus = i_status;
    this->MonsterNum = i_MonsterNum;


    Monsterlist[i_MonsterNum] = this -> monsetrStatus;

    /*
    vector<Status> Monsterattribute;
    Monsterattribute.push_back(this->monsetrStatus);
    Monsterlist[i_MonsterNum] = Monsterattribute;
    */
   
}

Monster::~Monster()
{

}

int Monster::getMonsterNum()
{
    return this->MonsterNum;
}

void Monster::setMonsterNum(const int num)
{
    this->MonsterNum = num;
}



void Monster::set_Nowhp(int i_hp)
{   
    this->monsetrStatus.setn_hp(i_hp);
}

Status Monster::get_Monsterstat(const int& num)
{
    return Monsterlist[num]; //번호로 몬스터 스텟을 가져오기 위함.
}

Status Monster::get_Monsterstat()
{
    return monsetrStatus; 
}

void Monster::attack(Character i_ch)
{
    int damage = i_ch.getn_hp() - (this->monsetrStatus.get_atk());// 데미지 캐릭터의 현재 hp - 몬스터의 공격력
    i_ch.setn_hp(damage); // 데미지라는 변수로 캐릭터의 hp 바꿔준다.
    this->monsetrStatus.setn_mp(this->monsetrStatus.getn_mp()-20); //몬스터 mp 20 감소 시켜준다.

}
