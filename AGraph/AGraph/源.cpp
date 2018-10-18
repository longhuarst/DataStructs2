#include <iostream>
#include <time.h> 



using namespace std;



#define MaxSize (5)


//�߱�
typedef struct ArcNode {
	int adjvex;//��ǰ�ߵĶ���
	struct ArcNode *next;//ָ����һ������
}ArcNode;


//�����
typedef struct {
	
	int vex;//�������
	ArcNode *first;//�߱�ͷ

}VNode;



//ͼ�ڽӱ�
typedef struct AGraph_ {
	
	VNode adjlist[MaxSize];//�ڽӱ�
	int vexnum;//�������
	int arcnum;//�߸���
}*AGraph;







//�ڽӾ���ת��Ϊ�ڽӱ�洢��ʽ
void Matrix2List(int Matrix[][MaxSize], AGraph &G)
{

	G = new struct AGraph_;
	
	for (int i = 0; i < MaxSize; ++i) {
		G->adjlist[i].first = NULL;
		G->adjlist[i].vex = i;
	}






	G->vexnum = MaxSize;
	G->arcnum = 0;//�ڽӾ�����Ϊ1����Ŀ
	for (int i = 0; i < MaxSize; ++i) {
		for (int j = i + 1; j < MaxSize; ++j) {
			if (Matrix[i][j] == 1) {
				G->arcnum++; //i - > j ֮���б� ���ߴ洢���߱���ȥ

				if (G->adjlist[i].first == NULL) {
					G->adjlist[i].first = new ArcNode;
					G->adjlist[i].first->adjvex = j;
					G->adjlist[i].first->next = NULL;
				}
				else {
					struct ArcNode *p = G->adjlist[i].first;

					while (p->next != NULL) p = p->next;
					

					p->next = new ArcNode;
					p->next->adjvex = j;
					p->next->next = NULL;

				}
				
			}
		}
	}
}

//�����ڽӱ�
void ListOrder(AGraph G)
{
	for (int i = 0; i < MaxSize; ++i) {
		cout << (char)('A' + i) << " | " << i << " | ";
		ArcNode *p = G->adjlist[i].first;

		while (p) {
			cout << "* | ---> | " << p->adjvex << " | ";
			p = p->next;
		}

		cout << "^ |" << endl;
	}
}



void Visit(VNode *v)
{
	cout << (char)('A' + v->vex) << " ";
}



int visited[MaxSize] = { 0 };

//������������㷨
void DFS(AGraph G,VNode *v)
{
	//���ʵ�һ����
	Visit(v);
	visited[v->vex] = 1;

	ArcNode *pArc = v->first;

	while (pArc) {
		if (visited[pArc->adjvex] == 0) {
			DFS(G,&G->adjlist[pArc->adjvex]);
		}
		pArc = pArc->next;
	}
	


}

























#define MatrixMaxSize (MaxSize)

int Matrix[MatrixMaxSize][MatrixMaxSize];


AGraph G;



int main()
{
	cout << "ͼ - �ڽӱ�" << endl;

	srand(time(NULL));

	//��������ͼ
	cout << "�����������ͼ<>" << endl;

	for (int i = 0; i < MatrixMaxSize; ++i) {
		for (int j = i + 1; j < MatrixMaxSize; ++j) {
			int x = rand() % 100;
			if (x > 50) {
				Matrix[i][j] = 1;
			}
			else {
				Matrix[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < MatrixMaxSize; ++i) {
		Matrix[i][i] = 0;
	}

	for (int i = 0; i < MatrixMaxSize; ++i) {
		for (int j = 0; j < i; ++j) {
			Matrix[i][j] = Matrix[j][i];
		}
	}


	cout << "  ";
	for (int i = 0; i < MatrixMaxSize; ++i) {
		cout << (char)('A' + i) << " ";
	}
	cout << endl;
	for (int i = 0; i < MatrixMaxSize; ++i) {
		cout << (char)('A' + i) << " ";
		for (int j = 0; j < MatrixMaxSize; ++j) {
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}



	cout << "�ڽӱ� --> �ڽӾ���" << endl;
	Matrix2List(Matrix, G);

	cout << "��ʾ�ڽӱ�" << endl;
	ListOrder(G);

	//������ȱ����㷨
	cout << "������������㷨" << endl;
	DFS(G,&G->adjlist[0]);





	system("pause");
}












