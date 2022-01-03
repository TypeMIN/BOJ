#include <iostream>

using namespace std;

int main(void){
    double a, b;    // long double a,b; 도 가능
    cin >> a >> b;
    cout.precision(10);    // 출력 시 오차를 막기 위해 소숫점 자리수 조절
    cout << a/b;
}