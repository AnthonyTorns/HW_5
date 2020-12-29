/*
 PSEUDOCODE:
 Bubble Sort:
 for(i less than the amount of elements){
  for(element after i is less than elements){
    if(element at i is greater than element behind it)
      swap = holds i;
      element at i = element following it
      position following position at i = swap
      swap = NULL;
 
InsertionSort:
variable = 1(will hold intiak position after first element)
int i = 0(intial starting point of vector)
varible to hold the value after the starting position of vec
call to Insertiin sort helper
 
 Inserertion Sort Helper:
 if(there are more variables to check)
    if (element at given position is greater than the follwoing element && i is not negative)
      following position of i is repelaced with position i's element
      i deincremeents to to move to preceding position or -1 if i = 0;
      call to InsertionSortHeleper
      element at i = swap element
      position that needs to be checked is incremeented
      i = position preceding start
      swap equals the value that needs to be checked
      call to InsertionSortHelepr
 
 Merge: vector passed by reference, start of vec, end of vec, and mid of vect
 left size = start to middle of vect + 1
 right size = mid to end of vect
 
 declare two vects(left and right)

 fill left vec with elements on left side
 fill right with elements on left side
 
 
 variable to hold left elements start position
 variable to hold right elements start position
 variable to hold merged eleemetns start position = left;
 while(left and right positions are less than leftsize and right size){
  if left element is <= right eleement
   merged eleement at given position eqaul left element
 else
   merged element at given position is right element
 
 while there are more elements in left or right vectors fill the rest of the merged array with those elements.
 
 MergeSortHelepr: vector passed by reference, beginining of vect, end of vect
 if (beginning < end)
   middle = begin + ending-beginning divided by 2
  call to MergeSortHelepr:vect, beggining, middle
  call to MergeSortHelepr: vect, middle+1, end
  call to Merge: vect, ending, beginning, middle

 MergeSort:
 start = 0
 end equal last position in vec
 call to MergeSortHelper: vect, start, end
 */
#include <iostream>
#include <string>
#include <vector>
void BubbleSort(std::vector<std::string> &vec) {
  const int elements = vec.size();
  std::string swap = "/0";
  for (int i = 0; i < elements; i++) {
    for (int j = i + 1; j < elements; j++) {
      if (vec[i].compare(vec[j]) > 0){
        swap = vec[i];
        vec[i] = vec[j];
        vec[j] = swap;
        swap = "/0";
      }
    }
  }
}

static void InsertionSortHelper(int start, int length, std::vector<int> &v, int i, int swap) {
  if (start < length) {
    if (v[i] > swap && i >= 0) {
      v[i+1] = v[i];
      i--;
      return InsertionSortHelper(start, length, v, i, swap);
    }
   // i++;
    v[i+1] = swap;
    start++;
    i = start - 1;
    swap = v[i+1];
    return InsertionSortHelper(start, length, v, i, swap);
  }
  
}

void InsertionSort(std::vector<int> &v)
{
  
  if (v.size() > 1) {
    int sorted_element = 1;
    int i = sorted_element - 1;
    int swap =  v[i+1];
    const int size = v.size();
    InsertionSortHelper(sorted_element, size, v, i, swap);
  }
}

void Merge(std::vector<std::string> &v, int left, int mid, int right) {
int left_size = mid - left + 1;
int right_size = right - mid;

std::vector<std::string> left_vector (left_size);
std::vector<std::string> right_vector (right_size);

for (int i = 0; i < left_size; i++) {
  left_vector[i] = v[i+left];
}
for (int j = 0; j < right_size; j++) {
  right_vector[j] = v[mid+1+j];
}

int f_sub = 0;
int s_sub = 0;
int m_sub = left;
while (f_sub<left_size && s_sub<right_size) {
  if (left_vector[f_sub].compare(right_vector[s_sub]) <= 0) {
    v[m_sub] = left_vector[f_sub];
    f_sub++;
  }
  else {
    v[m_sub] = right_vector[s_sub];
    s_sub++;
  }
  m_sub++;
}

while (f_sub < left_size) {
  v[m_sub] = left_vector[f_sub];
  m_sub++;
  f_sub++;
}

while (s_sub < right_size) {
  v[m_sub] = right_vector[s_sub];
  m_sub++;
  s_sub++;
  
}

}
static void MergeSortHelper(std::vector<std::string> &vect, int begin, int ending) {
  if (begin<ending) {
    int middle = begin + (ending-begin) /2;
    MergeSortHelper(vect, begin, middle);
    MergeSortHelper(vect, middle+1, ending);
    Merge(vect, begin, middle, ending);
  }
}

void MergeSort(std::vector<std::string> &vec) {
  int start = 0;
  int end = vec.size() - 1;
  MergeSortHelper(vec, start, end);
  
}
