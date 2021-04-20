/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.18
���� : ����Ŭ ���� - 20040
Ǯ�� : ���Ͽ� ���ε带 ����ϸ� �����ϰ� Ǯ���� ����
       �־��� ������� �����ϸ鼭 ���� ���� �θ� ��带 ������
	   �� ��� �ݺ����� �����ϰ� ���� �������� �Ǵ� �����̴�.
*/

#include<iostream>

using namespace std;

int parent[500001];

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
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		parent[i] = i;

	int ans = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (findParent(a, b)) {
			ans = i + 1;
			break;
		}
		unionParent(a, b);
	}
	cout << ans;
}