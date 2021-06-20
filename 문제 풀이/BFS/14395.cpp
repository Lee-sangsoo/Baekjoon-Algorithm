/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.16
���� : 14395 - 4����
Ǯ�� : �� ������ �ִ� 10����� ���� ������ ���� ������ �迭�� ������ ��� �� ������ �ʹ����� ���� �䱸�ȴ�.
       �̷� ������ Ǯ�� map�̳� set�� ����ϸ� �ȴ�. (�ߺ��� ���ϱ� ������ set�� ����)
	   map�� set�� key�� �������� ó���� �Ǳ� ������
	   ������ Ư���ϰų� ��� ���ϱ� ���� ��쿡�� �̸� ����ϸ� �ȴ�.

	   �� ��츦 ǥ�����ڸ�
	   q<ll, string> -> ���� ���� �ش� ������ ���µ� �ʿ��� ������� ����� ť
	   m<ll, int> -> �Ϲ� bfs�� chk ������ �ϴ� map

	   bfs Ž���� �ϸ鼭 
	   m[i]�� 0�̰ų� (Ž�� ������ ���ٸ�) i�� MAX��(10��) ���� �۴ٸ� Ž���� �����Ѵ�. 
	   (i�� *, +, -, /�� ó���� ����)
	   
	   �� ������ ó���ϸ鼭 ã���� �ϴ� ���� ���´ٸ� �ٷ� ������ְ� ����
	   ���� �ݺ����� ����� ������ ���� ã�� ���Ѵٸ� -1�� ������ش�.

	   ������ �켱������ ���Ѿ� �ϱ� ������ 
	   * + - / ������� ť�� �־��ش�.
*/
#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>

using namespace std;

long long s, t;
long long INF = 1000000000;
queue<pair<long long, string>> q;
unordered_map<long long, int> m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> s >> t;
	if (s == t) {
		cout << 0;
		return 0;
	}
	m[s] = 1;
	q.push({ s, "" });
	while (!q.empty()) {
		long long num = q.front().first; // long long... -> int�� �ּ� ��� Ʋ�� �κ�
		string s = q.front().second;
		q.pop();
		if (num == t) {
			cout << s;
			return 0;
		}
		if (m[num * num] == 0 && num * num <= INF) {
			m[num * num] = 1;
			q.push({ num * num, s + '*' });
		}
		if (m[num + num] == 0 && num + num <= INF) {
			m[num + num] = 1;
			q.push({ num + num, s + '+' });
		}
		if (m[num - num] == 0 && num - num <= INF) {
			m[num - num] = 1;
			q.push({ num - num, s + '-' });
		}
		if (num != 0 && m[num / num] == 0 && num / num <= INF) {
			m[num / num] = 1;
			q.push({ num / num, s + '/' });
		}
	}

	cout << -1;
}