/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.24
���� : �պ��� - 2225
Ǯ�� : �� �������� �䱸�ϴ� ����� �׸��� �׷��� ���� ����.
       
	   O + O + O + ... + O = N
	  |        K��        |
	  |       K-1��     |  = N - ������ O
	  �� �ȴ�.
	  �� �׸����� Ȯ���� �� �ֵ���
	  ������ O�� �� �� �ִ� ���� 0 ~ N�̸�
	  �׿� ���� N - (0 ~ N) ������ Ȯ���ϸ� �ȴ�.

	  D[N][K] = 0 ~ N�� ���ڸ� K�� ����� ���� N�� �Ǵ� ����� ��
	  �̹Ƿ�
	  D[N][K] = D[N-1][K-0] + D[N-1][K-1] + D[N-1][K-2] + ... �ذ��� �ȴ�.
	  K - ? �� ������ N�� ũ�⸦ ���󰣴�.
*/
#include<iostream>

using namespace std;

int n, k;
long long d[201][201];
const int mod = 1000000000;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
		d[1][i] = i;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] = (d[i][j] + d[i - 1][j - k]) % mod;
			}
		}
	}

	cout << d[n][k];
}