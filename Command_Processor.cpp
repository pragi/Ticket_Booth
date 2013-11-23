#include <iostream>
#include "Command_Processor.h"
#include "Menu.h"
using namespace std;

Command_Processor::Command_States
	Command_Processor::command_state = Initial;

Venue** Command_Processor::venues = 0;
Venue* Command_Processor::selected_venue = 0;
int* Command_Processor::nr_venues = 0;

Menu* Command_Processor::menus[NR_VENUES];

void Command_Processor::Process_Commands(Venue** venues_, int* nr_venues_)
{
	cout <<"Process_commands starting\n";
	venues = venues_;
	nr_venues = nr_venues_;
	Create_Menus();

	while (command_state != Done)
	{
		//const string* cmd = menus[command_state]->Get_Command();
		const string* cmd;
		switch (command_state)
		{
		case Initial:	cmd = menus[command_state]->Get_Command();
						Process_Command_0(*cmd);
						break;

		case Venue_Selected:	cout << endl << "Selected Venue is "
									<< selected_venue->Name() << endl;
								cmd = menus[command_state]->Get_Command();
								Process_Command_1(*cmd);
								break;

		case Done: break;
		command_state = Done;
		}
	}

	cout << "Process_Commands exiting\n";
}

void Command_Processor::Create_Menus()
{
	// for initial command state
	Menu* menu = new Menu("Enter command number:\n");
	menu->Add_Command("Select Venue");
	menu->Add_Command("Quit");
	menus[0] = menu;

	//Menu for Venue Selected
	menu = new Menu("Enter command number:\n");
	menu->Add_Command("Display Venue");
	menu->Add_Command("Select Show");
	menu->Add_Command("Change Venue");
	menu->Add_Command("Quit");
	menus[1] = menu;
}

void Command_Processor::Select_Venue()
{
	Menu* menu = new Menu("Select Venue");
	for (int i = 0; i <*nr_venues; ++i)
	{
		menu->Add_Command(venues[i]->Name());
	}

	menu->Add_Command("Cancel");

	const string* venue_name = menu->Get_Command();

	if (*venue_name == "Cancel")
	{
		command_state = Initial;
		//cout << "cancel called\n";
		return;
	}
	else
	{
		for (int i = 0; i <*nr_venues; ++i)
		{	
			if (venues[i]->Name() == *venue_name)
			{
				selected_venue = venues[i];
				command_state = Venue_Selected;
				delete menu;
				return;
			}
		}
	}
	cout << "Error in Command_Processor::Select_Venue()\n";
}


void Command_Processor::Process_Command_0(const string& cmd)
{
	if (cmd == "Select Venue")
	{
		// select venue
		//cout << "Select Venue command\n";
		Select_Venue();
		
		if (command_state == Initial)
			command_state = Initial;
		else
			command_state = Venue_Selected;
	}
	else if (cmd == "Quit")
	{
		//cout << "Quit command\n";
		command_state = Done;
	}
}

void Command_Processor::Process_Command_1(const string& cmd)
{
	if (cmd == "Display Venue")
	{
		// Display venue
		cout << "Display venue command\n";
		selected_venue->Display_All();
	}
	else if (cmd == "Select Show")
	{
		// select show
		cout << "Select show command\n";
	}
	else if (cmd == "Change Venue")
	{
		//cout << "Change Venue command\n";
		command_state = Initial;
	}
	else
	{
		cout << "Quit command\n";
		command_state = Done;
	}
}