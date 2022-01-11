#include <iostream>
#include <algorithm> // stable_sort()

using namespace std;

typedef struct { // 회원을 저장할 구조체
  int age;  // 회원의 나이
  string name; // 회원의 이름
} Member;

bool cmp(Member m1, Member m2){
  return m1.age < m2.age; // 나이 순 오름차순
}
/*
void Move_member(int begin, int end, Member* list) {
  // 회원을 추가할 자리를 만드는 함수
  // 추가할 자리 이후의 자료들을 오른쪽으로 한칸 옮김
  for(int i = end; i >= begin; i--){
    list[i+1].age = list[i].age;
    list[i+1].name = list[i].name;
  }
}

void Add_member(int order, Member input, Member* list) {
  // 새로운 회원 추가
  // 나이순으로 정렬하면서 추가 (가입 순서는 자동으로 정렬)
  for(int i = 0; i < order; i++)
  // 새로운 회원이 배열 중간에 들어갈 때
    if(input.age < list[i].age){
      Move_member(i, order-1, list);
      list[i].age = input.age;
      list[i].name = input.name;
      return;
    }
  // 새로운 회원이 가장 연장자일 때
  list[order].age = input.age;
  list[order].name = input.name;
}
*/
int main(void) {
  int N;
  // Member input;
  Member* member_list;

  cin >> N;
  member_list = new Member[N]; // 크기가 N인 배열 동적할당
  for(int i = 0; i < N; i++) {
    cin >> member_list[i].age >> member_list[i].name; // 입력

    // cin >> input.age >> input.name;
    // Add_member(i, input, member_list);
  }

  stable_sort(member_list, member_list+N, cmp);
  // stable_sort()함수를 사용해서 가입 순서 변경 X

  for(int i = 0; i < N; i++)
    cout << member_list[i].age << " " << member_list[i].name << '\n';
    // 정렬된 회원 목록 출력

  delete[] member_list; // 동적할당 해제
  return 0;
}