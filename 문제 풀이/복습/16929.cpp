/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.24
���� : Two Dots - 16929
Ǯ�� : ����Ŭ�� ������ ã�� �����̴�.
       DFS�� ����Ͽ� �־��� ��� �׷������� �����¿�� �̵��ϸ� 
	   ����Ŭ�� �����ϴ��� ã���� �ȴ�.

	   ��� ������ ����� 2������ �ִ�.
	   1. dfs�Լ��� cnt ���� �־� ��湮���� cnt ���� ���� ���� cnt ���� ���̰�
		  �󸶳� ������ Ȯ���Ͽ� 3�̻��̶�� ����Ŭ�� �����Ѵٰ� ����.
	   2. ���� ������ ��ǥ�� ���� Ž������ �Ѱ��־� ���� �湮���� �ٽ� ���� �ʵ����ϰ�
		  �� ��, �̹� �湮�� ������ ��湮�Ѵٸ� �̴� ����Ŭ�� �����Ѵٴ� ���̴�.
       
	   �� 2���� ��� �� 2��° ����� ����Ͽ��� ������ �Ʒ��� ����.

	   ******
	   ���� dfs�Լ��� bool �Լ��� �����ϰ� �ʹٸ� (ans ������ ���� �ʴ´ٰ��ϸ�)
	   return dfs( ... ) �� �ƴ϶�
	   if(dfs( ... )) return true; �� ���� ������� ����ؾ��Ѵ�.
	   (��ٷ� return �� ��� ���������� ����� ���� �ʾҴ�)
*/
#include<iostream>
#include<string>

using namespace std;

int n, m;
char arr[51][51];
bool chk[51][51];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool ans = false;

void dfs(int px, int py, int x, int y) {
	if (ans) return;
	chk[x][y] = true;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (px == nx && py == ny) continue;
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (arr[nx][ny] != arr[x][y]) continue;
		if (chk[nx][ny]) {
			ans = true;
			return;
		}
		dfs(x, y, nx, ny);
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
			dfs(-1, -1, i, j);
			if (ans) {
				cout << "Yes";
				return 0;
			}
		}
	}

	cout << "No";
	return 0;
}