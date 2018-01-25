//Tim Garvin

#include "sort.h"

int main()
{
	//Instantiates a class Sort object
	Sort* heapsort;
	heapsort = new Sort();

	//Loops class Sort until the user types 'quit'
	while(heapsort->get_command() != "quit")
	{
		heapsort->user_entry(); //Gets the command and heap data from the user
		heapsort->sort(); //Sorts the heap
		heapsort->reset_values(); //Resets values for next sort
	}

	return 0;
}