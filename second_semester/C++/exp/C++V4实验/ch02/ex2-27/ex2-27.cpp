#include <iostream>
using namespace std ;

int main()
{
	int i,score;
	
	cout << "�㿼�Կ��˶��ٷ�?(0~100):";
	cin >> score;
	if (score>100 || score<0)
		cout << "����ֵ������0��100֮��!";
	else
	{
	
		i = score/10;
		switch (i)
		{
		case 10:
		case 9:
			cout << "��ĳɼ�Ϊ�ţ�";
			break;
		case 8:
			cout << "��ĳɼ�Ϊ����";
			break;
		case 7:
		case 6:
			cout << "��ĳɼ�Ϊ�У�";
			break;
		default:
			cout << "��ĳɼ�Ϊ�";
		}
	}
	return 0;
}
