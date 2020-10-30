
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "map_integrity_check.h"
#include "warningMessage.h"

using namespace std;

class Map {
private:
    int map_num;
    int map_type;
    int level_limit;
    int monster_num;
    map_integrity_check check;

    vector<int> item_list;
    vector<int> linked_map;

public:
    Map();

    ~Map();

    Map load_map(string);

    void set_map_num(int);

    void set_map_type(int);

    void set_level_limit(int);

    void set_monster_num(int);

    void set_item_list(vector<int>);

    void set_linked_map(vector<int>);

    int get_map_num();

    int get_map_type();

    int get_level_limit();

    int get_monster_num();

    vector<int> get_item_list();

    vector<int> get_linked_map();


};
