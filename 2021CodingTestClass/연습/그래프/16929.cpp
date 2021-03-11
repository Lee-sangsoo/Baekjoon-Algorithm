/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.11
���� : Two Dots - 16929
Ǯ�� : DFS�� ���� ����Ŭ�� �ִ��� ã�� ����
       2���� ����� �ִ�.

	   ù��°�δ� 
	   1. DFS �Լ��� �Ű������� ���� ����Ǵ� �ܰ��� �� (�׷��� ���ۺ��� ��ܰ� ��������)
	   2. �湮 �ߴ��� ���ߴ��� ����
	   3. �湮�Ѱ��� ���� �������κ����� �Ÿ�

	   �� 3������ ������ ���� �������� �������� �湮�ϰ��� �ϴ� ������
	   "�̹� �湮�� ����"�̰� "���� ���� �ܰ�" - "�ش� ������ �Ÿ�" ��
	   4 �̻��̶�� ����Ŭ�� �±� ������ �������� ó���Ѵ�.


	   �ι�°�δ�
	   1. ���� ������ ��ǥ
	   2. ���� ������ ��ǥ

	   �� 2������ ������ ���Ӱ� �湮 ������ ��ǥ�� ���� ������ �����ϴ� ����̴�.
	   �� ���� ������ �湮���� �ʰ� Ž���� �����ϰ� �Ǹ�
	   ����Ŭ�� ������ �ʴ� �� ������ �湮�ߴ� �������� ���� �ʴ´�.

	   �� ���� �̿��Ͽ� ���� ������ ������ ������ ����Ŭ ���θ� �Ǵ� �����ϴ�.
*/
#include<iostream>
#include<string>

using namespace std;

int n, m;
bool chk[51][51];
char arr[51][51];
bool ans;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void go(int px, int py, int x, int y) {
	if (ans) return;
	chk[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx == px && ny == py) continue;
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (arr[x][y] != arr[nx][ny]) continue;
		if (chk[nx][ny]) {
			ans = true;
			return;
		}
		go(x, y, nx, ny);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
			arr[i][j] = s[j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (chk[i][j]) continue;
			go(-1, -1, i, j);
			if (ans) {
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
}