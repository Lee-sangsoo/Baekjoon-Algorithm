/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.30
���� : 9656 - �� ���� 2
Ǯ�� :  N�� ¦����� ������ ����̰� �̱��
	   Ȧ����� ������ â���̰� �̱�� �����̴�.
*/
#include<iostream>
#include<algorithm>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	if (n % 2 == 0) cout << "SK";
	else cout << "CY";
}