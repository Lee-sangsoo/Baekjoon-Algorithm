/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.22
���� : �� - 5427
Ǯ�� : BFS�� ����Ͽ� ó���ϴ� ����
       ���� ������ �ð��� 
	   ����̰� �־��� ���� ������ �����µ� �ɸ��� �ð��� ���ϸ� �Ǵµ�

	   ���� ������ �ð��� �켱������ ���Ͽ�
	   ����̰� �̵��ϴ� �ð��� ���� �� BFS Ž�� �� ť�� ���� �������� ����Ѵ�.

	   ���� ���� Ư�� ĭ���� ������ �ð��� ����̰� �ش� ĭ���� �̵��ϴµ� �ɸ��� 
	   �ð����� ���ٸ� �̵����� ���ϱ� ������ ť�� �־� Ž���� �ʿ䰡 ����.

	   �̸� ����Ͽ� ó���ϸ�
	   �� ���� �ð��� ���ؾ� �ϱ� ������ �ʱⰪ�� -1�� �ξ�
	   �񱳰��� -1�̶�� ���� ���ٴ� ���̱� ������ �̵��� �����ϵ��� ó���Ѵ�.
*/
#include<iostream>
#include<queue>
#include<string>
#include<vector>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> m >> n;
		queue<pair<int, int>> fq;
		queue<pair<int, int>> sq;
		vector<vector<char>> mp(n, vector<char>(m, ' '));
		vector<vector<bool>> chk(n, vector<bool>(m, false));
		vector<vector<bool>> schk(n, vector<bool>(m, false));
		vector<vector<int>> fdist(n, vector<int>(m, -1));
		vector<vector<int>> sdist(n, vector<int>(m, -1));
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				mp[i][j] = s[j];
				if (mp[i][j] == '@') {
					sq.push({ i, j });
					sdist[i][j] = 0;
					schk[i][j] = true;
				}
				if (mp[i][j] == '*') {
					fq.push({ i, j });
					fdist[i][j] = 0;
					chk[i][j] = true;
				}
			}
		}

		while (!fq.empty()) {
			auto cur = fq.front();
			fq.pop();
			int x = cur.first, y = cur.second;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (chk[nx][ny] || mp[nx][ny] == '#') continue;
				fq.push({ nx, ny });
				chk[nx][ny] = true;
				fdist[nx][ny] = fdist[x][y] + 1;
			}
		}

		int cnt = 0;
		bool cn = false;
		while (!sq.empty()) {
			auto cur = sq.front();
			sq.pop();
			cnt++;
			int x = cur.first, y = cur.second;
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					cn = true;
					cnt = sdist[x][y] + 1;
					break;
				}
				if (schk[nx][ny] || mp[nx][ny] == '#') continue;
				if (sdist[x][y] + 1 >= fdist[nx][ny] && fdist[nx][ny] != -1) continue;
				sq.push({ nx, ny });
				schk[nx][ny] = true;
				sdist[nx][ny] = sdist[x][y] + 1;
			}
			if (cn) break;
		}
		if (cn) cout << cnt << '\n';
		else cout << "IMPOSSIBLE" << '\n';
	}

}

