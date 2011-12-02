/*
 * Main class for Sort
 * Author: Jonathan Limpalair
 *
 * Usage: ./Sort
 * When asked for file name, use syntax such as "file.txt"
 */

#include <iostream>
#include <string>
#include "Sort.h"

using namespace std;

/*
 * Main Function
 */
int main(int argc, char **argv)
{
  //variables
  string choice, file, file2;
  int size, check;
  
  //choose which sort
  cout << "Welcome to the sorting program by Jonathan Limpalair." << endl;
  cout << "Please choose which algorithm to sort with: (quicksort or mergesort)" << endl;
  cin >> choice;

  //keep track of which sort regardless of spelling
  if(choice == "quicksort" || choice == "Quicksort" || choice == "QuickSort" || choice == "qs" || choice == "QS") check = 1;
  else if(choice == "mergesort" || choice == "Mergesort" || choice == "MergeSort" || choice == "ms" || choice == "MS") check = 2;
  
  //check if choice is valid
  if(check == 1 || check == 2)
    cout << choice << " was chosen." << endl;
  else
  {
    cout << "Invalid choice." << endl;
    return(1);
  }
  
  //ask for array size and store it
  cout << "Enter the size of the array to be sorted: ";
  cin >> size;

  //check if size > 0
  if(size <= 0)
  {
    cout << "Size must be greater than 0. Now exiting." << endl;
    return(1);
  }
  
  if(check == 1) 
  {    
    //input input and output file names
    cout << "Now enter the file name containing integer numbers: ";
    cin >> file;
    cout << "Now enter the file name for the output: ";
    cin >> file2;

    //create Sort object
    Sort mySort(size, file);

    //output values entered
    cout << endl << "This is what you entered: " << endl;
    mySort.display();
  
    //sort values
    mySort.QuickSort(0, size-1);

    //display sorted array
    cout << endl << "The sorted array is:" << endl;
    mySort.display();
    
    //write output to output file
    mySort.write(file2);
    cout << endl << "Sorted list written to " << file2;
  }
  else if(check == 2)
  {    
    //input input and output file names
    cout << "Now enter the file name containing integer numbers: ";
    cin >> file;
    cout << "Now enter the file name for the output: ";
    cin >> file2;

    //create Sort object
    Sort mySort(size, file);

    //output values entered
    cout << endl << "This is what you entered: " << endl;
    mySort.display();
    
    //call getData() to pass as a parameter in MergeSort()
    int *array = mySort.getData();
    
    //sort
    mySort.MergeSort(array, size);

    //display sorted array
    cout << endl << "The sorted array is:" << endl;
    mySort.display();
    
    //write output to output file
    mySort.write(file2);
    cout << endl << "Sorted list written to " << file2;
  }
  
  //exit
  cout << endl;
  return(0);
}//end Main
