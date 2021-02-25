/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.25
���� : RGB �Ÿ� - 1149
Ǯ�� : ������ ������ ������ �޶�� �Ѵ� ��� ���ǿ� ����
       D[N][K] = N��° ���� K��° ������ ĥ���� �� �ּ� ���
	   �̶�� �����ϸ� 
	   ������ R, G, B �� 3���� ���̱� ������ K�� 1 2 3 ���� ó���Ѵ�.
	   N��° ���� 1�� ĥ�ϰ� �ʹٸ� N-1��° ���� 2�� 3�̿��� �Ѵ�.
	   �� �� ���� ����� ��� ���� �����ϸ� �ȴ�.

	   ���������� ������ ��� ���� 
	   D[N][1 ~ 3] �� �ּ� ����� ������ ���� ������ �ȴ�.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int p[1001][4];
int d[1001][4];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < 4; j++)
			cin >> p[i][j];

	for (int i = 1; i < 4; i++)
		d[1][i] = p[1][i];

	for (int i = 2; i <= n; i++) {
		d[i][1] = min(d[i - 1][2], d[i - 1][3]) + p[i][1];
		d[i][2] = min(d[i - 1][1], d[i - 1][3]) + p[i][2];
		d[i][3] = min(d[i - 1][1], d[i - 1][2]) + p[i][3];
	}

	int ans = 1000 * 1000;
	for (int i = 1; i < 4; i++)
		ans = min(ans, d[n][i]);

	cout << ans;
}