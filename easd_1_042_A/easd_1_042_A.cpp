// 1. karena untuk menyelesaikan masalah kita harus membuat sebuah program yang dimana untuk membuat program tersebut harus 
//	  membuat suatu algoritma terlebih dahulu setelah itu baru diimplementasikan
// 2. - static example array
//	  - Dynamix example linked list
// 3. berikut faktor faktor yang mempengaruhi waktu ialah compiler, operating system, programming language,size of the input
// 4. Merge Sort karena ia membagi data menjadi 2 sehingga menjadi efisien untuk memilah data yang besar
// 5. quadratic bubble sort, insertion sort, shell sort dan log linear quicksort, merge sort, heap sort
// 6. 

#include <iostream>
using namespace std;

// array of integers to hold values
int abrar[62];
int cmp_count = 0; // number of comparasion
int mov_count = 0; // number of data movements
int n;

void input() {
	while (true)
	{
		cout << "masukan panjang element array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
		cout << "\nmaksimum panjang array adalah 20" << endl;
	}

	cout << "\n==================" << endl;
	cout << "\nenter array element" << endl;
	cout << "\n==================" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> abrar[i];
	}
}
// swaps the element at index x with the element at index y
void swap(int x, int y)
{
	int temp;

	temp = abrar[x];
	abrar[x] = abrar[y];
	abrar[y] = temp;
}

void m_short(int low, int high)
{
	int pivot, i, ab;
	if (low > high)														// langkah 1
		return;

	//partition the list into two parts:
	//one containing elements less that or equal to pivot
	//outher containning element greather than pivot

	pivot = abrar[low];													// langkah 2

	i = low + 1;														// langkah 3
	ab = high;															// langkah 4


	while (i <= ab)														// langkah 10
	{
		//search for an element greater than pivot
		while ((abrar[i] <= pivot) && (i <= high))						// langkah 5
		{
			i++;														// langkah 6
			cmp_count++;
		}
		cmp_count++;
		//search for an element less than or equal to pivot
		while ((abrar[ab] > pivot) && (ab >= low))						// langkah 7
		{
			ab--;														// langkah 8
			cmp_count++;
		}
		cmp_count++;

		// langkah 9
		if (i < ab)	// if the greater element is on the left of the element
		{
			//swap the element at index i whit the element at index j
			swap(i, ab);
			mov_count++;
		}
	}
	//j now containt the index of the last element in the sorted list
	if (low < ab)														// langkah 11
	{
		//move the pivot to its correct position in the list
		swap(low, ab);
		mov_count++;
	}
	//sort the list on the left of pivot using quick sort
	m_short(low, ab - 1);												// langkah 12

	//sort the list on the right of pivot using quick sort
	m_short(ab + 1, high);												// langkah 13


}


void display() {
	cout << "\n------------------" << endl;
	cout << "sorted array" << endl;
	cout << "------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << abrar[i] << " ";
	}

	cout << "\n\Number of comparasions: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}

int main()
{

	input();
	//sort the array using quick sort
	m_short(0, n - 1);
	display();
	system("pause");

	return 0;
}
