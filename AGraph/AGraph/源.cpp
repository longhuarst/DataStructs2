#include <iostream>



using namespace std;

#define MaxSize (100) //��󶥵���


typedef struct ArcNode{

	int adjvex;//����

	struct ArcNode *next;//��һ������

}ArcNode;

typedef struct VNode {
	int data;//������Ϣ
	ArcNode *fist;//��һ������
}VNode;

typedef struct {

	VNode adjLists[MaxSize];
	int vex_num;//������
	int arc_num;//����

}AGraph;



















AGraph *G;



int main(int argc, char *argv)
{


	






















	system("pause");

}