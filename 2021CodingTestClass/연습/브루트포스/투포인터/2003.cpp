/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.10
���� : ������ �� 2 - 2003
Ǯ�� : �� ������ ���� 
       �� �����͸� ������ �� �˸� Ǯ �� �ִ� �����̴�.
*/
#include<iostream>

using namespace std;

int n, s;
int arr[10001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int st = 0, en = 0;
	int sum = 0;
	int cnt = 0;
	while (1) {
		if (sum > s) sum -= arr[st++];
		else if (en == n) break;
		else sum += arr[en++];

		if (sum == s) cnt++;
	}

	cout << cnt;
}