// Declaration of libraries

#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <stdlib.h>
#include <graphics.h>
#include <stdio.h>
#include <dos.h>

// Function related to sorting in class sorting
class  sorting
{
		int  array[50],array1[50],final[100],i,n,m,j;
	public:
		// Function to read an array
		void read();

		// Function to read arrays for merge sort
		void read_mer();

		// Function to display an array
		void display();

		// Function to perform bubble sort
		void bub_sort();

		// Function to perform selection sort
		void Sel_sort();

		// Function to perform insertion sort
		void Ins_sort();

		// Function to perform quick sort
		void Qui_sort();

		// Function to perform heap sort
		void Heap_sort();

		// Function to build a heap
		void heap(int array[], int n);

		// Function to interchange the value of root node with a
		// child node in heap sort
		void below_heap(int array[], int first, int last);

		// Function to perform merges sort
		void Mer_sort();

		// Function to perform shell sort
		void Shell_sort();

		// Function to split the array into two halves during quick sort
		void partition(int array[], int  beg, int end, int *loc);

		// Function to called recursively partition itself
		void quick_sort(int array[], int n, int l, int u);

		// Function to draw a box at front screen
		void box(int x1, int y1, int x2, int y2);
};

// Function to draw box at the time of menu display

void sorting::box(int x1, int y1, int x2, int y2)
{
	for (int col = x1; col < x2; col++)
	{
		gotoxy(col, y1);
		cprintf("%c", 196);
		gotoxy(col, y2);
		cprintf("%c", 196);
	}

	for (int row = y1; row < y2; row++)
	{
		gotoxy(x1, row);
		cprintf("%c", 179);
		gotoxy(x2, row);
		cprintf("%c", 179);
	}

	gotoxy(x1, y1);
	cprintf("%c", 218);
	gotoxy(x1, y2);
	cprintf("%c", 192);
	gotoxy(x2, y1);
	cprintf("%c", 191);
	gotoxy(x2, y2);
	cprintf("%c", 217);
}

// This function is used to read the values in an array having n elements

void sorting::read()
{
	int row = 7;
	box(2, 1, 75, 24);
	gotoxy(24, 2);
	cout << "Enter how many elemnets =  ";
	cin >> n;
	gotoxy(13, 4);
	cout << " Input array ";
	gotoxy(12, 5);
	cout<<"****************";
	for (i = 0; i < n; i++)
	{
		gotoxy(10, row);
		cout << " Enter " << (i+1) << " element = ";
		gotoxy(30, row);
		cin >> array[i];
		row++;
	}
}

/* Function to read arrays for merge sort. */
void sorting::read_mer()
{
	int row = 8;

	box(2, 1, 75, 24);


	gotoxy(20, 2);
	cout << "Enter elements in First Array  =  ";
	cin >> n;
	gotoxy(20, 3);
	cout << "Enter elemnets in second Array =  ";
	cin >> m;
	gotoxy(24, 22);
	cout << "Note:- Please enter sorted data \n";

	gotoxy(17, 5);
	cout<<"---------------------------------------";
	gotoxy(6, 6);
	cout << " IST Array";
	gotoxy(5, 7);
	cout << "************";
	for (i = 0; i < n; i++)
	{
		gotoxy(6, row);
		cout << (i+1) << " element = ";
		gotoxy(18, row);
		cin >> array[i];
		row++;
	}

	row = 8;

	gotoxy(25, 6);
	cout << " IIND Array";
	gotoxy(24, 7);
	cout << "*************";
	for (i = 0; i < m; i++)
	{
		gotoxy(25, row);
		cout <<  (i+1) << " element = ";
		gotoxy(39, row);
		cin >> array1[i];
		row++;
	}
}

// This function is used to display the sorted elements
// from every sorting technique.
void sorting::display()
{
	int row =7;

//	box(2, 1, 75, 24);

	gotoxy(50, 4);
	cout << "  Sorted array  \n";

	gotoxy(49, 5);
	cout << "******************";

	for (i = 0; i < n; i++)
	{
		gotoxy(50, row);
		cout << (i+1) << " Element is = ";
		gotoxy(65, row);
		cout << array[i];
		row++;
	}
}

// This is the method of sorting by which the array element
// are interchanged within its relative values
void sorting::bub_sort()
{
	int temp, j;
	// Reads the array elements
	read();

	for (i = 0; i < n - 1; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if (array[i] > array[j])
			{

				temp = array[i];
				array[i] = array[j];
				array[j] = temp;

			}
		}
	}

	gotoxy(25, 18);
	textbackground(MAGENTA);
	textcolor(5+143);
	cprintf(" RESULT OF BUBBLE SORT ");
	textbackground(BLACK);
	textcolor(2);

	// Displays the arrays elements
	display();
	getch();
}

// This function is used to perform the quick sort
void sorting::Qui_sort()
{
	// Inputs the array elements for quick sort
	read();

	// For quick sort
	quick_sort(array, n, 0, n-1);

	gotoxy(25, 18);
	textbackground(MAGENTA);
	textcolor(5+143);
	cprintf(" RESULT OF QUICK SORT ");
	textbackground(BLACK);
	textcolor(2);

	// Displays the sorted elements using the display() function
	display();

	getch();
}

// This function performs the partition changing in the array
// by the quick sort method
void sorting::quick_sort(int array[], int n, int l, int u)
{
	int loc;

	if (l < u)
	{

		partition(array, l, u, &loc);
		quick_sort(array, n, l, loc-1);
		quick_sort(array, n, loc+1, u);

	}
}

// Function to perfrom the partition in the array for quick sort

void sorting::partition(int array[], int  beg, int end, int *loc)
{
	int first, last, flag, temp;

	*loc = first = beg;

	last = end;
	flag = 0;

	while (!flag)
	{
		while (array[last] >= array[*loc] && (*loc != last))
			last --;

		if (*loc == last)
			flag = 1;
		else
		{

			if (array[*loc] > array[last])
			{

				temp = array[*loc];
				array[*loc] = array[last];
				array[last] = temp;
				*loc = last;

			}
		}

		if (!flag)
		{

			while ((array[first] <= array[*loc]) && (*loc != first))
				first++;

			if (*loc == first)
				flag = 1;
			else
			{
				if (array[*loc] <array[first])
				{

					temp = array[*loc];
					array[*loc] = array[first];
					array[first] = temp;
					*loc = first;

				}
			}
		}
	}
}

// Function is used to perform the heap sort technique
void sorting::Heap_sort()
{
	// Reads the elements in array
	read();

	int temp;

	heap(array, n);

	for (i = n-1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		below_heap(array, 0, i-1);
	}

	gotoxy(28, 18);
	textbackground(MAGENTA);
	textcolor(5+143);
	cprintf(" RESULT OF HEAP SORT ");
	textbackground(BLACK);
	textcolor(2);

	// Displays the elemnts
	display();
	getch();
}

// Function which create a heap for heap sort
void sorting::heap(int array[], int n)
{
	int counter;

	// Bitwise right shift
	counter = (n-1) >> 1;

	for (i = counter; i >= 0; i--)
		below_heap(array, i, n-1);
}

// Function is used to create lower heap in array for heap sort
void sorting::below_heap(int array[], int first, int last)
{
	int count, l_child, r_child, max, temp;

	if (first == 0)
		l_child = 1;
	else
		// Bitwise left shift
		l_child = first << 1;

	r_child = l_child + 1;

	if (l_child <= last)
	{
		max = array[l_child];
		count = l_child;
		if (r_child <= last)
		{
			if (array[r_child] > max)
			{
				max = array[r_child];
				count = r_child;
			}
		}

		if (array[first] < array[count])
		{
			temp = array[first];
			array[first] = array[count];
			array[count] = temp;
			below_heap(array, count, last);
		}
	}
}

// Function is used to make selection sort in an array
void sorting::Sel_sort()
{
	// Reads the array elements for selection sort
	read();

	int small;
	int pos;

	for (i = 0; i < n-1; i++)
	{
		small= array[i];
		pos = i;

		for(int j = i+1 ; j < n; j++)
		{

			if (array[j] < small)
			{
				small = array[j];
				pos = j;
			}
		}

		if ( pos != i)
		{
			int temp = array[i];
			array[i] = array[pos];
			array[pos] = temp;
		}
	}

	gotoxy(28, 18);
	textbackground(MAGENTA);
	textcolor(5+143);
	cprintf(" RESULT OF SELECTION SORT ");
	textbackground(BLACK);
	textcolor(2);

	// Displays the sorted elements
	display();
	getch();
}

// Function is used to perform the shell sort in an array
void sorting::Shell_sort()
{
	// Reads the elements for shell sort
	read();

	int temp;
	for (int inc = n/2; inc>0; inc /= 2)

	for (int i = inc; i < n; i++)
	{

		temp = array[i];
		for (int j = i;j >= inc && temp < array[j-inc]; j -= inc)
			array[j] = array[j-inc];
		array[j] = temp;
	}

	gotoxy(20, 18);
	textbackground(MAGENTA);
	textcolor(5+143);
	cprintf(" RESULT OF SHELL SORT");
	textbackground(BLACK);
	textcolor(2);

	// displays the sorted elements
	display();
	getch();
}


// Function is used to perform insertion sort
void sorting::Ins_sort()
{
	int temp;

	read();

	for (int i = 1; i < n; i++)
	{
		temp = array[i];
		for (int j = i; temp < array[j-1]; j--)
			array[j] = array[j-1];
		array[j] = temp;
	}

	gotoxy(28, 18);
	textbackground(MAGENTA);
	textcolor(5+143);
	cprintf(" RESULT OF INSERTION SORT ");
	textbackground(BLACK);
	textcolor(2);

	// Displays the sorted elements
	display();
	getch();
}

// Function is used to perfrom merge sort in two arrays
void sorting::Mer_sort()
{
	int row = 8;
	// Reads the elements in different arrays
	read_mer();

	i = j = 0;
	int k = 0;

	while ((i < n) && (j < m))
	{

		if (array[i] < array1[j])
		{

			final[k] = array[i];
			k = k + 1;
			i = i + 1;

		}
		else
		{

			final[k] = array1[j];
			k = k + 1;
			j = j + 1;

		}
	}

	while (i < n)
	{
		final[k] = array[i];
		k = k + 1;
		i = i + 1;
	}

	while (j < m)
	{
		final[k] = array1[j];
		k = k + 1;
		j = j + 1;
	}

	gotoxy(28, 18);
	textbackground(MAGENTA);
	textcolor(5+143);
	cprintf(" RESULT OF MERGE SORT");
	textbackground(BLACK);
	textcolor(2);
	gotoxy(50, 6);
	cout << " Sorted array  \n";
	gotoxy(49, 7);
	cout << "******************";
	int t = m + n;

	for (i = 0; i < t; i++)
	{
		gotoxy(50, row);
		cout << (i+1) << " Element is = ";
		gotoxy(65, row);
		cout << final[i];
		row++;
	}
	getch();

}


typedef char option[15];

char menu();

void grap_screen();
void end();



// MAIN PROGRAM
void main()
{

	char choice;
	sorting  sort;
	// To display the first screen of sort techniques
//	grap_screen();

	do
	{
		choice = menu();

		clrscr();
		switch (choice)
		{
			case '1':

				sort.bub_sort();
				break;

			case '2':

				sort.Heap_sort();
				break;

			case '3':

				sort.Sel_sort();
				break;

			case '4':

				sort.Ins_sort();
				break;

			case '5':

				sort.Qui_sort();
				break;

			case '6':

				sort.Mer_sort();
				break;

			case '7':

				sort.Shell_sort();
				break;

			default :
				end();
				exit(0);

		}
	} while (choice != 0);

}

// Function used to do screening
void normalvideo(int x, int y, char *str)
{
   gotoxy(x, y);
   cprintf("%s", str);
}

// Function to reverse the video
void reversevideo(int x, int y, char *str)
{
	 textcolor(RED);
	 textbackground(WHITE);

	 gotoxy(x, y);
	 cprintf("%s", str);
	 textcolor(GREEN);
	 textbackground(BLACK);
}

// Function to display the main menu

char menu()
{
	clrscr();
	int i, done;

	sorting sort;

	option a[]=
			{
				" Bubble-Sort",
				"  Heap-sort ",
				"Selection-Sort",
				"Insertion-Sort",
				"  Quick-sort",
				"  Merge-sort",
				"  Shell_sort",
				"     Quit   "
			};

	clrscr();
	sort.box(20, 6, 65, 20);
	sort.box(18, 4, 67, 22);
	textcolor(5+143);
	gotoxy(30, 5);
	textbackground(WHITE);
	cprintf("S O R T I N G  -  M E N U");
	textbackground(BLACK);
	textcolor(22);

	for (i = 1; i < 8; i++)
		normalvideo(32, i+8, a[i]);

	reversevideo(32, 8, a[0]);
	reversevideo(32, 8, a[0]);

	i = done = 0;
//	_setcursortype(_NOCURSOR);

	do
	{
		int key = getch();

		switch (key)
		{
			case 00:

				key = getch();

				switch (key)
				{
					case 72:

						normalvideo(32, i+8, a[i]);
						i--;
						if (i == -1)
							i = 7;

						reversevideo(32, i+8, a[i]);
						break;

					case 80:

						normalvideo(32, i+8, a[i]);
						i++;

						if (i == 8)
							i = 0;
						break;
				}
				break;

			case 13:
				 done = 1;
		}
	} while (!done);

  //	_setcursortype(_NOCURSOR);
	return(i+49);
}
						reversevideo(32, i+8, a[i]);
						break;
				}
				break;

			case 13:
				 done = 1;
		}
	} while (!done);

  //	_setcursortype(_NOCURSOR);
	return(i+49);
}
