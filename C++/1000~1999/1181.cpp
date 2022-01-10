#include <iostream>
#include <string> // string 자료형
#include <algorithm> // sort()

using namespace std;

bool cmp_str(string s1, string s2) // 정렬 기준
{
  if(s1.length() == s2.length()) // 길이가 같을 때, 사전순
    return s1 < s2;
  else // 길이가 짧은 순
    return s1.length() < s2.length();
}

int main(void)
{
  int N;
  string* words;

  cin >> N;
  words = new string[N]; // 크기가 N인 배열 동적할당

  for(int i = 0; i < N; i++)
    cin >> words[i]; // 주어진 단어들을 배열에 입력

  sort(words, words+N, cmp_str); // 주어진 조건에 맞게 정렬

  cout << words[0] << '\n';
  for(int i = 1; i < N; i++)
    if(words[i].compare(words[i-1]) != 0) // 중복되는 단어 출력 제외
      cout << words[i] << '\n';

  delete[] words; // 동적할당 해제
  return 0;
}