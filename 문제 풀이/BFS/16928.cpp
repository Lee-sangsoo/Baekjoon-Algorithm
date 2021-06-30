/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.04
���� : 16928 - ��� ��ٸ� ����
Ǯ�� : 1���� BFS ����
       ��ٸ��� ���� ������ �ִ� 15��������, �� ������ ��� ���� ������ ���Ϳ� �����ϰ� �׶� �׶� Ž���Ͽ� �������� �Ǹ�
	   �޸��� ȿ������ �������� �ð��� ȿ���� �������� �ȴ�. �׷��� ������ �ִ� 100���� ĭ�� ��ٸ��� ���� ���̱� ������
	   �׳� ��� ��ٸ��� ������ ũ�� 100�� �迭 2���� ���� �����Ͽ� �˻��Ѵ�.
	   �˻縦 �����ϸ� ��ٸ��� ���� �ִٸ� nx�� ���� �ٲپ��ֵ��� �Ѵ�.

	   �׷��� Ž���� ��ġ�� ���� dist[100]�� ���� ������ �ȴ�.
*/
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
int dist[101];
bool chk[101];
int ladder[101];
int snake[101];

int dx[] = { 1, 2, 3, 4, 5, 6 };

void go() {
	queue<int> q;
	q.push(1);
	chk[1] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int k = 0; k < 6; k++) {
			int nx = x + dx[k];
			if (nx > 100 || chk[nx]) continue;
			if (ladder[nx] != 0) nx = ladder[nx];
			if (snake[nx] != 0) nx = snake[nx];
			if (nx > 100 || chk[nx]) continue;
			q.push(nx);
			chk[nx] = true;
			dist[nx] = dist[x] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
		ladder[from] = to;
	}
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		snake[from] = to;
	}
	go();
	cout << dist[100];
}