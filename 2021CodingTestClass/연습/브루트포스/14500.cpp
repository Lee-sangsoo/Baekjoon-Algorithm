/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.10
���� : ��Ʈ�ι̳� - 14500
Ǯ�� : ��Ʈ�ι̳븦 �����ϴ� ������ �ϳ��� ���� �����ϸ� 
       �� ��ǥ���� �����Ͽ� ���ӵǴ� 3���� ���� �湮�ϴ� ����̴�.
	   �̸� �̿��ϸ� DFS�� ����� ������� Ǯ�̰� �����ϴ�.

	   DFS�� �ٸ����� �� �ϳ� ���̴�. �ϳ��� ������ �ش� ���� ����ߴٰ� �ؼ�
	   �� ���� �׸� ���� �Ǵ°��� �ƴ϶�
	   �ٸ� ������ �ش� ���� ����Ҽ��� �ֱ� ������
	   �̸� ���� ���ִ� chk �迭�� �Լ��� ����� �� �ٽ� false�� �ٲ��־���Ѵ�.

	   ��ó�� ���� ���� ������ Ž���� �����ϸ鼭 
	   ���� ū ���� ã��

	   ������
	     ��
	   �� ����� ���ӵ� 3������ �ƴϱ⵵ �ϰ� ��ͷ� �����ϸ� �ð��� �� ���� �ɸ��� ������
	   �� ��縸 ���� ���ܸ� �ξ� �� ó���� �ϵ��� �Ѵ�.

	   ���� DFS�� �ٸ� �� �ϳ��� �������ָ� �ȴ�.

	   (��� ��� �������� �ð��� �� ���� �ɸ���)
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int a[501][501];
int chk[501][501];

int n, m;
int ans = 0;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void go(int cnt, int cur, int x, int y) {
	if (cnt == 4) {
		ans = max(ans, cur);
		return;
	}

	if (x < 0 || x >= n || y < 0 || y >= m) return;
	if (chk[x][y]) return;
	chk[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		go(cnt + 1, cur + a[x][y], nx, ny);
	}
	chk[x][y] = false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			go(0, 0, i, j);
			if (j + 2 < m) {
				int temp = a[i][j] + a[i][j + 1] + a[i][j + 2];
				if (i - 1 >= 0) {
					int temp2 = temp + a[i - 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
				if (i + 1 < n) {
					int temp2 = temp + a[i + 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
			}
			if (i + 2 < n) {
				int temp = a[i][j] + a[i + 1][j] + a[i + 2][j];
				if (j + 1 < m) {
					int temp2 = temp + a[i + 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
				if (j - 1 >= 0) {
					int temp2 = temp + a[i + 1][j - 1];
					if (ans < temp2) ans = temp2;
				}
			}
		}
	}
	cout << ans;
}