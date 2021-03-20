#include<iostream>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

int n, m;
int arr[1001][1001];
bool chk[1001][1001];
int dist[1001][1001];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };


void setup() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			chk[i][j] = false;
			dist[i][j] = 0;
		}
	}
}

int bfs() {
	queue<pair<int, int>> q;
	int ans = -1;
	q.push({ 0, 0 });
	chk[0][0] = true;
	dist[0][0] = 1;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first, y = cur.second;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (chk[nx][ny] || arr[nx][ny] != 0) continue;
			q.push({ nx, ny });
			chk[nx][ny] = true;
			dist[nx][ny] = dist[x][y] + 1;
		}
	}

	if (dist[n - 1][m - 1] != 0) ans = dist[n - 1][m - 1];
	return ans;
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

	int ans;
	ans = bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				setup();

				arr[i][j] = 0;
				int tmp = bfs();
				if (ans == -1) ans = tmp;
				else {
					if(tmp != -1) ans = min(ans, tmp);
				}
				arr[i][j] = 1;
			}
		}
	}

	cout << ans;
}



/*
1. BFS�� ���ؼ� ���� �ذ��� �� �ִ� �����̴�. ���� ������ Queue���� 4���� ������ �������־���.

  { {x, y}, {�� �μ� Ƚ��, ���� ĭ��} } �̷��� �� 4���� �����鿡 ���ؼ� �������־���.



2. �Ϲ����� BFS�� �����Ű��, ���� �ν����� �Ⱥν������� ���ؼ��� ���� Ȯ���� ���ָ� �Ǳ� ������

   Ž���� ������ ��Ÿ���� Visit�Լ��� 3���� �迭�� �̿��ؼ� ��Ÿ������.

   Visit[x][y][�����μ�Ƚ��] �̷��� ǥ���Ͽ���.

   �̹� �湮�� �����̴���, ���� �μ��� �Դ���, ���� �μ��� �ʰ� �Դ����� ���� �ٸ� ��ΰ� �Ǳ� ������ ������ ǥ��

   �Ͽ���.



3. BFS�ȿ��� �̵��� ����ĭ�� ���ؼ��� ������ �ϳ� �� ������ �־�� �Ѵ�.

  1. ���� �̵��Ϸ��� ���� ĭ�� ���̰�, �̹� ���� �ѹ� �μ̴ٸ�?

	 �� ���̻� ������ �� ����. ���� Queue�� �־����� �ʴ´�.

  2. ���� �̵��Ϸ��� ���� ĭ�� ���̰�, ���� ���� �μ��� �ʾҴٸ�?

	 �� ���� �ν��ٴ� ǥ�ø� ���ְ�, Queue�� �־ ���� �ܰ踦 �����Ѵ�.

  3. ���� �̵��Ϸ��� ���� ĭ�� �� ĭ�̰�, ���� �ѹ� �μ��� �湮�Ѵٸ�?

	 �� ���� �ѹ� �μ��� �湮�� �������� Ȯ�����ְ�, �ƴ϶�� Queue�� �־ ���� �ܰ踦 �����Ѵ�.

  4. ���� �̵��Ϸ��� ���� ĭ�� �� ĭ�̰�, ���� �μ��� �ʰ� �湮�Ѵٸ�?

	 �� ���� �μ��� �ʰ� �湮�� �������� Ȯ�����ְ�, �ƴ϶�� Queue�� �־ ���� �ܰ踦 �����Ѵ�.



  �����ؾߵ� �� 4������ �Ǵ� �� ó�� ��������, ������ �����غ��� �׷��� �ʴ�.

  ��Ȯ�� ������ �ڵ带 ��������.



��ó: https://yabmoons.tistory.com/73 [�幮's Coding World..]
*/