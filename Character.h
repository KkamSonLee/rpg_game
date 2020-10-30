#pragma once
#include<iostream>
#include "Monster.h"
#include "Status.h"

class Monster; //�ĺ��� ���� ����

class Character
{
private:
    Status &status;


public:
    Character(Status& i_status);
    ~Character();

    void show_stat(); //sata ��ü ���
    void attack(Monster& mon, const int& i_mp); // �����Լ� ������ ������ ������ �ٲ���� �ϱ� ������ ������ ���
    void check_level(); // ������ �˻� �� ���� ���� ������ �������ִ� �Լ� �Դϴ�. status ��ü�� �������� �ʾƵ� �˴ϴ�.

    Status get_stat();
    int get_nhp();
    int get_nmp();
    int get_mhp();
    int get_mmp();
    int get_atk();
    int get_exp();
    int get_level();
    int get_location();
    int get_money();


    void set_stat(int& i_max_HP, int& i_max_MP, int& i_now_HP, int& i_now_MP, int& i_atk, int& i_exp, int& i_level, int& i_location, int& i_money);
    void set_nhp(int i_hp);
    void set_nmp(int i_mp);
    void set_mhp(int i_hp);
    void set_mmp(int i_mp);
    void set_atk(int i_atk);
    void set_exp(int i_exp);
    void set_level(int i_level);
    void set_location(int i_location);
    void set_money(int i_money);



    //Inventory.open();


};
