/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.11
���� : ���� ����ö 2ȣ�� - 16947
Ǯ�� : �׷������� ������ ������ ������ ������ ���� �� ����Ŭ�� �� �ϳ� ���̶�� �Ѵ�.
       �� ���� �׷������� �� ������ ����Ŭ�� �ش�Ǵ��� �ȵǴ����� �����ְ�
	   �� ������ �������� BFS�� ������ �����̴�.

	   1. DFS�� ����Ŭ Ȯ��
	   2. BFS�� ����Ŭ�� ������ �Ÿ� Ȯ��

	   1. int�� DFS �Լ��� ���� ����Ŭ ���� Ȯ��
	   2. ����ũ = 0 ������ = BFS�� ���� �Ÿ� ���
*/

#include<iostream>
#include<queue>

using namespace std;

vector<int> arr[3001];
int chk[3001];
int dist[3001];
int n;


// chk[0] = �湮 ����	chk[1] = �湮 ����	chk[2] = �湮 �߰� ����Ŭ��
// go�� ��� => -2 = ����Ŭ�� ã�Ұ� x�� ����Ŭ�� ���Ե��� �ʴ´�.
//              -1 = ����Ŭ�� ã�� ���ߴ�.
//               1 ~ n = ����Ŭ�� ã�Ұ� ����Ŭ�� ���� �����̴�.
int cycle(int x, int p) { // p -> x (����)
	if (chk[x] == 1) return x; // �̹� �湮�� ������ �ٽ� �湮�ߴ� = ����Ŭ�� �������̴� = return
	chk[x] = 1; // x�� �湮�ߴٰ� �˸���
	for (int nxt : arr[x]) { 
		if (nxt == p) continue; // ������ �湮�ߴ� �����̶�� �ǳʶٱ�
		int res = cycle(nxt, x); // ���� �������� ���� ���� ��� = ����Ŭ�� �ش��ϴ��� Ȯ��
		if (res == -2) return -2; // -2 = ����Ŭ�� �ƴϴ�.
		if (res >= 0) { // ��� = ���� �̶�� ����Ŭ�̴�.
			chk[x] = 2; // �ش� ������ ����Ŭ�̰�
			if (x == res) return -2; // ���� ������ �������̶�� �� �ڷδ� ��� ����Ŭ�� �ƴϴ� = -2 ����
			else return res; // �������� �ƴ϶�� �������� ����
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	cycle(1, 0);

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (chk[i] == 2) {
			dist[i] = 0;
			q.push(i);
		}
		else {
			dist[i] = -1;
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int nxt : arr[x]) {
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[x] + 1;
			q.push(nxt);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << dist[i] << ' ';
	cout << '\n';
}