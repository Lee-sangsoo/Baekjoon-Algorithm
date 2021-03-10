/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.10
���� : �κм����� �� - 14225
Ǯ�� : ��� �κм����� ���鼭 ������ ������ chk �迭�� �ε����� ���� true�� �ٲ��ְ�
       ������ Ž������ chk[i]�� false�� ���� ������ ������ְ� �����Ѵ�.
	   (���� : 1 ~ 2000001) (200���� ���� -> n�ִ� = 20, arr[n] �ִ� = 100000)
*/
#include<iostream>

using namespace std;

int n;
int arr[21];
bool chk[2000001];

void go(int i, int sum) {
	if (i == n) {
		chk[sum] = true;
		return;
	}

	go(i + 1, sum + arr[i]);
	go(i + 1, sum);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	go(0, 0);
	for (int i = 1; ; i++) {
		if (chk[i] == false) {
			cout << i;
			break;
		}
	}
}