/*
 * Implementation of Sort class
 * Author: Jonathan Limpalair
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include "Sort.h"

using namespace std;

/*
 * Constructors and destructors
 */

//Parametric Constructor
Sort::Sort(int s, string f)
{
  size = s;
  file = f;

  //input file stream
  ifstream input;
	
  //opens input file
  input.open(file.c_str());
	
  //check to see if the file opened successfully
  if(input.fail())
  {
    //if file failed to open displays error message and exits program
    cout << "Error opening input file" << endl;
    exit(1);
  }

  //allocate memory
  data = new int [size];
  if(data == NULL)
  {
    cout << "[ERROR] Sort::allocateMemory -> Insufficient Memory" << endl;
    exit(1);
  }

  //set all values in array to values from file
  else
    {      
      //for loop for index i
      for(int i = 0; i < size; i++)
	{
          input >> data[i];
          //check if enough integers to satisfy demand
          if(input.eof() == 1)
          {
            cout << "File does not contain " << size << " elements. Now exiting." << endl;
            exit(1);
          }
	}
    }
  //closes the input file
  input.close();
}//end Sort::Sort

//destructor
Sort::~Sort()
{
  if(data != NULL)
    delete [] data;
}//end Sort::~Sort

/*
 * Quicksort
 */

void Sort::QuickSort(int start, int end)
{
  //variables
  int pivot = start;
  int i = start;
  int j = end;
  bool check;
  
  //keep going until it has gone through each element
  while(i<j)
  {
    //keep track of when to decrement i or j
    check = false;
    //compare pivot to values on the right
    if(pivot <= i)
    {
      //swap values if value at pivot is smaller than value at j and update pivot
      if(data[pivot] > data[j])
      {
        swap(pivot,j);
        pivot = j;
        ++i;
        check = true;
      }
      if (!check) --j;
    }
    //compare pivot to values on the left
    else if(pivot >= j)
    {
      //swap values if value at pivot is smaller than value at i and update pivot
      if(data[pivot] < data[i])
      {
        swap(i,pivot);
        pivot = i;
        --j;
        check = true;
      }
      if (!check) ++i;
    }
  }
  
  //recursion calls
  if(end > start)
  {
    QuickSort(start, pivot-1);
    QuickSort(pivot+1, end);
  }
}//end Sort::QuickSort

//swap helper method for quicksort
void Sort::swap(int s1, int s2)
{
  int tmp;
  tmp = data[s1];
  data[s1] = data[s2];
  data[s2] = tmp;
}//end Sort::swap

/*
 * MergeSort
 */

void Sort::MergeSort(int *A, int n)
{
  //only need mergesort if more than one element
  if(n > 1)
  {
    //variables
    int p = n-n/2;
    int q = n/2;

    //pointer arrays used to split A
    int *B = new int [p];
    int *C = new int [q];
    
    //copy each 'half' into seperate arrays
    for(int i = 0; i < p; i++)
    {
      int tmp = p+i;
      B[i] = A[i];
      if(i<q) C[i] = A[tmp];
    }

    //recursive calls
    MergeSort(B, p);
    MergeSort(C, q);

    //merge everything back together
    Merge(B, C, A, n, p, q);
  }
}//end Sort::MergeSort

//helper method for MergeSort to merge arrays back together, sorted
void Sort::Merge(int *B, int *C, int *A, int n, int p, int q)
{
  //variables
  int i, j, k;
  i=j=k=0;

  //loop through to sort by checking which value is larger
  while(i < p && j < q)
  {
    //if value at B is larger than value at C, 'pop out' value at B
    if(B[i] <= C[j])
    {
      A[k] = B[i];
      i++;
    }
    //if value at C is larger than value at B, 'pop out' value at C
    else
    {
      A[k] = C[j];
      j++;
    }
    k++;
  }

  //pop out leftover elements from C array
  if(i == p)
  {
    while(j < q)
    {
      A[k] = C[j];
      j++;
      k++;
    }
  }

  //pop out leftover elements from B array
  else
  {
    while(i < p)
    {
      A[k] = B[i];
      i++;
      k++;
    }
  }

  //copy array 'A' into main array 'data'
  for(int ii = 0; ii < size; ii++)
  {
    data[ii] == A[ii];
  }
}//end Sort::Merge

/*
 * IO
 */

//display array to stdout
void Sort::display() const
{
  for(int i = 0; i < size; ++i)
  {
    cout << data[i]<< " ";
  }
  cout << endl;
}//end Sort::display

/*
 * Getter
 */

int* Sort::getData()
{
  return data;
}//end Sort:getData

//write sort result into output file
void Sort::write(string f2)
{
  //variables
  file2 = f2;
  
  //creates ofstream, output stream object
  ofstream output;
  
  //opens the output file
  output.open(file2.c_str());

  //checks to see if the output file successfully opened
  if(output.fail())
  {
    //if output file did not open displays error message and exits
    cout << "Error opening output file" << endl;
    exit(1);
  }

  //writes to file all of the values for the image
  for(int i = 0; i < size; i++)
  {
    output << data[i] << " ";
  }

  //closes the output file
  output.close();
}
//End of write function for Image class









