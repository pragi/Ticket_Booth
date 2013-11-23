#include <iostream>
#include <string>
#include <cassert>
#include "tinyxml.h"
#include "Venue_from_Xml.h"
#include "Venue.h"
#include "Command_Processor.h"
using namespace std;

void Display_Data(Venue** venues, int nr_venues)
{
	for (int i = 0; i < nr_venues; ++i)
	{
		venues[i]->Display_All();
	}
}

int main(void)
{
	cout << "This is Ticket Booth 1\n\n";

	Venue* venues[50];
	int nr_venues = 0;
	nr_venues = Venue_from_Xml::Get_Venues(venues);
	//Display_Data(venues, nr_venues);

	Command_Processor::Process_Commands(venues, &nr_venues);

 //   Venue* venue[10];

 //   cout << "This is Ticket_Booth_0\n\n";
 //   string filename = "Venues.xml";
 //   TiXmlDocument doc(filename);

 //   bool loadOkay = doc.LoadFile();
 //   if (!loadOkay)
 //   {
 //       cout << "Could not load file " << filename << endl;
 //       cout << "Error='" << doc.ErrorDesc() <<"'. Exiting.\n";
 //       cin.get();
 //       exit( 1 );
 //   }

 //   TiXmlNode* venue_file_node = doc.FirstChild("venue_file");
	//assert(venue_file_node != 0);
 //   //cout << venue_file_node->Value() << endl;

	//TiXmlNode* venue_node = venue_file_node->FirstChild();
	//while (venue_node != 0)
	//{
	//	int i =0;
 //   
	//	assert(venue_node != 0);
	//	//cout << venue_node->Value() << endl;
 //   
	//	venue[i] = Venue_from_Xml::Get_Venue(venue_node);

	//	venue[i++]->Display_All();

	//	venue_node = venue_node->NextSibling();
	//}

	cout << "Normal Termination\n";
	cin.get();
	cin.get();
    return 0;
}
