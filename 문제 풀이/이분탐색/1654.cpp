/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.13
���� : ���� �ڸ��� - 1654
Ǯ�� : �̺�Ž���� ����Ͽ� Ž�� ������ �ٿ��� �ϴ� ����
       ������ �̺�Ž�� => �ش� ��ġ
	   �� �������� �̺�Ž�� => ���� ū ��

	   �� ������ Ǯ�� ���ؼ��� �̺�Ž���� �����ϸ鼭
	   �ݺ����� �������ö����� Ž���� ���� ������ en�� ������ָ� �ȴ�.

	   (�ߺ��� ���Ұ� �ִ� �迭���� �̺�Ž���� ������ ��)
	   (���� ���� ��ġ => mid < target)
	   (���� ���� ��ġ => mid <= target)
	   (https://yu5501.tistory.com/80 -> �� ������ ��α�)
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int k, n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> k >> n;
	vector<long long> arr(k);
	for (int i = 0; i < k; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	long long st = 1, en = arr[k - 1];
	while (st <= en) {
		long long mid = (st + en) / 2;
		long long sum = 0;
		for (int i = 0; i < k; i++)
			sum += arr[i] / mid;

		if (sum < n) {
			en = mid - 1;
		}
		else {
			st = mid + 1;
		}
	}
	cout << en;
}