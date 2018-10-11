#include <iostream>

#include <queue>

using namespace std;



typedef struct ThreadedBinaryTreeNode{
	
	int data;

	int ltag, rtag;

	struct ThreadedBinaryTreeNode *lchild, *rchild, *parent;



}ThreadedBinaryTreeNode, *ThreadedBinaryTree;


void visit(ThreadedBinaryTree root)
{
	if (root) {
		cout << root->data << " ";
	}
}

void PreOrder(ThreadedBinaryTree root)
{
	if (root) {
		visit(root);
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}


void InOrder(ThreadedBinaryTree root)
{
	if (root) {
		InOrder(root->lchild);
		visit(root);
		InOrder(root->rchild);
	}
}



void PostOrder(ThreadedBinaryTree root)
{
	if (root) {
		PostOrder(root->lchild);
		PostOrder(root->rchild);
		visit(root);
	}
}

void LevelOrder(ThreadedBinaryTree root)
{
	if (!root)  return;
	queue<ThreadedBinaryTree> Q;
	ThreadedBinaryTree p;
	Q.push(root);
	while (!Q.empty()) {
		p = Q.front();
		visit(p);
		Q.pop();
		if (p->lchild) Q.push(p->lchild);
		if (p->rchild) Q.push(p->rchild);
	}
}



ThreadedBinaryTree NewNode(int data)
{
	ThreadedBinaryTree p = new struct ThreadedBinaryTreeNode;
	p->data = data;
	p->lchild = NULL;
	p->rchild = NULL;
	p->parent = NULL;
	p->ltag = 0;
	p->rtag = 0;

	return p;
}

void BuildTree(ThreadedBinaryTree &root,int max)
{
	int counter = 0;

	if (root) {
		cout << "�޷�������,����Ϊ��" << endl;
		return;
	}



	queue<ThreadedBinaryTree> Q;

	root = NewNode(++counter);

	
	Q.push(root);

	while (!Q.empty()) {
		
		ThreadedBinaryTree prev = Q.front();
		Q.pop();

		
		if (counter >= max) return;
		prev->lchild = NewNode(++counter);

		if (counter >= max) return;
		prev->rchild = NewNode(++counter);

		prev->lchild->parent = prev;
		prev->rchild->parent = prev;

		Q.push(prev->lchild);
		Q.push(prev->rchild);

	
	}

}



//ǰ�����������
void PrevThreaded(ThreadedBinaryTree root, ThreadedBinaryTree &prev)
{
	if (root) {
		if (root->lchild == NULL) {
			root->lchild = prev;
			root->ltag = 1;
		}
		if (prev != NULL && prev->rchild == NULL) {
			prev->rchild = root;
			prev->rtag = 1;
		}
		prev = root;
		if (root->ltag == 0) PrevThreaded(root->lchild, prev);
		if (root->rtag == 0) PrevThreaded(root->rchild, prev);
	}
}

//����ǰ��������
void CreatePrevThreadedTree(ThreadedBinaryTree root)
{
	ThreadedBinaryTree prev = NULL;
	if (root) {
		PrevThreaded(root, prev);
		prev->rchild = NULL;
		prev->rtag = 1;
	}
}


//ǰ�������� ǰ�����

void ThreadedPrevOrder(ThreadedBinaryTree root)
{
	if (!root)
		return;

	ThreadedBinaryTree p = root;


	while (p) {
		while (p->ltag == 0) {
			visit(p);
			p = p->lchild;
		}
		visit(p);
		p = p->rchild;
	}
	
}





//����������
void InThreaded(ThreadedBinaryTree root, ThreadedBinaryTree &prev)
{
	if (root) {
		
		InThreaded(root->lchild, prev);

		if (root->lchild == NULL) {
			root->lchild = prev;
			root->ltag = 1;
		}
		if (prev != NULL && prev->rchild == NULL) {
			prev->rchild = root;
			prev->rtag = 1;
		}

		prev = root;

		InThreaded(root->rchild, prev);

	}
}


//������������������
void CreateInThreadedTree(ThreadedBinaryTree root)
{
	ThreadedBinaryTree prev = NULL;
	if (root) {
		InThreaded(root, prev);
		prev->rchild = NULL;
		prev->rtag = 1;
	}
}


ThreadedBinaryTree First(ThreadedBinaryTree root)
{
	while (root->ltag == 0)
		root = root->lchild;
	return root;
}


ThreadedBinaryTree Next(ThreadedBinaryTree root)
{
	if (root->rtag == 0) return First(root->rchild);
	return root->rchild;
}





//�������������� �� �������
void ThreadedInOrder(ThreadedBinaryTree root)
{
	ThreadedBinaryTree p = First(root);
	for (; p != NULL; p = Next(p)) {
		visit(p);
	}
}









//����������

void PostThreaded(ThreadedBinaryTree root, ThreadedBinaryTree &prev)
{
	if (root) {
		PostThreaded(root->lchild, prev);
		PostThreaded(root->rchild, prev);

		if (root->lchild == NULL) {
			root->lchild = prev;
			root->ltag = 1;
		}
		if (prev != NULL && prev->rchild == NULL) {
			prev->rchild = root;
			prev->rtag = 1;
		}

		prev = root;
	}
}



void CreatePostThreadedTree(ThreadedBinaryTree root)
{
	ThreadedBinaryTree prev = NULL;

	if (root) {
		PostThreaded(root,prev);
	}
}



void ThreadedPostOrder(ThreadedBinaryTree root)
{
	bool bk_ = false;
	while (root) {
		while (root->ltag == 0 && bk_ == false) root = root->lchild;
		visit(root);
		bk_ = false;
		if (root->rtag == 0) {
			ThreadedBinaryTree p = root;

			if (root->parent == NULL)
				return;

			root = root->parent->rchild;

			if (root == NULL || root == p) {
				root = p->parent;
				bk_ = true;
			}
		}
		else {
			root = root->rchild;
			bk_ = true;
		}
	}
}































ThreadedBinaryTree prevTree;
ThreadedBinaryTree InTree;
ThreadedBinaryTree PostTree;




int main()
{


	cout << "======================ǰ�����======================" << endl;
	
	cout << "������" << endl;

	BuildTree(prevTree,7);
	

	cout << "��α����� : ";
	LevelOrder(prevTree); cout << endl;
	
	cout << "��������� ��";
	PreOrder(prevTree); cout << endl;

	cout << "������ ǰ����� ������";
	CreatePrevThreadedTree(prevTree); cout << endl;

	cout << "ǰ������������ ǰ�������";
	ThreadedPrevOrder(prevTree); cout << endl;





	cout << "======================�������======================" << endl;

	cout << "������" << endl;

	BuildTree(InTree, 7);


	cout << "��α����� : ";
	LevelOrder(InTree); cout << endl;

	cout << "�б����� ��";
	InOrder(InTree); cout << endl;

	cout << "������ ǰ����� ������";
	CreateInThreadedTree(InTree); cout << endl;

	cout << "�������������� ���������";
	ThreadedInOrder(InTree); cout << endl;









	cout << "======================�������======================" << endl;

	cout << "������" << endl;

	BuildTree(PostTree, 7);


	cout << "��α����� : ";
	LevelOrder(PostTree); cout << endl;

	cout << "������� ��";
	PostOrder(PostTree); cout << endl;

	cout << "������ ������� ������";
	CreatePostThreadedTree(PostTree); cout << endl;

	cout << "�������������� ���������";
	ThreadedPostOrder(PostTree); cout << endl;





























	system("pause");
}