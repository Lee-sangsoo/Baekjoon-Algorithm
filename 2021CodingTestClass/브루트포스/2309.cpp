/*
�ۼ��� : �̻��
�Ͻ� : 2021.02.15
���� : �ϰ� ������ - 2309
Ǯ�� : �־��� ����� ���� 9�� �ſ� �۱� ������ ���Ʈ ������ �����ϸ� �ȴ�.
       7�� Ű�� ���� 100�̶�� ���� 9���� �տ��� 2���� ���� �� 100�� �Ǹ� �� �θ���
	   �߸��� �����̶�� ���̹Ƿ�
	   ��� �������� �տ��� 2�� �ݺ����� ���� 100�� �Ǵ� ��츦 ã�� ������ָ� �ȴ�.

	   9���� 2���� ã�� ����̹Ƿ� 
	   9C2 �� 9 * 8 / 2 = 36�̴�.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<int> height;
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		int h;
		cin >> h;
		height.push_back(h);
		sum += h;
	}
	sort(height.begin(), height.end());
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - height[i] - height[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					cout << height[k] << '\n';
				}
				return 0;
			}
		}
	}
}