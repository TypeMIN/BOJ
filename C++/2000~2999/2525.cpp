#include <iostream>

using namespace std;

int main(void) {
  int hour, minute;
  int require_hour, require_minute;

  cin >> hour >> minute;
  cin >> require_minute;

  require_hour = require_minute/60;
  for(int i = 0; i < require_hour; i++)
    hour++;
  minute += require_minute%60;

  if(minute > 59) {
    minute -= 60;
    hour++;
  }
  if(hour > 23) {
    hour %= 24;
  }

  cout << hour << " " << minute << '\n';
  return 0;
}  