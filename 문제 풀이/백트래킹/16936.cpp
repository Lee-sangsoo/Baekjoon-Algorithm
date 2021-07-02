/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.22
���� : 16936 - ��3��2
Ǯ�� : �־��� ���ڵ��� ������ �������� ������ ��迭�̱� ������
       ��� ������ ���� 3���� ������ �������ų� 2�� �������� ���� ���̴�.

	   ó������ next_permutation�� ���� ��� ������ Ȯ���Ϸ��� ������ N�� �ִ� 100�̱� ������ �ð��ʰ��� �����.

	   �̸� �ذ��ϱ� ���� ���������� ����ϸ� ������ ���ٰ� �Ѵ�.

	   �־��� ������ ���μ����� �Ͽ� ��Ÿ����
	   �� ������ 3^n * 2^m * ... �� ���� ��Ÿ���� �ȴ�.
	   �� �� ���ϰ��� �ϴ� �������� ������ ��Ÿ���� ���ؼ���
	   ������ 3 = 3�� n�� �پ��� ����
	   ���ϱ� 2 = 2�� m�� �����ϴ� ���� ���� ó���ϸ� �ȴ�.

	   ��, 3�� �������� ���ٸ� ������ �����ϴ� �������� ó���ϰ�
	   3�� �������� �ٸ��ٸ� 3�� �������� �����ϴ� �������� ó���ϸ� �ȴ�.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
long long arr[101];
vector<pair<long long, long long>> v;

bool chk(pair<long long, long long> a, pair<long long, long long> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		arr[i] = num;
		long long mod = 0;
		while (num % 3 == 0) {
			mod++;
			num /= 3;
		}
		v.push_back({mod, arr[i]});
	}

	sort(v.begin(), v.end(), chk);
	for (int i = 0; i < v.size(); i++) 
		cout << v[i].second << ' ';
	
	return 0;
}