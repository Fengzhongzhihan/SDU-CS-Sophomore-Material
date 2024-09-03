//10_8.cpp
#include <queue>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SPLIT_TIME_MIN = 500;		//ϸ���������ʱ��
const int SPLIT_TIME_MAX = 2000;	//ϸ�������ʱ��

class Cell;
priority_queue<Cell> cellQueue;

class Cell {	//ϸ����
private:
	static int count;	//ϸ������
	int id;		//��ǰϸ�����
	int time;	//ϸ������ʱ��
public:
	Cell(int birth) : id(count++) {	//birthΪϸ������ʱ��
		//��ʼ����ȷ��ϸ������ʱ��
		time = birth + (rand() % (SPLIT_TIME_MAX - SPLIT_TIME_MIN)) + SPLIT_TIME_MIN;
	}
	int getId() const { return id; }			//�õ�ϸ�����
	int getSplitTime() const { return time; }	//�õ�ϸ������ʱ��
	bool operator < (const Cell& s) const { return time > s.time; }	//���塰<��

	//ϸ������
	void split() const {
		Cell child1(time), child2(time);	//����������ϸ��
		cout << time << "s: Cell #" << id << " splits to #"
			<< child1.getId() << " and #" << child2.getId() << endl;
		cellQueue.push(child1);	//����һ����ϸ��ѹ�����ȼ�����
		cellQueue.push(child2);	//���ڶ�����ϸ��ѹ�����ȼ�����
	}
};
int Cell::count = 0;

int main() {
	srand(static_cast<unsigned>(time(0)));
	int t;	//ģ��ʱ�䳤��
	cout << "Simulation time: ";
	cin >> t;
	cellQueue.push(Cell(0));	//����һ��ϸ��ѹ�����ȼ�����
	while (cellQueue.top().getSplitTime() <= t) {
		cellQueue.top().split();	//ģ����һ��ϸ���ķ���
		cellQueue.pop();			//���ոշ��ѵ�ϸ������
	}
	return 0;
}
