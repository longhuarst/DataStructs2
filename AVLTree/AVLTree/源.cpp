#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>


using namespace std;






//二叉平衡树
typedef struct AVLTreeNode{
	int data;
	struct AVLTreeNode *left, *right;
	int height;
}AVLTreeNode,*AVLTree;









int Height(AVLTree T)
{
	if (!T)
		return -1;
	else return T->height;
}









//左单旋转(左左旋转/LL旋转)
void SingleRotationLeft(AVLTree &T)
{
	AVLTree p = T;
	T = p->left;
	p->left = T->right;
	T->right = p;
	T->right->height = max(Height(T->right->left),Height(T->right->right)) + 1;
	T->height = max(Height(T->left),Height(T->right)) + 1;
}








//右单旋转（右右旋转/RR旋转）
void SingleRotationRight(AVLTree &T) {
	AVLTree p = T;
	T = p->right;
	p->right = T->left;
	T->left = p;
	T->left->height = max(Height(T->left->left), Height(T->left->right)) + 1;
	T->height = max(Height(T->left), Height(T->right)) + 1;
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
			if ((Height(T->left) - Height(T->right)) == 2) {
				//平衡被破坏
				if (key < T->right->data) {
					//左左旋
					SingleRotationLeft(T);
				}
				else if (key > T->left->data) {
					//左右旋
					DoubleRotationLeft(T);
				}
			}
		}
		else if (key > T->data) {
			insert(T->right, key);
			//重新计算高度
			if (Height(T->right) - Height(T->left) == 2) {
				//平衡被破坏
				if (key > T->right->data) {
					//右右旋
					SingleRotationRight(T);
				}
				else if (key < T->left->data) {
					//右左旋
					DoubleRotationRight(T);
				}
			}
		}
		else {
			cout << "插入了已存在的值!" << endl;
			exit(-1);
		}

		T->height = max(Height(T->left), Height(T->right)) + 1;
	}
}












void Visit(AVLTree T) {

	if (!T) {
		std::cout << "X ";
	}else
		std::cout << T->data <<" ";
}










//层次遍历
void LevelOrder(AVLTree T) {


	queue<AVLTree> Q;

	if (!T)
		return;

	Q.push(T);


	while (!Q.empty()) {

		Visit(Q.front());

		if (Q.front()->left) Q.push(Q.front()->left);
		if (Q.front()->right) Q.push(Q.front()->right);

		Q.pop();


	}



}





void Delete(){


}













int main()
{


	AVLTree T = NULL;

	for (int i = 0; i < 20; ++i) {
		insert(T, i);
	}



	LevelOrder(T);


	system("pause");


}
