#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class warningMessage
{
	
public:
	warningMessage(); //생성자
	int printWarning(int e_or_w, string Message); //경고 메시지를 출력해줄 함수(e_or_w는 오류인지 경고인지 알려주는 int값)
};

