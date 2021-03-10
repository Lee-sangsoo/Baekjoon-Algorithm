/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.03
���� : �̷� Ž�� - 2178
Ǯ�� : �Ÿ��� ã�� �⺻���� ����
       �Ÿ��� ã�� ������ dfs�δ� �Ұ����ϰ� bfs�� Ǯ��� �Ѵ�.
	   (dfs�� ��� ���� ��ġ���� �� �� �ִ� ��� ��ġ�� �Ÿ� + 1 �� �Ǿ�� �ϴµ� �װ� �ȵ�)

	   �̸� ���� bfs�� �����Ͽ� ����ϸ� ó�� �����ϴ�.
*/
#include<iostream>
#include<string>
#include<queue>

using namespace std;

int arr[101][101];
bool chk[101][101];
int dist[101][101];
int n, m;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(pair<int, int> p) {
	queue<pair<int, int>> q;
	int x = p.first, y = p.second;
	q.push({ x, y });
	dist[x][y] = 1;
	chk[x][y] = true;

	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		int nowx = now.first, nowy = now.second;
		for (int i = 0; i < 4; i++) {
			int nx = nowx + dx[i];
			int ny = nowy + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (chk[nx][ny] || arr[nx][ny] == 0) continue;
			q.push({ nx, ny });
			chk[nx][ny] = true;
			dist[nx][ny] = dist[nowx][nowy] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			arr[i][j] = s[j] - '0';
	}

	dfs({ 0,0 });

	cout << dist[n - 1][m - 1];
}