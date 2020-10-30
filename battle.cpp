#include "battle.h"

int battle::Battle(Character &myCharacter, Inventory &myInventory, Monster &nowMonster, int map_num, warningMessage &wMessage) //전투에 임하는 함수
{
	string input_order; //입력받은 명령어를 저장하는 string형 변수
	//몬스터 번호는 1부터 최대 몬스터 번호까지의 값이다.
	while (1)
	{
		show_Stats(myCharacter, nowMonster); //스탯 표시
		getline(cin, input_order);
		if (input_order == "attack") //attack 6글자를 정확하게 입력한 경우
		{
			int check;
			check = attack_situation(myCharacter, myInventory, nowMonster, map_num, wMessage); //공격 상황을 구현해 놓은 함수 호출
			if (check == 2) //전투 부 프롬프트로 돌아간다는 신호가 돌아오면
				continue;
			else if (check == 1) //마을로 돌아간다는 신호가 돌아오면
				return 1;
		}
		else if (input_order == "run") //run 3글자가 정확하게 입력된 경우
		{
			std::cout << "현재 사냥터에서 도망갑니다.\n";
			return 1; //1을 반환한다. (1을 반환할 경우 마을로 돌아간다는 의미입니다)
		}
		else if (input_order == "inventory") //inventory 9글자가 정확하게 입력된 경우
		{
			std::cout << "인벤토리를 오픈합니다.\n";
			myInventory.openInv(); //인벤토리 오픈
		}
		else //유효하지 않은 입력인 경우
		{
			int check = wMessage.printWarning(1, 1); //1은 경고라는 뜻, 다른 1은 유효하지 않은 형식이라는 뜻
			std::cout << "\n";
			continue; //전투 부 프롬프트로 다시 돌아간다
		}
	}
	//전투 부 프롬프트는 1이 return 되지 않는 한 종료되지 않을 것입니다. (무한루프에서 빠져나오는 다른 방법은 x)
}

void battle::show_Stats(Character& myCharacter, Monster& nowMonster)
{
	//정보 표시(부 프롬포트 첫 화면)
	cout << "Player Lv" << myCharacter.get_level() << "\n";
	cout << "HP " << myCharacter.get_nhp() << "/" << myCharacter.get_mhp() << "\n";
	cout << "MP " << myCharacter.get_nmp() << "/" << myCharacter.get_mmp() << "\n";
	cout << "exp " << myCharacter.get_exp() << "\n";
	//몬스터 이름과 체력 출력
	cout << "[Monster]"<<nowMonster.get_name(nowMonster.getMonsterNum())<<" HP : " << nowMonster.get_nhp() << "/" << nowMonster.get_mmp() << "\n"; 
	cout << "\n"; //개행문자
}

void battle::save_character(Character& myCharacter, Inventory& myInventory, warningMessage &wMessage) //캐릭터 정보를 저장하는 함수
{
	//캐릭터 정보 세이브 과정을 거칠 것임
	vector<int> for_save_status; //스탯 저장을 위한 임시 벡터
	vector<int> for_save_slot; //아이템 저장을 위한 임시 벡터
	for_save_slot = myInventory.getSlot(); //아이템 slot의 정보를 넘겨준다
	for_save_status = myCharacter.get_stat().getstatus(); //스탯 저장을 위해 정보를 넘겨준다
	ofstream fout; //파일 출력 객체 생성
	fout.open("character.txt"); //character.txt라는 파일 열기(기존의 파일 내용은 삭제)
	if (!fout.is_open()) //열리지 않는 경우
	{
		int check = wMessage.printWarning(0, 4); //0은 오류 메시지이고, 4는 txt 파일 출력 실패라는 뜻
		if (check == 0) //오류인 것이 확인되면
			exit(0); //강제종료
	}
	//캐릭터가 가지고 있는 모든 stat에 관한 정보를 형식에 맞게 txt 파일에 출력할 것입니다.
	for (auto iter = for_save_status.begin(); iter != for_save_status.end(); iter++) //status에 관한 정보 저장
	{
		fout << *iter << '\t';
	}
	
	//캐릭터가 가지고 있는 모든 아이템을 형식에 맞게 txt 파일에 출력할 것입니다.
	for (auto iter = for_save_slot.begin(); iter != for_save_slot.end(); iter++)
	{
		if (for_save_slot.end() == ++iter) //마지막 출력인 경우
		{
			fout << *iter;
			break;
		}
		else //일반 출력인 경우
			fout << *iter << '\t';
	}
	fout.close(); //출력 완료 후에는 파일 닫기
}

int battle::attack_situation(Character& myCharacter, Inventory& myInventory, Monster& nowMonster, int map_num, warningMessage &wMessage)
{
	if (myCharacter.get_nmp() <= 20) //현재 MP가 사용하려는 MP 이상만큼 있는 경우(여기선 20)
	{
		std::cout << "캐릭터의 현재 mp가 20 이하입니다.\n";
		return 2; //전투 부 프롬프트로 돌아간다
	}
	else //MP가 20 초과인 경우
	{
		myCharacter.attack(nowMonster, 20); //캐릭터가 몬스터 공격
		if (nowMonster.get_nhp() > 0) //몬스터의 체력이 0 이상이라면
		{
			nowMonster.attack(myCharacter, 0); //몬스터가 캐릭터 공격
			if (myCharacter.get_nhp() <= 0) //캐릭터의 현재 hp가 0 이하라면
			{
				std::cout << "캐릭터의 현재 hp가 0 이하입니다.\n";
				std::cout << "마을로 돌아갑니다.\n";
				myCharacter.set_nhp(1); //전투 불능 상태로 hp 조절(now_HP == 1)
				return 1; //1을 반환한다. (1을 반환할 경우 마을로 돌아간다는 의미입니다. (주 프롬포트에서 정수 받아서 마을로 이동시키면 될 것 같습니다.))
			}
			//캐릭터의 현재 hp가 0 이상이면 여기로 올 텐데, 다시 전투 부 프롬프트로 돌아가게 만들어 주면 됩니다.
			return 2; //전투 부 프롬프트로 돌아간다.
		}
		else if (nowMonster.get_nhp() <= 0) //몬스터의 체력이 0 이하라면(몬스터를 잡은 것)
		{
			if (map_num == 3) //보스맵인 경우
			{
				int plus_money, plus_exp; //추가할 돈, exp
				plus_money = nowMonster.get_money() + myCharacter.get_money(); //원래 있던 돈 + 추가로 얻은 돈
				plus_exp = nowMonster.get_exp() + myCharacter.get_exp(); //원래 있던 exp + 추가로 얻은 exp

				 //캐릭터에 money값과 exp 값을 재설정 시켜준다 (REWARD)
				myCharacter.set_money(plus_money);
				myCharacter.set_exp(plus_exp);

				save_character(myCharacter, myInventory, wMessage); //캐릭터 정보 저장

				return 1; //1을 반환한다. (1을 반환하면 마을로 돌아가는 겁니다.)
				
			}
			else if (map_num == 2) //일반 사냥터인 경우
			{
				int plus_money, plus_exp; 
				plus_money = nowMonster.get_money() + myCharacter.get_money();
				plus_exp = nowMonster.get_exp() + myCharacter.get_exp();
				
				myCharacter.set_money(plus_money);
				myCharacter.set_exp(plus_exp);

				return 1; //1을 반환한다. (1을 반환하면 마을로 돌아가는 겁니다.)
			}
		}
	}
}


