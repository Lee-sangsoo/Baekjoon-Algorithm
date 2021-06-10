/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.10
���� : 17141 - ������ 2
Ǯ�� : BFS������ ������ ��ģ ����
       �ܼ� BFS�� �ܼ� ���� ������ ��� ���� �����ϰ� Ǯ �� �ְ� �� ������ �� �˰����� ��ġ�� �����ϰ� Ǯ �� �ִ� ���������� �ظŴٰ� Ǯ �� �־���.

	   ������ ���ϴ� ����� 
	   n�� m �������� �ٽ� �ѹ� Ǯ��� ���� �ʿ��ϰ�
	   
	   Ư�� �˰���� Ư�� �˰����� ��ġ�� ������ �������� �ͼ����� ������ �̿� �ͼ������� �� �� ����.

	   �� n���� ���̷������� m���� ��� ó���� �� �� �������� ������ ���õȴ�.
	   (������ ���� : ������ ��� ������ �ٸ� �Ȱ��� ������ ���Ǵµ� �� ���������� ������ �Ȱ��� ����� ���� ������ �ʿ䰡 ����)
	   (�׷��� ������ ������ ���ϴ� select_virus �Լ� ���� �� ���)
	   
	   m���� ���̷����� �����ϰ� �� ���̷����� bfs�� �����Ͽ��ش�.
	   bfs Ž���� ��ģ ����
	   '���� �ƴϸ鼭 Ž���� ���� ���� ��' ��, ���̷����� ������ ���Ѱ��� �ִٸ� ���� �񱳸� ���� �ʴ´�.

	   �� ������ �����ϸ� ���� ����� �����ϸ� �ȴ�.
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int arr[51][51];
vector<pair<int, int>> virus;

bool selected[11];
pair<int, int> select_xy[11];

int dx[] = { -1, 0, 1 ,0 };
int dy[] = { 0, 1, 0, -1 };

int ans = 987654321;

void bfs() {
	queue<pair<int, int>> q;
	bool chk[51][51];
	int dist[51][51];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			chk[i][j] = false;
			dist[i][j] = -1;
		}
	
	for (int i = 0; i < m; i++) {
		q.push({ select_xy[i].first, select_xy[i].second });
		chk[select_xy[i].first][select_xy[i].second] = true;
		dist[select_xy[i].first][select_xy[i].second] = 0;
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first, y = cur.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (arr[nx][ny] == 1 || chk[nx][ny]) continue;
			chk[nx][ny] = true;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx, ny });
		}
	}

	int cur_ans = 0;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 1 && dist[i][j] == -1) {
				flag = true;
				break;
			}
			cur_ans = max(cur_ans, dist[i][j]);
		}
		if (flag) break;
	}
	if(!flag) 
	ans = min(ans, cur_ans);
}

void select_virus(int nxt, int cnt) {
	if (cnt == m) {
		bfs();
		return;
	}

	for (int i = nxt; i < virus.size(); i++) {
		if (selected[i]) continue;
		selected[i] = true;
		select_xy[cnt] = virus[i];
		select_virus(i + 1, cnt + 1);
		selected[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
			
	select_virus(0, 0);
	if (ans == 987654321) ans = -1;
	cout << ans;
}