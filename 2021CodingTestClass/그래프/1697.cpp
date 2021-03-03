/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.04
���� : ���ٲ��� - 1697
Ǯ�� : 1���� �迭���� bfs Ž���� �����ϴ� �����̴�.
       �Ϲ����� bfs ������ �Ȱ����� 2���� ��ǥ�� 1�������� �����Ѵٰ� �����ϸ� �ȴ�.
	   �̵� ����� 3������ �ֱ� ������ �� 3���� ����� ���� �����ϸ� �ȴ�.

	   ������ �ִ� 10�� ���� �� �� �ֱ⶧����
	   �� �ι��� 20������ ����ִ°��� ����.
*/
#include<iostream>
#include<queue>

using namespace std;

int dist[200001];
bool chk[200001];
int n, k;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	q.push(n);
	chk[n] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int nx;
		nx = now - 1;
		if (nx >= 0 && chk[nx] == false) {
			q.push(nx);
			chk[nx] = true;
			dist[nx] = dist[now] + 1;
		}

		nx = now + 1;
		if (nx < 200000 && chk[nx] == false) {
			q.push(nx);
			chk[nx] = true;
			dist[nx] = dist[now] + 1;
		}

		nx = now * 2;
		if (nx < 200000 && chk[nx] == false) {
			q.push(nx);
			chk[nx] = true;
			dist[nx] = dist[now] + 1;
		}
	}

	cout << dist[k];
}