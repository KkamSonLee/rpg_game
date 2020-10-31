#pragma once
#include "warningMessage.h"

warningMessage::warningMessage()
{
	//생성자에는 아무런 행동이 필요 없습니다.
}

int warningMessage::printWarning(int e_or_w, string Message)
{
	cout << Message << '\n';
	if (e_or_w == 1) //경고 메시지인 경우(그냥 넘기고 다음 과정을 실행해도 되는 경우)
	{
		return e_or_w; //경고 메시지임을 알려주는 정수(여기선 1)을 return 해준다
	}
	if (e_or_w == 0) //오류 메시지인 경우(그냥 넘기고 다음 과정을 실행하면 안되는 경우)
	{
		//여기서 바로 끝내고 싶으면 이대로 냅두시면 될 것 같고, 0을 바깥에서 리턴받고 종료시키셔도 될 것 같습니다!
	    exit(0);
	}
}
