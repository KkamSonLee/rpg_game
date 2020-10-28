
#include "battle.h"

int battle::Battle(Character &myCharacter, Inventory &myInventory, Monster &nowMonster, int map_num) //������ ���ϴ� �Լ�
{
	string input_order; //�Է¹��� ���ɾ �����ϴ� string�� ����
	//���� ��ȣ�� 1���� �ִ� ���� ��ȣ ������ ���̴�
	while (1)
	{
		show_Stats(myCharacter, nowMonster); //���� ǥ��
		std::cout << "����> ";
		getline(cin, input_order);
		
		if (input_order == "attack") //attack 6���ڸ� ��Ȯ�ϰ� �Է��� ���
		{
			int check;
			check = attack_situation(myCharacter, myInventory, nowMonster, map_num); //���� ��Ȳ�� ������ ���� �Լ� ȣ��
			if (check == 2) //���� �� ������Ʈ�� ���ư��ٴ� ��ȣ�� ���ƿ���
				continue;
			else if (check == 1) //������ ���ư��ٴ� ��ȣ�� ���ƿ���
				return 1;
		}
		else if (input_order == "run") //run 3���ڸ� ��Ȯ�ϰ� �Է��� ���
		{
			std::cout << "���� ����Ϳ��� �������ϴ�.\n";
			return 1; //1�� ��ȯ�Ѵ�. (1�� ��ȯ�� ��� ������ ���ư��ٴ� �ǹ���)
		}
		else if (input_order == "inventory") //inventory 9���ڸ� ��Ȯ�ϰ� �Է��� ���
		{
			std::cout << "�κ��丮�� �����մϴ�.\n";
			myInventory.openInv(); //�κ��丮 ����
		}
		else //��ȿ���� ���� �Է��� ���
		{
			std::cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���\n";
			continue; //���� �� ������Ʈ�� �ٽ� ���ư���.
		}
	}
	//���� �� ������Ʈ�� 1�� return ���� �ʴ� �� ������� ���� ���Դϴ�. (���ѷ������� ���������� �ٸ� ����� x)
}

void battle::show_Stats(Character& myCharacter, Monster& nowMonster)
{
	//���� ǥ��(�� ������Ʈ ù ȭ��)
	cout << "Player Lv" << myCharacter.get_level() << "\n";
	cout << "HP " << myCharacter.get_nhp() << "/" << myCharacter.get_mhp() << "\n";
	cout << "MP " << myCharacter.get_nmp() << "/" << myCharacter.get_mmp() << "\n";
	cout << "exp " << myCharacter.get_exp() << "\n";
	cout << "[Monster]"<<nowMonster.get_name(nowMonster.getMonsterNum())<<" HP : " << nowMonster.get_nhp() << "/" << nowMonster.get_mmp() << "\n"; //���� �̸��� ü�� ���
	cout << "\n"; //���๮��
}

void battle::save_character(Character& myCharacter, Inventory& myInventory) //ĳ���� ������ �����ϴ� �Լ�
{
	//ĳ���� ���� ���̺� ������ ���� ��ĥ ����
	vector<int> for_save_status; //���� ������ ���� �ӽ� ����
	vector<int> for_save_slot; //������ ������ ���� �ӽ� ����
	for_save_slot = myInventory.getSlot(); //������ slot�� ������ �Ѱ��ش�
	for_save_status = myCharacter.get_stat().getstatus(); //���� ������ ���� ������ �Ѱ��ش�
	ofstream fout; //���� ��� ��ü ����
	fout.open("character.txt"); //character.txt��� ���� ����(������ ���� ������ ����)
	//ĳ���Ͱ� ������ �ִ� ��� stat�� ���� ������ ���Ŀ� �°� txt ���Ͽ� ����� ���Դϴ�.
	for (auto iter = for_save_status.begin(); iter != for_save_status.end(); iter++) //status�� ���� ���� ����
	{
		fout << *iter << '\t';
	}
	fout << "/";
	//ĳ���Ͱ� ������ �ִ� ��� �������� ���Ŀ� �°� txt ���Ͽ� ����� ���Դϴ�.
	for (auto iter = for_save_slot.begin(); iter != for_save_slot.end(); iter++)
	{
		if (for_save_slot.end() == ++iter) //������ ����� ���
		{
			fout << *iter;
			fout << "/";
			break;
		}
		else //�Ϲ� ����� ���
			fout << *iter << '\t';
	}
	fout.close(); //��� �Ϸ� �Ŀ��� ���� �ݱ�
}

int battle::attack_situation(Character& myCharacter, Inventory& myInventory, Monster& nowMonster, int map_num)
{
	if (myCharacter.get_nmp() <= 20) //���� MP�� ����Ϸ��� MP �̻�ŭ �ִ� ���(���⼱ 20)
	{
		std::cout << "ĳ������ ���� mp�� 0 �����Դϴ�.\n";
		return 2; //���� �� ������Ʈ�� ���ư���
	}
	else //MP�� 20 �ʰ��� ���
	{
		myCharacter.attack(nowMonster, 20); //ĳ���Ͱ� ���� ����
		if (nowMonster.get_nhp() > 0) //������ ü���� 0 �̻��̶��
		{
			nowMonster.attack(myCharacter, 0); //���Ͱ� ĳ���� ����
			if (myCharacter.get_nhp() <= 0) //ĳ������ ���� hp�� 0 ���϶��
			{
				std::cout << "ĳ������ ���� hp�� 0 �����Դϴ�.\n";
				std::cout << "������ ���ư��ϴ�.\n";
				myCharacter.set_nhp(1); //���� �Ҵ� ���·� hp ����(now_HP == 1)
				return 1; //1�� ��ȯ�Ѵ�. (1�� ��ȯ�� ��� ������ ���ư��ٴ� �ǹ��Դϴ�. (�� ������Ʈ���� ���� �޾Ƽ� ������ �̵���Ű�� �� �� �����ϴ�.))
			}
			//ĳ������ ���� hp�� 0 �̻��̸� ����� �� �ٵ�, ������ �ش� ������ �� ���������Ƿ� �ٽ� ������Ʈ ������� ���ư��ϴ�
		}
		else if (nowMonster.get_nhp() <= 0)//������ ü���� 0 ���϶��(���͸� ���� ��)
		{
			if (map_num == 3) //�������� ���
			{
				int plus_money, plus_exp; //�߰��� ��, exp
				plus_money = nowMonster.get_money() + myCharacter.get_money(); //���� �ִ� �� + �߰��� ���� ��
				plus_exp = nowMonster.get_exp() + myCharacter.get_exp(); //���� �ִ� exp + �߰��� ���� exp

				save_character(myCharacter, myInventory);

				//ĳ���Ϳ� money���� exp ���� �缳�� �����ش� (REWARD)
				myCharacter.set_money(plus_money);
				myCharacter.set_exp(plus_exp);

				return 1; //1�� ��ȯ�Ѵ�. (1�� ��ȯ�� ��� ������ ���ư��ٴ� �ǹ��Դϴ�. (�� ������Ʈ���� ���� �޾Ƽ� ������ �̵���Ű�� �� �� �����ϴ�.))
				//ĳ���� ���� ���Ἲ �˻�� 1�� ��ȯ�� ���� �ǽ��ϸ� �� ���Դϴ�.
			}
			else if (map_num == 2) //�Ϲ� ������� ���
			{
				int plus_money, plus_exp; //�߰��� ��, exp
				plus_money = nowMonster.get_money() + myCharacter.get_money(); //���� �ִ� �� + �߰��� ���� ��
				plus_exp = nowMonster.get_exp() + myCharacter.get_exp(); //���� �ִ� exp + �߰��� ���� exp

				//ĳ���Ϳ� money���� exp ���� �缳�� �����ش� (REWARD)
				myCharacter.set_money(plus_money);
				myCharacter.set_exp(plus_exp);

				return 1; //1�� ��ȯ�Ѵ�. (1�� ��ȯ�� ��� ������ ���ư��ٴ� �ǹ��Դϴ�. (�� ������Ʈ���� ���� �޾Ƽ� ������ �̵���Ű�� �� �� �����ϴ�.))
			}
		}
	}
}


