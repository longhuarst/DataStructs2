#include <iostream>



using namespace std;

#define MaxSize (100) //最大顶点数


typedef struct ArcNode{

	int adjvex;//顶点

	struct ArcNode *next;//下一个顶点

}ArcNode;

typedef struct VNode {
	int data;//顶点信息
	ArcNode *fist;//第一个顶点
}VNode;

typedef struct {

	VNode adjLists[MaxSize];
	int vex_num;//顶点数
	int arc_num;//边数

}AGraph;



















AGraph *G;



int main(int argc, char *argv)
{


	






















	system("pause");

}