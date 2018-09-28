#include <iostream>


using namespace std;


//аз╫с╠М

#define MaxVertexNum (100)
typedef int VertexType;

typedef struct ArcNode{
	int adjvex;
	struct ArcNode *next;
}ArcNode;

typedef struct VNode{
	VertexType data;
	ArcNode *first;
}VNode,AdjList[MaxVertexNum];


typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;






















int main()
{






	system("pause");

}