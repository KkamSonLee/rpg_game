#pragma once
#include "warningMessage.h"

warningMessage::warningMessage()
{
	//�����ڿ��� �ƹ��� �ൿ�� �ʿ� �����ϴ�.
}

int warningMessage::printWarning(int e_or_w, string Message)
{
	cout << Message << '\n';
	if (e_or_w == 1) //��� �޽����� ���(�׳� �ѱ�� ���� ������ �����ص� �Ǵ� ���)
	{
		return e_or_w; //��� �޽������� �˷��ִ� ����(���⼱ 1)�� return ���ش�
	}
	if (e_or_w == 0) //���� �޽����� ���(�׳� �ѱ�� ���� ������ �����ϸ� �ȵǴ� ���)
	{
		//���⼭ �ٷ� ������ ������ �̴�� ���νø� �� �� ����, 0�� �ٱ����� ���Ϲް� �����Ű�ŵ� �� �� �����ϴ�!
	    exit(0);
	}
}
