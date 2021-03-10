/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.04
���� : ���ٲ��� 4 - 13913
Ǯ�� : bfs�� ��θ� �����ϴ� ���
       �������� ����ϸ� Ǯ�̰� �����ϴ�.
	   
	   ��� ����� vector�� ����Ͽ� ���� �� ��� ���־�����

	   stack�� ����Ͽ� reverse�� ������� �ʰų�

	   ����Լ��� ���� ó���� �����ϴ�.
*/
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n, k;
int dist[200001];
bool chk[200001];
int pre[200001];
queue<int> q;

void print(int p) {
	if (p != n) {
		print(pre[p]);
	}
	cout << p << ' ';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	q.push(n);
	chk[n] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x - 1 >= 0 && chk[x-1] == false) {
			q.push(x - 1);
			chk[x - 1] = true;
			pre[x - 1] = x;
			dist[x - 1] = dist[x] + 1;
		}

		if (x + 1 <= 200000 && chk[x + 1] == false) {
			q.push(x + 1);
			chk[x + 1] = true;
			pre[x + 1] = x;
			dist[x + 1] = dist[x] + 1;
		}

		if (x * 2 <= 200000 && chk[2 * x] == false) {
			q.push(x * 2);
			chk[x * 2] = true;
			pre[x * 2] = x;
			dist[x * 2] = dist[x] + 1;
		}
	}

	cout << dist[k] << '\n';
	// ����Լ��� print �Լ��� ��ü ����
	/*
	vector<int> path;
	int x = k;
	while (x != n) {
		path.push_back(x);
		x = pre[x];
	}
	path.push_back(x);
	reverse(path.begin(), path.end());
	for (auto i : path)
		cout << i << ' ';
	*/
	print(k);
}