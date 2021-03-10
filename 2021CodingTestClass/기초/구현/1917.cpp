/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.07
���� : ������ü ������ - 1917
Ǯ�� : ������ü�� �������� �� 11�� �ۿ� ���ٰ� �Ѵ�.
       ���������̴� ���� �� 11���� �������� ��� ���ؼ�
	   �� ��쿡 ���� ȸ�� ��Ű�� ��Ī ��Ű�� ��츦 ���� �� ��찡 �����ϴ���
	   Ȯ���ϸ� �Ǵ� �����̴�.
	   (���� �����ؼ� Ǯ���� �ڵ� = ���� �ڵ�)
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<vector<string>> cubes = {
	{"0010",
	 "1111",
	 "0010"},

	{"0100",
	 "1111",
	 "1000"},

	{"0010",
	 "1111",
	 "0100"},

	{"0001",
	 "1111",
	 "1000"},

	{"0001",
	 "1111",
	 "0100"},

	{"11100",
	 "00111"},

	{"1100",
	 "0111",
	 "0010"},

	{"1100",
	 "0111",
	 "0001"},

	{"0010",
	 "1110",
	 "0011"},

	{"0001",
	 "1111",
	 "0001"},

	{"1100",
	 "0110",
	 "0011"}
};
vector<string> mirror(vector<string> &b) {
	vector<string> ans(b.size());
	for (int i = 0; i < b.size(); i++) {
		string temp(b[i]);
		reverse(temp.begin(), temp.end());
		ans[i] = temp;
	}
	return ans;
}
vector<string> rotate(vector<string> &b) {
	vector<string> ans(b[0].size());
	for (int j = 0; j < b[0].size(); j++) {
		for (int i = (int)b.size() - 1; i >= 0; i--) {
			ans[j] += b[i][j];
		}
	}
	return ans;
}
bool check(vector<vector<int>> &a, vector<string> &b, int x, int y) {
	int n = a.size();
	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			int nx = x + i;
			int ny = y + j;
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (b[i][j] == '0') {
					if (a[nx][ny] == 1) return false;
				}
				else if (b[i][j] == '1') {
					if (a[nx][ny] == 0) return false;
				}
			}
			else {
				return false;
			}
		}
	}
	return true;
}
int main() {
	int t = 3;
	while (t--) {
		int n = 6;
		vector<vector<int>> a(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		bool ans = false;
		for (auto &c : cubes) {
			vector<string> cube(c);
			for (int mir = 0; mir < 2; mir++) {
				for (int rot = 0; rot < 4; rot++) {
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < n; j++) {
							ans |= check(a, cube, i, j); // �ϳ��� true�� true (����)
						}
					}
					cube = rotate(cube); // 4�� ȸ��
				}
				cube = mirror(cube); // 2�� ��Ī
			}
		}
		cout << (ans ? "yes" : "no") << '\n';
	}
	return 0;
}