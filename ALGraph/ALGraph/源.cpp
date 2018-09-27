#include <iostream>



using namespace std;


#define MaxVexNum 100

typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *next;
}ArcNode;


typedef struct VNode{
	int data;
	ArcNode *first;
}Vnode,AdjList[MaxVexNum];


typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;







int main()
{












	system("pause");



}