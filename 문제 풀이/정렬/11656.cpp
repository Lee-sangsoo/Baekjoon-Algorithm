/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.27
���� : ���̻� �迭 - 11656
Ǯ�� : string�� substr�� algorithm�� sort�� �̿��ϸ� �����ϰ� Ǯ���� ����
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	cin >> s;
	vector<string> arr;
	for (int i = 0; i < s.length(); i++) 
		arr.push_back(s.substr(i, s.length()));

	sort(arr.begin(), arr.end());
	for (string i : arr)
		cout << i << '\n';
}