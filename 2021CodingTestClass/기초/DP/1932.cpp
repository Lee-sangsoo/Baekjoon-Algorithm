/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.25
���� : ���� �ﰢ�� - 1932
Ǯ�� : D[N][K] = N��° K��° ���� ���� �� �ִ� ��
       �̶�� �ΰ� �����ϸ�
	   K�� ũ�⿡ ���� 
	   D[N][K] = MAX(D[N-1][K-1], D[N-1][K]) + P[N][K]
	   �� �ȴ�.
	   ���⼭ 
	   D[N-1][K-1]�� K-1 >= 0 �� ����        
	   D[N-1][K]�� K < N �� ���� �����Ѵ�.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int d[501][501];
int p[501][501];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> p[i][j];

	d[0][0] = p[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j - 1 >= 0) d[i][j] = max(d[i][j], d[i - 1][j - 1]);
			if (j < i) d[i][j] = max(d[i][j], d[i - 1][j]);
			d[i][j] += p[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, d[n - 1][i]);
	cout << ans;
}