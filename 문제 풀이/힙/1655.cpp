/*
�ۼ��� : �̻��
�Ͻ� : 2021.01.30
���� : ����� ���ؿ� - 1655
Ǯ�� : �켱���� ť�� 2�� ����ؼ� ó���ϴ� �����̴�.
       ���� ���� �� �ð� �ʰ��� Ǯ�� ���� �̷��� �־� Ȯ���غ���
	   �� �Է¸��� sort�� �����ߴµ� �ð� ������ 0.1�ʿ��� ����� �ȵǴ°� �翬�ߴ�.

	   ������ Ǯ�� ������ ������ ����.
	   2���� �켱���� ť�� 
	   �ϳ��� �ִ� ��
	   �ϳ��� �ּ� ���� �����Ѵ�.

	   �ִ� ���� ��� ���Ҵ� �ּ� ���� ��� ���Һ��� �۰� �����ϸ�

	   �ִ� ���� ũ��� �ּ� ���� ũ�⺸�� 1���� ũ�ų� ������ �����Ѵ�.

	   ũ�⸦ ���ߴ� ���� ó�� ���� ������ ����Ǵ� ��찡 ����µ�,
	   �켱 push�� �� ����
	   �� ��� �ּ� ���� ���� ū ���� �ִ� ���� ���� ū ������ ũ�� ������
	   �� �� ���� swap ���ֵ��� ����.

	   �߰� ���� ���ϴ� �켱���� ť ��������.

	   �������� ���� ���ϵ� �ϴ�
*/
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	priority_queue<int, vector<int>, greater<int>> lpq; // �ּ���
	priority_queue<int, vector<int>, less<int>> gpq; // �ִ���
	int n;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		if (gpq.size() > lpq.size()) lpq.push(a);
		else gpq.push(a);

		if (!gpq.empty() && !lpq.empty()) {
			if (gpq.top() > lpq.top()) {
				int n1 = gpq.top();
				int n2 = lpq.top();
				gpq.pop();
				lpq.pop();
				lpq.push(n1);
				gpq.push(n2);
			}
		}
		cout << gpq.top() << '\n';
	}
}