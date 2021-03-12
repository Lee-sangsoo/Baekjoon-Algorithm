/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.13
���� : �ּҰ� ã�� - 11003
Ǯ�� : ���� ����Ͽ� Ǫ�� �����̵� ������ �����̴�.
       �ּҰ��� ã�� ����
	   ���� �����ϴ� ����
	   ���� ��, �ε��� �� pair �����̴�.

	   1 5 6
	   0 1 2 �� ���� ���ִٸ�
	   ���� �ε����� 3�� ���� �� 2������ ������.

	   ���� 6���� ū ���� ������
	   ���� ���� 1�� pop ���ְ� ���� ���� �־��ָ� �ȴ�.

	   ���� 5�� 6���� ���� ���� ���´ٸ�
	   �켱 ���� ���� �ε��� 0�� 1���� pop ���ְ�
	   2�� ���Դٰ� ������ �Ѵٸ�
	   ������ 2�� ���������� ���̳� 2���� ���� ���� ������ �ʴ´ٸ�
	   ���� ���� ���� 2�� �Ǳ� ������
	   ������ 2���� ū ������ �������ش�. ��
	   ����������
	   2
	   3 �� ���� �ȴ�.

	   �� �Ŀ� �����ϸ� 3�� i - L �� �־��� ������ �Ѿ�ٸ� ������
	   2���� ���� ���� ������ �ش� ���� �����ش�.

	   �̷��� ó������ �� �׻� ���� ���� ���� ���� ���� ���� ���� ���̴�.
*/
#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, l;
	cin >> n >> l;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) 
		cin >> arr[i];

	deque<pair<int, int>> dq;
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		int x = arr[i];
		if (!dq.empty() && dq.front().second <= i - l)
			dq.pop_front();
		while (!dq.empty() && dq.back().first > x)
			dq.pop_back();

		dq.push_back({ x, i });
		ans[i] = dq.front().first;
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
}