/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.02
���� : ���� �ǰ��� ������ - 1600
Ǯ�� : �� Ǯ����� ������ �� ��¿��� �߸��� ����...
       �߸��� �κ��� ���� ����� ans - 1�� ����� �ؼ����µ�,
	   ������ ans�� ã�� �������� ���� ������ ��� ans�� -1��
	   ����Ǿ� �ִٰ� �� �� ����� �ϸ� -2�� ���ͼ� ���� ó���� �Ǿ���...

	   �� �ܿ� ����� ����.
	   ���� ������ �̵��ϱ� �������� ���� �� �̵������ ��� �����ϸ� ��ó�� �̵��ϰ�
	   �׷��� ������ �׳� �̵��ϴ� ���� 3���� chk �迭�� ����Ͽ� Ǯ�� �Ǿ���.

	   �̵� ������ Ƚ���� �����ִٸ� Ƚ���� �ϳ� ���ҽ�Ű�� �̵��� ���� �������ְ�
	   Ƚ���� ���ٸ� ������ ĭ���θ� �̵��� �����ϰ� �Ѵ�.

	   �̸� ����ϸ� �����ϰ� �ذ� �����ϴ�
	   (�Ǽ���... ����... ����...)

	   �Ǽ��� �߰��� ���
		- �ش����� ���� �־�� �ȴ� (�迭�� 1X1 �̶���� ���� ���ϴ� ���̶���� ���)
*/

#include<iostream>
#include<queue>

using namespace std;

int k, n, m;
int chk[201][201][31];
int arr[201][201];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int hdx[] = { -2, -2, -1, 1, 2, 2, 1, -1 }; // 8
int hdy[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0,0},k });
	chk[0][0][k] = 1;
	int cnt = 0;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first.first, y = cur.first.second, z = cur.second;

		if (z > 0) {
			for (int k = 0; k < 8; k++) {
				int nx = x + hdx[k];
				int ny = y + hdy[k];
				int nz = z - 1;
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (chk[nx][ny][nz] || arr[nx][ny] == 1) continue;
				q.push({ {nx, ny}, nz });
				chk[nx][ny][nz] = chk[x][y][z] + 1;
			}
		}

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (arr[nx][ny] == 1 || chk[nx][ny][z]) continue;
			q.push({ { nx, ny }, z });
			chk[nx][ny][z] = chk[x][y][z] + 1;
		}
		/*
		for (int k = 0; k < 8; k++) {
			int nx = x + hdx[k];
			int ny = y + hdy[k];
			int nz = z - 1;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0) continue;
			if (chk[nx][ny][nz] || arr[nx][ny] == 1) continue;
			q.push({ {nx, ny}, nz });
			chk[nx][ny][nz] = chk[x][y][z] + 1;
		}
		*/
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> k;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	bfs();

	int ans = -1;
	for (int i = 0; i <= k; i++) {
		if (chk[n - 1][m - 1][i] != 0) {
			if(ans == -1 || ans > chk[n - 1][m - 1][i] - 1)
				ans = chk[n - 1][m - 1][i] - 1;
		}
	}
	cout << ans;
}