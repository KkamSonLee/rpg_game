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
    Status monsterStatus; // 전투에 의해서 바뀌는 몬스터의 현재 정보입니다. 
    int MonsterNum;
    

public:

    Monster(); // 회의때 논의
    Monster(const Status& i_status, const int& MonsterNum);
    ~Monster();
    

    void attack(Character& ch, const int& mp); // 공격할 캐릭터의 스탯값을 바꿔줘야 하기때문에 참조값 사용
    void reset(const int& num); // 몬스터 hp,mp 재설정
    void change(const int& num, Status st); // 몬스터 기본 정보 변경 회의때 논의


    Status get_Monsterstat(); // 몬스터의 기본정보가 아닌 현재 정보 반환
    Status get_MonsterInfo(const int& num); // 번호에 해당하는 몬스터 기본 정보 반환
    string get_name(const int& num);    
    int getMonsterNum();

    int get_nhp();
    int get_nmp();
    int get_mhp();
    int get_mmp();
    int get_atk();
    int get_exp();// 몬스터가 줄 경험치
    int get_level();
    int get_location();
    int get_money(); // 몬스터가 줄 돈

    void setMonsterNum(int num);

    void set_nhp(int i_hp);
    void set_nmp(int i_mp);
    void set_mhp(int i_hp);
    void set_mmp(int i_mp);
    void set_atk(int i_atk);
    void set_exp(int i_exp);
    void set_level(int i_level);
    void set_location(int i_location);
    void set_money(int i_money);





};