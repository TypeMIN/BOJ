#include <iostream>
#include <algorithm> // sort()

using namespace std;

typedef struct { // 좌표 구조체
  int value; // 좌표값
  int order; // 입력 순서
  int count; // 압축값
} Point;

bool cmp_value(Point x1, Point x2) {
  return x1.value < x2.value;
} // 좌표값 오름차순 정렬

bool cmp_order(Point x1, Point x2) {
  return x1.order < x2.order;
} // 입력 순서 오름차순 정렬

int main(void) {
  int N; // 좌표의 수
  int count; // 압축값
  Point* x; // 좌표 배열

  cin >> N;
  x = new Point[N];
  for(int i = 0; i < N; i++) {
    cin >> x[i].value; // 좌표값 입력
    x[i].order = i; // 입력 순서 저장
  }
  // 좌표값 오름차순 정렬
  sort(x, x+N, cmp_value);
  
  count = 0;
  x[0].count = count;
  for(int i = 1; i < N; i++) {
    if(x[i].value > x[i-1].value)
      count++;
    // 좌표값이 이전 값과 같을 시 압축값 증가 X
    x[i].count = count;
  }
  // 입력 순서 오름차순 정렬
  sort(x, x+N, cmp_order);
  // 압축값 출력
  for(int i = 0; i < N-1; i++)
    cout << x[i].count << " ";
  cout << x[N-1].count << '\n';

  delete[] x;
  return 0;
}