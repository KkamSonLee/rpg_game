#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class warningMessage
{
private:
	int warningNum; //��� Ȥ�� �����޽��� ��ȣ
	vector<string> Message_List; //��� Ȥ�� �����޽��� ����
	
public:
	warningMessage(); //������
	int printWarning(int e_or_w, int warningNum); //��� �޽����� ������� �Լ�(e_or_w�� �������� ������� �˷��ִ� int��)
	string get_WarningMessage(int warningNum);
};

