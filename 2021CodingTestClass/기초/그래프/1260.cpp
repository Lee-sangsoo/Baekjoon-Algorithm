/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.01
���� : DFS�� BFS - 1260
Ǯ�� : DFS�� BFS�� �⺻������ �����ϴ� �����̴�.
       �ּ����� ó���� �Լ����� "�������"�� �̿��� Ǯ���̸�
	   �ּ��� �ƴ� �� �ڵ�� "��������Ʈ"�� �̿��� Ǯ���̴�.

	   BFS�� �湮�Ѵ� = �Լ��� ȣ���Ѵ� = �Լ��� ������ �� chk �� ����
	   DFS�� �湮�Ѵ� = ť�� �ִ´� = ť�� ���� �� chk �� ����

	   DFS�� ���� �� �𸣴� ���� ���⼭ �� �˾ư� �ʿ䰡 �ִ�.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m, v;
vector<int> g[1001];
queue<int> q;
bool chk[1001];

void dfs(int x) {
	chk[x] = true;
	for (int i = 0; i < g[x].size(); i++) {
		int y = g[x][i];
		if (!chk[y]) {
			cout << y << ' ';
			dfs(y);
		}
	}
}

/*
void dfs(int x){
	chk[x] = true;
	for(int i = 1; i<=n; i++){
		if(a[x][i] == 1 && !chk[i]){
			dfs(i);
		}
	}
}
*/

void bfs(int x) {
	chk[x] = true;
	q.push(x);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < g[x].size(); i++) {
			int y = g[x][i];
			if (!chk[y]) {
				cout << y << ' ';
				q.push(y);
				chk[y] = true;
			}
		}
	}
}

/*
void bfs(int x){
	chk[x] = true;
	q.push(x);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i = 1; i<=n; i++){
			if(a[now][i] == 1 && chk[i] == false){
				chk[i] = true;
				q.push(i);
			}
		}
	}
}
*/

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		sort(g[i].begin(), g[i].end());

	cout << v << ' ';
	dfs(v);
	cout << '\n';
	for (int i = 0; i < n + 1; i++)
		chk[i] = false;
	cout << v << ' ';
	bfs(v);
}