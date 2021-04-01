/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.01
���� : ī�� ��ü ���� - 15903
Ǯ�� : �켱���� ť�� ����ϸ� �����ϰ� �ذ�Ǵ� �����̴�.
       �ּ� ���� �����Ͽ� ���� ����Ǿ��ִ� �� �� ���� ���� �� 2������ 
	   ������ ���� ���� ���� ���� 2�� Ǫ���Ͽ� �������ָ� �ȴ�.

	   �̷��� �����ϸ鼭 �� ���� int ������ �Ѿ �� �ֱ� ������
	   int�� �ƴ� long long���� ������ָ� �ȴ�.
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	while (k--) {
		long long first = pq.top();
		pq.pop();
		long long second = pq.top();
		pq.pop();
		pq.push(first + second);
		pq.push(first + second);
	}

	long long sum = 0;
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}

	cout << sum;
}