/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.18
���� : N�� M (7) - 15656
Ǯ�� : ���� N�� M �������� ���ڰ� 1 ~ N�� �ƴ� �־����� N���� ���ڷ� ó���ϴ� ����
	   ���������� ��� ���ָ� �Ǳ� ������ vector�� ���� �޾� ���� ���ְ� ������ȴ�.

	   �ߺ��� ����ϴ� ���� ó���ϴ� ����
	   ���ǹ��� ���� ���� ���ϸ� �ȴ�.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> number;
int arr[8];
int n, m;

void go(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		arr[k] = number[i];
		go(k + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		number.push_back(a);
	}
	sort(number.begin(), number.end());
	go(0);
}