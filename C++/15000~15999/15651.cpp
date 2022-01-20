#include <iostream>

using namespace std;

int M; // sequence 함수 안에서도 접근할 수 있도록 전역변수로 선언

void sequence(int n, int m, int* seq) {
  if(m > 0) {
    for(int i = 0; i < n; i++) {
      seq[M-m] = i+1; // 배열에 숫자 입력
      sequence(n, m-1, seq);
      // 재귀를 통해서 수열 구현
    }
  }
  else {
    for(int i = 0; i < M; i++)
      cout << seq[i] << " ";
    cout << '\n';
  }
}

int main(void) {
  int N;
  int* seq; // 수열을 출력하기 전 저장할 배열

  cin >> N >> M;
  seq = new int[M];

  sequence(N, M, seq);

  delete[] seq;
  return 0;
}