/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.14
���� : ���� �ڸ��� - 2805
Ǯ�� : �̺�Ž���� ����Ͽ� Ǯ���ϴ� ����
       �Ϲ������� �̺�Ž���� ����ϸ� ���� st�� en ���� �ٲ��־�� �ϴ��� 
	   Ȯ���ϸ� �ۼ��ϸ� �ȴ�.

	   sum�� m���� �۴� == �� ���� �߶�� �Ѵ� -> mid���� ����� �Ѵ�.
	   sum�� m���� ũ�� == �� ���� �߶� �ȴ� -> mid���� ������ �ȴ�.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	vector<long long> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	long long st = 1, en = arr[n - 1];
	while (st <= en) {
		long long mid = (st + en) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++)
			if(arr[i] > mid)
				sum += (arr[i] - mid);

		if (sum < m) {
			en = mid - 1;
		}
		else {
			st = mid + 1;
		}
	}
	cout << en;
}