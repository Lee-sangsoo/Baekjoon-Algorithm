/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.23
���� : Ʈ���� �θ� ã�� - 11725
Ǯ�� : Ʈ���� �з��Ǿ� ������ BFS�� ���� �׷��� Ž�� ������ �ȴ�.
       BFS�� ���鼭 ó�� �湮�ϴ� ����� ��� �Դ��� Ȯ���Ͽ�
	   �ش� ���� parent�迭�� �����ϰ� �������� ��� ���ָ� �Ǵ� �����̴�.
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n;
vector<int> arr[100001];
int parent[100001];
bool chk[100001];

void bfs() {
	queue<int> q;
	q.push(1);
	chk[1] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto nxt : arr[x]) {
			if (chk[nxt]) continue;
			parent[nxt] = x;
			q.push(nxt);
			chk[nxt] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	bfs();

	for (int i = 2; i <= n; i++)
		cout << parent[i] << '\n';
}