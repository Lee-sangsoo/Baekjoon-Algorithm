/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.18
���� : NM�� K (1) - 18290
Ǯ�� : N�� M ������ 1�������� ������ ���ؼ� �̾Ƴ��� �������ٸ�
       �� ������ 2�������� ������ �̾Ƴ��� Ǫ�� �����̴�.

	   ó�� �����ߴ� ����� ���� ó���� ��ǥ�� �������� �Ѱܼ� �������� �ƴ��� 
	   Ȯ���ϴ� ����� ���µ�, �̷��� �ϸ� �����Ⱚ�� ������
	   ���� ó�� �Ѱ��ִ� ���� �������� ��� �ϴ����� ��������.

	   �� ������ �ٲ㼭 ������ �����
	   ���� ó���ϰ��� �ϴ� ��ǥ�� ������ ĭ�� �̹� �湮�ߴ��� ���ߴ��� Ȯ���Ͽ�
	   �湮�ߴٸ� �ǳʶٴ� ����� ����Ͽ���.

	   ���������� ������ ����.
	   nx�� ny�� ������ ������ �� �����Ͽ��� �ϸ� (0 <= / > n)
	   ���� ó�� �ּҰ��� ������ �� �������� ������ ���� �ֱ� ������ 
	   ����� ���� ���� �־�� �Ѵٴ� �� 
	   �� �ΰ����� ���� �ؾ� �Ѵ�. 
	   (���� ���� ���� ���� ��ĵ� �߿�)
	   go �Լ��� ���� ����
*/
#include<iostream>

using namespace std;

int n, m, k;
int ans = -2147483647;
int point[11][11];
bool chk[11][11];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void go(int sel, int sum) {
	if (sel == k) {
		if (ans < sum) ans = sum;
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (chk[i][j]) continue;
			bool con = true;
			for (int t = 0; t < 4; t++) {
				int nx = i + dx[t];
				int ny = j + dy[t];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (chk[nx][ny]) con = false;
				}
			}
			if (con) {
				chk[i][j] = true;
				go(sel + 1, sum + point[i][j]);
				chk[i][j] = false;
			}
		}
	}
}
/*
	go �Լ��� �ߺ��� ��ǥ�� ������ �˻��ϱ� ������
	�ð� ���⵵�� ����غ��� �� 1���� ���� �ܿ� �ð��� ����ϰ� �ȴ�.

	�̸� �����ϱ� ���� ���Ǵ� �����
	go_fast �Լ��� ����.

	px�� py�� ������ ������ ���� ��ǥ�� �Ѱ��ִ� ���̸�
	�� ���� �����ͼ� ���� ������ ��ǥ�� ������ �ٿ��ִ� ����̴�.

	i��ǥ�� px���� �����ϴ� ������ ����������,
	j��ǥ�� i���� ���� �ٸ��� �ϴ� ������ ������ ����.
		i == px -> �̹� �˻��� ���̱� ������ px �������� �˻��Ѵ�.
			(������ ������ ��� ���� ���� ���)
		i != px -> �˻����� ���� ���̱� ������ ó������ �˻��Ѵ�.
			(������ ������ ��� �ٸ� ���� ���)
	�̷��� ���� �˻��ϸ� �ߺ��� �˻縦 ���Ѵ�.
*/
void go_fast(int px, int py, int sel, int sum) {
	if (sel == k) {
		if (ans < sum) ans = sum;
		return;
	}

	for (int i = px; i < n; i++) {
		for (int j = (i == px ? py : 0); j < m; j++) {
			if (chk[i][j]) continue;
			bool con = true;
			for (int t = 0; t < 4; t++) {
				int nx = i + dx[t];
				int ny = j + dy[t];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if (chk[nx][ny]) con = false;
				}
			}
			if (con) {
				chk[i][j] = true;
				go_fast(i, j, sel + 1, sum + point[i][j]);
				chk[i][j] = false;
			}
		}
	}
}
/*
	go_1d�� ���
	2�����迭�� �ִ� ���� 1���� �迭�� ���� ó���ϴ� ����̴�.

	N * M ũ���� �迭�� ������ ���� 1�������� ó���� �����ϴ�.
	
	[r][c] = [r*c]
	(r, c) = r * m + c

	�� 2���� �迭�� 1�������� �ٿ��аͰ� �����ϴ�.

	�ݺ����� ���� �ݺ� Ƚ���� ������, go_fast�� ���� ���������� �����ϸ�
	ó���ϸ� �� ������ ������ 
	�������� ������ ���� prev ���� �Ѱ��ش�.
	prev = ���� ���� ��ǥ
*/
void go_1d(int prev, int sel, int sum) {
	if (sel == k) {
		if (ans < sum) ans = sum;
		return;
	}

	for (int j = prev + 1; j < n*m; j++) {
		int x = j / m;
		int y = j % m;
		if (chk[x][y]) continue;
		bool con = true;
		for (int t = 0; t < 4; t++) {
			int nx = x + dx[t];
			int ny = y + dy[t];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (chk[nx][ny]) con = false;
			}
		}
		if (con) {
			chk[x][y] = true;
			go_1d(x*m + y, sel + 1, sum + point[x][y]);
			chk[x][y] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> point[i][j];
		}
	}
	go(0, 0);
	go_fast(0, 0, 0, 0);
	go_1d(-1, 0, 0);
	cout << ans;
}