/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.05
���� : �迭 ������ 2 - 16927
Ǯ�� : �迭 ������ 1 �� ���� �����ε�, ��� ȸ����Ű������ �ٸ���.
       �� �������� �־����� �ִ� r(ȸ�� Ƚ��)�� 10����̸�
	   �̸� ��� ������ �Ǹ� �ð��ʰ��� �����.

	   �迭 ������ 1���� ��� ó������ �����غ� �����
	   �־����� r�� ���� �������� �ϴ� �迭�� ���̷� ������ �� ��������ŭ�� ������ ����̴�.

	   �� ����� ���� �����̱⵵ �ѵ�, ���� ó�� ������ �迭 ������ 1���� �� ����� ����ϸ�
	   �� �׵θ��� ���̺��� �ٸ��� �ϱ⵵ �ؾ� �ϰ� ���� �����ϰ� �����ؾ� �ϸ�
	   �� �� �� �ݺ����� tmp�� arr�� ���� �ٲ���� �ϱ� ������ �ð��ʰ��� ����ȴ�.

	   ���Ǹ� ���� Ǯ�̸� �����.
	   Ǯ�̴� ������ ����.

	   �迭���� ���� �ٱ��� ������ 0��° �׷��̶� ġ��
	   �� ������ �������� �����ߵǴ� ���� ������� 1���� �迭�� ��´�.
	   �̷��� �� �׷��� ������ 1���� �迭�� ��� �ΰ� �������� �Ѿ��.

	   1���� �迭�� ������ ���ٸ�
	   1 2 3 4 5 
	   1�� ȸ�� = 2 3 4 5 1
	   2�� ȸ�� = 3 4 5 1 2
	   3�� ȸ�� = 4 5 1 2 3
	   ...
	   �� n�� ȸ���� �ϸ� n��° �ε����� 0��°�� ���� �ȴ�.

	   �� ���� ����Ͽ� ������ Ǯ���� �Ѵ�.

	   1���� �迭�� ��� ������ ���� �߿��ϸ� 
	   �򰥸��� �ʵ��� �� �����Ͽ� ��ƾ� �Ѵ�.

	   �׸��� ���� idx�� ����Ͽ� idx��° ���� ���ʴ�� �迭�� �����Ѵ�.

	   idx = n��° �� -> n+1��° �� -> ... -> ������ ������ 0 (������ ������ ����)

	   group ���Ϳ��� ���� ������� ����ֱ� ������ 
	   �������� �Ȱ��� ������ �迭�� ������ �ȴ�.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[301][301];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	vector<vector<int>> groups;
	int groupn = min(n, m) / 2;
	
	for (int k = 0; k < groupn; k++) {
		vector<int> group;
		for(int j = k; j<m-k; j++) 
			group.push_back(arr[k][j]);

		for (int i = k + 1; i < n - k; i++)  
			group.push_back(arr[i][m - 1 - k]);

		for (int j = m - 2 - k; j >= k; j--)
			group.push_back(arr[n - 1 - k][j]);

		for (int i = n - 2 - k; i >= k + 1; i--)
			group.push_back(arr[i][k]);

		groups.push_back(group);
	}

	for (int k = 0; k < groupn; k++) {
		int len = groups[k].size();
		int idx = r % len;

		for (int j = k; j < m - k; j++, idx = (idx + 1) % len)
			arr[k][j] = groups[k][idx];

		for (int i = k + 1; i < n - k; i++, idx = (idx + 1) % len)
			arr[i][m - 1 - k] = groups[k][idx];

		for (int j = m - 2 - k; j >= k; j--, idx = (idx + 1) % len)
			arr[n - 1 - k][j] = groups[k][idx];

		for (int i = n - 2 - k; i >= k + 1; i--, idx = (idx + 1) % len)
			arr[i][k] = groups[k][idx];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
}