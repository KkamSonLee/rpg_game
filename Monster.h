#pragma once
#include<iostream>
#include <vector>
#include "Character.h"
#include "Status.h"

class Character; //�ĺ��� ���� ����

class Monster {
private:
    string name; // ������ �̸��� �����ϴ� �迭�Դϴ�.
    int MonsterNum;
    static const int Monsterlist[3][9];
    static const string namelist[3];


public:

    Status monsterStatus; // ������ ���ؼ� �ٲ�� ������ ���� �����Դϴ�.

    Monster(int MonsterNum);
    ~Monster();
    void setStat(int num);
    void attack(Character& ch, int mp); // ������ ĳ������ ���Ȱ��� �ٲ���� �ϱ⶧���� ������ ���


    Status get_Monsterstat(); // ������ �⺻������ �ƴ� ���� ���� ��ȯ
    Status get_MonsterInfo(int num); // ��ȣ�� �ش��ϴ� ���� �⺻ ���� ��ȯ
    string get_name(int num);
    int getMonsterNum();

    int get_nhp();
    int get_nmp();
    int get_mhp();
    int get_mmp();
    int get_atk();
    int get_exp();// ���Ͱ� �� ����ġ
    int get_level();
    int get_location();
    int get_money(); // ���Ͱ� �� ��

    void setMonsterNum(int num);
    void set_stat(int num);
    void set_name();
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