#include <iostream>
#include <string>
using namespace std;

#define	N	8

float	grades[N];		//��ųɼ�������

int main()
{
	int 	i;
	float	total,average;
	
	//��ʾ����ɼ�
	for(i = 0; i < N; i++ )
	{
		cout << "Enter grade #" <<(i +1) << ": ";
		cin >> grades[i];
	}
	
	total = 0;
	for (i = 0; i < N; i++)
		total += grades[i];
	average = total / N;
	cout << "\nAverage grade: " << average << endl;
	return 0;
}
