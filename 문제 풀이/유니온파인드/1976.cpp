/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.17
���� : ���� ���� - 1976
Ǯ�� : ���Ͽ� ���ε带 ����Ͽ� Ǯ���� ����
       ������ ������ �ش� ������ BFS, DFS�ε� Ǯ ���� �ִٰ� �Ѵ�
	   (�־����� ���� ������ ��� �׷��� �������� �־����� ������ �����ϴ�)

	   ��ķ� �־����� �������� ���� �����ְ� (Union)
	   ������ ���� ��θ�
	   0 - 1 // 1 - 2 // 2 - 3 // ...
	   �� ���� ���� ���տ� �����ִ��� Ȯ��(Find)���ָ� �Ǵ� �����̴�.
*/
#include<iostream>
#include<vector>

using namespace std;

int n, m;
int parent[201];

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return 1;
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			if (num == 1) unionParent(i, j);
		}
	}

	vector<int> res(m);
	for (int i = 0; i < m; i++)
		cin >> res[i];

	bool chk = true;
	for (int i = 0; i < res.size() - 1; i++) {
		if (!findParent(res[i], res[i + 1])) {
			chk = false;
			break;
		}
	}

	if (chk) cout << "YES";
	else cout << "NO";
}