/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.10
���� : 3107 - IPv6
Ǯ�� : �־��� ������ ���� ó���ϸ� �Ǵ� ���� ����
       ��ü������ ó���� ��İ� ������ ������ ����.

	   1. �־��� ���ڸ� :, ::, ���� �� ������ split ���Ϳ� �����Ѵ�.
	      C++���� split �Լ��� ���� ������ �����Ͽ���.
		  (split �Լ��� �ִٰ� �ص� ::�� ó�����־�� �ϱ� ������ ���������� ��ó���� �ʿ��ϴ�)
	   2. split ���͸� ����Ͽ� ::�� ������ ��(����Ǳ� ��)�� ���� ��(����� ��) ������ ������ ����
	      st_en[0] = ::�� ������ �� ������ ���� // st_en[1] = ::�� ���� �� ������ ����
	   3. ������ ���� st ���Ϳ� :�� ::�� ������ ���ڵ鸸 �����Ѵ�.
	   4. 2������ �� ���� �������� �������� st_en[0]�� ��ŭ ans�� �տ������� ���� (0, 1, 2, ...)
	   5. 2������ �� ���� �������� �������� st_en[1]�� ��ŭ ans�� �ڿ������� ���� (..., 6, 7, 8)
		  (st ũ�⿡ ���� ó���ؾ� �ϸ� �� ������ �������ֱ� ������ ���� idx���� �ξ� �������Ѱ��� ó��)
	   6. ans�� ����� ���ڵ��� ���̸� Ȯ���Ͽ� ���̰� 4�� ���� �ʴ´ٸ� ������ ���̸�ŭ 0�� ä�� ����� ���ڿ��� �����ش�.
	   7. ������ָ� ��

	   �� ������ ���� ó���ϵ��� �Ѵ�.
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

string input;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> input;
	string s = "";
	vector<string> split;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == ':') {
			if (s != "") {
				split.push_back(s);
				s = "";
			}

			if (input[i + 1] == ':') {
				split.push_back("::");
				i++;
			}
			else {
				split.push_back(":");
			}
		}
		else {
			s += input[i];
		}
	}
	if (s != "") split.push_back(s);
	
	vector<int> st_en(2, 0);
	vector<string> st;
	int cnt = 0;
	for (string i : split) {
		if (i == ":") continue;
		if (i == "::") cnt++;
		else {
			st_en[cnt]++;
			st.push_back(i);
		}
	}

	vector<string> ans(8, "");
	int idx = 0;
	for (int i = 0; i < st_en[0]; i++) {
		ans[i] = st[idx];
		idx++;
	}
	for (int i = 8 - st_en[1]; i < 8; i++) {
		ans[i] = st[idx];
		idx++;
	}

	for (int i = 0; i < ans.size(); i++) {
		string zero = "";
		for (int j = ans[i].length(); j < 4; j++)
			zero += "0";
		ans[i] = zero + ans[i];
	}

	for (int i = 0; i < ans.size() - 1; i++) {
		cout << ans[i] << ':';
	}
	cout << ans[ans.size() - 1];
}