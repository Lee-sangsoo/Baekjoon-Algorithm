/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.15
���� : ��� - 1037
Ǯ�� : �־����� ������ ��� vector�� �Է� ���� ���� ���� �����ϰ�
       ���ĵ� �������� ���� ���� ���� ���� ū ���� ���ϸ� �� ���� N�� �ȴ�.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<int> arr;
	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	sort(arr.begin(), arr.end());
	cout << arr[0] * arr[arr.size() - 1] << '\n';

}