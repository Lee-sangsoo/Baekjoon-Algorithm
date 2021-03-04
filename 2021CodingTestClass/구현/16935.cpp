/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.05
���� : �迭 ������ 3 - 16935
Ǯ�� : �׻� �������� ���� ������ �� �밡�ٶ� �� ���� Ǯ���� ���� ������...
       �迭�� ������ ó���ϴ� �����̴�.

	   �׸��� �׷����� ��ǥ�� ���ϸ� �����ϰ� ó�� ������ 
	   ������ ���� ����, �¿� ������ �޸�
	   90�� ȸ��, ���� ������� �� ������ �ٲ� ������ �ֱ� ������ 
	   ���� �迭�� �ΰ� ����ؾ� �Ѵ�.

	   �� �ܿ��� ���� ����� �ʰ� �ð��� �� �ɸ��� �����̴�.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n, m, r;
int arr[101][101];

void first() {
	for (int i = 0; i < n / 2; i++) 
		for (int j = 0; j < m; j++) 
			swap(arr[i][j], arr[n - i - 1][j]);
}

void second() {
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m / 2; j++) 
			swap(arr[i][j], arr[i][m - 1 - j]);
}

void third() {
	int tmp[101][101];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tmp[j][n - 1 - i] = arr[i][j];

	swap(n, m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = tmp[i][j];
}

void fourth() {
	int tmp[101][101];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tmp[m-1-j][i] = arr[i][j];

	swap(n, m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = tmp[i][j];
}

void fifth() {
	int tmp[101][101];

	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < m / 2; j++)
			tmp[i][j + m / 2] = arr[i][j];
	
	for (int i = 0; i < n / 2; i++)
		for (int j = m / 2; j < m; j++)
			tmp[i + n / 2][j] = arr[i][j];

	for (int i = n / 2; i < n; i++)
		for (int j = m / 2; j < m; j++)
			tmp[i][j - m / 2] = arr[i][j];

	for (int i = n / 2; i < n; i++)
		for (int j = 0; j < m / 2; j++)
			tmp[i - n / 2][j] = arr[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = tmp[i][j];
}

void sixth() {
	int tmp[101][101];

	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < m / 2; j++)
			tmp[i + n / 2][j] = arr[i][j];

	for (int i = 0; i < n / 2; i++)
		for (int j = m / 2; j < m; j++)
			tmp[i][j - m / 2] = arr[i][j];

	for (int i = n / 2; i < n; i++)
		for (int j = m / 2; j < m; j++)
			tmp[i - n / 2][j] = arr[i][j];

	for (int i = n / 2; i < n; i++)
		for (int j = 0; j < m / 2; j++)
			tmp[i][j + m / 2] = arr[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = tmp[i][j];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	while (r--) {
		int cal;
		cin >> cal;
		switch (cal) {
		case 1:
			first();
			break;
		case 2:
			second();
			break;
		case 3:
			third();
			break;
		case 4:
			fourth();
			break;
		case 5:
			fifth();
			break;
		case 6:
			sixth();
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
}