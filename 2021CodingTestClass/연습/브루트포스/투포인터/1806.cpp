/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.10
���� : �κ��� - 1806
Ǯ�� : �������ͷ� ������ ���󰡸� ���� �־��� �� �̻��� �� ��쿡
       �� ������ ���̰� �ּ��� ���� ã�� ����

	   �������� ������ �ϸ� �����ϰ� �ذ��� �Ǹ�
	   ������ ���Ѵٸ� �� ���� �ʱⰪ�� 100001�� ������ �ǹǷ�
	   �� ��츸 ����ó���� ���ָ� �ȴ�.
*/

#include<iostream>

using namespace std;

int n, s;
int arr[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int st = 0, en = 0;
	int sum = 0, ans = 100001;
	while (1) {
		if (sum > s) sum -= arr[st++];
		else if (en == n) break;
		else sum += arr[en++];

		if (sum >= s && ans > en - st) {
			ans = en - st;
		}
	}
	if (ans == 100001) ans = 0;
	cout << ans;
}