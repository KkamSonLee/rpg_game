#include "warningMessage.h"

warningMessage::warningMessage()
{
	//���� �޽����� ��ȣ�� �տ������� 0~8�����Դϴ�.(���� �� ���¿�����..)
	Message_List.push_back("Gramatically Error!\n");
	Message_List.push_back("Invalid Context!\n"); //�ǹ� ��Ģ�� ��߳��� �͵� ���⿡ ���Ե� ���Դϴ�.
	Message_List.push_back("Not Valid File Context! Go to previous Prompt.\n"); //��ȿ�� �˻��� �� ����� �� �����ϴ�.
	Message_List.push_back("Failed to open .txt File!\n");
	Message_List.push_back("Failed to save file!\n");
	Message_List.push_back("Failed to load file!\n");
	Message_List.push_back("Overflow the max slot number!\n");
	Message_List.push_back("It's not a consuming item. Cannot be used!\n");
	//�߰������� �ʿ��� ���޽��� + �����޽����� �ִٸ� �ǵ�� ���ֽø� �����ϰڽ��ϴ� �Ф�
}

int warningMessage::printWarning(int e_or_w, int warningNum)
{
	cout << get_WarningMessage(warningNum); //��� or �����޽��� ���
	if (e_or_w == 1) //��� �޽����� ���(�׳� �ѱ�� ���� ������ �����ص� �Ǵ� ���)
	{
		return e_or_w; //��� �޽������� �˷��ִ� ����(���⼱ 1)�� return ���ش�
	}
	if (e_or_w == 0) //���� �޽����� ���(�׳� �ѱ�� ���� ������ �����ϸ� �ȵǴ� ���)
	{
		return e_or_w; //���� �޽������� �˷��ִ� ����(���⼱ 0)�� return ���ش�
	}
	return 0;
}

string warningMessage::get_WarningMessage(int warningNum)
{
	return Message_List[warningNum];
}
