#pragma once
#include <string>
using namespace std;

class Menu
{
public:
	static const int MAX_COMMANDS = 10;

private:
	string* commands[MAX_COMMANDS];
	int nr_commands;
	const string prompt;

public:
	Menu(const string& prompt_);
	~Menu(void);
	void Add_Command(const string& cmd);

	const string* Get_Command(void) const;
};