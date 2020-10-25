#pragma once
#include<iostream>
#include <vector>

using namespace std;

class Status{

    private:
        int max_HP;
        int max_MP;
        int now_HP;
        int now_MP;
        int atk;
        int exp;
        int level;
        int location;
        vector<int>stat_list; //위의 속성들을 담아둘 벡터

    public:
        Status(); 
        Status(int& i_max_HP, int& i_max_MP, int& i_now_HP,int& i_now_MP, int& i_atk, int& i_exp, int& i_level, int& i_location);
        ~Status();
        void show();
        void setstatus(int& i_max_HP, int& i_max_MP, int& i_now_HP,int& i_now_MP, int& i_atk, int& i_exp, int& i_level, int& i_location);
        vector<int> getstatus();
        void set_atk(int i_atk);
        void setn_hp(int i_hp);
        void setn_mp(int i_mp);
        void setn_mhp(int i_hp, int i_mp); //hp mp 동시 수정
        int getn_hp();
        int getn_mp();
        int get_atk();
        // 우선은 getset 같은 경우는 전체를 한번에 수정, 반환하는 형식으로 구현, 이후 특정 변수만 반환, 수정하고 싶다면
        //추가 예정
};