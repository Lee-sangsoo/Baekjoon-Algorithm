/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.25
���� : ī�� - 11652
Ǯ�� : ������ ���ִ� ���Ŀ� �ش�Ǵ� ����������, ���� Ǯ�̴� hash_map�� ����Ͽ���.
       �� ���� key�� �־� ���� ū ���� �����°��� O(n)�� ã���� �Ͽ���.

	   �� ������ �־����� ���� ������ int�� �����ϱ� ������
	   long long���� �޾��ְ� �����ϰ� ����ؾ� �Ѵ�.
*/
#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	unordered_map<long long, int> hm;
	for (int i = 0; i < n; i++) {
		long long tmp; // �� �κп��� int tmp�� �����Ͽ� ó���� ������ ������
		cin >> tmp;	   // �ڷ��� ����!
		hm[tmp]++;
	}

	long long ans = 0, cnt = 0;
	for (auto i : hm) {
		if (cnt < i.second) {
			ans = i.first;
			cnt = i.second;
		}
		if (cnt == i.second) {
			ans = ans < i.first ? ans : i.first;
		}
	}

	cout << ans;
}