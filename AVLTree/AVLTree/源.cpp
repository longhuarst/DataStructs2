#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;


//二叉平衡树
typedef struct AVLTreeNode{
	int data;
	struct AVLTreeNode *left, *right;
	int height;
}AVLTreeNode,*AVLTree;


//左旋
void RotationLeft(AVLTree &T)
{
	AVLTree p = T;
	T = p->right;
	p->right = T->left;
	T->left = p;
	T->left->height = Heigth(T->left);
	T->height = Heigth(T);
}

//右旋
void RotationRight(AVLTree &T) {
	AVLTree p = T;
	T = p->left;
	p->left = T->right;
	T->right = p;
	T->right->height = Heigth(T->right);
	T->height = Heigth(T);
}

//左右旋转
void RotationLeftRight(AVLTree &T) {
	RotationLeft(T->left);
	RotationRight(T);
}

//右左旋转
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
			//重新计算高度
			if ((T->height = Heigth(T)) == 2) {
				//平衡被破坏
				if (key < T->right->data) {
					//右右旋
					RotationRight(T);
				}
				else if (key > T->left->data) {
					//左右旋
					RotationLeftRight(T);
				}
				T->height = Heigth(T);
			}
		}
		else if (key > T->data) {
			insert(T->right, key);
			//重新计算高度
			if ((T->height = Heigth(T)) == 2) {
				//平衡被破坏
				if (key > T->right->data) {
					//左左旋
					RotationLeft(T);
				}
				else if (key < T->left->data) {
					//右左旋
					RotationRightLeft(T);
				}
				T->height = Heigth(T);
			}
		}
		else {
			cout << "插入了已存在的值!" << endl;
			exit(-1);
		}
	}
}

int main()
{

}
