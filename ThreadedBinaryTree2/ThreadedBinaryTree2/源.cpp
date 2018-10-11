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
		cout << "无法构造树,树不为空" << endl;
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



//前序遍历线索化
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

//创建前序线索树
void CreatePrevThreadedTree(ThreadedBinaryTree root)
{
	ThreadedBinaryTree prev = NULL;
	if (root) {
		PrevThreaded(root, prev);
		prev->rchild = NULL;
		prev->rtag = 1;
	}
}


//前序线索树 前序遍历

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





//中序线索化
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


//创建中序线索二叉树
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





//中序线索二叉树 的 中序遍历
void ThreadedInOrder(ThreadedBinaryTree root)
{
	ThreadedBinaryTree p = First(root);
	for (; p != NULL; p = Next(p)) {
		visit(p);
	}
}









//后序线索化

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


	cout << "======================前序遍历======================" << endl;
	
	cout << "构造树" << endl;

	BuildTree(prevTree,7);
	

	cout << "层次遍历树 : ";
	LevelOrder(prevTree); cout << endl;
	
	cout << "先序遍历树 ：";
	PreOrder(prevTree); cout << endl;

	cout << "二叉树 前序遍历 线索化";
	CreatePrevThreadedTree(prevTree); cout << endl;

	cout << "前序线索二叉树 前序遍历：";
	ThreadedPrevOrder(prevTree); cout << endl;





	cout << "======================中序遍历======================" << endl;

	cout << "构造树" << endl;

	BuildTree(InTree, 7);


	cout << "层次遍历树 : ";
	LevelOrder(InTree); cout << endl;

	cout << "中遍历树 ：";
	InOrder(InTree); cout << endl;

	cout << "二叉树 前序遍历 线索化";
	CreateInThreadedTree(InTree); cout << endl;

	cout << "中序线索二叉树 中序遍历：";
	ThreadedInOrder(InTree); cout << endl;









	cout << "======================后序遍历======================" << endl;

	cout << "构造树" << endl;

	BuildTree(PostTree, 7);


	cout << "层次遍历树 : ";
	LevelOrder(PostTree); cout << endl;

	cout << "后遍历树 ：";
	PostOrder(PostTree); cout << endl;

	cout << "二叉树 后序遍历 线索化";
	CreatePostThreadedTree(PostTree); cout << endl;

	cout << "中序线索二叉树 后序遍历：";
	ThreadedPostOrder(PostTree); cout << endl;





























	system("pause");
}