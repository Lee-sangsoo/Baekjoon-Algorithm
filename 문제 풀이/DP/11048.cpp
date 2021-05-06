/*
�ۼ��� : �̻��
�Ͻ� : 2021.05.06
���� : �̵��ϱ� - 11048
Ǯ�� : DP �����̴�.
       �ϳ��� ĭ���� �� 3�������� �� �� �ְ�, �̸� �ݴ�� ���ϸ� 
	   �� ĭ�� �������� �� �� �ִ� ����� �� 3������ �ִٴ� ���̴�.
	   ��, ���� ĭ�� (r, c) ���, (r-1, c-1) (r-1, c) (r, c-1) �� 3�������� �� �� �ִ�.

	   3���� ��ο��� �� �� �ִ� ���� (1,1)���� ���� �����Ͽ� (n-1, m-1)���� �̸�
	   0��� 0���� ��� ���ʿ��� ���������� Ȥ�� ������ �Ʒ��θ� �� �� �ִ� ����� ���̱� ������
	   �⺻ ���̽������� �������ְ� �����ϸ� �ȴ�.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int arr[1001][1001];
int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	dp[0][0] = arr[0][0];
	for (int i = 1; i < m; i++)
		dp[0][i] = dp[0][i - 1] + arr[0][i];

	for (int i = 1; i < n; i++)
		dp[i][0] = dp[i - 1][0] + arr[i][0];

	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1])) + arr[i][j];

	cout << dp[n - 1][m - 1];
}