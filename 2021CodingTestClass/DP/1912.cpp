/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.24
���� : ������ - 1912
Ǯ�� : �� �������� ���� �̿��� ������ ���������� ���ϸ� �����ϰ� ó���� �����ϴ�.
       
	   ���� ���ڿ� 
	   ���������� �ִ� �� + ���� ���ڸ� ���Ͽ�
	   �� ū ���� �����ϸ� �ȴ�.

	   ������� �����ϴ� ���ӵ� ������ �� VS ���������� �ִ� ���� ���ӵ� ������ �տ� ���� ���� ����
	   �� ���� ���Ͽ� �ִ븦 �־��ָ� �ȴ�.

	   D[N] = N��° ���� ������ ���� ū ������
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int d[100001];
int a[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	d[0] = a[0];
	for (int i = 1; i < n; i++) {
		d[i] = max(d[i - 1] + a[i], a[i]);
	}

	int ans = -1000 * 100000;
	for (int i = 0; i < n; i++) {
		if (ans < d[i]) ans = d[i];
	}
	cout << ans;
}