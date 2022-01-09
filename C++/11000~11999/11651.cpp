#include <iostream>
#include <algorithm> // sort()

using namespace std;

typedef struct {  // 좌표 구조체
  int x, y;
} Point;

bool cmp(const Point &p1, const Point &p2) {
  // 좌표의 y값 오름차순, 같을 시 x값 오름차순
  if(p1.y < p2.y)
    return true;
  else if(p1.y == p2.y)
    return p1.x < p2.x;
  else
    return false;
}

int main(void) {
  int N; // 입력할 좌표의 수
  Point* points; // 좌표를 저장할 공간

  cin >> N;
  points = new Point[N]; // 입력할 수 만큼 동적할당
  for(int i = 0; i < N; i++) // 좌표 입력
    cin >> (points[i]).x >> (points[i]).y; 

  sort(points, points+N, cmp); // 오름차순 정렬

  for(int i = 0; i < N; i++) // 정렬한 좌표 출력
    cout << points[i].x << " " << points[i].y << '\n';

  delete[] points; // 동적할당 해제
  return 0;
}