/*
�ۼ��� : �̻��
�Ͻ� : 2021.05.04
���� : �Ʊ� ��� - 16236
Ǯ�� : ������ �Ｚ ���⹮��
       bfs�� ������ ���ĵ� �����̴�.

	   bfs�� �ܼ� ������ �� �ƴ϶� �߰����� ���� �߰��� �ʿ��ϴ�.

	   1. ���� �� �ִ� ����Ⱑ �ִ��� Ȯ���ϴ� �Լ� (find_fish)
	   2. ��ġ���� ���ʳ� �ɸ����� Ȯ���� ���� �Լ� (BFS)
	   3. ���� ���¿��� (0, 0) ~ (N, N)���� ���ʴ�� Ȯ���ϸ� "���� �� �ְ�" "�ּ� �Ÿ�"�� ������ ����� ã�� (find_food)
	   4. �̵��ϱ�

	   �� 4�ܰ踦 main �Լ� �ȿ��� �߰����� �Լ��� ���� �����Ͽ���.

	   �� Ž���� ���� ����� ���� ��� �ִ�.
	   1. find_fish�� ���� �̵��� �������� Ȯ���ϱ� ���� ���� bfs Ž���� ���� ���־�� �Ѵ�. ( ����� ũ�� Ȯ��, ����Ⱑ �ִ��� Ȯ��, �̵� �������� Ȯ��)
	   2. bfs���� �̵��� ������ ���� "����� ũ�� <= ��� ũ��" �� �κ��̴�.
	   3. find_food���� ����� ���� ������ ����.
	    3-1. ���� ũ�Ⱑ ���� ������ ã��
		3-2. �̵� �Ÿ��� �ּ��� ����� ã��
		 3-2-1. �Ÿ��� ���ٸ� ���� ����, ������ ������ ã��
	   �� ������ ��ģ ���� ���� �̵��� ��ġ�� �Ѱ��ְ� �ش� ��ġ�� �� �̵���Ű�� �ȴ�.

	   �߰������� ����� ũ�⸦ ���������ִ� �κе� �ʿ��ϴ�.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int shark_size;
int arr[21][21];
int dist[21][21];
bool chk[21][21];
int nx, ny;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool find_fish() {
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			if (shark_size > arr[i][j] && arr[i][j] != 0 && dist[i][j] != 0) return false;

	return true;
}

void bfs() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			dist[i][j] = 0;
			chk[i][j] = false;
		}

	queue<pair<int, int>> q;
	q.push({ nx, ny });
	chk[nx][ny] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first, y = cur.second;
		for (int k = 0; k < 4; k++) {
			int nxtx = x + dx[k];
			int nxty = y + dy[k];
			if (nxtx < 0 || nxtx >= n || nxty < 0 || nxty >= n) continue;
			if (arr[nxtx][nxty] > shark_size || chk[nxtx][nxty]) continue;
			dist[nxtx][nxty] = dist[x][y] + 1;
			q.push({ nxtx, nxty });
			chk[nxtx][nxty] = true;
		}
	}
}

pair<int, int> find_food() {
	pair<int, int> ret = { n, n };
	int min_dist = n * n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (shark_size > arr[i][j] && arr[i][j] != 0 && dist[i][j] != 0) {
				if (min_dist > dist[i][j]) {
					min_dist = dist[i][j];
					ret.first = i;
					ret.second = j;
				}
				else if (min_dist == dist[i][j]) {
					if (ret.first > i && ret.second > j) {
						ret.first = i;
						ret.second = j;
					}
				}
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	shark_size = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				nx = i;
				ny = j;
			}
		}
	}

	int sec = 0;
	int grow = 0;
	while(1) {
		bfs();

		if (find_fish()) {
			cout << sec;
			break;
		}

		auto nxt = find_food();
		arr[nx][ny] = 0;
		arr[nxt.first][nxt.second] = 9;
		sec += dist[nxt.first][nxt.second];
		grow++;
		if (grow == shark_size) {
			shark_size++;
			grow = 0;
		}
		nx = nxt.first;
		ny = nxt.second;

		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << arr[i][j] << ' ';
			cout << '\n';
		}
		cout << '\n';
		*/
	}
}

/*
6

1 2 1 1 1 1

1 3 6 2 2 3

1 2 5 2 2 3

3 3 2 4 6 3

0 0 0 0 0 6

0 0 0 1 1 9
*/