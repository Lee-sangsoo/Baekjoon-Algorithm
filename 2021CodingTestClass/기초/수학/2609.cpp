/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.15
���� : �ִ������� �ּҰ���� - 2609
Ǯ�� : �ִ������� ��Ŭ���� ȣ����
       �ּҰ������ �ִ������� �̿��Ͽ�

	   ��Ŭ���� ȣ���� => GCD(a, b) = GCD(b, a%b) �̸� b�� 0�� �� a�� a�� b�� �ִ������̴�.

	   �ּ� ����� => GCD(a, b) = g ��� �� ��
	   LCM(a, b) = (a * b) / g �̴�.
*/
#include<iostream>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	
	int g = gcd(a, b);
	int l = a * b / g;

	cout << g << '\n';
	cout << l << '\n';
}