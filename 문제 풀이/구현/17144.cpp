/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.02
���� : 17144 - �̼����� �ȳ�!
Ǯ�� : ũ�� 2���� ����� �����ϸ� �ذ��� ������ �����̴�.

	   �⺻ ����
	   1. ���� ũ��� R X C ũ���̴�
	   2. ���� û����� �׻� 1���� �����ϸ� 2���� ���� �����Ѵ�
	   3. a �迭�� �̼������� ���̴�.
       ������ ��
	   1. �̼����� Ȯ��
	      - (r,c)�� ���� 4�������� Ȯ��ȴ�.
		  - ���� û���� Ȥ�� ���� ��� Ȯ����� �ʴ´�.
		  - Ȯ�� �Ǵ� ���� a[r][c] / 5 �̴� (�Ҽ����� ������)
		  - Ȯ���� ���� ���� a[r][c]�� �̼����� ���� (a[r][c] / 5) * Ȯ��� ���� ��ŭ �����Ѵ�.
	   2. ���� û���� �۵�
	      - ���� û������ ������ ��� �ݽð� �������� �ٶ��� �д�.
		  - ���� û������ �Ʒ����� ��� �ð� �������� �ٶ��� �д�.
		  - �� �Ʒ� ��� �ٶ� ���⿡ ���� ��ĭ�� �̵��Ѵ�.
		  - ���� û���⿡�� ������ �ٶ��� �̼����� ���� 0�̸� ���� ��쵵 �̼������� 0�̵ȴ�.
	   3. �� �̼������� ��

	   �� 3������ �����Ͽ� T�� ���� �ݺ��ǵ��� �����ϸ� �ȴ�.

	   Ȯ���� ��� �� ĭ���� �󸶳� ���� �����Ǵ��� ���ϱ� ���� ���� add_dust��� �迭�� �ΰ� ��� Ȯ���Ų ����
	   �ѹ��� �� ���� ������Ű���� �Ѵ�.

	   ���� û������ �۵���
	   ó�� ��迡�� ������ �ٶ��� �̼������� 0�̴� ��
	   ������ ���� ���� �̼������� ������ٴ� ���� ����ϸ� �ӽ� �迭�� ������ �ʾƵ� ó���� �����ϴ�.

	   ó�� ������ ���� �����صΰ� ������ ��� �����ϴٰ� ������ ���� ���� �������� �ʾƵ� �ȴ�.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int r, c, t;
int a[51][51];
vector<pair<int, int>> air_cleaner;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void spread() {
	int add_dust[51][51];
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			add_dust[i][j] = 0;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (a[i][j] == 0 || a[i][j] == -1) continue;
			int spread_cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 1 || nx >= r + 1 || ny < 1 || ny >= c + 1) continue;
				if (a[nx][ny] == -1) continue;
				add_dust[nx][ny] += a[i][j] / 5;
				spread_cnt++;
			}
			add_dust[i][j] -= (a[i][j] / 5) * spread_cnt;
		}
	}

	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			a[i][j] += add_dust[i][j];
}

void up_work() {
	int x = air_cleaner[0].first;
	int y = air_cleaner[0].second;
	int prev_dust = 0;
	for (int i = y + 1; i <= c; i++) {
		int nxt_dust = a[x][i];
		a[x][i] = prev_dust;
		prev_dust = nxt_dust;
	}
	for (int i = x - 1; i >= 1; i--) {
		int nxt_dust = a[i][c];
		a[i][c] = prev_dust;
		prev_dust = nxt_dust;
	}
	for (int i = c - 1; i >= y; i--) {
		int nxt_dust = a[1][i];
		a[1][i] = prev_dust;
		prev_dust = nxt_dust;
	}
	for (int i = 2; i < x; i++) {
		int nxt_dust = a[i][y];
		a[i][y] = prev_dust;
		prev_dust = nxt_dust;
	}
}

void down_work() {
	int x = air_cleaner[1].first;
	int y = air_cleaner[1].second;
	int prev_dust = 0;
	for (int i = y + 1; i <= c; i++) {
		int nxt_dust = a[x][i];
		a[x][i] = prev_dust;
		prev_dust = nxt_dust;
	}
	for (int i = x + 1; i <= r; i++) {
		int nxt_dust = a[i][c];
		a[i][c] = prev_dust;
		prev_dust = nxt_dust;
	}
	for (int i = c - 1; i >= y; i--) {
		int nxt_dust = a[r][i];
		a[r][i] = prev_dust;
		prev_dust = nxt_dust;
	}
	for (int i = r - 1; i > x; i--) {
		int nxt_dust = a[i][y];
		a[i][y] = prev_dust;
		prev_dust = nxt_dust;
	}
}

int total_dust() {
	int cnt = 0;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (a[i][j] == -1) continue;
			cnt += a[i][j];
		}
	}
	return cnt;
}

void show_dust() {
	cout << '\n';
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> r >> c >> t;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1) {
				air_cleaner.push_back({ i, j });
			}
		}
	}

	while (t--) {
		spread();
		up_work();
		down_work();
	}
	int ans = total_dust();
	cout << ans;
}

