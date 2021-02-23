/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.23
���� : ���� - 11723
Ǯ�� : ��Ʈ����ũ�� ����� ������ 
       �˻�, �߰�, ����, ��� �ϴ� ����� �����ϴ� ����

	   S�� X�� �ִ��� �˻� = S & (1 << X)
	   S�� X�� �߰� = S | (1 << X)
	   S�� X�� ���� = S & ~(1 << X)
	   S�� X�� ��� = S ^ (1 << X)

	   all�� ��� 1���� 20���� ��� ��Ʈ�� �ִٴ� ���̱� ������
	   �ݺ����� ���鼭 ��� ��Ʈ�� 1�� ������ָ� �ȴ� (�߰�)
*/
#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	int num = 0;
	while (n--) {
		string s;
		cin >> s;
		if (s == "add") {
			int k;
			cin >> k;
			num = num | (1 << k);
		}
		else if (s == "remove") {
			int k;
			cin >> k;
			num = num & ~(1 << k);
		}
		else if (s == "check") {
			int k;
			cin >> k;
			if (num & (1 << k)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (s == "toggle") {
			int k;
			cin >> k;
			num = num ^ (1 << k);
		}
		else if (s == "all") {
			for (int i = 1; i <= 20; i++)
				num = num | (1 << i);
		}
		else {
			num = 0;
		}
	}
}