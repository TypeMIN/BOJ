#include <iostream>
#include <cstdlib>

using namespace std;

int count_number = 0;
int chessboard[15];

void N_Queen(int n, int x) { // x = x좌표
  if(x == n) {
    count_number++;
  }
  else {
    for(int y = 0; y < n; y++) { // y = y좌표
      for(int i = 0; i < x; i++)
        if(chessboard[x] == chessboard[i] || x - i == abs(chessboard[x]-chessboard[i]))
          return;
      chessboard[x] = y;
      N_Queen(n, x+1);
    }
  }
  return;
}

int main(void) {
  int N;

  cin >> N;
  N_Queen(N, 0);
  cout << count_number << '\n';
  return 0;
}