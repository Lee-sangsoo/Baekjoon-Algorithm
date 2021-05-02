/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.29
���� : ������ - 14502
Ǯ�� : BFS�� ����Ž���� ������ ����
       BFS �κ��� �����ߴ�. ���� ��ĭ���� ���������� ���� ��� ���������� ���� ���ΰ� ����
	   ��� ������ ������ �� ��ĭ(0)�� ����Ͽ� �������ָ� �Ǿ���.

	   ����Ž���� ��� �ִ� ���� 3������ ���� �� �ֱ� ������
	   �ִ� ũ�Ⱑ 8 X 8�� ũ���̹Ƿ� ��� ����� ���� ó�� �غ��Ƶ� �Ǵ� ��������.
	   �� ��� ��ĭ�� ���� ���� ���ư��� Ȯ�����ָ� �ȴ�.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
int arr[9][9];
bool chk[9][9];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int bfs(int k[][9]) {
	queue<pair<int, int>> q;
	int a[9][9];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			a[i][j] = k[i][j];
			chk[i][j] = false;
		}
			

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 2) {
				q.push({ i, j });
				chk[i][j] = true;
			}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first, y = cur.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (a[nx][ny] == 1 || chk[nx][ny]) continue;
			a[nx][ny] = 2;
			chk[nx][ny] = true;
			q.push({ nx, ny });
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 0)
				cnt++;

	return cnt;
}

void show(int a[][9]) {
	cout << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << a[i][j] << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	int total = n * m;
	int ans = 0;
	for (int i = 0; i < total; i++) {
		if (arr[i / m][i % m] == 1 || arr[i / m][i % m] == 2) continue;
		for (int j = i + 1; j < total; j++) {
			if (arr[j / m][j % m] == 1 || arr[j / m][j % m] == 2) continue;
			for (int k = j + 1; k < total; k++) {
				if (arr[k / m][k % m] == 1 || arr[k / m][k % m] == 2) continue;
				arr[i / m][i % m] = 1;
				arr[j / m][j % m] = 1;
				arr[k / m][k % m] = 1;
				int tmp = bfs(arr);
				if (ans < tmp) ans = tmp;
				arr[i / m][i % m] = 0;
				arr[j / m][j % m] = 0;
				arr[k / m][k % m] = 0;
			}
		}
	}
	cout << ans;
}

