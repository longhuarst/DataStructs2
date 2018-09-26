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


AVLTree findmax(AVLTree T) {

	if (!T)
		return NULL;

	while (T->right) {
		T = T->right;
	}

	return T;

}



//删除
AVLTree Delete(AVLTree &T, int key){

	if (!T)
		return NULL;

	if (key == T->data) {
		AVLTree p = T;

		if (T->left == NULL && T->right == NULL) { //叶子节点
			delete T; //直接删除
			return NULL;
		}
		else if (T->left == NULL) {
			T = T->right;
			delete p;
			return T; 
		}
		else if (T->right == NULL) {
			T = T->left;
			delete p;
			return T;
		}
		else {
			p = findmax(p->left);//找到左子树中的最大值
			T->data = p->data;
			if (T->data == T->left->data)
				T->left = NULL;
			else
				Delete(T->left, T->data);//删除最大值
			return T;
		}

		
	}


	if (key < T->data) {
		T->left = Delete(T->left, key);

		if (Height(T->right) - Height(T->left) == 2) {//不平衡点在左边
			if (Height(T->left->right) > Height(T->left->left)) {
				SingleRotationRight(T->left);
			}
			SingleRotationLeft(T);
		}
	}
	else if (key > T->data) {
		T->right = Delete(T->right, key);
		if (Height(T->left) - Height(T->right) == 2) {
			if (Height(T->right->left) > Height(T->right->right)) {
				SingleRotationLeft(T->right);
			}
			SingleRotationRight(T);
		}
	}

	T->height = max(Height(T->left), Height(T->right)) + 1;


	return T;




}





void search(AVLTree T, int key) {

	if (!T) {
		cout << "没找到！" << endl;
		return;
	}

	if (T->data == key) {
		cout << "找到了！" << endl;
	}
	else if (key < T->data) {
		search(T->left, key);
	}
	else if (key > T->data) {
		search(T->right, key);
	}




}







int main()
{


	AVLTree T = NULL;

	for (int i = 0; i < 20; ++i) {
		insert(T, i);
	}



	LevelOrder(T);




	cout << endl << "";

	Delete(T,5);


	LevelOrder(T);

	cout << endl;

	search(T,4);

	search(T,5);

	system("pause");


}
