/*
�ۼ��� : �̱���
�Ͻ� : 2021.07.03
���� : 15558 - ���� ����
Ǯ�� : BFS�� ���� �־��� ���ڿ��� �̵��� �������� Ȯ���ϴ� ����
       1���� �迭�� 2�� �־�����. ������, �� �迭 ���̸� �Դ� ���� �ؾ� �ϱ� ������
	   ���� �����ϰ� �ڵ带 �ۼ��ϱ� ���� 2���� �迭�� �� �迭�� ���ļ� ����Ͽ���.

	   BFS�� Ž���ϸ� ���� �̵��� �־��� ���� ������ ���� �� �ִ����� Ȯ���Ͽ� �����ϴٸ� 1�� �Ұ����ϴٸ� 0�� ������ָ� �ȴ�.
	   ���� �ϴٸ�(������ �Ѿ�ٸ�) BFSŽ���� ť�� ��� ���� �ش� ���� ���� ���̰�
	   �Ұ��� �ϴٸ� ť�� �������� ������ ����� ���� ������ ���� ���̴�.
	   �� ���� ����Ͽ� ������ ������ָ� �ȴ�.

	   N�ʸ��� N��° ĭ�� ������ٰ� ���´�. �̸� ó���ϱ� ����
	   N�ʿ� Ư�� ĭ i��°�� ���ٸ� �ش� ĭ���� �̵��� �ð��� N���̸� �� �ð��� ������ 
	   �̵��� ��ģ �����̴�. �׷��� ������ �̵� = ť�� ���� �̱� ������ 
	   ť�� ������ �� ���ʿ� �ش� ĭ���� �̵��ߴ����� �Բ� �������ش�.

	   �̷��� �����ϸ� ������ ����� ��찡 �ִ��� ������ Ž���Ѵ�.

	   BFS�� ���ʴ� �ݺ� �湮 ���� �����̴�. -> �Ǽ��� �κ��̴�. (�������ΰ��� ����� ���� �׻� ������ �� �ľ�����)
*/


#include<iostream>
#include<string>
#include<queue>

using namespace std;

int n, k;
bool arr[2][100001]; // false = 0 = ���� / true = 1 = ����
bool chk[2][100001];

bool bfs() {
	queue<pair<int, pair<int, int>>> q; // <��, ���� ��, ���° ĭ> �� => 0 = ��, 1 = ��
	q.push({ 0, { 0, 0 } });
	chk[0][0] = true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int sec = cur.first;
		int line = cur.second.first;
		int x = cur.second.second;
		if (x + 1 >= n || x + k >= n) return true;

		if (sec < x + 1 && !chk[line][x + 1] && arr[line][x + 1] == 1) {
			q.push({ sec + 1, { line, x + 1 } });
			chk[line][x + 1] = true;
		}
		if (sec < x - 1 && !chk[line][x - 1] && arr[line][x - 1] == 1) {
			q.push({ sec + 1, { line, x - 1 } });
			chk[line][x - 1] = true;
		}
		int nxt_line = line == 1 ? 0 : 1;
		if (sec < x + k && !chk[nxt_line][x + k] && arr[nxt_line][x + k] == 1) {
			q.push({ sec + 1, { nxt_line, x + k } });
			chk[nxt_line][x + k] = true;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == '1') arr[0][i] = 1;
		if (s2[i] == '1') arr[1][i] = 1;
	}

	if (bfs()) cout << 1;
	else cout << 0;
}