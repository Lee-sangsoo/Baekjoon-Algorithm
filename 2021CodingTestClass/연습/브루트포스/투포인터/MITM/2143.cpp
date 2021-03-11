/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.10
���� : �� �迭�� �� - 2143
Ǯ�� : ���ʰ� �ٸ� ������ ���ǿ� �°� ���Ͽ� ���� ���� ������ ���� ���� �����̱� ������
       �� ������ MITM �����̴�.

	   ���ӵ� �迭�� ���̱� ������ �������� ����Ͽ� N^2 �ȿ�
	   ���ӵ� �迭���� ���� ���Ͽ� first�� second�� �־��ְ�

	   �� ���� MITM�� ���� ������ �����ϴ� ���� �����ָ� �ȴ�.1`
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, m;
	cin >> t;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++)
		cin >> b[i];

	int nsize = 0;
	int msize = 0;

	vector<int> first;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = i; j < n; j++) {
			tmp += a[j];
			first.push_back(tmp);
		}
	}

	vector<int> second;
	for (int i = 0; i < m; i++) {
		int tmp = 0;
		for (int j = i; j < m; j++) {
			tmp += b[j];
			second.push_back(tmp);
		}
	}

	sort(first.begin(), first.end());
	sort(second.begin(), second.end(), greater<int>());

	int st = 0, en = 0;
	long long ans = 0;
	while (st < first.size() && en < second.size()) {
		if (first[st] + second[en] == t) {
			long long c1 = 1;
			long long c2 = 1;
			st++; en++;
			while (st < first.size() && first[st] == first[st - 1]) {
				c1++;
				st++;
			}
			while (en < second.size() && second[en] == second[en - 1]) {
				c2++;
				en++;
			}
			ans += c1 * c2;
		}
		else if (first[st] + second[en] < t) {
			st++;
		}
		else {
			en++;
		}
	}

	cout << ans;
}