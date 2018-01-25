//Tim Garvin

class Heap
{
	private:
		int *heap_data;
		int data_size;
		int *sorted_data;
	public:
		Heap(); //constructor
		~Heap(); //destructor

		void initialize_heapdata(int size); //Declares function to initialize the heap array

		void insert(int index, int data); //Declares function to insert values in the heap
		void delete_max(); //Declares function to delete the root node and sort the array

		void heapify(int data[], int index); //Declares function that helps convert the array back into a heap
		void bubble_up(int data[]); //Declares function to convert the array back into a heap after insertion
		void bubble_down(int data[]); //Declares function to convert the array back into a heap after deletion

		int* get_data(); //Declares function that returns the heap array

		bool isEmpty(); //Declares function to check if the heap is empty or not
};