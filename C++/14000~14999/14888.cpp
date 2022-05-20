#include <iostream>

using namespace std;

int plus(int a, int b) {
  return a + b;
}

int minus(int a, int b) {
  return a - b;
}

int multiple(int a, int b) {
  return a * b;
}

int divide(int a, int b) {
  return a / b;
}

int findMaxResult(int n, int i, int* numbers, int* numOperators) {
  if(i == n) {
    return 17;
  }
}

int main(void) {
  int N;
  int* numbers;
  int numOperators[4];

  cin >> N;
  numbers = new int[N];
  for(int i = 0; i < N; i++)
    cin >> numbers[i];
  for(int j = 0; j < 4; j++)
    cin >> numOperators[j];

  
}