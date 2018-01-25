//Tim Garvin

#include <iostream>
#include <string>
#include "heap.h"

using namespace std;

class Sort
{
	private:
		string *command;
		int *num_elements;
		Heap *heap;
		bool *valid_entry;
	public:
		Sort(); //constructor
		~Sort(); //destructor
		
		void user_entry(); //Declares function to get the command and heap data from the user
		void sort(); //Declares function to sort the heap

		string get_command(); //Declares function to get the command entered

		bool check_command(); //Declares function to validate the command entered

		void reset_values(); //Declares function to reset values for next sort
};