#include <iostream>



using namespace std;



//�߱�
typedef struct ArcNode{

	int adjvex;//�����

	struct ArcNode *next;//��һ����

}ArcNode;


//�����
typedef struct VNode {

	int adjvex;//�����

	ArcNode *first;//ָ���һ����


}VNode;


//ͼ
typedef struct {

	VNode adjList;//����
	
	int arcnum;//����
	int vexnum;//������

}*AGraph;



















int main()
{















	system("pause");


}