#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;






//����ƽ����
typedef struct AVLTreeNode{
	int data;
	struct AVLTreeNode *left, *right;
	int height;
}AVLTreeNode,*AVLTree;

int Height(AVLTree T)
{
	if (T->left == NULL && T->right == NULL)
		return -1;
	if (T->left == NULL)
		return T->right->height + 1;
	if (T->right == NULL)
		return T->left->height + 1;
	return T->left->height > T->right->height ? T->left->height : T->right->height + 1;
}

//����ת(������ת/LL��ת)
void SingleRotationLeft(AVLTree &T)
{
	AVLTree p = T;
	T = p->left;
	p->left = T->right;
	T->right = p;
	T->right->height = Height(T->right);
	T->height = Height(T);
}

//�ҵ���ת��������ת/RR��ת��
void SingleRotationRight(AVLTree &T) {
	AVLTree p = T;
	T = p->right;
	p->right = T->left;
	T->left = p;
	T->left->height = Height(T->left);
	T->height = Height(T);
}

//������ת(LR��ת)
void DoubleRotationLeft(AVLTree &T) {
	SingleRotationRight(T->left);
	SingleRotationLeft(T);
}

//������ת(RL��ת)
void DoubleRotationRight(AVLTree &T) {
	SingleRotationLeft(T->right);
	SingleRotationRight(T);
}


void insert(AVLTree &T, int key) 
{
	if (!T) {
		T = new AVLTreeNode;
		T->data = key;
		T->left = NULL;
		T->right = NULL;
		T->height = 0;
	}
	else {
		if (key < T->data) {
			insert(T->left, key);
			//���¼���߶�
			if ((T->height = Height(T)) == 2) {
				//ƽ�ⱻ�ƻ�
				if (key < T->right->data) {
					//������
					SingleRotationLeft(T);
				}
				else if (key > T->left->data) {
					//������
					DoubleRotationLeft(T);
				}
				T->height = Height(T);
			}
		}
		else if (key > T->data) {
			insert(T->right, key);
			//���¼���߶�
			if ((T->height = Height(T)) == 2) {
				//ƽ�ⱻ�ƻ�
				if (key > T->right->data) {
					//������
					SingleRotationRight(T);
				}
				else if (key < T->left->data) {
					//������
					DoubleRotationRight(T);
				}
				T->height = Height(T);
			}
		}
		else {
			cout << "�������Ѵ��ڵ�ֵ!" << endl;
			exit(-1);
		}
	}
}

int main()
{

}
