#include <iostream>
#include <queue>

using namespace std;


//邻接表
#define MaxVertexNum (100)
typedef int VertexType;

//边表
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *next;
}ArcNode;

//顶点表
typedef struct VNode{
	VertexType data;
	ArcNode *first;
}VNode,AdjList[MaxVertexNum];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum;//顶点数、边数
}ALGraph;



int visited[MaxVertexNum];

void visit(ALGraph G,int V)
{

	cout << G.vertices[V].data << " ";
}



//返回第一个邻接点
int FirstNeighbor(ALGraph G, int v)
{
	return G.vertices[v].first->adjvex;
}

int NextNeighbor(ALGraph G, int v, int w)
{
	ArcNode *p = G.vertices[v].first;

	while (p != NULL && p->adjvex != w)
		p = p->next;

	if (p == NULL)
		return -1;

	p = p->next;

	if (p == NULL)
		return -1;

	return p->adjvex;
}

//广度优先搜索算法
void BFS(ALGraph G, int v) 
{
	visit(G, v);//先访问节点
	visited[v] = true;

	queue<int> Q;
	Q.push(v);

	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		//cout <<endl<< " _ "<<v<<" ";

		//cout << "第一个邻接节点=" << FirstNeighbor(G, v) << endl;

		for (int i = FirstNeighbor(G, v); i >= 0; i = NextNeighbor(G, v, i)) {
			//cout << "x ";
			if (!visited[i]) {
				visit(G, i);
				visited[i] = true;
				Q.push(i);
			}
			else {
				//cout << "本点已经被访问过 " << endl;
			}

		}


	}

	


}


void BFSTraverse(ALGraph G)
{
	

	for (int i = 0; i < G.vexnum; ++i) {
		visited[i] = false;
	}


	for (int i = 0; i < G.vexnum; ++i) {
		if (!visited[i]) {
			BFS(G, i);
			cout << "///" << endl;
		}
	}

}








bool dfs_visited[MaxVertexNum] = {false};

void DFS(ALGraph G, int v)
{
	visit(G, v);
	dfs_visited[v] = true;

	for (int i = FirstNeighbor(G, v); i >= 0; i = NextNeighbor(G, v, i)) {
		if (!dfs_visited[i]) {
			DFS(G, i);
		}
	}
}







int main()
{

	ALGraph G;


	//构造图
	G.vexnum = 8;
	G.arcnum = 10;

	G.vertices[0].first = new ArcNode;
	G.vertices[0].first->adjvex = 1;
	G.vertices[0].first->next = new ArcNode;
	G.vertices[0].first->next->adjvex = 4;
	G.vertices[0].first->next->next = NULL;

	G.vertices[1].first = new ArcNode;
	G.vertices[1].first->adjvex = 0;
	G.vertices[1].first->next = new ArcNode;
	G.vertices[1].first->next->adjvex = 5;
	G.vertices[1].first->next->next = NULL;


	G.vertices[2].first = new ArcNode;
	G.vertices[2].first->adjvex = 3;
	G.vertices[2].first->next = new ArcNode;
	G.vertices[2].first->next->adjvex = 5;
	G.vertices[2].first->next->next = new ArcNode;
	G.vertices[2].first->next->next->adjvex = 6;
	G.vertices[2].first->next->next->next = NULL;


	G.vertices[3].first = new ArcNode;
	G.vertices[3].first->adjvex = 2;
	G.vertices[3].first->next = new ArcNode;
	G.vertices[3].first->next->adjvex = 7;
	G.vertices[3].first->next->next = NULL;

	G.vertices[4].first = new ArcNode;
	G.vertices[4].first->adjvex = 0;
	G.vertices[4].first->next = NULL;

	G.vertices[5].first = new ArcNode;
	G.vertices[5].first->adjvex = 2;
	G.vertices[5].first->next = new ArcNode;
	G.vertices[5].first->next->adjvex = 6;
	G.vertices[5].first->next->next = NULL;


	G.vertices[6].first = new ArcNode;
	G.vertices[6].first->adjvex = 2;
	G.vertices[6].first->next = new ArcNode;
	G.vertices[6].first->next->adjvex = 3;
	G.vertices[6].first->next->next = new ArcNode;
	G.vertices[6].first->next->next->adjvex = 5;
	G.vertices[6].first->next->next->next = new ArcNode;
	G.vertices[6].first->next->next->next->adjvex = 7;
	G.vertices[6].first->next->next->next->next = NULL;


	G.vertices[7].first = new ArcNode;
	G.vertices[7].first->adjvex = 3;
	G.vertices[7].first->next = new ArcNode;
	G.vertices[7].first->next->adjvex = 6;
	G.vertices[7].first->next->next = NULL;

	for (int i = 0; i < G.vexnum; ++i) {
		G.vertices[i].data = i+1;

	}



	for (int i = 0; i < G.vexnum; ++i) {
		visited[i] = false;
	}
	BFS(G, 1);





	cout << "----------" << endl;
	for (int i = 0; i < G.vexnum; ++i) {
		dfs_visited[i] = false;
	}
	DFS(G, 0);
	//cout << "xxxxxx" << endl;




	//for (int i = 0; i < G.vexnum; ++i) {
	//	int w;
	//	w = FirstNeighbor(G, i);
	//	cout<<w<<" ";

	//	while (w >= 0) {
	//		w = NextNeighbor(G, i, w);
	//		cout << w << " ";
	//	}
	//	cout << endl;
	//}
	//

	//cout << "====";
	//cout << endl;
	////广度优先搜索算法 
	//BFSTraverse(G);
	//cout << "====";
	//cout << endl;


	
	system("pause");

}






