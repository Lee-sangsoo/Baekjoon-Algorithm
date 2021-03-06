/*
작성자 : 이상수
일시 : 2021.02.25
제목 : 제곱수의 합 - 1699
풀이 : 1, 2, 3 더하기와 매우 유사한 문제이다.
       1, 2, 3 더하기 때와 다른점은 1, 2, 3 이 아니라
	   1, 4, 9, 16, ... 와 같은 제곱수들이라는 말이다.

	   수의 합을 제곱수의 합으로 하기 때문에 
	   N번째 자리에는 1이 올수도 있고 4가 올수도 있고 9가 올수도 있고 더 클수도 있다.

	   이런점을 감안하여
	   현재 N을 감안하여 최대로 확인 가능한 제곱수를 찾아
	   N - K^2 을 해가면서 그 값이 가장 작은 값에 + 1을 해주면 된다.

	   즉 말로 풀어 설명하면
	   마지막 항이 1인 경우
	   마지막 항이 4인 경우
	   마지막 항이 9인 경우
	   ...
	   처럼 처리 가능하다
	   D[N] = MIN(D[N], D[N - K^2] + 1) 이 된다.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int d[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		for (int j = 2; j*j <= i; j++) {
			d[i] = min(d[i], d[i - j * j] + 1);
		}
	}
	cout << d[n];
}