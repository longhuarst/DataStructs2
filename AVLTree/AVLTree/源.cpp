#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>


using namespace std;






//����ƽ����
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









//����ת(������ת/LL��ת)
void SingleRotationLeft(AVLTree &T)
{
	AVLTree p = T;
	T = p->left;
	p->left = T->right;
	T->right = p;
	T->right->height = max(Height(T->right->left),Height(T->right->right)) + 1;
	T->height = max(Height(T->left),Height(T->right)) + 1;
}








//�ҵ���ת��������ת/RR��ת��
void SingleRotationRight(AVLTree &T) {
	AVLTree p = T;
	T = p->right;
	p->right = T->left;
	T->left = p;
	T->left->height = max(Height(T->left->left), Height(T->left->right)) + 1;
	T->height = max(Height(T->left), Height(T->right)) + 1;
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
			if ((Height(T->left) - Height(T->right)) == 2) {
				//ƽ�ⱻ�ƻ�
				if (key < T->right->data) {
					//������
					SingleRotationLeft(T);
				}
				else if (key > T->left->data) {
					//������
					DoubleRotationLeft(T);
				}
			}
		}
		else if (key > T->data) {
			insert(T->right, key);
			//���¼���߶�
			if (Height(T->right) - Height(T->left) == 2) {
				//ƽ�ⱻ�ƻ�
				if (key > T->right->data) {
					//������
					SingleRotationRight(T);
				}
				else if (key < T->left->data) {
					//������
					DoubleRotationRight(T);
				}
			}
		}
		else {
			cout << "�������Ѵ��ڵ�ֵ!" << endl;
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










//��α���
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
