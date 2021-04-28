/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.28
���� : �ܾ� ���� - 1339
Ǯ�� : �ΰ��� ����� �����Ѵ�.
       1. ����
	   2. ���׽� ó��

	   ���� Ǭ ����� ���� ����̴�.
	   (���Ʈ���� ����� ������ �ð� ���ѿ� ���� �����ϰ� �ɸ����� ���׽� ������� ó���ϸ� 0ms������ ó���� �����ϴٰ� �Ѵ�)

	   �켱 �־��� ���� ���ĺ����� ������ � ���ĺ����� ���Դ°� Ȯ���Ѵ�.
	   ���� ������ Ȯ���Ͽ� �ִ� ��� �ִ��� Ȯ���ϰ�
	   �ش� ���ĺ��鿡 �ִ� ������ 9���� ���ҽ��Ѱ��� ���� �����Ѵ�.

	   ���� ������ ������ ������ �ִ밪�� �˻��ϸ� �ȴ�.

	   ó�� Ǯ�̸� �ϰ��� ���� 3���� �������� �ð��ȿ� ��µ��� �ʾ� ����ϴٰ�
	   Ǯ�̵�� ���� �ٸ����� ��� ������ �ϴ� ��� �Ǿ��� (��ǻ�� ��� �����ΰ� ����)

	   ���׽� ó�� ����� ������ ���ٰ� �Ѵ�.
	   ACDEB + GCF = 10000A + 1010C + 100(D + G) + 10E + B + F
	   �̸� ū ���� ������ �Ǵ� ���� 9���� ���ҽ��Ѱ��� �����Ű�� �Ǵ� �׸���� Ǯ�̰� �����ϴٰ� �Ѵ�.

	   �ִ� ��� ���ĺ��� �ִ����� �̸� ��� ���ڿ� ��Ī�� �������� ���� ������ڸ�

	   1. �ִ� ��� ���ĺ��� �ִ°� -> ������ ��ĵ� ����������, vector�� erase�� unique�� ����ϸ� ���� ������ ó���� �����ϴٰ� �Ѵ�.
	   2. ���ڿ� ��Ī -> ó���� �ؽ� ���� ����Ͽ� ó���Ͽ�����, C++�� ���ڵ��� �ƽ�Ű�ڵ� ���� ��Ī�Ǿ� ����Ǳ� ������ 
	                     �� ������ 256ũ���� �迭�� m['a'] = 3 ���� �����ϸ� a�� �����Ǵ� m[97] = 3�� ����ȴ�. �̷��� ó���ϸ�
						 ���� Ž���� ���� �ؽ� �ʿ� ���� ������ ó���� �����ϴ�.
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n;
bool alphabet[26];
vector<vector<char>> words;
char m[256];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vector<char> word;
		for (int i = 0; i < s.length(); i++) {
			alphabet[s[i] - 'A'] = true;
			word.push_back(s[i]);
		}
		words.push_back(word);
	}

	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i]) {
			m[i + 'A'] = cnt;
			cnt++;
		}
	}

	int arr[10];
	int now = 9;
	for (int i = 0; i < cnt; i++) {
		arr[i] = now;
		now--;
	}

	int ans = 0;
	do {
		int totalSum = 0;
		for (int i = 0; i < words.size(); i++) {
			int sum = 0;
			int mul = 1;
			for (int j = words[i].size() - 1; j >= 0; j--) {
				sum += arr[m[words[i][j]]] * mul;
				mul *= 10;
			}
			totalSum += sum;
		}
		if (ans < totalSum) ans = totalSum;
	} while (prev_permutation(arr, arr + cnt));

	cout << ans;
}