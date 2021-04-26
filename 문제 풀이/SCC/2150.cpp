/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.23
���� : Strongly Connected Component - 2150
Ǯ�� : SCC�� ������ ���� �����̴�.
       ���� ��ƴ�... ���� ��ü�� ��ư� �����ϰ� ǥ���ϸ�
	   ����Ŭ�� ���ϴ� �����ε� ����Ŭ�� ���ϴ°� ���� ��������� ó��
	   SCC�� ���䵵 ���� ��ƴ�.

	   ���ΰ� �ſ� ���� �ʿ��ϸ� 
	   ������ �ֱ������� Ȯ���Ͽ� �������� (���� ��� ������ �𸣴°� �˰����̴ϱ�...)

	   �򰥸��°�
	   1. d�迭�� �ǹ�
	   2. id�� ����
	   
	   �Ƹ��� �� 2������ �˰ԵǸ� ������ ������ ����.
*/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int v, e;
int id, d[10001]; // �� ��帶�� ������ ��ȣ�� �Ҵ� �޵����Ѵ�.
vector<int> arr[10001];
vector<vector<int>> SCC;
bool finished[10001]; // �ش� ����� dfs�� �������� Ȯ���ϴ� �迭
stack<int> s;

int dfs(int x) {
	d[x] = ++id; // ���� ó�� �θ�� �����̵� ��
	s.push(x);

	int parent = d[x]; // ó���� �θ��� �ڱ� �ڽ�
	for (int i = 0; i < arr[x].size(); i++) {
		int y = arr[x][i];
		if (d[y] == 0) parent = min(parent, dfs(y));
		else if (!finished[y]) parent = min(parent, d[y]);
	}

	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x) break;
		}
		SCC.push_back(scc);
	}

	return parent;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
	}

	for (int i = 1; i <= v; i++) {
		if (d[i] == 0) dfs(i);
	}

	for (int i = 0; i < SCC.size(); i++)
		sort(SCC[i].begin(), SCC[i].end());

	sort(SCC.begin(), SCC.end());

	cout << SCC.size() << '\n';
	for (int i = 0; i < SCC.size(); i++) {
		for (int j = 0; j < SCC[i].size(); j++)
			cout << SCC[i][j] << ' ';
		cout << "-1\n";
	}
}