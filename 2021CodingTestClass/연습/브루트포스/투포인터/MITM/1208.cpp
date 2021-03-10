/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.10
���� : �κм����� �� 2 - 1208
Ǯ�� : MITM ���� (Meet In The Middle)
       ���� ũ���� ����� ������ �� �� �ذ��� ����� ���� �� ������ �ذ��ϴ� ����

	   �� �������� �־����� �ִ� n�� 40���� �κм����� ��� ���ؼ� �� ����� 
	   Ȯ���ϱ⿡�� �־��� �ð��� �׸�ŭ ���� �ʴ�.

	   �׷��� ������ �־��� ������ ������ ������ ��ƴ ��ƴ�� ���� ���� �� �ִ�
	   ������ ���� ��Ÿ�����ش�.
	   �� �� ���͸� ���� ���ϰ��� �ϴ� ���� ���� �� �ִ��� Ȯ���ϵ����Ѵ�.

	   first = 0 ~ n/2 ������ ������ ���� �� �ִ� �յ�
	   second = n/2 ~ n ������ ������ ���� �� �ִ� �յ�

	   �� �� ���� ������ 
	   first�� ��������
	   second�� �������� ������ ���ְ�
	   �� ������ �˰����� ����Ѵ�.

	   first�� ��ҿ� second�� ����� ���� s���
	   �� �� first���� ���� �κ� ������ second���� ���� �κм����� ��ġ��
	   ���� s�� �����ϴ� �κ� ������ �Ǳ� ������
	   ans�� �߰����ָ� �ȴ�.

	   ���⼭, ���� ���� ��ҿ� ���� ���� ������ �͵��� �ִٸ� �ѹ��� ó�����ְ�
	   �� ���� c1, c2�� ���� ���� ���� �� ���� ���Ͽ� �� ������ �����ش�.

	   ���� �� ���� s���� �۴ٸ� first�� �����ڸ� ������Ű��  (�� ����)
	   �� ���� s���� ũ�ٸ� second�� �����ڸ� ������Ű�� �ȴ� (�� ����)

	   ���� ���ؾ��ϴ� s�� 0�̶�� �츮�� ���� ����
	   �����յ� ���ԵǾ� �ֱ� ������ -1�� �Ͽ� �����ճ����� ���� �������־�� �Ѵ�.
	   (�������� ũ�Ⱑ ����� �κ������� ���϶�� �Ͽ��� ����)
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	// N => n-m | m ���� ������.
	int m = n / 2;
	n = n - m;

	// 2^n ũ���� �迭�� ��� 0���� ä���.
	// ���̰� n�� ������ ���� �� �ִ� ��� �κ������� ���� = 2^n
	vector<int> first(1 << n);
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j))
				first[i] += a[j];
		}
	}

	vector<int> second(1 << m);
	for (int i = 0; i < (1 << m); i++) {
		for (int j = 0; j < m; j++) {
			if (i & (1 << j))
				second[i] += a[j + n]; // m = �޺κ�
		}
	}

	sort(first.begin(), first.end());
	sort(second.begin(), second.end());
	reverse(second.begin(), second.end());

	n = (1 << n);
	m = (1 << m);

	int st = 0, en = 0;
	long long ans = 0;
	while (st < n && en < m) {
		if (first[st] + second[en] == s) {
			long long c1 = 1;
			long long c2 = 1;
			st++; en++;
			while (st < n && first[st] == first[st - 1]) {
				c1++;
				st++;
			}
			while (en < m && second[en] == second[en - 1]) {
				c2++;
				en++;
			}
			ans += c1 * c2;
		}
		else if (first[st] + second[en] < s) {
			st++;
		}
		else {
			en++;
		}
	}
	if (s == 0) ans -= 1;
	cout << ans;
}