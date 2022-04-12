#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
  int dice[3]; // 주사위의 눈
  int price; // 상금 액수
  cin >> dice[0] >> dice[1] >> dice[2];

  // 주사위의 눈을 오름차순으로 정렬
  sort(dice, dice+3);

  // 세 주사위 눈이 모두 같은 경우
  if(dice[0] == dice[2])
    price = 10000 + dice[1]*1000;
  // 세 주사위 중 두 개의 눈이 같은 경우 
  else if(dice[0] == dice[1] || dice[1] == dice[2])
    price = 1000 + dice[1]*100;
  // 세 주사위의 눈이 모두 다른 경우
  else
    price = dice[2]*100;

  cout << price << '\n';
  return 0;
}