// Declaration of libraries

#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <stdlib.h>
#include <graphics.h>
#include <stdio.h>
#include <dos.h>


// Function related to sorting in class sorting
class sorting
{
int array[50],array1[50],final[100],i,n,m,j;
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
void Mer_sort();// Function to perform shell sort
void Shell_sort();
// Function to split the array into two halves during quick sort
void partition(int array[], int beg, int end, int *loc);
// Function to called recursively partition itself
void quick_sort(int array[], int n, int l, int u);
// Function to draw a box at front screen
void box(int x1, int y1, int x2, int y2);
};

// This function is used to display the sorted elements
// from every sorting technique.
void sorting::display()
{
int row =7;
//
box(2, 1, 75, 24);
gotoxy(50, 4);
cout << " Sorted array \n";
gotoxy(49, 5);
cout << "******************";
for (i = 0; i < n; i++)
{
gotoxy(50, row);
cout << (i+1) << " Element is = ";
gotoxy(65, row);
cout << array[i];
row++;
}}

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

// Function which create a heap for heap sort
void sorting::heap(int array[], int n)
{
int counter;
// Bitwise right shift
counter = (n-1) >> 1;
for (i = counter; i >= 0; i--)
below_heap(array, i, n-1);
}

//MAIN PROGRAM

void main()
{



}
