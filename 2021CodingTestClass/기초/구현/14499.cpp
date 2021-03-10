/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.05
���� : �ֻ��� ������ - 14499
Ǯ�� : ���� ����.
       ó�� �ظ� ������ ���� ����� �ֻ����� 1�� ���� ���� �� ������������ �̵��ϸ� 
	   ���� �ٲ�� �Ǵµ� ��->��, ��->�� ���� �� ��� �� �쿡 �ִ� ���� �ٲ�� ������
	   �̸� ��� �ϸ� ó���� �� ������ ��� ����� �־���.
	   (�̷��� ��� ��� �̵��� ��� �� ���� ���� ����� �ٸ� �迭�� �����Ͽ� ���� ����)

	   ������, �ٸ� �������� �����ϸ� �����ϰ� �ذ��� �Ǿ���.

	   �ֻ����� ������ �ְ� �ֻ����� ���� ���鸸 �̵��� ���� �ٲ�� �ϸ� �Ǿ���.
	   ��, �ֻ����� ���⿡�� ������ ������ �ϸ� �Ǿ���.

	   �� ����� ���� ���� �Ʒ��� ewns�� ���� �� ��ȭ�̴�.

	   �� ��ȭ�� ���� 
	   1. ������ Ȯ�����ְ�
	   2. �̵��� ���� �ֻ��� �� ��ȭ�� �����ϰ�
	   3. ���(dice[1]) ���� ������ְ�
	   4. ������ �ֻ����� ���� ���� ������ ó�����ְ�
	   5. ���� �ֻ����� ��ġ�� �ٲ��ش�.

	   �̷��� ���ʴ�� ó���ϸ� ����� �����ϴ�.

	   ������ �ֻ����� �����ͼ� Ǯ����...
*/
#include<iostream>

using namespace std;

int n, m, x, y, k;
int mp[21][21];
int dice[7];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mp[i][j];

	while (k--) {
		int ewns;
		cin >> ewns;

		int nx = x + dx[ewns - 1];
		int ny = y + dy[ewns - 1];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		if (ewns == 1) {
			int tmp = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = tmp;
		}
		else if (ewns == 2) {
			int tmp = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = tmp;
		}
		else if (ewns == 3) {
			int tmp = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = tmp;
		}
		else {
			int tmp = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = tmp;
		}

		cout << dice[1] << '\n';

		if (mp[nx][ny] == 0) {
			mp[nx][ny] = dice[6];
		}
		else {
			dice[6] = mp[nx][ny];
			mp[nx][ny] = 0;
		}
		x = nx;
		y = ny;
	}
}