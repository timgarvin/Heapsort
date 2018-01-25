//Tim Garvin

#include "sort.h"

//Initializes constructor and variables
Sort::Sort()
{
	command = new string;
	*command = "none";
	
	num_elements = new int;

	valid_entry = new bool;
	*valid_entry = true;
	
	heap = new Heap();
};

//Sets values based on user input
void Sort::user_entry()
{
	cout<<"heapsort> ";
	cin>>*command;

	check_command(); //Validates command entered

	//Checks if command is valid and if the next character is a space
	if(*valid_entry == true && cin.peek() == ' ')
	{
		cin>>*num_elements;

		heap->initialize_heapdata(*num_elements);
	}

	int data;

	//Loops to add data to the heap until there is no more data to add
	for(int i = 1; *valid_entry == true && cin.peek() == ' '; i++)
	{
		cin>>data;

		heap->insert(i, data); //Inserts data into the heap array

		if(i > 1)
		{
			heap->bubble_up(heap->get_data()); //Converts the array into a heap after insertion
		}
	}
};

//Sorts the heap
void Sort::sort()
{
	//Checks if the command is 'sort' and whether user entry is valid so far
	if(*command == "sort" && *valid_entry == true)
	{
		//Loops while heap is not empty
		while(heap->isEmpty() != true)
		{
			heap->delete_max(); //Deletes root node of the heap
			heap->bubble_down(heap->get_data()); //Converts the array back into a heap after deletion
		}

		cout<<endl;
	}
};

//Gets the command value
string Sort::get_command()
{
	return *command;
};

//Checks if user entered a valid command
bool Sort::check_command()
{
	if(*command != "quit" && *command != "sort")
	{
		cout<<"Error! Command not supported."<<endl;
		*valid_entry = false;
		return false;
	}
	else
	{
		return true;
	}
};

//Resets values for next command
void Sort::reset_values()
{
	*valid_entry = true;
};

//Destructor used to clear allocated memory
Sort::~Sort()
{
	delete command;
	delete num_elements;
	delete heap;
	delete valid_entry;
};