#include <iostream>
#include <cstdlib>

using namespace std;

int count_number = 0; // 퀸을 놓는 방법의 수
int chessboard[15];   // 체스판

bool Queen_check(int x) { // 새로운 퀸을 자리에 놓을 수 있는지 판별
  for(int i = 0; i < x; i++)
    if(chessboard[x] == chessboard[i] || x-i == abs(chessboard[x] - chessboard[i]))
      return 0;
  return 1;
}

void N_Queen(int n, int x) { // x = x좌표
  if(x == n)
    count_number++; // 모든 퀸을 다 놓았을 때 횟수 증가
  else {
    for(int y = 0; y < n; y++) { // y = y좌표
      chessboard[x] = y;  // 새로운 퀸을 놓음
      if(Queen_check(x))  // 새로운 퀸이 조건을 만족하는지 확인
        N_Queen(n, x+1);  // 만족하면 다음 퀸으로 이동
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