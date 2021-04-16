/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.16
���� : �� ����� - 2252
Ǯ�� : �������� ����
	   �������� �ϴ� ���
	   1. ������ �����Ѵ�.
	   2. ������ 0�� ������ ť�� �ְ� �ݺ����� �����Ѵ�.
	   3. ���������� ����Ŭ�� �߻��ϸ� �Ұ����ϱ⿡ �ݵ�� ��� ��带 1�� �湮�ϴ� 
	      �� N���� �ݺ��� �ʿ��ϴ�.
	   4. ť�� ���� ���� ���� ����
	   5. �ش� ���� ���� ���Ϳ� �־��ش�.
	   6. �ش� ��忡�� �̵� ������ ������ Ȯ���Ͽ� �ش� ������ ������ 1�� ���ҽ�Ű��
	      ���� ������ 0�� �Ǵ� ��尡 �ִٸ� �ش� ��带 ť�� �ִ´�.
	   7. �� ������ �ݺ��Ͽ� ���������� ���� ���͸� ������ش�.
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m;
int inDegree[32001];
vector<int> arr[32001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		inDegree[b]++;
	}

	vector<int> ans;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	for (int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();
		ans.push_back(x);

		for (auto nxt : arr[x]) {
			if (--inDegree[nxt] == 0) q.push(nxt);
		}
	}

	for (int x : ans) cout << x << ' ';
}


