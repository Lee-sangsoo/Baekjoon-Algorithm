/*
�ۼ��� : �̱���
�Ͻ� : 2021.07.01
���� : 16945 - ���� ������� �����ϱ�
Ǯ�� : ������ ��Ȯ�� �а� �ľ�����...
       �־��� �迭�� �ּ������� �����Ͽ� '���� ������'�� ����� �����̴�.
	   ���� �������� ���Ǹ� ��Ȯ�� �ľ����� �ʾƼ� �ظž��µ�,

	   ���� ������� N X N ũ���� �迭�� 1 ~ N^2������ ���� "�ϳ���" ������ ��, ��, �밢���� ���� ���� ��� ���� �迭�� ���� �������� �Ѵ�.
	   ���� �ϳ��� ����ִٴ°��� �ľ����� �ʰ� Ǯ�ٰ� ���� ������ ����� �̸� �ľ��ϰ� ����
	   ������ ����Ͽ� Ǯ�� �Ͽ���.

	   ������ ó���ϱ� ���� �Է¹޴� �迭�� ������ ���� �迭 ��� 1���� �迭�� ����Ͽ���.

	   �� ó���� ���� ���� ����� �´��� Ȯ���ϴ� �Լ��� ���� �̵��� ���� �ּҰ��� ã�� �Լ��� �����Ͽ� �����Ͽ���.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int arr[9];
int ch[9];
int ans = 987654321;

int calc() {
	int ret = 0;
	for (int i = 0; i < 9; i++) {
		int diff = arr[i] - ch[i];
		if (diff < 0) diff = -diff;
		ret += diff;
	}
	return ret;
}

bool chk() {
	int sum = ch[0] + ch[1] + ch[2];
	if (sum != (ch[3] + ch[4] + ch[5])) return false;
	if (sum != (ch[6] + ch[7] + ch[8])) return false;
	if (sum != (ch[0] + ch[3] + ch[6])) return false;
	if (sum != (ch[1] + ch[4] + ch[7])) return false;
	if (sum != (ch[2] + ch[5] + ch[8])) return false;
	if (sum != (ch[0] + ch[4] + ch[8])) return false;
	if (sum != (ch[2] + ch[4] + ch[6])) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 9; i++)
			cin >> arr[i];

	for (int i = 0; i < 9; i++)
		ch[i] = i + 1;

	do {
		if (chk()) {
			int cur = calc();
			ans = min(ans, cur);
		}

	} while (next_permutation(ch, ch + 9));

	cout << ans;
}