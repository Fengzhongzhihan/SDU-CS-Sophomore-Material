//�ļ�1����Ķ��壬Point.h
class Point {	//��Ķ���
public:	//�ⲿ�ӿ�
	Point(int x = 0, int y = 0) : x(x), y(y) { }
	Point(const Point &p);
	~Point() { count--; }
	int getX() const { return x; }
	int getY() const { return y; }
	static void showCount();	//��̬������Ա
private:	//˽�����ݳ�Ա
	int x, y;
	static int count;	//��̬���ݳ�Ա
};
