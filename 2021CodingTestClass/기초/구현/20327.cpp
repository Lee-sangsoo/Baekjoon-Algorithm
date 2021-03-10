/*
�ۼ��� : �̻��
�Ͻ� : 2021.03.07
���� : �迭 ������ 6 - 20327
Ǯ�� : �迭 ������ 3�� �ҽ��� ���� �ٲ��ָ� �ȴ�.
       ���� �ڵ尡 ��ü�� ���� �ϱ� ������ �׻� �ε����� 0���� �����ߴٸ�
	   �� ������ ���۰� ���� ��ġ�� �Ű������� �Ѱ��ָ� �ȴ�.

	   �� ������� ������ �ͼ� ����ϸ� �ǰ� 
	   1 ~ 4���� 5 ~ 8�� ������ ���� �����ϸ� Ǯ�� �ȴ�.

	   (������ �ſ� ���� �ɸ���...)
	   (���� �ڵ�)
*/
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> operation1(vector<vector<int>> &a) {
	int n = a.size();
	vector<vector<int>> ans(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i][j] = a[n - i - 1][j];
		}
	}
	return ans;
}
vector<vector<int>> operation5(vector<vector<int>> &a, int l) {
	int n = a.size();
	vector<vector<int>> ans(n, vector<int>(n));
	int sub_size = (1 << l);
	int sub_count = n / sub_size;
	for (int i = 0; i < sub_count; i++) {
		for (int j = 0; j < sub_count; j++) {
			int x1 = i * sub_size;
			int y1 = j * sub_size;
			int x2 = (sub_count - i - 1)*sub_size;
			int y2 = j * sub_size;
			for (int x = 0; x < sub_size; x++) {
				for (int y = 0; y < sub_size; y++) {
					ans[x1 + x][y1 + y] = a[x2 + x][y2 + y];
				}
			}
		}
	}
	return ans;
}
vector<vector<int>> operation2(vector<vector<int>> &a) {
	int n = a.size();
	vector<vector<int>> ans(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i][j] = a[i][n - j - 1];
		}
	}
	return ans;
}
vector<vector<int>> operation6(vector<vector<int>> &a, int l) {
	int n = a.size();
	vector<vector<int>> ans(n, vector<int>(n));
	int sub_size = (1 << l);
	int sub_count = n / sub_size;
	for (int i = 0; i < sub_count; i++) {
		for (int j = 0; j < sub_count; j++) {
			int x1 = i * sub_size;
			int y1 = j * sub_size;
			int x2 = i * sub_size;
			int y2 = (sub_count - j - 1)*sub_size;
			for (int x = 0; x < sub_size; x++) {
				for (int y = 0; y < sub_size; y++) {
					ans[x1 + x][y1 + y] = a[x2 + x][y2 + y];
				}
			}
		}
	}
	return ans;
}
vector<vector<int>> operation3(vector<vector<int>> &a) {
	int n = a.size();
	vector<vector<int>> ans(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i][j] = a[n - j - 1][i];
		}
	}
	return ans;
}
vector<vector<int>> operation7(vector<vector<int>> &a, int l) {
	int n = a.size();
	vector<vector<int>> ans(n, vector<int>(n));
	int sub_size = (1 << l);
	int sub_count = n / sub_size;
	for (int i = 0; i < sub_count; i++) {
		for (int j = 0; j < sub_count; j++) {
			int x1 = i * sub_size;
			int y1 = j * sub_size;
			int x2 = (sub_count - j - 1)*sub_size;
			int y2 = i * sub_size;
			for (int x = 0; x < sub_size; x++) {
				for (int y = 0; y < sub_size; y++) {
					ans[x1 + x][y1 + y] = a[x2 + x][y2 + y];
				}
			}
		}
	}
	return ans;
}
vector<vector<int>> operation4(vector<vector<int>> &a) {
	int n = a.size();
	vector<vector<int>> ans(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i][j] = a[j][n - i - 1];
		}
	}
	return ans;
}
vector<vector<int>> operation8(vector<vector<int>> &a, int l) {
	int n = a.size();
	vector<vector<int>> ans(n, vector<int>(n));
	int sub_size = (1 << l);
	int sub_count = n / sub_size;
	for (int i = 0; i < sub_count; i++) {
		for (int j = 0; j < sub_count; j++) {
			int x1 = i * sub_size;
			int y1 = j * sub_size;
			int x2 = j * sub_size;
			int y2 = (sub_count - i - 1)*sub_size;
			for (int x = 0; x < sub_size; x++) {
				for (int y = 0; y < sub_size; y++) {
					ans[x1 + x][y1 + y] = a[x2 + x][y2 + y];
				}
			}
		}
	}
	return ans;
}
void operation_1_to_4(vector<vector<int>> &a, int k, int sx, int sy, int len) {
	vector<vector<int>> b(len, vector<int>(len));
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			b[i][j] = a[sx + i][sy + j];
		}
	}
	if (k == 1) {
		b = operation1(b);
	}
	else if (k == 2) {
		b = operation2(b);
	}
	else if (k == 3) {
		b = operation3(b);
	}
	else if (k == 4) {
		b = operation4(b);
	}
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			a[sx + i][sy + j] = b[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, r;
	cin >> n >> r;
	int size = (1 << n);
	vector<vector<int>> a(size, vector<int>(size));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> a[i][j];
		}
	}
	while (r--) {
		int k, l;
		cin >> k >> l;
		int sub_size = (1 << l);
		if (1 <= k && k <= 4) {
			for (int i = 0; i < size; i += sub_size) {
				for (int j = 0; j < size; j += sub_size) {
					operation_1_to_4(a, k, i, j, sub_size);
				}
			}
		}
		else if (5 <= k && k <= 8) {
			if (k == 5) {
				a = operation5(a, l);
			}
			else if (k == 6) {
				a = operation6(a, l);
			}
			else if (k == 7) {
				a = operation7(a, l);
			}
			else if (k == 8) {
				a = operation8(a, l);
			}
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}