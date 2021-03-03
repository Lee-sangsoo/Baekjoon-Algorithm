/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.01
���� : �丶�� - 7576
Ǯ�� : dfs�� Ǯ�̰� �Ұ����� ������. bfs ����ؾ� �Ѵ�.
       �丶�䰡 �ϳ��� �־����ٸ� �̷�Ž�� ������ �Ȱ��� Ǯ�� �Ǵµ�,
	   �丶�䰡 ���������� ���� �� �ִ�.

	   �� ��, ��� �丶�信�� �Ȱ��� ���İ� �Ǿ� �ͱ� ������
	   ��� ó�������� �߿��Ͽ���.

	   ó�� ������ ����� Ž���� �ϴٰ� dist�� �̹� ���� �ִٸ� 
	   �� ���� ���ο� ���� ���Ͽ� �� ���� ���� �ִ� ������ �Ͽ��µ�,
	   �̷��� �ϸ� Ž�� �������� ������ �־���.

	   �׷��� �ٽ� ������ ����� ó�� �丶�䰡 �ִ� ��ġ�� �Է¹��� ��
	   ��� �丶�䰡 �ִ� ��ġ�� ť�� �־�ΰ� �� ���� bfs Ž���� �ϴ� ����̿���.

	   �̷��� �����ϰ� �Ǹ� ó�� �丶�䰡 �ִ� ��� ��ġ���� �Ϸ縸�� 
	   ������ ���������� �ǰ� �� ���¿��� ť�� ��Ȳ�� 
	   ��� 2���� �丶����� ��ġ�� ����ִ�.

	   �̷��� �ݺ��ϸ鼭 ���� chk�� true�� ���� �����ٸ� �� ���� �� ���� ����
	   �丶�䰡 �;��ٴ� ���̹Ƿ� ���� �ٲ� �ʿ䰡 ������.

	   ��, ������ �������� 0�� �ƴ� 1�� �־� ó���Ͽ��� ������ 
	   ���信 -1�� �� ���� �����̴�.
*/
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
int tomato[1001][1001];
bool chk[1001][1001];
int dist[1001][1001];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int nowx = cur.first, nowy = cur.second;
		for (int k = 0; k < 4; k++) {
			int nx = nowx + dx[k];
			int ny = nowy + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (tomato[nx][ny] == -1 || chk[nx][ny]) continue;
			q.push({ nx, ny });
			chk[nx][ny] = true;
			dist[nx][ny] = dist[nowx][nowy] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == -1) dist[i][j] = -1;
			if (tomato[i][j] == 1) {
				q.push({ i, j });
				chk[i][j] = true;
				dist[i][j] = 1;
			}
		}
	}

	bfs();

	int ans = 0;
	bool cant = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == 0) cant = true;
			ans = max(ans, dist[i][j]);
		}
	}

	if (cant) cout << -1;
	else cout << ans - 1;
}