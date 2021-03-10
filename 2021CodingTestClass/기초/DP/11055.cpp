/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.25
���� : ���� ū �����ϴ� �κ� ���� - 11055
Ǯ�� : ���� �� �����ϴ� �κ� ���� ������ �ſ� �����ϴ�.
       ���� �� �κ� ������ ã�� ������ �Ȱ��� �˰���
	   d[i] = max(d[i], d[j] + 1) �̿���.
	   ���⼭ ���̰� �ƴ� ���̱� ������
	   d[i]�� �̶������� ���� ��Ƶΰ�
	   d[j] + a[i]�� �ٲ��ָ� �����ϰ� �ذ�ȴ�.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int a[1001];
int s[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		s[i] = a[i];
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				s[i] = max(s[i], s[j] + a[i]);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, s[i]);

	cout << ans;
}