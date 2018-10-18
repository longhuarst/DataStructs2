#include <iostream>



using namespace std;



//边表
typedef struct ArcNode{

	int adjvex;//顶点号

	struct ArcNode *next;//下一个边

}ArcNode;


//顶点表
typedef struct VNode {

	int adjvex;//顶点号

	ArcNode *first;//指向第一个边


}VNode;


//图
typedef struct {

	VNode adjList;//顶点
	
	int arcnum;//边数
	int vexnum;//顶点数

}*AGraph;



















int main()
{















	system("pause");


}