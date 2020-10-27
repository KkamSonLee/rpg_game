#include "warningMessage.h"

warningMessage::warningMessage()
{
	//���� �޽����� ��ȣ�� �տ������� 0~8�����Դϴ�.(���� �� ���¿�����..)
	Message_List.push_back("���� ��Ģ�� ��߳��ϴ�.\n");
	Message_List.push_back("�߸��� �����Դϴ�. �ٽ� �Է��ϼ���.\n"); //�ǹ� ��Ģ�� ��߳��� �͵� ���⿡ ���Ե� ���Դϴ�.
	Message_List.push_back("������ ��ȿ���� �ʽ��ϴ�. ���� ȭ������ ���ư��ϴ�.\n"); //��ȿ�� �˻��� �� ����� �� �����ϴ�.
	Message_List.push_back("�ҷ������� ������ ������ ������ ���� �ʽ��ϴ�.\n");
	Message_List.push_back("���� ���忡 �����Ͽ����ϴ�.\n");
	Message_List.push_back("���� �ҷ����⿡ �����Ͽ����ϴ�.\n");
	Message_List.push_back("�ִ� ���� ��ȣ�� �ʰ��Ͽ����ϴ�.\n");
	Message_List.push_back("��Ҹ� �������Դϴ�. �Ҹ��� �� ���� �������Դϴ�.\n");
	//�߰������� �ʿ��� ���޽��� + �����޽����� �ִٸ� �ǵ�� ���ֽø� �����ϰڽ��ϴ� �Ф�
}

void warningMessage::printWarning(int warningNum)
{
	cout << get_WarningMessage(warningNum); //��� or �����޽��� ���
}

string warningMessage::get_WarningMessage(int warningNum)
{
	return Message_List[warningNum];
}
