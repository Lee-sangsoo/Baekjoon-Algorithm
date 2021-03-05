/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.05
���� : �迭 ������ 1 - 16926
Ǯ�� : ���� �����ε� �޹��̹迭�̶� ����ϴ�.
       sx�� sy�� ���� 0,0 ���� �����Ͽ� ��ȸ�� ��ġ�� �迭 �������� �� ��
	   1�� Ŀ����. ���� ��ȸ�� �� �� �ٲ�°��� �ƴѰ� �;� ���� ���� �����ؾ� �ϳ�
	   ������, ��ȸ�� �ϴٺ��� �ᱹ�� ó���� ������ ���ƿ��� �Ǿ��ִ�.
	   ��, ���� ���� �ٲٰų� ������ �ʿ�� ����.

	   ó���� N-1�� M-1���� �ݺ��ϸ� �� ������ N-3, M-3 �� 2�� �����ϸ� �����Ѵ�.
	   �� ���� n�� m���� Ŭ�������� �ϸ� �ȴ�.

	   ���������� �ľ��� ���� ���������̴�.
*/
#include<iostream>

using namespace std;

int n, m, r;
int arr[301][301];

void rotation() {
	int tmp[301][301];
	int miner = 1;
	int sx = 0, sy = 0;
	while (n > miner && m > miner) {
		for (int i = 0; i < n - miner; i++) {
			tmp[sx + 1][sy] = arr[sx][sy];
			sx++;
		}
		for (int i = 0; i < m - miner; i++) {
			tmp[sx][sy + 1] = arr[sx][sy];
			sy++;
		}
		for (int i = 0; i < n - miner; i++) {
			tmp[sx - 1][sy] = arr[sx][sy];
			sx--;
		}
		for (int i = 0; i < m - miner; i++) {
			tmp[sx][sy - 1] = arr[sx][sy];
			sy--;
		}
		miner += 2;
		sx++; sy++;
	}

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
		rotation();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
}