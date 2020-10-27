#include "warningMessage.h"

warningMessage::warningMessage()
{
	//오류 메시지의 번호는 앞에서부터 0~8까지입니다.(현재 이 상태에서는..)
	Message_List.push_back("문법 규칙에 어긋납니다.\n");
	Message_List.push_back("잘못된 형식입니다. 다시 입력하세요.\n"); //의미 규칙에 어긋나는 것도 여기에 포함될 것입니다.
	Message_List.push_back("파일이 유효하지 않습니다. 이전 화면으로 돌아갑니다.\n"); //유효성 검사할 때 사용할 것 같습니다.
	Message_List.push_back("불러오려는 파일의 형식이 문법에 맞지 않습니다.\n");
	Message_List.push_back("파일 저장에 실패하였습니다.\n");
	Message_List.push_back("파일 불러오기에 실패하였습니다.\n");
	Message_List.push_back("최대 슬롯 번호를 초과하였습니다.\n");
	Message_List.push_back("비소모성 아이템입니다. 소모할 수 없는 아이템입니다.\n");
	//추가적으로 필요한 경고메시지 + 오류메시지가 있다면 피드백 해주시면 감사하겠습니다 ㅠㅠ
}

void warningMessage::printWarning(int warningNum)
{
	cout << get_WarningMessage(warningNum); //경고 or 오류메시지 출력
}

string warningMessage::get_WarningMessage(int warningNum)
{
	return Message_List[warningNum];
}
