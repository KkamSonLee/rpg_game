#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class warningMessage
{
private:
	int warningNum; //���޽��� ��ȣ
	vector<string> Message_List; //���޽��� ����
	
public:
	warningMessage(); //������
	void printWarning(int warningNum); //��� �޽����� ������� �Լ�
	string get_WarningMessage(int warningNum);
};

