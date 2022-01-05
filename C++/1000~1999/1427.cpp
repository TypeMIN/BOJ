#include <iostream>
#include <string> // string 관련 함수 사용을 위함

using namespace std;

void swap(int* arr, int a, int b) { 
  // 내림차순 정렬 시 배열의 순서를 바꾸는 함수
  if(a != b){
    int temp;
    temp = arr[b];
    arr[b] = arr[a];
    arr[a] = temp;
  }
  return;
}

int main(void) {
  int num;  // input value
  string num_str; 
  int num_arr[10];  // 각 자리수로 나눈 수를 입력할 배열
  int num_len;  // 주어진 수의 자릿수
  int max_pos;  // 정렬에서 필요한 요소

  cin >> num;
  num_str = to_string(num); // int -> string 형변환
  num_len = num_str.length();
  for(int i = 0; i < num_len; i++)  // 각 자리수대로 끊어서 정수배열에 저장
    num_arr[i] = (int)(num_str[i] - 48); // char -> int 형변환

  for(int i = 0; i < num_len - 1; i++) {  // 내림차순 정렬
    max_pos = i;
    for(int j = i+1; j < num_len; j++)
      if(num_arr[j] > num_arr[max_pos])
        max_pos = j;
    swap(num_arr, i, max_pos);
  }

  num_str.clear();  // string 초기화
  for(int i = 0; i < num_len; i++)  // 내림차순으로 정렬된 숫자들을 차례대로 입력
    num_str.push_back((char)(num_arr[i] + 48));
  cout << num_str << endl;

  return 0;
}