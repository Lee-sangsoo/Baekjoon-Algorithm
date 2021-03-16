/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.16
���� : ���ϻ��� - 10026
Ǯ�� : BFS�� �̿��Ͽ� �׷��� ���� ���ϴ� �����ε�,
       �� 2���� Ž���� �����ؾ� �Ѵ�. 
	   �� �� �ѹ��� �Ϲ����� BFS�� �����ϸ� �ǰ�
	   �ٸ� �ѹ��� Ž�� ������ �޸��Ͽ� �����Ͽ��� �Ѵ�.

	   ���� �����̱� ������
	   R, G, B �� �߿���
	   R, G�� ���� ������ ���� �ȴ�.
	   �� ���� �ٸ��� �����ڸ� �� �� �ϳ��� B�϶� �ٸ� �ϳ��� B�� �ƴ϶�� 
	   ���� �ٸ� �׷��� �ȴٴ� ���̴�.
*/
#include<iostream>
#include<queue>
#include<string>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool chk[101][101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	char arr[101][101];
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j];
		}
	}

	queue<pair<int, int>> q;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (chk[i][j]) continue;
			q.push({ i, j });
			chk[i][j] = true;

			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				int x = cur.first, y = cur.second;

				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (chk[nx][ny] || arr[x][y] != arr[nx][ny]) continue;
					q.push({ nx, ny });
					chk[nx][ny] = true;
				}
			}

			cnt++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			chk[i][j] = false;
		}
	}

	int cnt2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (chk[i][j]) continue;
			q.push({ i, j });
			chk[i][j] = true;

			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				int x = cur.first, y = cur.second;

				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (chk[nx][ny]) continue;
					if ((arr[x][y] == 'B' && arr[nx][ny] != 'B') || (arr[x][y] != 'B' && arr[nx][ny] == 'B')) continue;
					q.push({ nx, ny });
					chk[nx][ny] = true;
				}
			}

			cnt2++;
		}
	}

	cout << cnt << ' ' << cnt2;
}