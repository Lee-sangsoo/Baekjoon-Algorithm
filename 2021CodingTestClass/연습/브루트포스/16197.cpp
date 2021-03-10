/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.10
���� : �� ���� - 16197
Ǯ�� : BFSó�� �������� ���Ʈ�����ʿ� �� ������.
       ������ ó�� Ǯ �� ���Ǹ� ���� �ʰ� Ǯ�ٺ���
	   �����̶�� �����̶�� �� �� �ִ� void ���� ��ȣ�Ѵ�.
	   �׷��ٺ��� ���ᰪ�� �������� ���ߴµ�, ���߿� ������ �����غ���
	   
	   ���� Ƚ���� 10ȸ�� �Ѿ �� �׳� �������ִ°� �ƴ϶�
	   ���� 11�� �ʱ�ȭ�Ͽ� ���Ḧ ���ְ� ���� ��¿� �־�
	   ���� 11�̶�� -1�� ������ִ� ����� �ϸ� �Ǵ� ��������.

	   �����ؾ� �ϴ� �κ�
	   1. ���� ���� (t�� 10���� ũ�ٸ�)
	   2. �̵��� ��, �̵��ϴ� ���� ���̶�� �̵����� �ʵ����ϴ� ��
	   3. ���� ��¿� �־� ���� �����ϴ� ��

	   2���� �߿��ϴ�. (���� ������ �����̰�, ���̶�� �� ���� ���� �״�� ���� = �������� ����)
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<char>> con;
vector<pair<int, int>> coin;
int n, m;


int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int go(int t, int fx, int fy, int sx, int sy) {
	if (t > 10) {
		return -1;
	}

	int cnt = 0;
	if (fx < 0 || fx >= n || fy < 0 || fy >= m) cnt++;
	if (sx < 0 || sx >= n || sy < 0 || sy >= m) cnt++;
	if (cnt == 1) {
		return t;
	}
	else if (cnt == 2) return -1;
	int ans = -1;

	for (int i = 0; i < 4; i++) {
		int nfx = fx + dx[i];
		int nfy = fy + dy[i];

		int nsx = sx + dx[i];
		int nsy = sy + dy[i];

		if (nfx >= 0 && nfx < n && nfy >= 0 && nfy < m && con[nfx][nfy] == '#') {
			nfx = fx;
			nfy = fy;
		}
		if (nsx >= 0 && nsx < n && nsy >= 0 && nsy < m && con[nsx][nsy] == '#') {
			nsx = sx;
			nsy = sy;
		}
		int tmp = go(t + 1, nfx, nfy, nsx, nsy);
		if (tmp == -1) continue;
		if (ans == -1 || ans > tmp) ans = tmp;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vector<char> tmp;
		for (int j = 0; j < s.length(); j++) {
			tmp.push_back(s[j]);
			if (s[j] == 'o') {
				coin.push_back({ i, j });
			}
		}
		con.push_back(tmp);
	}

	cout << go(0, coin[0].first, coin[0].second, coin[1].first, coin[1].second);
}