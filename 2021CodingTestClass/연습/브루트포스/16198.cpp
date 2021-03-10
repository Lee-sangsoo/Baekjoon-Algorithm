/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.10
���� : ������ ������ - 16198
Ǯ�� : �������� �����ذ��鼭 �ش� ������ ������ ����� �Ǵµ�,
       Ǯ��� ������, ���ο� ���͸� ���� �ѱ�� �������� �ð��� ���� ��ƸԴ´�.

	   �̸� �ذ��� ����� �ʿ��ϸ� (���� �ڵ�� ����)
	   (���� �ڵ�� �ݺ����� ���� ó��)

	   �Ѱ��ִ� ������ ũ�Ⱑ 3���� �۴ٸ� ���̻� ������ �μ��� ���ϹǷ�
	   ���� �����ְ� �����ϸ� �ȴ�.
*/
#include<iostream>
#include<vector>

using namespace std;

int n;
int ans = 0;

void go(vector<int> e, int mul) {
	if (e.size() < 3) {
		if (ans < mul) ans = mul;
		return;
	}

	for (int i = 1; i < e.size() - 1; i++) {
		vector<int> tmp(e);
		tmp.erase(tmp.begin() + i);
		go(tmp, mul + e[i - 1] * e[i + 1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	vector<int> energy(n);
	for (int i = 0; i < n; i++)
		cin >> energy[i];

	go(energy, 0);
	cout << ans;
}