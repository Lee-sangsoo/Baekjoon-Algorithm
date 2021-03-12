/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.12
���� : N��° ū �� - 2075
Ǯ�� : �켱���� ť�� ����ϴ� ����
       �켱���� ť�� ����Ͽ� �����̵� �����츦 �����ϸ� �ȴ�.
	   min heap�� �����Ͽ� ���� ����� n���� �Է� �޾� ť�� ��´�.
	   �� ���� ���� ���� ���� top�� n��°�� ū ���̴�.

	   �� �Ŀ� n���� ���� �Է� ������
	   �� 2n���� ������ n���� �������ָ� �� �ٽ� n��° ū ���� top�� ���� �ȴ�.

	   �� ������ �ݺ� ���ָ� �ȴ�.
*/
#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			pq.push(num);
		}
		for (int k = 0; k < n; k++) pq.pop();
	}

	cout << pq.top();
}