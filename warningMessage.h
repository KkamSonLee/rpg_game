#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class warningMessage
{
private:
	int warningNum; //경고메시지 번호
	vector<string> Message_List; //경고메시지 문구
	
public:
	warningMessage(); //생성자
	void printWarning(int warningNum); //경고 메시지를 출력해줄 함수
	string get_WarningMessage(int warningNum);
};

