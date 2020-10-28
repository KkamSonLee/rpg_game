#include "Monster.h"

Status Monster::Monsterlist[99]; // ������ �⺻�������� ����ֽ��ϴ�(���� ���� ���� ����)
const string Monster::namelist[4] = { "목검", "장검", "HP포션", "MP포션" };
Monster::Monster()
    :MonsterNum(0){
}

Monster::Monster(const Status& i_status, const int& i_MonsterNum)
    :MonsterNum(0)
{
    this->monsterStatus = i_status;
    Monsterlist[i_MonsterNum] = i_status; // ������ �⺻������ ����, ���� ������ �ش��ϴ� ��ȣ�� ���� �⺻ ���� ����
    this->MonsterNum = i_MonsterNum;
   
}

Monster::~Monster(){
}


void Monster::attack(Character& i_ch , int i_mp) {
    int use_mp = i_mp;
    if (this->get_nmp() < i_mp) {
        cout << "MP�� �����մϴ�." << endl;
    }
    int damage = i_ch.get_nhp() - (this->get_atk());// ������ ĳ������ ���� hp - ������ ���ݷ�
    i_ch.set_nhp(damage); // ��������� ������ ���ݴ�� ĳ������ hp �ٲ��ش�.
    this->set_nmp(this->get_nmp() - i_mp); //���� mp�� �Ű����� �޴� ��ŭ ���� �����ش�.

}

void Monster::reset(const int& num) {
    this->monsterStatus = Monsterlist[num]; // ������ ���� ������ ���Ͱ� ������ �ִ� �⺻ ������ �缳��
}

void Monster::change(const int& num, Status st) { // ���� ��ȣ�� �ش��ϴ� �⺻������ü ��ȯ 
    Monsterlist[num] = st;
}


///get
string Monster::get_name(const int& num) {// ���� ��ȣ�� �Է��ϸ� �ش� ������ �̸��� ��ȯ�մϴ�. �ٸ� status������ ���� �̸� ������ �ټ� ���� ������ �ڵ� ���ο��� �����迭�� ���ؼ�
    // ���ϴ� ����� ����߽��ϴ�. 
    return this->namelist[num - 1]; // �迭�ε� �̰Ŵ� 0�� ����� �ִ� �迭�� �ƴϱ� ������ 
}
Status Monster::get_Monsterstat() {
    return this->monsterStatus; //������ �⺻������ �ƴ� ������ ���� ����
}
Status Monster::get_MonsterInfo(const int& num) {
    return Monsterlist[num];
}
int Monster::getMonsterNum() {
    return this->MonsterNum;
}
int Monster::get_nhp() {
    return this->monsterStatus.get_nhp();
}
int Monster::get_nmp() {
    return this->monsterStatus.get_nmp();
}
int Monster::get_mhp() {
    return this->monsterStatus.get_mhp();
}
int Monster::get_mmp() {
    return this->monsterStatus.get_mmp();
}
int Monster::get_atk() {
    return this->monsterStatus.get_atk();
}
int Monster::get_exp() {
    return this->monsterStatus.get_exp();
}
int Monster::get_level() {
    return this->monsterStatus.get_level();
}
int Monster::get_location() {
    return this->monsterStatus.get_location();
}
int Monster::get_money() {
    return this->monsterStatus.get_money();
}



///set
void Monster::setMonsterNum(const int num) {
    this->MonsterNum = num;
}
void Monster::set_nhp(int i_hp) {
    this->monsterStatus.set_nhp(i_hp);
}
void Monster::set_nmp(int i_mp) {
    this->monsterStatus.set_nmp(i_mp);
}
void Monster::set_mhp(int i_hp) {
    this->monsterStatus.set_mhp(i_hp);
}
void Monster::set_mmp(int i_mp) {
    this->monsterStatus.set_mmp(i_mp);
}
void Monster::set_atk(int i_atk) {
    this->monsterStatus.set_atk(i_atk);
}
void Monster::set_exp(int i_exp) {
    this->monsterStatus.set_exp(i_exp);
}
void Monster::set_level(int i_level) {
    this->monsterStatus.set_level(i_level);
}
void Monster::set_location(int i_location) {
    this->monsterStatus.set_location(i_location);
}
void Monster::set_money(int i_money) {
    monsterStatus.set_money(i_money);
}



