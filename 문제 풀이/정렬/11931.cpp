/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.26
���� : �� �����ϱ� 4 - 11931
Ǯ�� : ���� �����Ͽ� ����ϴ� ������ ����
       sort ���� 3��° �ɼ�
	   greater<int>() : �������� (ū�� ������)
	   less<int>() : �������� (������ ������)
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end(), greater<int>());
	for (int i : arr)
		cout << i << '\n';
}