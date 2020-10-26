#pragma once
#include<iostream>
#include <vector>
#include "Character.h"
#include "Status.h"

class Character; //식별자 오류 방지

class Monster {
private:
    static Status Monsterlist[99]; //몬스터 기본정보들을 저장하는 배열입니다.
    const static string namelist[4]; // 몬스터의 이름을 저장하는 배열입니다. 
    Status monsterInfo; // 몬스터의 기본정보입니다.
    Status monsterStatus; // 전투에 의해서 바뀌는 몬스터의 현재 정보입니다. 
    int MonsterNum;
    

public:

    Monster();
    Monster(const Status i_status, const int& MonsterNum);
    ~Monster();
    
    void setMonsterNum(int num); // 몬스터의 번호를 주면 몬스터의 기본정보 status 객체를 반환합니다. 
    void set_nhp(int n_hp);

    int getMonsterNum();
    int get_nhp(); 
    string get_name(const int& num);

    Status get_Monsterstat(); // 몬스터의 기본정보가 아닌 현재 정보 반환
    Status get_MonsterInfo(const int& num); // 번호에 해당하는 몬스터 기본 정보 반환
    void attack(Character &ch); // 공격할 캐릭터의 스탯값을 바꿔줘야 하기때문에 참조값 사용
    void reset(); // 몬스터 hp,mp 재설정
    void change(const int& num, Status st); // 몬스터 기본 정보 변경

};