/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.11
���� : ���� - 1026
Ǯ�� : ���� ������ * ���� ���� ���� ���ؼ� ���� ���ϸ� ���� ���� ���� ���´�.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i] * b[i];

	cout << sum;
}