/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.10
���� : ������ �� 2 - 2003
Ǯ�� : �������͸� ����ϴ� ������ ����
	   ���������� ������ �����ϱ� ���� �����̴�.

	   �������͸� ���� ������ ������ �������� ���ϰų� ����� ������ �� �����ϴ�.

	   �ٽ��� �˾Ƶ���.
*/
#include <iostream>

using namespace std;

int n, m;
int num[10001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	int cnt = 0, sum = 0;
	int s = 0, e = 0;
	while (1) {
		if (sum >= m) sum -= num[s++]; // ���� ���� ���ϰ��� �ϴ� ������ ũ�ٸ� start�� ���ְ� 1 ����
		else if (e == n) break; // end�� n�� �������� ������ �����̱� ������ ����
							    // s�� n���� ������Ų ���� �����ص� �ȴ�.
		else sum += num[e++]; // �� 2������ �ش����� �ʴ� ���ϴ� ������ �۰� e�� n�� �ƴ϶�� e�� ����
		if (sum == m) cnt++; // ���̶�� count�� ����
	}
	cout << cnt;

}


/*
�������� �˰��� �ٽ�
int cnt = 0, sum = 0;
	int s = 0, e = 0;
	while (1) {
		if (sum >= m) sum -= num[s++];
		else if (e == n) break;
		else sum += num[e++];
		if (sum == m) cnt++;
	}
*/