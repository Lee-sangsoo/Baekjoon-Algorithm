/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.12
���� : �� ����� - 2252
Ǯ�� : �������� �˰����̴�.
       �������� �˰����� ���

	   ����
	   1. ����Ŭ�� ����� �ϰ�
	   2. ���⼺ �׷������� �Ѵ�

	   ť�� ����Ѵ�.
	   ���
	   1. ���� ������ 0�� ��� ������ ť�� ����
	   2. ť���� ���Ҹ� �ϳ� ������ �ش� ������ ����� ��� ���� ����
	   3. ���� �������� ���������� 0�̵� ������ ť�� ����
	   4. ť�� �������� �ݺ�
		(4 ���� ��� ������ �湮���� ���ϰ� ť�� ��ٸ� ����Ŭ�� �����Ѵٴ� ���̴�.)
	   5. �� ���� ť���� ���������� ������ �������� ����̴�.
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<int> arr[32001];
int inDegree[32001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		inDegree[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (auto nxt : arr[x]) {
			if (--inDegree[nxt] == 0) q.push(nxt);
		}
	}
	
}