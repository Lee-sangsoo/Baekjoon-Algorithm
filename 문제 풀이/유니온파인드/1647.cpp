/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.17
���� : ���� ���� ��ȹ - 1647
Ǯ�� : ũ�罺Į �˰����� ����Ͽ� �ּ� ���� Ʈ��(MST)�� ����� ����
       �� ���������� �־��� Ʈ���� 2���� Ʈ���� ����� ó���ؾ� �Ѵٴ� ������ �ִ�.
	   
	   �־��� Ʈ���� 2���� Ʈ���� ����� 2���� Ʈ�������� �������� �ּ�����?
	   �� ������ ó�� ���� ���� ����� �ߴ�.
	   ������, �������� ��ΰŸ��� ���� �ʾҴ�.

	   �켱 �ּ� ���� Ʈ���� �־��� Ʈ������ �����ϸ�
	   "�ּ� ����� ������ �ϳ��� Ʈ���� ���δ�"
	   �� ���� �� �ϳ��� Ʈ���� ����Ŭ�� ���� �ϳ��� ������θ� �̷���� Ʈ���̸�
	   �� Ʈ������ �ϳ��� ������ �����Ѵٴ� ����
	   "�ΰ��� Ʈ���� ���������� ��� ���̴�"
	   �̷��� �ּ� ����� ���ϱ� ������ 
	   �ϳ��� MST�� ����� �ְ� ���� ��������
	   ���� ��ΰ� ����� ���� �ϳ��� �����ϸ� 2���� Ʈ���� ����
	   �ּ� ����� ���´�.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
int parent[100001];

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
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	vector<Edge> arr;
	for (int i = 0; i < m; i++) {
		int a, b, dist;
		cin >> a >> b >> dist;
		arr.push_back(Edge(a, b, dist));
	}
	sort(arr.begin(), arr.end());
	int sum = 0;
	int minus;
	for (int i = 0; i < arr.size(); i++) {
		if (!findParent(arr[i].node[0], arr[i].node[1])) {
			sum += arr[i].dist;
			minus = arr[i].dist;
			unionParent(arr[i].node[0], arr[i].node[1]);
			//cout << arr[i].node[0] << " -> " << arr[i].node[1] << '\n';
		}
	}
	cout << sum - minus;
}