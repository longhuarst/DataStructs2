#include <iostream>


using namespace std;


#define maxVertexNum 100

typedef struct ArcNode{
	int tailvex, headvex;
	struct ArcNode *hlink, *tlink;
}ArcNode;

typedef struct VNode {
	int data;
	ArcNode *firstin, *firstout;
}VNode;

typedef struct {
	VNode xlist[maxVertexNum];
	int vexnum, arcnum;
}GLGraph;






int main() 
{









	system("pause");

}