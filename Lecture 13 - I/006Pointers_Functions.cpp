#include<iostream>

using namespace std;

void increment1(int* ptr) { // passing addr by value since we are sending a copy of addr of a

  (*ptr)++;

}

void increment2(int*& ptrRef) { // passing addr by reference i.e. ptrRef is a new name for ptr

  (*ptrRef)++;

}

int main() {

  int a = 10;

  cout << "inside main(), before increment1() a = " << a << endl;

  increment1(&a);

  cout << "inside main(), after  increment1() a = " << a << endl;

  int b = 20;

  cout << "inside main(), before increment2() b = " << b << endl;

  int* ptr = &b;

  increment2(ptr);

  cout << "inside main(), after  increment2() b = " << b << endl;

  return 0;
}