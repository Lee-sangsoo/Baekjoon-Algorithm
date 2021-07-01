/*
�ۼ��� : �̱���
�Ͻ� : 2021.07.01
���� : 1197 - �ּ� ���д� Ʈ��
Ǯ�� : ũ�罺Į �˰����� ������ ���� �����̴�.
       ũ�罺Į �˰����� ���Ͽ�-���ε带 ����Ͽ� �ּ� ���д� Ʈ��(�ּ� ���� Ʈ��)�� ã�� �˰����̴�.

	   ũ�罺Į �˰��� �������� �ȴٸ� �����ϰ� �ذ��� �� �ִ� �����̴�.
	   �ּҽ���Ʈ�� ������ ��� ���� ���� �ܰ� ������� �ϴ� �� �ľ��ص���.

	   �ܿ�°��� �ƴ϶� � �������� �̷�����ְ� ��� �����Ǿ��ִ��� �����ϰ�
	   �̸� ������� �ڵ带 �ۼ��� �� �ֵ��� ����.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int v, e;
int parent[10001];

int getParent(int x) {
	if (parent[x] == x) return x;
	return getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	else return false;
}

class Edge {
public:
	int node[2];
	int dist;

	Edge(int a, int b, int dist) {
		this->node[0] = a;
		this->node[1] = b;
		this->dist = dist;
	}

	bool operator <(Edge &edge) {
		return this->dist < edge.dist;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> v >> e;

	for (int i = 1; i <= v; i++)
		parent[i] = i;

	vector<Edge> arr;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr.push_back(Edge(a, b, c));
	}

	sort(arr.begin(), arr.end());

	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (!findParent(arr[i].node[0], arr[i].node[1])) {
			sum += arr[i].dist;
			unionParent(arr[i].node[0], arr[i].node[1]);
		}
	}
	cout << sum;
}