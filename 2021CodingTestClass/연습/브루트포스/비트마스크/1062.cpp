/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.12
���� : ����ħ - 1062
Ǯ�� : ��� �ܾ��� ������ anta�̰� ���� tica �̱� ������
       ������������ a, n, t, i, c 5������ ����� �Ѵ�.
	   �׷��� ������ ���� k�� 5���� �۴ٸ� �� �ϳ��� �ܾ ���� ���ϱ� ������
	   0�� ��� ���ְ� �����ϸ� �ȴ�.

	   �� �ܿ��� �Է����� �־����� �� �ܾ����
	   anta�� tica�� ������ ��� �� �ִ� ö�� ������ ����� ���� ����

	   ó�� k������ 5���� ������� 5���� �����ϰ� �������� ����ϵ��� �Ѵ�.
	   ���⼭ k�� ���� ö���� ������ ũ�ٸ� �̴� ���� �ܾ��� ��� ö�ڸ� ��� �� �ִٴ�
	   ���̱� ������ n�� ������ְ� �����ϵ��� �Ѵ�.

	   �� ������ �� ��� �� �ִ� ��� ö�ڸ� 
	   0�� 1�� �̷���� ������ ������ ���� 
	   �� �ܾ��� k���� ����� �� ���� �� �ִ� ���� ū �ܾ� ���� ��󳻸� �ȴ�.
*/
#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;

	if (k < 5) {
		cout << 0;
		return 0;
	}

	unordered_map<char, int> hm;
	hm['a'] = 1;
	hm['n'] = 1;
	hm['t'] = 1;
	hm['i'] = 1;
	hm['c'] = 1;
	k = k - 5;

	vector<string> word;
	vector<char> tmp;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		s = s.substr(4);
		s = s.substr(0, s.length() - 4);
		word.push_back(s);
		for (int j = 0; j < s.length(); j++) {
			if (hm[s[j]] == 0) {
				tmp.push_back(s[j]);
				hm[s[j]] = 1;
			}
		}
	}

	if (tmp.size() < k) {
		cout << n;
		return 0;
	}

	for (int i = 0; i < tmp.size(); i++)
		hm[tmp[i]] = 0;

	vector<int> zo;
	for (int i = 0; i < tmp.size() - k; i++) {
		zo.push_back(0);
	}
	for (int i = 0; i < k; i++) {
		zo.push_back(1);
	}

	int ans = 0;
	do {
		for (int i = 0; i < zo.size(); i++) {
			if (zo[i] == 1) {
				hm[tmp[i]] = 1;
			}
		}

		int cnt = 0;
		for (int i = 0; i < word.size(); i++) {
			bool chk = true;
			for (int j = 0; j < word[i].length(); j++) {
				if (hm[word[i][j]] == 0) {
					chk = false;
					break;
				}
			}
			if (chk) cnt++;
		}
		if (ans < cnt) ans = cnt;

		for (int i = 0; i < zo.size(); i++) {
			if (zo[i] == 1) {
				hm[tmp[i]] = 0;
			}
		}


	} while (next_permutation(zo.begin(), zo.end()));

	cout << ans;
}

