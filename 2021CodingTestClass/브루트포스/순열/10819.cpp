/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.23
���� : ���̸� �ִ�� - 10819
Ǯ�� : �־��� ���� �����Ͽ� ù��° �������� �����ϵ��� �����ϰ�
       ������ ��ȸ�ϸ鼭 �־��� ���ǿ� �´� ���� �ִ밡 �Ǵ� ���� ã���� �ȴ�.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int num[9];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num, num + n);

	int maxSum = 0;
	do {
		int sum = 0;
		for (int i = 0; i < n - 1; i++) 
			sum += (num[i] > num[i + 1] ? num[i] - num[i + 1] : num[i + 1] - num[i]);
		
		if (maxSum < sum) maxSum = sum;

	} while (next_permutation(num, num + n));

	cout << maxSum;
}