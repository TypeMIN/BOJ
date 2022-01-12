#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
  int value;
  int order;
  int count;
} Point;

bool cmp_value(Point x1, Point x2) {
  return x1.value < x2.value;
}

bool cmp_order(Point x1, Point x2) {
  return x1.order < x2.order;
}

int main(void) {
  int N;
  int count;
  Point* x;

  cin >> N;
  x = new Point[N];
  for(int i = 0; i < N; i++) {
    cin >> x[i].value;
    x[i].order = i;
  }

  sort(x, x+N, cmp_value);

  count = 0;
  x[0].count = count;
  for(int i = 1; i < N; i++) {
    if(x[i].value > x[i-1].value) {
      count++;
    }
    x[i].count = count;
  }

  sort(x, x+N, cmp_order);

  for(int i = 0; i < N-1; i++) {
    cout << x[i].count << " ";
  }
  cout << x[N-1].count << '\n';

  delete[] x;
  return 0;
}