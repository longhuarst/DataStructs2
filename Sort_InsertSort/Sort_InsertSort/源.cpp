#include <iostream>
#include <random>
using namespace std;


//插入排序



void InsertSort(int *data,int length)
{
	int tmp;
	for (int i = 1; i < length; ++i) {
		if (data[i - 1] > data[i]) {
			tmp = data[i];
			int j;
			for (j = i; tmp < data[j - 1] && j>0; j--) {
				data[j] = data[j - 1];
			}
			data[j] = tmp;
		}
	}
}


int myRandom(int min, int max)
{
	static default_random_engine e;

	return (e() - e.min()) / (float)(e.max() - e.min()) * (max - min) + min;


}


int main(int argc, char *argv)
{

	

	

	int data[10];

	cout << "生成序列： ";
	for (int i = 0; i < 10; ++i) {
		data[i] = myRandom(0,100);
		cout << data[i] << " ";
	}
	cout << endl;


	cout << "进行插入排序..." << endl;

	InsertSort(data, sizeof(data) / sizeof(int));

	cout << "生成序列： ";
	for (int i = 0; i < 10; ++i) {
		cout << data[i] << " ";
	}
	cout << endl;


	system("pause");


}


