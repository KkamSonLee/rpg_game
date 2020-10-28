#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class warningMessage
{
private:
	int warningNum; //경고 혹은 오류메시지 번호
	vector<string> Message_List; //경고 혹은 오류메시지 문구
	
public:
	warningMessage(); //생성자
	int printWarning(int e_or_w, int warningNum); //경고 메시지를 출력해줄 함수(e_or_w는 오류인지 경고인지 알려주는 int값)
	string get_WarningMessage(int warningNum);
};

