#include "warningMessage.h"

warningMessage::warningMessage()
{
	//오류 메시지의 번호는 앞에서부터 0~8까지입니다.(현재 이 상태에서는..)
	Message_List.push_back("Gramatically Error!\n");
	Message_List.push_back("Invalid Context!\n"); //의미 규칙에 어긋나는 것도 여기에 포함될 것입니다.
	Message_List.push_back("Not Valid File Context! Go to previous Prompt.\n"); //유효성 검사할 때 사용할 것 같습니다.
	Message_List.push_back("Failed to open .txt File!\n");
	Message_List.push_back("Failed to save file!\n");
	Message_List.push_back("Failed to load file!\n");
	Message_List.push_back("Overflow the max slot number!\n");
	Message_List.push_back("It's not a consuming item. Cannot be used!\n");
	//추가적으로 필요한 경고메시지 + 오류메시지가 있다면 피드백 해주시면 감사하겠습니다 ㅠㅠ
}

int warningMessage::printWarning(int e_or_w, int warningNum)
{
	cout << get_WarningMessage(warningNum); //경고 or 오류메시지 출력
	if (e_or_w == 1) //경고 메시지인 경우(그냥 넘기고 다음 과정을 실행해도 되는 경우)
	{
		return e_or_w; //경고 메시지임을 알려주는 정수(여기선 1)을 return 해준다
	}
	if (e_or_w == 0) //오류 메시지인 경우(그냥 넘기고 다음 과정을 실행하면 안되는 경우)
	{
		return e_or_w; //오류 메시지임을 알려주는 정수(여기선 0)을 return 해준다
	}
	return 0;
}

string warningMessage::get_WarningMessage(int warningNum)
{
	return Message_List[warningNum];
}
