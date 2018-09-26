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

//左单旋转(左左旋转/LL旋转)
void SingleRotationLeft(AVLTree &T)
{
	AVLTree p = T;
	T = p->left;
	p->left = T->right;
	T->right = p;
	T->right->height = Height(T->right);
	T->height = Height(T);
}

//右单旋转（右右旋转/RR旋转）
void SingleRotationRight(AVLTree &T) {
	AVLTree p = T;
	T = p->right;
	p->right = T->left;
	T->left = p;
	T->left->height = Height(T->left);
	T->height = Height(T);
}

//左右旋转(LR旋转)
void DoubleRotationLeft(AVLTree &T) {
	SingleRotationRight(T->left);
	SingleRotationLeft(T);
}

//右左旋转(RL旋转)
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
			//重新计算高度
			if ((T->height = Height(T)) == 2) {
				//平衡被破坏
				if (key < T->right->data) {
					//左左旋
					SingleRotationLeft(T);
				}
				else if (key > T->left->data) {
					//左右旋
					DoubleRotationLeft(T);
				}
				T->height = Height(T);
			}
		}
		else if (key > T->data) {
			insert(T->right, key);
			//重新计算高度
			if ((T->height = Height(T)) == 2) {
				//平衡被破坏
				if (key > T->right->data) {
					//右右旋
					SingleRotationRight(T);
				}
				else if (key < T->left->data) {
					//右左旋
					DoubleRotationRight(T);
				}
				T->height = Height(T);
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
