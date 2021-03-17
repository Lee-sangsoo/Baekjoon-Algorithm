/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.17
���� : �ҹ��� ĥ���� - 1941
Ǯ�� : ���������� ���ļ� Ǯ��� �ϴ� ��Ʈ��ŷ �����̴�.
       �� 25���� �ڸ����� 7���� �̾Ƽ� ó���ϴ� �����ε�,
	   7���� �ڸ��� ��� ������ �Ǿ������� �ƹ��� �𸥴�.
	   �׷��� ������ �Ϲ����� DFS�� BFS�� Ǯ��� �����
	   ������ �̿��Ͽ� 0 ~ 24�� �� �� 7���� �̾Ƽ� �� ���� n�̶�� �� ��
	   arr[n / 5][n % 5] �� ���� �ش� ���� �����ϵ��� �Ѵ�.

	   �̷��� ���� ������ BFS�� ���� ���� ������ �ڸ��� �ִ��� Ȯ���ϰ�
	   ������ �ڸ��� ��ġ�Ѵٸ� �� ���鿡 'S'�� ������ 4�� �̻�����
	   Ȯ���� ���� ������ ������Ű�� �ȴ�.

	   1. 25�� �߿��� 7�� �̱�
	   2. ���� 7���� ���� �������� Ȯ��
	   3. ���� 7�� �� 4�� �̻��� 'S'���� Ȯ��

	   ��� ������ ���� ����.

	   3�� Ȯ���Ͽ� ������ 2�� Ȯ���ϴ� ����� 
	   2�� Ȯ���Ͽ� ������ 3�� Ȯ���ϴ� ��ĺ���
	   ��ǻ�Ϳ����� ������ ���ؿ����� ������
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int ans = 0;
char arr[5][5];
char brr[7];
vector<pair<int, int>> xy;
bool chk[5][5];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool check() {
	int zerone[5][5];
	bool chhk[5][5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			zerone[i][j] = 0;
			chhk[i][j] = false;
		}


	for (int i = 0; i < 7; i++)
		zerone[xy[i].first][xy[i].second] = 1;

	queue<pair<int, int>> q;
	q.push({ xy[0].first, xy[0].second });
	chhk[xy[0].first][xy[0].second] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int x = cur.first, y = cur.second;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			if (chhk[nx][ny] || zerone[nx][ny] != 1) continue;
			q.push({ nx, ny });
			chhk[nx][ny] = true;
		}
	}

	for (int i = 0; i < 7; i++)
		if (chhk[xy[i].first][xy[i].second] == false) return false;

	return true;
}

void go(int st, int cnt) {
	if (cnt == 7) {
		if (!check()) return;
		int count = 0;
		for (int i = 0; i < 7; i++)
			if (brr[i] == 'S') count++;
		if (count >= 4) ans++;
		return;
	}

	for (int i = st; i < 25; i++) {
		int x = i / 5;
		int y = i % 5;
		brr[cnt] = arr[x][y];
		xy.push_back({ x, y });
		go(i + 1, cnt + 1);
		xy.pop_back();
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 5; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 5; j++)
			arr[i][j] = s[j];
	}

	go(0, 0);

	cout << ans;
}