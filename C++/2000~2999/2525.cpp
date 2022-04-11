#include <iostream>

using namespace std;

int main(void) {
  int hour, minute; // 현재 시각
  int require_hour, require_minute; // 요리하는데 필요한 시간

  cin >> hour >> minute;  // 현재 시각 입력
  cin >> require_minute;  // 요리하는데 필요한 시간 입력

  require_hour = require_minute/60; // 시간 단위 계산
  for(int i = 0; i < require_hour; i++) // 시간의 합
    hour++;
  minute += require_minute%60;  // 분의 합

  if(minute > 59) { // 60분이 초과했을 때 받아올림
    minute -= 60;
    hour++;
  }
  if(hour > 23) { // 24시 -> 0시로 전환
    hour %= 24;
  }

  cout << hour << " " << minute << '\n';  // 종료되는 시각 출력
  return 0;
}  