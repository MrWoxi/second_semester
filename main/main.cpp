// Copyright 2024 Marina Usova

#define EASY_EXAMPLE
#ifdef EASY_EXAMPLE

#include <iostream>
#include <iomanip>
#include "../lib_easy_example/easy_example.h"
#include "../lib_tvector/TVector.h"

int main() {
  TVector<int> vec(12);
  vec.print();
  return 0;
}

#endif  // EASY_EXAMPLE
