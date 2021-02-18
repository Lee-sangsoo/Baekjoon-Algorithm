/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.18
���� : N�� M (6) - 15655
Ǯ�� : ���� N�� M �������� ���ڰ� 1 ~ N�� �ƴ� �־����� N���� ���ڷ� ó���ϴ� ����
	   ���������� ��� ���ָ� �Ǳ� ������ vector�� ���� �޾� ���� ���ְ� ������ȴ�.

	   �ߺ����� �ʴ� ������ ���������� ó���Ϸ��� st�� ���� �޾� �Ѱ��ָ�ȴ�.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int> number;
int arr[9];
bool chk[9];

void go(int k, int st) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = st; i < number.size(); i++) {
		arr[k] = number[i];
		go(k + 1, i+1);
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
	go(0, 0);
}