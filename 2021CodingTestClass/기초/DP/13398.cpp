/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.25
���� : ������ 2 - 13398
Ǯ�� : ���� �� ������� ���� ������ ����� �������� Ǯ�� �ȴ�.
       � ������ ���� �� Ư�� ���� �������� �� ���� ū ����� ����
	   
	   � ���� ������ �ִ� �հ�
	   � ������ �����ϴ� �ִ� �� �κ�
	   �� ���� ���� ū ���� ã���� �ȴ�.

	   �ٽ� ���� i��°�� ����ٰ� �����ϸ�

	    i-1   i   i+1
		�� (i-1��°���� ������ �ִ� ��) + (i+1��°���� �����ϴ� �ִ� ��)
		�� ���� ���� ū ���� ã���� �ȴ�.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int ed[100001];
int sd[100001];
int a[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	ed[0] = a[0];
	for (int i = 1; i < n; i++) 
		ed[i] = max(a[i], ed[i - 1] + a[i]);
	
	sd[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--)
		sd[i] = max(a[i], sd[i + 1] + a[i]);

	int ans = 100000 * -1000;
	for (int i = 0; i < n; i++)
		ans = max(ans, ed[i]);

	for (int i = 1; i < n - 1; i++)
		ans = max(ans, ed[i - 1] + sd[i + 1]);

	cout << ans;
}