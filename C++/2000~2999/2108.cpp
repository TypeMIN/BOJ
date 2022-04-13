#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
  int N;    // 입력되는 자료의 개수
  double avg, sum;  // 산술평균을 구하기 위한 변수 선언
  int median, mode, range;  // 중앙값, 최빈값, 범위를 저장할 변수 선언
  int num_max; // 중복되는 최빈값의 수
  int nums[500000]; // 입력된 수를 저장할 배열
  int counts[8001]; // 입력된 수의 횟수를 기록할 배열
  int max_pos[8001]; // 최빈값이 여러 개 있을 때 저장할 배열
  for(int i = 0; i < 8001; i++){  // 배열 초기화
    counts[i] = 0;
  }
  cin >> N;

  sum = 0;
  for(int i = 0; i < N; i++) {
    cin >> nums[i]; // 입력된 수를 배열에 저장
    sum += nums[i]; // 저장하면서 입력된 수의 총합 계산
    counts[nums[i]+4000]++; // 저장하면서 입력된 수의 횟수 체크
  }

  sort(nums, nums+N); // 저장한 배열 오름차순 정렬

  num_max = 0;  // 최빈값의 수
  max_pos[0] = 0; // 최빈값 배열
  for(int i = 0; i < 8001; i++){
    if(counts[i] > 0){
      if(num_max == 0){ // 첫번째 나온 값을 최빈값 지정
        max_pos[0] = i;
        num_max = 1;
      }
      else{ // 기존 최빈값이 존재하는 경우
        if(counts[i] > counts[max_pos[0]]){ // 새로운 최빈값
          max_pos[0] = i;
          num_max = 1; // 최빈값 개수 초기화
        }
        else if(counts[i] == counts[max_pos[0]]){ // 중복된 최빈값
          max_pos[num_max] = i;
          num_max++;  // 중복된 개수 체크
        }
      }
    }
  }

  // 산술평균
  avg = round(sum/N);
  if(avg == -0)
    avg = 0;
  // 중앙값
  median = nums[N/2];
  // 최빈값
  if(num_max > 1) // 여러 개의 최빈값이 존재하는 경우
    mode = max_pos[1] - 4000; // 두 번째로 작은 값 출력
  else  // 하나의 최빈값만 있는 경우
    mode = max_pos[0] - 4000;
  // 범위
  range = nums[N-1] - nums[0];

  cout << avg << endl << median << endl << mode << endl << range << endl;
  return 0;
}