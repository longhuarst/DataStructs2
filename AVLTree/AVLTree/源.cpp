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


//����
void RotationLeft(AVLTree &T)
{
	AVLTree p = T;
	T = p->right;
	p->right = T->left;
	T->left = p;
	T->left->height = Heigth(T->left);
	T->height = Heigth(T);
}

//����
void RotationRight(AVLTree &T) {
	AVLTree p = T;
	T = p->left;
	p->left = T->right;
	T->right = p;
	T->right->height = Heigth(T->right);
	T->height = Heigth(T);
}

//������ת
void RotationLeftRight(AVLTree &T) {
	RotationLeft(T->left);
	RotationRight(T);
}

//������ת
void RotationRightLeft(AVLTree &T) {
	RotationRight(T->right);
	RotationLeft(T);
}

int Heigth(AVLTree T)
{
	if (T->left == NULL && T->right == NULL)
		return -1;
	if (T->left == NULL)
		return T->right->height + 1;
	if (T->right == NULL)
		return T->left->height + 1;
	return T->left->height>T->right->height?T->left->height:T->right->height + 1;
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
			if ((T->height = Heigth(T)) == 2) {
				//ƽ�ⱻ�ƻ�
				if (key < T->right->data) {
					//������
					RotationRight(T);
				}
				else if (key > T->left->data) {
					//������
					RotationLeftRight(T);
				}
				T->height = Heigth(T);
			}
		}
		else if (key > T->data) {
			insert(T->right, key);
			//���¼���߶�
			if ((T->height = Heigth(T)) == 2) {
				//ƽ�ⱻ�ƻ�
				if (key > T->right->data) {
					//������
					RotationLeft(T);
				}
				else if (key < T->left->data) {
					//������
					RotationRightLeft(T);
				}
				T->height = Heigth(T);
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
