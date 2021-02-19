/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.19
���� : ��ȣ ����� - 1759
Ǯ�� : N�� M (2)�� �ſ� ������ �����̴�.
       N�� M ������ Ǯ �� ����Լ��� ���� Ǯ���� ������ 
	   �Ȱ��� ����Լ��� Ǯ���Ѵ�.

	   ������ ��� �ִµ�
	   ������ ���� 
	   ��ȣ�� �ּ� �� ���� ����, �ּ� �� ���� �������� �����Ǿ� �ִٴ� ���̴�.
	   �̰� ������ ���� ��ȣ�� ��� �����ϱ� ������

	   chk �Լ��� ����Ͽ� �̸� ������ ���� ������ֵ��� �Ѵ�.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int l, c;
vector<char> pw;
char arr[16];

bool chk(string s) {
	int aeiou = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			aeiou++;
	}
	if (aeiou >= 1 && s.length() - aeiou >= 2) return true;
	else return false;
}
// ����� ���� �ۼ��� �Լ�
// ��� ������ ���ĺ��� ���̰� 26�̶�� ����� �Ұ����ϴ�.
void go(int cnt, int st) {
	if (cnt == l) {
		string tmp = "";
		for (int i = 0; i < l; i++)
			tmp += arr[i];
		if (chk(tmp)) cout << tmp << '\n';
		return;
	}

	for (int i = st; i < pw.size(); i++) {
		arr[cnt] = pw[i];
		go(cnt + 1, i + 1);
	}
}

// ������ �������� �ۼ��� �Լ�
void go_sel(int cnt, int idx) {
	if (cnt == l) {
		string tmp = "";
		for (int i = 0; i < l; i++)
			tmp += arr[i];
		if (chk(tmp)) cout << tmp << '\n';
		return;
	}

	if (idx >= pw.size()) return; // �� �κ��� �ʿ��ϴ�.
	arr[cnt] = pw[idx];
	go_sel(cnt + 1, idx + 1);
	go_sel(cnt, idx + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char a;
		cin >> a;
		pw.push_back(a);
	}
	sort(pw.begin(), pw.end());
	go_sel(0, 0);
}