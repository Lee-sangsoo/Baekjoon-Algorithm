/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.26
���� : ������ ���� - 5648
Ǯ�� : �޴� ���� 10^12�� �ִ��̱� ������ ���� �޾Ƽ� long long�� �����ؾ� �Ѵ�.
       ���ڿ��� �Է¹޾� reverse�Լ��� ���� �ش� ���ڿ��� ������
	   ������ ���ڿ��� stoll�� ���� long long���� ��ȯ�Ͽ� ���Ϳ� ����ش�.
	   stoll �������� 000012 �� ���� ���� �ڵ����� 12�� �Ǳ� ������
	   �׳� ������ ���� ���ָ� �ȴ�.

	   ���� �����ϰ� ������ ���� ������ָ� �ȴ�.
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> arr;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		arr.push_back(stoll(s));
	}

	sort(arr.begin(), arr.end());
	for (auto i : arr)
		cout << i << '\n';
}