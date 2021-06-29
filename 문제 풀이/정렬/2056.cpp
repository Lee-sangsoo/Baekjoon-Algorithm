/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.29
���� : 2056 - �۾�
Ǯ�� : ������ Ǯ���� ��Ÿũ����Ʈ ���� ���� ������ ����ϴ�.
       ���������� ���� �켱�õǴ� ������ �������� �� ������ � �ð��� ���߾�� �ϴ����� ���ؾ� �Ѵ�.

	   2���� �Ǽ��� �ߴ�.
	   1. ���������� �����ϴ°��� �ַ� �ϴٺ��� ���� �ʱ�ȭ�� ���� �ʾҴ�.
	   2. ���� ������ 0�� �ɶ��� ���� �񱳸� ���� ��ȭ�� �־���.

	   �켱 1������ Ȯ���ϸ� �̰� �Ǽ��� �´�. �⺻������ ���� ������ ������ �ϰ� �ʱ�ȭ�� ��ġ�� ������ �� ���� ������ ���� �𸣰�
	   �׷��� ������ �������� ����� �̷���� ���� ����. (� �Է��� �������� �𸣰�����, �ʱ�ȭ�� ���� �ذ��� �����ߴ�.)

	   2���� ���������� 0�̵Ǵ� ������ ��� ���� �۾��� �������̴�. 
	   �� ���� �ٽ� �����ڸ� ť�� � ������ �������� ���� ���������� 0�̵Ǵ� ������ �޶����ٴ� ���̵ȴ�.
	   �׷��� ������ ���� ������ 0�� �Ǵ� �������� �񱳸� �����ϸ� �ùٸ� ���� ���� �ʰԵǰ� ��� �������� �� ���� �����־�� �Ѵ�.

	   �̷��� ������ ���� ��� ������ �ɸ��� �ð��� result���� ���� ���� �ɸ��� �ð��� ���ؼ� �������� ������ָ� �ȴ�.
	   (��� �ǹ��� ���� ���� �Ϸ��ؾ� �ϱ� �����̴�.)
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;
int inDegree[10001];
int time[10001];
//int result[10001];
vector<int> g[10001];

int calc() {
	queue<int> q;
	vector<int> result(n + 1, 0);
	for (int i = 1; i <= n; i++)
		if (inDegree[i] == 0) {
			q.push(i);
			result[i] = time[i];
		}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < g[x].size(); i++) {
			int y = g[x][i];
			result[y] = max(result[y], result[x] + time[y]);
			if (--inDegree[y] == 0) q.push(y);
		}
	}

	int ret = 0;
	for (int i = 1; i <= n; i++)
		ret = max(ret, result[i]);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int kn;
		cin >> time[i];
		cin >> kn;
		for (int j = 0; j < kn; j++) {
			int degree;
			cin >> degree;
			inDegree[i]++;
			g[degree].push_back(i);
		}
	}

	cout << calc();
}