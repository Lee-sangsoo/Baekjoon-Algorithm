/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.10
���� : �Ҽ��� ������ - 1644
Ǯ�� : �����佺�׳׽��� ü�� ����Ͽ� ���� �Ҽ��� ã�� 
       �Ҽ����� ���Ϳ� ��Ƶΰ� �� ���͸� ����Ͽ�
	   �� �����͸� �����ϸ� �Ǵ� �����̴�.

	   �� �������� �ִ밪���� �־����� ������
	   400���ε�, �����佺�׳׽��� ü���� 
	   j�� ���۰��� i * i�� �ϰ� �Ǹ� ������ �ʹ� Ŀ���� �Ǽ� ������ �����.
	   ���� ��ȿ�����̴��� j�� ���۰��� i * 2�� ���� (ū ���̴� ���� �׳� �̷��� ����)
*/
#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;

	vector<bool> prime(n + 1);
	vector<int> arr;
	for (int i = 2; i <= n; i++) {
		if (prime[i]) continue;
		arr.push_back(i);
		for (int j = i * 2; j <= n; j += i) {
			prime[j] = true;
		}
	}

	int st = 0, en = 0;
	long long sum = 0, cnt = 0;
	while (1) {
		if (sum > n) sum -= arr[st++];
		else if (en == arr.size()) break;
		else sum += arr[en++];

		if (sum == n) cnt++;
	}

	cout << cnt;
}