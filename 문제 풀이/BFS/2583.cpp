/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.19
���� : ���� ���ϱ� - 2583
Ǯ�� : BFS �������� ��ǥ ������ �ƴ� ���� �������� ���� �� �� ������ �ٽ�
       ��ǥ�� �������� �ٲ� �� �ִ��� Ȯ�� �ϴ� ����
	   �־��� ������ ��ǥ�� �����Ѵٴ� ���� 
	   �־����� �簢���� ��ǥ���� x, y, nx, ny ��� �� ��
	   x ~ nx - 1 ����
	   y ~ ny - 1 ���� �� �ش� ������ �ǰ�
	   �� �������� 1�� ����� �ְ� 1�� �ƴ� ������ ũ��� ������ �������� �ȴ�.
*/
#include<iostream>
#include<queue>
#include<algorithm>
#include<queue>

using namespace std;

int n, m, k;
int arr[101][101];
bool chk[101][101];
vector<int> ans;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> m >> n >> k;
	while (k--) {
		int x, y, nx, ny;
		cin >> x >> y >> nx >> ny;
		for (int i = x; i < nx; i++) {
			for (int j = y; j < ny; j++) {
				arr[i][j] = 1;
			}
		}
	}

	queue<pair<int, int>> q;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0 && !chk[i][j]) {
				int cnt = 0;
				chk[i][j] = true;
				q.push({ i, j });
				while (!q.empty()) {
					auto cur = q.front();
					q.pop();
					cnt++;
					int x = cur.first, y = cur.second;
					for (int ck = 0; ck < 4; ck++) {
						int nx = x + dx[ck];
						int ny = y + dy[ck];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (chk[nx][ny] || arr[nx][ny] != 0) continue;
						chk[nx][ny] = true;
						q.push({ nx, ny });
					}
				}
				ans.push_back(cnt);
			}
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i : ans)
		cout << i << ' ';
	
}