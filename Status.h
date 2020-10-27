#pragma once
#include<iostream>
#include <vector>

using namespace std;

class Status {

private:
    int max_HP;
    int max_MP;
    int now_HP;
    int now_MP;
    int atk;
    int exp;
    int level;
    int location;
    int money;
    vector<int>stat_list; //위의 속성들을 담아둘 벡터

public:
    Status(); // 회의때 논의
    Status(int& i_max_HP, int& i_max_MP, int& i_now_HP, int& i_now_MP, int& i_atk, int& i_exp, int& i_level, int& i_location , int i_money); // 객체
    ~Status();

    void show();

    void set_status(int& i_max_HP, int& i_max_MP, int& i_now_HP, int& i_now_MP, int& i_atk, int& i_exp, int& i_level, int& i_location,int& i_money);
    void set_atk(int i_atk);
    void set_mhp(int i_hp);
    void set_mmp(int i_mp);
    void set_nhp(int i_hp);
    void set_nmp(int i_mp);
    void setn_mhp(int i_hp, int i_mp); //hp mp 동시 수정
    void set_location(int i_location);
    void set_level(int i_level);
    void set_exp(int i_exp);
    void set_money(int i_money);


    int get_mhp();
    int get_mmp();
    int get_nhp();
    int get_nmp();
    int get_atk();
    int get_level();
    int get_exp();
    int get_location();
    int get_money();
    vector<int> getstatus();

    /*friend bool operator ==(Status& st, Status& st2)
    {
        return st.stat_list == st.stat_list;
    }*/

};