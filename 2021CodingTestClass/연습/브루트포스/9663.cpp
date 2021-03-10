/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.10
���� : N-Queen - 9663
Ǯ�� : ��Ʈ��ŷ�� ���鼭 �´� ����� ���� ã���� �Ǵ� ����
       ���ǿ��� �˷��ִ� Ǯ�̴� �Ź� �ٸ� Ǯ�̸� �˷��༭ �ʹ� �����...

	   ���� ���� ������ ������
	   ��, �� �밢���� ���� ���� �� �� �̴�.
	   �̸� �����Ͽ� ���� �밢���� ���� ������ �� ������ �ϳ��� ���� ���� �� �ִ�.
*/
#include<iostream>

using namespace std;

int n, cnt = 0;
bool isused1[40];
bool isused2[40];
bool isused3[40];

void go(int k) {
	if (k == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isused1[i] || isused2[k + i] || isused3[n + k - i - 1]) continue;
		isused1[i] = true;
		isused2[k + i] = true;
		isused3[n + k - i - 1] = true;
		go(k + 1);
		isused1[i] = false;
		isused2[k + i] = false;
		isused3[n + k - i - 1] = false;
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	go(0);
	cout << cnt;
}