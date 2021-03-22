/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.22
���� : ���� - 2573
Ǯ�� : BFS�� Ȱ���Ͽ� ������ ���ҿ� �׷��� ���� �����ϴ� �Լ��� ����Ͽ� Ǯ�� �Ǵ� �����̴�.
       
	   ���� ���� -> ���� ������ �������� ��, ��, ��, �쿡 ��� �ٴٰ� �ִ��� Ȯ���Ͽ�
	   �ش� ������ ���ο� �迭 Ȥ�� ���Ϳ� �����Ͽ� �������� ���ҽ�Ų��.
	   (�ȱ׷��� ������ ȿ���� ������ �ٸ� ���꿡 ������ ��ġ�� �ȴ�)

	   �׷� �� -> bfs�� ���鼭 ����� ť Ž���� ����Ǿ��°� Ȯ���Ѵ�.
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m;
int arr[301][301];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };


int bfs() {
	bool chk[301][301];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			chk[i][j] = false;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > 0 && chk[i][j] == false) {
				cnt++;
				queue<pair<int, int>> q;
				q.push({ i, j });
				chk[i][j] = false;
				
				while (!q.empty()) {
					auto cur = q.front();
					q.pop();
					int x = cur.first, y = cur.second;
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (chk[nx][ny] || arr[nx][ny] <= 0) continue;
						q.push({ nx, ny });
						chk[nx][ny] = true;
					}
				}
			}
		}
	}
	return cnt;
}

void decrease() {
	vector<vector<int>> tmp;
	for (int i = 0; i < n; i++) {
		vector<int> dec;
		for (int j = 0; j < m; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (arr[nx][ny] <= 0) cnt++;
			}
			dec.push_back(cnt);
		}
		tmp.push_back(dec);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] -= tmp[i][j];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int i = 0; ; i++) {
		int res = bfs();
		if (res >= 2) {
			cout << i;
			break;
		}
		else if (res == 0) {
			cout << 0;
			break;
		}
		decrease();
	}
}