/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.16
���� : ��Ʈ��ũ ���� - 1922
Ǯ�� : ���Ͽ� ���ε带 ����ϴ� �˰����� "ũ�罺Į �˰���" ����
       ū Ʋ�� ���Ͽ� ���ε�� �ٸ��� �ʴ�.
	   
	   1. �־��� �������� ����� ������������ �����Ѵ�.
	   2. ���� ���� ����� ������� �����Ѵ�.
	   3. ��, ����Ŭ�� ������ �ʵ��� �Ѵ�.

	   ���⼭ 
	   2���� ���� �Ŀ� unionParent�� �����ϸ� �Ǹ�
	   3���� findParent�� ����� ������ ���� �����ϸ� �ذ�ȴ�.

	   ���Ͽ� ���ε带 �˸� �����ϰ� ���� ������ �˰����̸�
	   �� ������ ũ�罺Į �˰����� �˸� �����ϰ� �ذ� ������ �����̴�.

	   �ּ� -> Ŭ������ ���� �������� ���� (��ü������ �� �Լ����� ����(operator))

	   ���� -> ������ �ͼ��� ���� ��� (vector, func)
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
int parent[1001];
vector<pair<pair<int, int>, int>> arr; // (a -> b) = dist

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

bool func(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	return a.second < b.second;
}

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	bool operator <(Edge &edge) {
		return this->distance < edge.distance;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	/*
	vector<Edge> arr;
	for (int i = 0; i < m; i++) {
		int a, b, dist;
		cin >> a >> b >> dist;
		arr.push_back(Edge(a, b, dist));
	}

	sort(arr.begin(), arr.end());
	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (!findParent(arr[i].node[0], arr[i].node[1])) {
			sum += arr[i].distance;
			unionParent(arr[i].node[0], arr[i].node[1]);
		}
	}
	*/

	for (int i = 0; i < m; i++) {
		int a, b, dist;
		cin >> a >> b >> dist;
		arr.push_back({ {a, b}, dist });
	}
	sort(arr.begin(), arr.end(), func);
	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (!findParent(arr[i].first.first, arr[i].first.second)) {
			sum += arr[i].second;
			unionParent(arr[i].first.first, arr[i].first.second);
		}
	}

	cout << sum;
}