/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.22
���� : 16922 - �θ� ���� �����
Ǯ�� : �� ������ ������ ���� �ذ��ϴ� �����̴�.
       ���� �߿����� '�ߺ� ����' �� ����ؾ� �Ѵ�.
	   �ߺ� ���� = 1, 2, 3 ���� 2�� �̱� -> 1 1, 1 2, 1 3, 2 3 (��, �ߺ��� ���������� ������ ������� �ʴ� ��)

	   �ߺ������� ���ϴ� ����� �����ϰ� Ǯ���ϸ� �����ϰ� �ذ�ȴ�.
	   
	   "�������� ��������, �׸��� �ߺ����� �ƴ��� �� ��������"
	   "������ ������ �Ű澲�� �ʴ� ��, ������ �������� �Ű澲�� ��"
*/
#include<iostream>

using namespace std;

int n;
int ans = 0;
bool num[1001];
int point[4] = { 1, 5, 10, 50 };

void go(int cnt, int now, int nxt) {
	if (cnt == n) {
		if (!num[now]) {
			num[now] = true;
			ans++;
		}
		return;
	}

	for (int i = nxt; i < 4; i++)
		go(cnt + 1, now + point[i], i);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	go(0, 0, 0);
	cout << ans;
}