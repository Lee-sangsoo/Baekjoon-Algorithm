/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.25
���� : ������ �� - 11057
Ǯ�� : ���� ���ų� Ŀ���� ����� ������ �ϸ� 
       0���� ������ �����ϱ� ������

	   D[1][0 ~ 9] = 1
	   D[i][j] = sum(d[i-1][k])  (k <= j)
	   �� ó�����ָ� �ȴ�.
*/
#include<iostream>

using namespace std;

int n;
int d[1001][10];
const int mod = 10007;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	
	for (int i = 0; i < 10; i++)
		d[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] = (d[i][j] + d[i - 1][k]) % mod;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++)
		ans = (ans + d[n][i]) % mod;

	cout << ans;
}