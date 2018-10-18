#include <iostream>
#include <time.h> 



using namespace std;



#define MaxSize (5)


//边表
typedef struct ArcNode {
	int adjvex;//当前边的顶点
	struct ArcNode *next;//指向下一个顶点
}ArcNode;


//顶点表
typedef struct {
	
	int vex;//顶点序号
	ArcNode *first;//边表头

}VNode;



//图邻接表
typedef struct AGraph_ {
	
	VNode adjlist[MaxSize];//邻接表
	int vexnum;//顶点个数
	int arcnum;//边个数
}*AGraph;







//邻接矩阵转换为邻接表存储方式
void Matrix2List(int Matrix[][MaxSize], AGraph &G)
{

	G = new struct AGraph_;
	
	for (int i = 0; i < MaxSize; ++i) {
		G->adjlist[i].first = NULL;
		G->adjlist[i].vex = i;
	}






	G->vexnum = MaxSize;
	G->arcnum = 0;//邻接矩阵中为1的数目
	for (int i = 0; i < MaxSize; ++i) {
		for (int j = i + 1; j < MaxSize; ++j) {
			if (Matrix[i][j] == 1) {
				G->arcnum++; //i - > j 之间有边 将边存储到边表中去

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

//遍历邻接表
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

//深度优先搜索算法
void DFS(AGraph G,VNode *v)
{
	//访问第一个点
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
	cout << "图 - 邻接表" << endl;

	srand(time(NULL));

	//构造无向图
	cout << "随机构造无向图<>" << endl;

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



	cout << "邻接表 --> 邻接矩阵" << endl;
	Matrix2List(Matrix, G);

	cout << "显示邻接表" << endl;
	ListOrder(G);

	//深度优先遍历算法
	cout << "深度优先搜索算法" << endl;
	DFS(G,&G->adjlist[0]);





	system("pause");
}












