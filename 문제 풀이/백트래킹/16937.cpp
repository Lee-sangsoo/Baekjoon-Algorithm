/*
�ۼ��� : �̱���
�Ͻ� : 2021.06.22
���� : 16937 - �� ��ƼĿ
Ǯ�� : ���� ä���� �߸��� ���� �־� ��Ȯ�� Ǯ������ Ȯ���� �� ����. (���۸��� ���� ����� �ߴ�)
       �켱 ��ƼĿ N�� �߿��� 2���� ��� �ش� ��ƼĿ�� ���� �� �ִ��� �������� �Ǵ��ϴ� �����̴�.

	   ��ƼĿ�� �������� �ƴ϶� 2�� ���̱� ������
	   ������ ���� N���� ��ƼĿ �߿��� 2���� ����.
	   �� ��, ��ƼĿ���� ȸ���� �����ϱ� ������ ȸ���� ����Ͽ��� �Ѵ�.
	   ����ؾ� �ϴ� �����δ� ȸ���� �Ȱ��� ��ƼĿ�� ���� �ʵ��� �ؾ� �Ѵ�.

	   �̸� �ľ��ϱ� ���� ���� ��ƼĿ�� ��� �ߴ��� ���ߴ��� Ȯ���ϴ� �ڵ带 �߰��Ѵ�.
	   V�� ����ũ��, ����ũ��, ��ƼĿ ��ȣ �� �����Ͽ�
	   ��ƼĿ ��ȣ�� ���� bool �迭�� ��� ���̶�� �ش� ��ƼĿ�� ȸ�� ���ѵ� ���̻� ������� ���ϵ��� �Ѵ�.

	   �̸� ���� ���������� ��ƼĿ�� ���̴µ�, ��ƼĿ�� ���̴� ����� �� 2�����̴�.
	   ���η� �̾� ���̱�
	   ���η� �̾� ���̱�

	   �� �ΰ��� ����� ����ϸ� �Ǵµ�, 
	   ��������
	     ����

	   �� 
	   �� �� ��
	   ��
	   ��

	   �̷��� ���η� ���̴� ��� ������ ���̸� ���� ���ؼ� �־��� ������ ũ�⸦ ������� Ȯ���ϰ� ������ ���̴� �� ���� Ȯ�����ָ� �ȴ�.
	   ���η� ���̴� ���� ������ ���̸� ���� ���ؼ� Ȯ���ϰ� ������ �� ���� Ȯ�����ָ� �ȴ�.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int h, w, n, Answer;
bool MAP[100][100]; // ������ �� �̻��ϴ�... -> �� �迭�� �����ϸ� ����� �ȴ�.
bool Select[101];
bool Select2[101];
vector<pair<pair<int, int>, int>> V;
vector<pair<int, int>> Sticker;

void DFS(int Idx, int Cnt)
{
	if (Cnt == 2) {
		int x1 = Sticker[0].first;
		int y1 = Sticker[0].second;
		int x2 = Sticker[1].first;
		int y2 = Sticker[1].second;
		int point = (x1 * y1) + (x2 * y2);

		if (x1 + x2 <= h && y1 <= w && y2 <= w) Answer = max(Answer, point);
		if (y1 + y2 <= w && x1 <= h && x2 <= h) Answer = max(Answer, point);
		return;
	}

	for (int i = Idx; i < V.size(); i++) {
		if (Select[i] || Select2[V[i].second]) continue;
		Select[i] = true;
		Select2[V[i].second] = true;
		Sticker.push_back({ V[i].first.first, V[i].first.second });
		DFS(i + 1, Cnt + 1);
		Sticker.pop_back();
		Select[i] = false;
		Select2[V[i].second] = false;
	}
}

int main(void){
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> h >> w >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;

		if (a != b)
		{
			V.push_back(make_pair(make_pair(a, b), i));
			V.push_back(make_pair(make_pair(b, a), i));
		}
		else V.push_back(make_pair(make_pair(a, b), i));
	}
	DFS(0, 0);
	cout << Answer << '\n';
	return 0;
}