/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.24
���� : ���� �� �����ϴ� �κ� ���� - 11053
Ǯ�� : N��° �ڸ��� ���� �κ� ������ �� ��� LIS�� ��� �Ǵ°� ��� �������� ����
       N��° �ڸ��� ���� 1 ~ N-1 ��° �ڸ��� ������ ���Ͽ� 
	   A[N] > A[1 ~ N-1] �� ���� ã�� max(D[1 ~ N-1]) + 1 �� �����̴�.

	   �� �ڽ��� ���� �������� ���� �߿��� ���� �� LIS�� ã�Ƽ� +1�� ���ִ°� �����̴�.
	   D[N] = MAX(D[K]) + 1
	   K < N
	   A[K] < A[N]
*/
#include<iostream>

using namespace std;

int n;
int d[1001];
int a[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		int maxCnt = 0;
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j] && maxCnt < d[j]) maxCnt = d[j];
		}
		d[i] = maxCnt + 1;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (ans < d[i]) ans = d[i];
	cout << ans;
}