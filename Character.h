#pragma once
#include<iostream>
#include <vector>
#include "Monster.h"
#include "Status.h"

class Monster; //식별자 오류 방지

class Character
{
private:
    Status status;
    //Inventory(money,slot);
    //int slot[10]; 민호님과 얘기해본 결과 제가 아닌 민호님이 다루는게 더 좋을거 같다고 하셔서 삭제했습니다.
public:
    Character(const Status i_status);
    ~Character();
    void show_stat(); //sata 전체 출력

    int get_nhp();
    Status get_stat();
    int get_atk();
    

    void set_nhp(int i_hp);
    void set_stat(int& i_max_HP, int& i_max_MP, int& i_now_HP, int& i_now_MP, int& i_atk, int& i_exp, int& i_level, int& i_location);
    void set_atk(int i_atk);

    void attack(Monster &mon); // 공격함수 공격할 몬스터의 정보를 바꿔줘야 하기 때문에 참조값 사용
    void check_level(); // 레벌업 검사 및 레벨 관련 정보만 변경해주는 함수 입니다. status 전체를 수정하지 않아도 됩니다.
    //Inventory.open();


};
