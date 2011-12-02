/*
 * Sort Class
 * Author: Jonathan Limpalair
 */

#ifndef SORT_H
#define SORT_H

#include <iostream>
using namespace std;

class Sort
{
private:
  int *data;
  int cnt;
  int size;
  string file, file2;

public:
  //constructors and destructors
  Sort(int s, string f); //parametric constructor, creates array of size s and assigns values from file f
  ~Sort(); //destructor

  //sorts and sort helper methods
  void QuickSort(int a, int b);
  void swap(int a, int b);
  void MergeSort(int *A, int n);
  void Merge(int *B, int *C, int *A, int n, int p, int q);

  void display() const; //displays data
  int* getData(); //returns data array pointer
  void write(string f2);
};

#endif //SORT_H
