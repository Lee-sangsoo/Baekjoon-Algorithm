/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.18
���� : ���� ���� - 2468
Ǯ�� : BFS�� ����Ͽ� Ǫ�� ����
       �־����� ���� �������� �ִ� ���� ã�Ƽ� �� �� ������ Ȯ���� �ϸ� �ȴ�.
	   1���� �ش� ���ڱ��� BFS�� ���鼭 �ش� ���� �ִ밡 �� �� ans ���� �ٲٵ��� �Ѵ�.
*/
#include<iostream>
#include<queue>

using namespace std;

int n;
int arr[101][101];
bool chk[101][101];
int ans = 1;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	int maxVal = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (maxVal < arr[i][j]) maxVal = arr[i][j];
		}
	
	for (int k = 1; k <= maxVal; k++) {

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				chk[i][j] = false;

		queue<pair<int, int>> q;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] > k && chk[i][j] == false) {
					q.push({ i, j });
					chk[i][j] = true;

					while (!q.empty()) {
						auto cur = q.front();
						q.pop();
						int x = cur.first, y = cur.second;
						for (int m = 0; m < 4; m++) {
							int nx = x + dx[m];
							int ny = y + dy[m];
							if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if (chk[nx][ny] || arr[nx][ny] <= k) continue;
							q.push({ nx, ny });
							chk[nx][ny] = true;
						}
					}
					cnt++;
				}
			}
		}

		if (ans < cnt) ans = cnt;
				
	}

	cout << ans;


}