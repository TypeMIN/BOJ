#include <iostream>
#include <cmath>    // sqrt(제곱근), pow(지수), abs(절댓값) 함수를 쓰기 위함

using namespace std;

int main() {
  int T;    // 테스트 케이스의 수
  double x1, y1, x2, y2, r1, r2, distance;
  cin >> T; 
  for(int i = 0; i < T; i++){    // 테스트 케이스의 수 만큼 반복
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));    
        // distance = 조규현과 백승환 사이의 직선거리
    if(distance > r1 + r2){    // 두 원이 서로 외부에 있을 때
      cout << "0\n";
    }
    else if(distance == r1 + r2){    // 두 원이 외접할 때
      cout << "1\n";
    }
    else if(distance == abs(r1 - r2)){
      if(distance == 0)    // 두 원이 같은 원일때
        cout << "-1\n";
      else    // 두 원이 내접할 때
        cout << "1\n";
    }
    else if(distance < abs(r1 - r2)){    // 한 원이 다른 원 안에 포함될 때
      cout << "0\n";
    }
    else if(distance > abs(r1 - r2)){    // 두 원이 서로 다른 두 점에서 만날 때
      cout << "2\n";
    }
  }
  return 0;
}