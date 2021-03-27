/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.27
���� : ��� ���� - 6593
Ǯ�� : 2�������� �����ϴ� BFS Ž���� 3�������� �����ϴ� �����̴�.
       [z][x][y]�� �ΰ� �̵��� �Ѵٰ� �����Ͽ��� ��
	   z�� 2����
	   x�� 2����
	   y�� 2������ �� 6������ �̵��� �����ϴ�.
	   �� �̵����� �����Ͽ� �̵� �迭�� ������ְ�
	   ��ҿ� ���� BFS Ž���� �����ϸ�ȴ�.
*/
#include<iostream>
#include<queue>
#include<string>

using namespace std;

int l, r, c;
char arr[31][31][31];
int chk[31][31][31];

int dz[] = { 0, 0, 0, 0, -1, 1 };
int dx[] = { -1, 0, 1, 0, 0, 0 };
int dy[] = { 0, 1, 0, -1, 0, 0 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	while (1) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					arr[i][j][k] = ' ';
					chk[i][j][k] = 0;
				}
			}
		}

		queue<pair<int, pair<int, int>>> q;
		pair<int, pair<int, int>> ep;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				string s;
				cin >> s;
				for (int k = 0; k < c; k++) {
					arr[i][j][k] = s[k];
					if (s[k] == 'S') {
						q.push({ i, {j, k} });
						chk[i][j][k] = 1;
					}
					if (s[k] == 'E') ep = { i, {j, k} };
				}
			}
		}

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			int z = cur.first, x = cur.second.first, y = cur.second.second;
			for (int k = 0; k < 6; k++) {
				int nz = z + dz[k];
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nz < 0 || nz >= l) continue;
				if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				if (chk[nz][nx][ny] || arr[nz][nx][ny] == '#') continue;
				q.push({ nz, {nx, ny} });
				chk[nz][nx][ny] = chk[z][x][y] + 1;
			}
		}
		
		if (chk[ep.first][ep.second.first][ep.second.second] == 0)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << chk[ep.first][ep.second.first][ep.second.second] - 1 << " minute(s).\n";
	}
}