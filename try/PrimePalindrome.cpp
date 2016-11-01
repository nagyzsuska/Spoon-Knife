//============================================================================
// Name        : PrimePalindrome.cpp
// Author      : Zsuzsanna Nagy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int reverseInt(int n);
bool isPalindrom(int n);
int decimalToBinary(int n); //from 0 to 1023
void palToArray(int n, int *array, int &index);

int main() {
  int primepal_array[5000];
  int index = 0;
  for (int num = 2; num < 1000000; num++) {
    if (isPalindrom(num)) {
      bool prime = true;
      for (int d = 2; d <= sqrt(num); d++) {
        if (num % d == 0) {
          prime = false;
          break;
        }
      }
      if (prime) {
        palToArray(num, primepal_array, index);
      }
    }
  }
  return 0;
}

int reverseInt(int n) {
  int temp = n;
  int counter = 0;
  do{
    temp /= 10;
    counter++;
  } while (temp > 0);
  int reverse = 0;
  for (int i = counter; i >= 0; i--) {
    reverse = reverse + n % 10 * pow(10, i);
    n = n / 10;
  }
  return reverse;
}

bool isPalindrom(int n) {
  return n==reverseInt(n);
}

int decimalToBinary(int n) { //from 0 to 1023
  int temp = n;
  int counter = 0;
    do{
      temp /= 2;
      counter++;
    } while (temp > 1);
  int binary =0;
  for (int i = 0; i <= counter; i++) {
    binary = binary + n % 2 * pow(10, i);
      n = n / 2;
  }
  return binary;
}

void palToArray(int n, int *array, int &index) {
  if (isPalindrom(n)) {
    array[index] = n;
    cout << array[index] << endl;
    index++;
  }
  if (index==3) {
    cout << "The 3. element in binary: " << decimalToBinary(n) << endl;
  }
}
