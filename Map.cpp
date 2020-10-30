
#include "Map.h"

Map::Map()
{
}

Map::~Map()
{
}

Map Map::load_map(string s)
{
	map_integrity_check check;
	vector<int> load_datas;
	vector<int> temp_linked_map;
	vector<int> temp_item_list;
	warningMessage msg;
	int Flag;
	load_datas = check.load_set(s);
	Flag = load_datas[0];

	if(Flag == 2 || Flag ==0)		//warning or success
	{
		int list_size_1 = load_datas[1];
		int list_size_2 = load_datas[2];
		set_map_num(load_datas[3]);
		for (int i = 3+1; i < 3 + list_size_1; i++) {
			temp_linked_map.push_back(load_datas[i]);
		}
		set_linked_map(temp_linked_map);
		set_level_limit(load_datas[3 + list_size_1]);
		set_map_type(load_datas[3 + list_size_1 + 1]);
		set_monster_num(load_datas[3 + list_size_1 + 2]);
		for (int j = 3 + list_size_1 + 4; j < load_datas.size(); j++) {
			temp_item_list.push_back(load_datas[j]);
		}
		set_item_list(temp_item_list);
		if (Flag == 2) {
			msg.printWarning(1, 1);
		}
		return *this;
	}
	else                    //error
	{
		msg.printWarning(0, 1);
		return *this;
	}
}

void Map::set_map_num(int map_num)
{
	this->map_num = map_num;
}

void Map::set_map_type(int map_type)
{
	this->map_type = map_type;
}

void Map::set_level_limit(int level_limit)
{
	this->level_limit = level_limit;
}

void Map::set_monster_num(int monster_num)
{
	this->monster_num = monster_num;
}

void Map::set_item_list(vector<int> item_list)
{
	this->item_list = item_list;
}

void Map::set_linked_map(vector<int> linked_map)
{
	this->linked_map = linked_map;
}

int Map::get_map_num()
{
	return this->map_num;
}

int Map::get_map_type()
{
	return this->map_type;
}

int Map::get_level_limit()
{
	return this->level_limit;
}

int Map::get_monster_num()
{
	return this->monster_num;
}

vector<int> Map::get_item_list()
{
	return this->item_list;
}

vector<int> Map::get_linked_map()
{
	return this->linked_map;
}
