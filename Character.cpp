#include "Character.h"

Character::Character(Status status)
{   
    this->slot[10] = {0, };
}

Character::~Character()
{ 

}

Status Character::get_stat()
{
}


void Character:: show_stat()
{
    status.show();
}

void Character:: attack()
{


}

void Character:: sort_slot()
{
    int temp;
    for (int i = 1; i<10; i++){
        int pre = this->slot[i-1];
        int cur = this -> slot[i];
        if((pre && cur) == 0){
            continue;
        }
        else if(pre == 0 && cur > 0){
            temp = cur;
            pre = temp;
            cur = pre;
        }

    }
}
 //Inventory open