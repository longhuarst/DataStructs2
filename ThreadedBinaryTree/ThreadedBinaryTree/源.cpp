#include <iostream>
#include <queue>


using namespace std;




//����������


typedef struct ThreadedBinaryTreeNode{

	int data;
	int ltag, rtag;
	struct ThreadedBinaryTreeNode *lchild, *rchild;

}ThreadedBinaryTreeNode, *ThreadedBinaryTree;




void Visit(ThreadedBinaryTree root)
{
	cout << root->data << " ";
}


//��ȡ�����������

int getDepth(ThreadedBinaryTree root)
{
	if (!root) {
		return -1;
	}
	int ldep, rdep;
	ldep = getDepth(root->lchild);
	rdep = getDepth(root->rchild);
	return (ldep > rdep ? ldep : rdep) + 1;
}





void addTree(ThreadedBinaryTree &root,int key)
{

	if (!root){
		root = new ThreadedBinaryTreeNode;
		root->lchild = NULL;
		root->rchild = NULL;
		root->ltag = 0;
		root->rtag = 0;
		root->data = key;
	}
	else {
		
		if (root->lchild == NULL) {
			root->lchild = new ThreadedBinaryTreeNode;
			root->lchild->lchild = NULL;
			root->lchild->rchild = NULL;
			root->lchild->ltag = 0;
			root->lchild->rtag = 0;
			root->lchild->data = key;
			return;
		}

		if (root->rchild == NULL) {
			root->rchild = new ThreadedBinaryTreeNode;
			root->rchild->lchild = NULL;
			root->rchild->rchild = NULL;
			root->rchild->ltag = 0;
			root->rchild->rtag = 0;
			root->rchild->data = key;
			return;
		}

		int ldep, rdep;
		
		ldep = getDepth(root->lchild);
		rdep = getDepth(root->rchild);


		if (ldep <= rdep) {
			addTree(root->lchild, key);
		}
		else {
			addTree(root->rchild, key);
		}



		
		
		
	}

		
}





//ǰ������
void PreThread(ThreadedBinaryTree root, ThreadedBinaryTree &prev)
{
	if (root) {
		if (!root->lchild) {
			root->lchild = prev;
			root->ltag = 1;
		}
		if (prev != NULL && prev->rchild == NULL) {
			prev->rchild = root;
			prev->rtag = 1;
		}
		prev = root;
		if (root->ltag == 0)
			PreThread(root->lchild,prev);
		if (root->rtag == 0) {
			PreThread(root->rchild,prev);
		}
	}
}


//����ǰ��������
void CreatePreThread(ThreadedBinaryTree root)
{
	ThreadedBinaryTree prev = NULL;
	if (root) {
		PreThread(root,prev);
		prev->rchild = NULL;
		prev->rtag = 1;
	}
}


//ǰ�����
void ThreadPreOrder(ThreadedBinaryTree root)
{
	ThreadedBinaryTree p = root;

	if (root) {
		
		while (p->ltag == 0) {
			Visit(p);
			p = p->lchild;
		}
		Visit(p);
		p = p->rchild;
	}
}


































//��������

void InThread(ThreadedBinaryTree root,ThreadedBinaryTree &prev) 
{
	if (root) {
		
		InThread(root->lchild,prev);

		if (root->lchild == NULL) {
			root->lchild = prev;
			root->ltag = 1;
		}
		

		if (prev != NULL && prev->rchild == NULL) {
			prev->rchild = root;
			prev->rtag = 1;
		}

		prev = root;

		InThread(root->rchild,prev);
	}
}


void CreateInThread(ThreadedBinaryTree root)
{
	ThreadedBinaryTree prev = NULL;

	if (root) {
		InThread(root, prev);

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
	if (root->rtag == 0) 
		return First(root->rchild);
	return root->rchild;
}



//�������
void ThreadInOrder(ThreadedBinaryTree root)
{

	for (ThreadedBinaryTree p = First(root); p != NULL; p = Next(p)) {
		Visit(p);
	}
}




//�����������
void PostThread(ThreadedBinaryTree root, ThreadedBinaryTree & prev)
{
	if (root) {
		PostThread(root->lchild, prev);
		PostThread(root->rchild, prev);

		if (root->lchild == NULL) {
			root->lchild = prev;
			root->ltag = 1;
		}
		if (prev != NULL && prev->rchild == NULL) {
			root->rchild = root;
			root->rtag = 1;
		}
		prev = root;
	}
}


void CreatePostThread(ThreadedBinaryTree root) 
{
	ThreadedBinaryTree prev = NULL;

	if (root) {
		PostThread(root, prev);
	}
}


void ThreadPostOrder(ThreadedBinaryTree root)
{

	while (root) {
		
		while (root->ltag == 0) {
			root = root->lchild;
		}
		Visit(root);
		root = root->rchild;
	}
}









//ǰ�����
void PreOrder(ThreadedBinaryTree root)
{
	if (root) {
		Visit(root);
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}



//�������
void InOrder(ThreadedBinaryTree root)
{
	if (root) {
		
		InOrder(root->lchild);
		Visit(root);
		InOrder(root->rchild);
	}
}






//�������
void PostOrder(ThreadedBinaryTree root)
{
	if (root) {

		PostOrder(root->lchild);
		
		PostOrder(root->rchild);

		Visit(root);
	}
}

void LevelOrder(ThreadedBinaryTree root)
{
	queue<ThreadedBinaryTree> Q;
	ThreadedBinaryTree p = root;

	if (!root)
		return;

	Q.push(root);

	while (!Q.empty()) {
		
		p = Q.front();
		Q.pop();

		Visit(p);

		if (p->lchild) Q.push(p->lchild);

		if (p->rchild) Q.push(p->rchild);

		
	}
}









ThreadedBinaryTree myTreePre = NULL;

ThreadedBinaryTree myTreeIn = NULL;

ThreadedBinaryTree myTreePost = NULL;





typedef struct x{

	char a;
	uint16_t xy;
	char o;

}ccc;














int main()
{

	ccc ccc;
	ccc.a = (char)0xa5;
	ccc.xy = 1111.1111111111;
	ccc.o = (char)0xa5;


	cout << "sizeof " << sizeof(x) << endl;


	for (int i = 0; i < 7; ++i) {
		addTree(myTreePre, i);
		addTree(myTreeIn, i);
		addTree(myTreePost, i);
	}

	cout << "ǰ�����" << endl;
	PreOrder(myTreePre);
	cout << endl;
	CreatePreThread(myTreePre);
	ThreadPreOrder(myTreePre);


	cout << "�������" << endl;
	InOrder(myTreeIn);
	cout << endl << "��α���" << endl;
	LevelOrder(myTreeIn);
	cout << endl;
	cout << "�����������" << endl;
	CreateInThread(myTreeIn);
	ThreadInOrder(myTreeIn);



	cout << "�������" << endl;
	PostOrder(myTreePost);
	cout << endl;
	CreatePostThread(myTreePost);
	ThreadPostOrder(myTreePost);





	//LevelOrder(myTree);





	system("pause");
}

