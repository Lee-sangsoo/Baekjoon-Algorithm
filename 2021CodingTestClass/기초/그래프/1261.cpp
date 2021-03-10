/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.04
���� : �˰��� - 1261
Ǯ�� : ���� �ν����� �μ��� �ʾҴ��ĸ� ������ ó���ϸ� �Ǵ� �����̴�.
       �ٽ� ����

	   ��� -> ��   = ����ġ 1
	   ��� -> ��� = ����ġ 0 
	   ���� ��� ó���ϸ� �ȴ�. 
	   ��, �������� ���� ����
	   ���̶�� ����ġ�� 1 ����
	   ����̶�� ����ġ�� 0 ���� �� �ȴ�.

	   �������� "���� �μ��� Ƚ��" ��� ǥ���� �ϱ� ������
	   ����ġ�� ���� �μ� Ƚ���� �ȴ�.

	   ����ġ�� 0�̶�� ���� �տ� �־��ְ�
	   ����ġ�� 1�̶�� ���� �ڿ� �־��־� BFS�� ó���ϸ� �ȴ�.

	   �׷��� Ž�� �������� ���� �߿��� ����
	   "������ ����ġ�� �δ°�" �� "� ���� �÷����� Ž���ؾ� �ϴ°�" �̴�.

	   �� �ΰ����� �����ϸ� ���� ó���ؾ� �Ѵ�.
*/
#include<iostream>
#include<string>
#include<deque>

using namespace std;

int n, m;
int arr[101][101];
bool chk[101][101];
int brk[101][101];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

deque<pair<int, int>> dq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			arr[i][j] = s[j] - '0';
	}

	dq.push_back({ 0,0 });
	chk[0][0] = true;
	while (!dq.empty()) {
		auto cur = dq.front();
		dq.pop_front();
		int x = cur.first, y = cur.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (chk[nx][ny]) continue;

			if (arr[nx][ny] == 1) {
				dq.push_back({ nx, ny });
				chk[nx][ny] = true;
				brk[nx][ny] = brk[x][y] + 1;
			}
			else {
				dq.push_front({ nx, ny });
				chk[nx][ny] = true;
				brk[nx][ny] = brk[x][y];
			}
		}
	}
	cout << brk[n - 1][m - 1];
}