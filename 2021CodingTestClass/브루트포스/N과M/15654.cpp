/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.18
���� : N�� M (5) - 15654
Ǯ�� : N�� M (1) �� �������� ���ڰ� 1 ~ N�� �ƴ� �־����� N���� ���ڷ� ó���ϴ� ����
       ���������� ��� ���ָ� �Ǳ� ������ vector�� ���� �޾� ���� ���ְ� ������ȴ�.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int> number;
int arr[9];
bool chk[9];

void go(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < number.size(); i++) {
		if (chk[i]) continue;
		chk[i] = true;
		arr[k] = number[i];
		go(k + 1);
		chk[i] = false;
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