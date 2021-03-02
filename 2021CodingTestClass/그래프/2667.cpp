/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.02
���� : ������ȣ���̱� - 2667
Ǯ�� : bfs�� dfs�� ����Ͽ� ���ã��� ����ϴ�.
       ������ void���̿��� dfs�� bfs �⺻������ ������ ũ�⸦ return ���־�� �ϱ� ������
	   int������ �ٲ��־�� �Ѵ�.
	   ó�� Ž���� ������ �� ũ��� 1�μ� ť�� ���ο� ��Ұ� �߰��� ������ ����
	   ���������ָ� �ȴ�.
	   ���� ���������ְ� Ž���� ������ (�ڽ��� �ֺ��� ��� 1�� �ƴҶ�) �� ���� return ���ش�.

	   �� ������ ������ Ž���� ��� ��忡 ���� �����ϰ�
	   ���� ������ ���� ���� ������ ��� ���ش�.

	   1. ���� ũ�⸦ ���� ��
	   2. ���� ������ ���� ���� �ʿ��ϴ�.

	   dfs�� Ǯ �� ó�� int �Լ��� ���� return �ϵ��� �ҷ��� ������
	   �ùٸ� ���� ������ �ʾҴ�.
	   �̸� �ذ��ϰ��� �� ����� ���������� �ϳ��� ���� �� ���� �������״�.
	   ���ǿ��� ó���� ����� �� ������ ��ȣ�� �Űܼ�
	   �ش� ���� ��ȣ�� �ε����� �ϴ� �迭�� ������ ���� ���� Ž���ϸ� ���������� ��Ÿ������.
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int arr[26][26];
bool chk[26][26];
int n;
int cntSz = 0; // dfs�� ��

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int bfs(pair<int, int> p) {
	int x = p.first, y = p.second;
	queue<pair<int, int>> q;
	q.push({ x,y });
	chk[x][y] = true;

	int cnt = 1;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int nowx = cur.first, nowy = cur.second;
		for (int k = 0; k < 4; k++) {
			int nx = nowx + dx[k];
			int ny = nowy + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (arr[nx][ny] == 0 || chk[nx][ny]) continue;
			q.push({ nx, ny });
			chk[nx][ny] = true;
			cnt++;
		}
	}

	return cnt;
}

void dfs(pair<int, int> p) {
	int x = p.first, y = p.second;
	chk[x][y] = true;
	cntSz++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (chk[nx][ny] || arr[nx][ny] == 0) continue;
		dfs({ nx, ny });
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			arr[i][j] = s[j] - '0';
	}

	int cnt = 0;
	vector<int> sz;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && chk[i][j] == false) {
				cnt++;
				//int cntSz = bfs({i,j}); // bfs�� ��
				cntSz = 0; // dfs�� ��
				dfs({ i,j }); // dfs�� ��
				sz.push_back(cntSz);
			}
		}
	}

	cout << cnt << '\n';
	sort(sz.begin(), sz.end());
	for (int i : sz)
		cout << i << '\n';
}