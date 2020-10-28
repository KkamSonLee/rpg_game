#pragma once
#include <string>
using namespace std;
class Town
{
public:
	int max_slot;
	Town();
	~Town();
	void choice();
	void help();
	void save(int);
	void quit();
	void load(int);
	void inventory();
	void move(string);
	void shop();
	void stat();
	bool is_digit(string);
};
