/*
�ۼ��� : �̻��
�Ͻ� : 2021.04.23
���� : Ʈ�� ��ȸ - 1991
Ǯ�� : ����(pre), ����(in), ����(post) ��ȸ(order)�� �����ϴ� ����
       Ʈ�� ��ȸ�� ������ ���� �ٷ� Ǯ� �����̴�.
	   ������ ó�� ��� �� ���� �Է��� �־��ְ� ó���ϴ� ����� ����ߴµ�
	   �򰥸��� �κ��� ���Ҵ�.

	   �ظ� �κ�
	   1. ��� ������ typedef struct�� ����Ͽ����� Ǯ�̿����� �׳� struct�� ���
	   2. �����Ҵ� �̾߱Ⱑ ���� ���ͼ� �򰥷ȴ�.
	   3. �Է��� ��� �޾ƾ� �ϴ��� ������.

	   �ذ� ���
	   1. C���� ����ϴ� typedef ����� C++�� �Ѿ���鼭 �׳� ������ε� �����ϰ�
	      �ٲ���ٰ� �Ѵ�. ������, C���� ȣȯ�� ���ؼ��� ���� ó���� �ùٸ���.
		  (�ڵ� �׽�Ʈ������ ���� ó���� �켱������ ����)
	   2. ���� Ǯ�̴� ����ü �迭�� ���� �ִ� ũ�⸦ �޾ƿͼ� ó���Ͽ�����,
	      ũ�⿡ �´� �޸� ���� ���� ó���� ���ؼ��� �����Ҵ��� �ùٸ���.
		  ( node *tree - ������ ����ü ������(�迭) ����)
		  ( tree = (node)malloc(sizeof(node) * n) - ũ�� n�� �´� �迭 ���� )
	   3. �迭�� ���� -> tree[i] => i����� ���� ���� ����
*/
#include<iostream>

using namespace std;

struct node {
	char data;
	node* leftChild;
	node* rightChild;
};

struct node tree[28];

void preorder(node* ptr) {
	if (ptr) {
		cout << ptr->data;
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

void inorder(node* ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data;
		inorder(ptr->rightChild);
	}
}

void postorder(node* ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data;
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		tree[i].data = i;
		tree[i].leftChild = NULL;
		tree[i].rightChild = NULL;
	}

	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		tree[a - 'A'].data = a;
		if (b != '.') tree[a - 'A'].leftChild = &tree[b - 'A'];
		if (c != '.') tree[a - 'A'].rightChild = &tree[c - 'A'];
	}

	preorder(&tree[0]);
	cout << '\n';
	inorder(&tree[0]);
	cout << '\n';
	postorder(&tree[0]);
}