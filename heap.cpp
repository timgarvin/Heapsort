//Tim Garvin

#include "sort.h"

//Initializes constructor and variables
Heap::Heap()
{
	heap_data = new int;

	data_size = 0;

	sorted_data = new int;
};

//Initializes heap size, heap array, and the sorted array based on user input
void Heap::initialize_heapdata(int size)
{
	data_size = size+1;

	heap_data = new int[size+1];

	//Loops through the heap array to initialize values
	for(int index = 0; index < size; index++)
	{
		if(index == 0) //Gives the first element the value of the heap's size
		{
			heap_data[index] = size;
		}
		else //Gives all other elements the value of 0
		{
			heap_data[index] = 0;
		}
	}

	sorted_data = new int[size];

	//Loops through initialized sorted array to set all elements to the value of 0
	for(int index = 0; index < size; index++)
	{
		sorted_data[index] = 0;
	}
}

//Inserts a value in the heap
void Heap::insert(int index, int data)
{
	heap_data[index] = data;
}

//Deletes the root node and sorts the array
void Heap::delete_max()
{
	cout<<"(";

	//Loops to display array output
	for(int i = 1; i < data_size; i++)
	{
		cout<<heap_data[i];

		if(i+1 == data_size)
		{
			cout<<")";
		}
		else
		{
			cout<<",";
		}
	}

	if(sorted_data[0] == 0) //Sets the first value in the sorted array to the first root node
	{
		sorted_data[0] = heap_data[1];
	}
	else
	{
		//Loops to add the next root node in the sorted array
		for(int i = 0; sorted_data[i] != 0; i++)
		{
			if(sorted_data[i+1] == 0)
			{
				sorted_data[i+1] = heap_data[1];
				break;
			}
		}
	}

	if(data_size > 1) //Checks that the heap is not empty
	{
		data_size--;
		
		int new_array[data_size];
	
		new_array[0] = data_size; //Sets the first value in the new array to size

		//Loops through the heap to set up for the new heap
		for(int i = 1; i < data_size; i++)
		{
			if(i == 1)
			{
				new_array[i] = heap_data[data_size]; //Sets new array's first value to the furthest right leaf child from the heap array to 
			}
			else
			{
				new_array[i] = heap_data[i]; //Sets new array's other values after the root node to the same heap values
			}
		}

		for(int i = 0; i < data_size; i++)
		{
			heap_data[i] = new_array[i];
		}
	}
};

//Helps convert the array back into a heap after insertion or deletion
void Heap::heapify(int data[], int index)
{
	int largest_index = index;
	int left_child_index = index*2;
	int right_child_index = index*2+1;

	//Sets largest_index to the index of the left child when left_child_index has a larger value
	if(left_child_index < data_size && data[left_child_index] >= data[largest_index])
	{
		largest_index = left_child_index;
	}
	
	//Sets largest_index to the index of the right child when right_child_index has a larger value
	if(right_child_index < data_size && data[right_child_index] > data[largest_index])
	{
		largest_index = right_child_index;
	}

	//Swaps values with the current index when largest_index has changed
	if(largest_index != index)
	{
		int temp = data[index];
		data[index] = data[largest_index];
		data[largest_index] = temp;

		heapify(data, largest_index);
	}
};

//Converts the array back into a heap after insertion
void Heap::bubble_up(int data[])
{
	//Loops until end of the heap is reached
	//for(int index = data_size/2; index >= 1; index--)
	for(int index = data_size-1; index > 1; index--)
	{
		heapify(data, index-1); //Swaps values when the parent node is smaller than the current node
	}
};

//Converts the array back into a heap after deletion
void Heap::bubble_down(int data[])
{
	//Loops until end of the heap is reached
	for(int index = 1; index <= data_size; index++)
	{
		heapify(data, index); //Swaps values when the current parent node is smaller than one or both of its children
	}
};

//Returns the heap array
int* Heap::get_data()
{
	return heap_data;
};

//Checks if the heap is empty or not
bool Heap::isEmpty()
{
	if(data_size == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
};

//Destructor used to clear allocated memory
Heap::~Heap()
{
	delete [] heap_data;

	delete [] sorted_data;
};