#include "Monster.h"

Status Monster::Monsterlist[99]; // 몬스터의 기본정보들을 담고있습니다(몬스터 도감 같은 개념)

Monster::Monster()
    :MonsterNum(0)
{


}

Monster::Monster(const Status i_status, const int& i_MonsterNum)
    :MonsterNum(0)
{
    this->monsterStatus = i_status;
    this->monsterInfo = this->monsterStatus;// 몬스터의 기본정보를 설정
    Monsterlist[i_MonsterNum] = this->monsterInfo; // 몬스터 도감에 해당하는 번호에 몬스터 기본 정보 저장
    this->MonsterNum = i_MonsterNum;
   
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

int Monster::get_nhp()
{
    return this->monsterStatus.get_nhp();
}

void Monster::set_nhp(int i_hp)
{   
    this->monsterStatus.set_nhp(i_hp);
}


Status Monster::get_Monsterstat()
{   
    return this->monsterStatus; //몬스터의 기본정보가 아닌 몬스터의 현재 정보

}

Status Monster::get_MonsterInfo(const int& num)
{   
    return Monsterlist[num]; 
}

void Monster::attack(Character &i_ch)
{
    int use_mp = 20;
    int damage = i_ch.get_nhp() - (this->monsterStatus.get_atk());// 데미지 캐릭터의 현재 hp - 몬스터의 공격력
    i_ch.set_nhp(damage); // 데미지라는 변수로 공격대상 캐릭터의 hp 바꿔준다.
    this->monsterStatus.set_nmp(this->monsterStatus.get_nmp()-use_mp); //몬스터 mp 20 감소 시켜준다.

}

void Monster::reset()
{
    this->monsterStatus = monsterInfo; // 몬스터의 현재 정보를 몬스터가 가지고 있는 기본 정보로 재설정
}

void Monster::change(const int& num, Status st) //()
{
    Monsterlist[num] = st;
    
}
