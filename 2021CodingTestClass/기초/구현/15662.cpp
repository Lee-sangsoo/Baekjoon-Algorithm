/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.05
���� : ��Ϲ��� (2) - 15662
Ǯ�� : ��Ϲ��� ������ �����ѵ� ��Ϲ����� ���� �������̴�.
       �ִ� 1000�� ���� �־����� �� ���� �ش� ��Ϲ������� 
	   ������ȣ, ū��ȣ�� ������ �ָ� �����ϰ� �ذ�ȴ�.

	   (��Ϲ��� 1�� ���������� �̷��� Ǯ�� �Ǿ���)
	   4�� n���� �ٲ��
	   ���õ� ��Ϲ������� 1���� ��Ϲ�ȣ ���� ���õ� ��Ϲ����� �۾����� ���ϰ�
	   ���õ� ��Ϲ������� 1 ū ��Ϲ�ȣ ���� ���õ� ��Ϲ����� Ŀ���� ���ϸ� �ȴ�.
	   (�۾����� -> num-1 ~ 1)
	   (Ŀ���� -> num-1 ~ n-1)
	   
	   �� �Ŀ��� ��Ϲ��� 1�� ������ �Ȱ���.
*/
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int gear[1001][8];
int n, k;

void turn_right(int arr[]) {
	int tmp = arr[7];
	for (int i = 7; i > 0; i--)
		arr[i] = arr[i - 1];
	arr[0] = tmp;
}

void turn_left(int arr[]) {
	int tmp = arr[0];
	for (int i = 0; i < 7; i++)
		arr[i] = arr[i + 1];
	arr[7] = tmp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			gear[i][j] = s[j] - '0';
	}

	cin >> k;
	while (k--) {
		int num, lr;
		cin >> num >> lr;

		int chk[1001];
		for (int i = 0; i < n; i++) chk[i] = 0;

		chk[num - 1] = lr;
		for (int i = num-1; i > 0; i--) {
			if (gear[i][6] == gear[i - 1][2]) break;
			else chk[i - 1] = chk[i] * -1;
		}
		for (int i = num-1; i < n; i++) {
			if (gear[i][2] == gear[i + 1][6]) break;
			else chk[i + 1] = chk[i] * -1;
		}


		for (int i = 0; i < n; i++) {
			if (chk[i] == 1) turn_right(gear[i]);
			else if (chk[i] == -1) turn_left(gear[i]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (gear[i][0] == 1) 
			ans++;
	}

	cout << ans;
}
