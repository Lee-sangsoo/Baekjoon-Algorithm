/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.01
���� : ���� ����� ���� - 11724
Ǯ�� : ��� ������ ���������� �Ͽ� dfs�� bfs�� ���� �����ϸ�
       �湮������ ���� �������� ���ؼ��� Ž���� �����ϸ�
	   �� Ƚ���� ��������.

	   �̸� ���� ó���ϸ� �Ǵ� ������ �����̴�.
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<int> g[1001];
bool chk[1001];
queue<int> q;

void dfs(int x) {
	chk[x] = true;
	for (int i = 0; i < g[x].size(); i++) {
		int y = g[x][i];
		if (!chk[y]) dfs(y);
	}
}

void bfs(int x) {
	chk[x] = true;
	q.push(x);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		for (int i = 0; i < g[y].size(); i++) {
			int cur = g[y][i];
			if (!chk[cur]) {
				chk[cur] = true;
				q.push(cur);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (chk[i]) continue;
		dfs(i);
		ans++;
	}

	cout << ans;
}