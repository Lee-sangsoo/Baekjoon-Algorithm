/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.16
���� : ����� ���� - 1012
Ǯ�� : �־��� ����� �׷��� ���� �׷��� ������ ���ϴ� ����
       bfs�� ���鼭 �� ��� �ݺ��Ǵ��� Ȯ���ϸ� �Ǵ� ������ �����̴�.
*/
#include<iostream>
#include<queue>

using namespace std;

int t, n, m, k;
int arr[51][51];
bool chk[51][51];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = 0;
				chk[i][j] = false;
			}
		}

		while (k--) {
			int a, b;
			cin >> a >> b;
			arr[a][b] = 1;
		}

		queue<pair<int, int>> q;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (chk[i][j] == false && arr[i][j] == 1) {
					q.push({ i, j });
					
					while (!q.empty()) {
						auto cur = q.front();
						q.pop();
						int x = cur.first, y = cur.second;
						for (int k = 0; k < 4; k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
							if (chk[nx][ny] || arr[nx][ny] != 1) continue;
							q.push({ nx, ny });
							chk[nx][ny] = true;
						}
					}

					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}