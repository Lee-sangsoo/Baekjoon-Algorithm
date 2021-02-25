/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.25
���� : ���� �� �����ϴ� �κ� ���� - 11722
Ǯ�� : ���� �� �����ϴ� �κ� ���� ��������
       a[i]�� a[j]�� ���ϴ� �κ��� �ε�ȣ�� �ݴ�� ���ָ� �ȴ�.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[1001];
int d[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] < a[j]) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, d[i]);

	cout << ans;
}