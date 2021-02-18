/*
작성자 : 이상수
일시 : 2021.02.18
제목 : N과 M (7) - 15656
풀이 : 기존 N과 M 문제에서 숫자가 1 ~ N이 아닌 주어지는 N개의 숫자로 처리하는 문제
	   사전순으로 출력 해주면 되기 때문에 vector에 값을 받아 정렬 해주고 돌리면된다.

	   중복을 허용하는 값을 처리하는 문제
	   조건문을 빼고 값을 구하면 된다.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> number;
int arr[8];
int n, m;

void go(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		arr[k] = number[i];
		go(k + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		number.push_back(a);
	}
	sort(number.begin(), number.end());
	go(0);
}