#include <iostream>
#include <vector>
#include <string>
#include "hw5.h"
void print(std::vector<std::string> &v) {
  std::cout << "[";
  bool first = true;
  for (auto x : v) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << x;
    first = false;
  }
  std::cout << "]";
  std::cout << std::endl;
}


void printnum(std::vector<int> &v) {
  std::cout << "[";
  bool first = true;
  for (auto x : v) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << x;
    first = false;
  }
  std::cout << "]";
  std::cout << std::endl;
}

int main() {
  std::vector<std::string> v;
  std::vector<int> num_v;
  num_v {
    4,
    3,
    2
  };
  v {
    "emma", 
    "dora", 
    "ruth", 
    "ziegellaub", 
    "eichler"
    };
  std::cout << "Case 1: ";
  BubbleSort(v);
  print(v);
  InsertionSort(num_v);
  std::cout << "Expected: [dora, eichler, emma, ruth, ziegellaub]" << std::endl;
  std::cout << "Case: 2: ";
  printnum(num_v);
  std::cout<< "Expected: [2, 3, 4]" <<std::endl;
}