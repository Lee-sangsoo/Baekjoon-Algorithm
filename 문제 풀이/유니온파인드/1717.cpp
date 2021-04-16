/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.16
���� : ������ ǥ�� - 1717
Ǯ�� : ���Ͽ�-���ε带 ���� �����Ѱ� Ȯ���ϴ� ����
       ���Ͽ����ε带 ����Ͽ� ���ϰ� ���� ����Ǿ� �ִ����� Ȯ���ϴ� �����̴�.
*/
#include<iostream>

using namespace std;

int n, m;
int parent[1000001];

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
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		parent[i] = i;

	while (m--) {
		int wm, a, b;
		cin >> wm >> a >> b;
		if (wm == 0) unionParent(a, b);
		else {
			if (findParent(a, b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}