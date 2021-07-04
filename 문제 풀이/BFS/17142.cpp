/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.10
���� : 17142 - ������ 3
Ǯ�� : ������ 2(17141) �������� Ư�� ������ �ϳ� �� ����� �����̴�.
       (������ 2 ������ Ǯ��Ҵٸ� �����ϰ� �ذ��� �� �ִ� ����)

	   ��Ȱ��ȭ ���̷����� Ȱ��ȭ ���̷����� ������ �Ǹ� Ȱ��ȭ ���̷����� �Ǵ� ������ �߰��Ǵµ�
	   �� ������ ������ ���� ó���ȴ�.
	   - �̹� �־��� ���̷����� Ȱ��ȭ�Ǵ� ���̱� ������ Ȱ��ȭ �� ��� ������ �ð��� �߰��Ǵ°��� �ƴ� �׳� �� �״�� Ȱ��ȭ ��, �ð��� �ɸ��� �ʴ´�.

	   �̸� �ٽ� �ذ��� ���鿡�� �����ڸ�
	   ��Ȱ��ȭ ���̷����� �ִ� ���� Ȱ��ȭ �ȴٰ� �ؼ� Ȱ��ȭ�� �ð��� �ش� ��ġ���� �ִ� �ð��� ��� �ش� �ð��� �ִ밡 ���� �ʴ´�.
	   (���信 ������ ��ġ�� �ʴ´�)

	   �׷��� ������ ������ 2 �������� 
	   �̸� ���̷����� �־���, �ش� ��ǥ���� ���̷����� ������ �ð��� 0�� �ƴ϶�� ���� ó���� ���Խ�Ű�� �ʴ´�.(ó�� ��Ʈ���� ���̷������� ��ǥ �ð��� ��� 0���� �ʱ�ȭ �ϱ� ����)

	   �̸� ���� �ذ���  �����ϴ�.

	   ���Ʈ���� + BFS�� ��ģ �����̴�.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 987654321;
int n, m;
int arr[51][51];
vector<pair<int, int>> virus;

bool select_chk[11];
pair<int, int> select_virus[11];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs() {
	bool chk[51][51];
	int dist[51][51];
	for(int i = 0; i<n; i++)
		for (int j = 0; j < n; j++) {
			chk[i][j] = false;
			dist[i][j] = -1;
		}

	queue<pair<int, int>> q;
	for (int i = 0; i < m; i++) {
		q.push({ select_virus[i].first, select_virus[i].second });
		chk[select_virus[i].first][select_virus[i].second] = true;
		dist[select_virus[i].first][select_virus[i].second] = 0;
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first, y = cur.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (chk[nx][ny] || arr[nx][ny] == 1) continue;
			chk[nx][ny] = true;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx, ny });
		}
	}

	int cur_ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 2 && dist[i][j] != 0) continue;
			if (arr[i][j] != 1 && dist[i][j] == -1) return;
			cur_ans = max(cur_ans, dist[i][j]);
		}
	}
	ans = min(ans, cur_ans);
}

void select_virus_xy(int nxt, int cnt) {
	if (cnt == m) {
		bfs();
		return;
	}

	for (int i = nxt; i < virus.size(); i++) {
		if (select_chk[i]) continue;
		select_chk[i] = true;
		select_virus[cnt] = virus[i];
		select_virus_xy(i + 1, cnt + 1);
		select_chk[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i<n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				virus.push_back({ i,j });
		}

	select_virus_xy(0, 0);
	if (ans == 987654321) ans = -1;
	cout << ans;
}