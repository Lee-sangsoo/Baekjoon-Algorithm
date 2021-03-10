/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.04
���� : �̸�Ƽ�� - 14226
Ǯ�� : ��� �б⸦ ���� �ϴ°� ���� �ʴ°��� ���� �̵��ϴ� ������ �޶����� �����̴�.
       ������ ���� �� ǥ������ ������ Ǯ�̴� 1���� �迭�� ����� DP�� BFS ����������,
	   �� ������ 
	   "ȭ�鿡 ǥ�õǴ� �̸�Ƽ���� ����" 
	   ��
	   "Ŭ�� ���忡 ����Ǿ��ִ� �̸�Ƽ���� ����"
	   �� ������ Ǯ��� �ϴ� 2���� ������� �� �� �ִ�.

	   ��, �ᱹ ���� ����� ȭ�鿡 ǥ�õǴ� �̸�Ƽ���� ����������, 
	   �� �������� Ŭ�����忡 ��� �ִ����� �ٸ��� �����̴�.

	   ȭ�� = S  Ŭ������ = C ��� �ϰ� ���� (S, C) ������ �ִٰ� �� ��
	   1. ���� = (S, C) -> (S, S) �� �̵��Ѵ� �� �� �ְ�
	   2. �ٿ��ֱ� = (S, C) -> (S+C, C) �̸�
	   3. ���� = (S, C) -> (S-1, C) �� �ȴ�.

	   ���� ó�� ȭ�鿡 ǥ�õǴ� �̸�Ƽ���� 1���̰�
	   Ŭ�����忡 ����Ǿ��ִ� �̸�Ƽ���� ������ 0����� ������
	   (1, 0)���� �����ϸ� �ȴ�.

	   �� �� BFS�� ���鼭 ó���ϸ� �Ǹ�
	   DP�ε� Ǯ ���� �ִ�.
*/
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int s, c;
int cnt[2001][2001];
bool chk[2001][2001];
queue<pair<int, int>> q; // first = ȭ��, second = Ŭ������

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> s;
	q.push({ 1, 0 });
	chk[1][0] = true;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int x = cur.first, y = cur.second;
		if (x < 1000 && chk[x][x] == false) {
			q.push({ x,x });
			chk[x][x] = true;
			cnt[x][x] = cnt[x][y] + 1;
		}

		if (x + y <= s && chk[x + y][y] == false) {
			q.push({ x + y, y });
			chk[x + y][y] = true;
			cnt[x + y][y] = cnt[x][y] + 1;
		}

		if (x - 1 >= 0 && chk[x - 1][y] == false) {
			q.push({ x - 1, y });
			chk[x - 1][y] = true;
			cnt[x - 1][y] = cnt[x][y] + 1;
		}
	}

	int ans = 987654321;
	for (int i = 0; i < 2001; i++)
		if (chk[s][i]) ans = min(ans, cnt[s][i]);
		

	cout << ans;
}