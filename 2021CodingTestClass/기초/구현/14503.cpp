/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.06
���� : �κ� û�ұ� - 14503
Ǯ�� : ��������
       ���� ������ ��κ� �ǵ��� �ľ��ϸ� �����ϰ� ó���� �����ϴ�.
	   �ǵ��� �ľ��ϴµ� ��	�� ���̸� ��� �ظŰ� �ǰ� �׿����� �ð��� �����ɸ���.

	   �� ������ �� ��쿡���� �켱������ �� ������ ó���ϸ� Ǯ�̰� ������ �����̴�.

	   c->d->a->b ������ ó���ϸ� �ȴ�.
	   �����丵�ϸ� �� �� ����� �ڵ尡 �ɰ� ���⵵�ϴ�.
*/
#include<iostream>

using namespace std;

int n, m, r, c, d;
int arr[51][51];
bool chk[51][51];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	int x = r, y = c;
	int ans = 0;
	while (1) {
		// 1��
		if (!chk[x][y]) {
			chk[x][y] = true;
			ans++;
		}

		// 2��

		// c, d. 4���� û�� ���ο� �� ���� Ȯ��
		int cnt = 0;
		for (int k = 0; k < 4; k++) {
			int nxx = x + dx[k];
			int nyy = y + dy[k];
			if (nxx < 0 || nxx >= n || nyy < 0 || nyy >= m) continue;
			if (arr[nxx][nyy] == 1 || chk[nxx][nyy]) cnt++;
		}

		// 4���� ��� ���̰ų� û�Ҹ� �ߴ�
		if (cnt == 4) {
			// ������ ��� ��ǥ
			int nxx, nyy;
			if (d == 0) {
				nxx = x + dx[2];
				nyy = y + dy[2];
			}
			else if (d == 1) {
				nxx = x + dx[3];
				nyy = y + dy[3];
			}
			else if (d == 2) {
				nxx = x + dx[0];
				nyy = y + dy[0];
			}
			else {
				nxx = x + dx[1];
				nyy = y + dy[1];
			}

			// ���� ���� ���� Ȯ��
			// ���� �Ұ� (���̸�)
			if (arr[nxx][nyy] == 1) break;
			else {
				x = nxx;
				y = nyy;
				continue;
			}
		}


		//���� ȸ��
		if (d == 0) d = 3;
		else d -= 1;

		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		// a. ���ʿ� û������ �������� �ְ� �� �� �ִٸ�
		if (!chk[nx][ny] && arr[nx][ny] == 0) {
			x = nx;
			y = ny;
			continue;
		}
		// b. ���ʿ� û���� ������ ���ٸ� = �̹� û�� �߰ų� ���̶��
		else {
			continue;
		}
	}

	cout << ans;
}