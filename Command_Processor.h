#pragma once
#include "Menu.h"
#include "Venue.h"
#include <string>
using namespace std;

class Command_Processor
{
public:
	static void Process_Commands(Venue** venues_, int* nr_venues_);

private:
	enum Command_States {Initial, Venue_Selected, Done};
	static const int NR_VENUES = (int) Done + 1;
	static Command_States command_state;
	
	static Menu* menus[NR_VENUES];

	static void Create_Menus();
	static void Select_Venue();
	static void Process_Command_0(const string& cmd);
	static void Process_Command_1(const string& cmd);

	Command_Processor(void) {};

	static Venue** venues;
	static Venue* selected_venue;
	static int* nr_venues;
	
	
};
