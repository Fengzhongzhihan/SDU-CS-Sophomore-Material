#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main()
{
	locale loc("zh_CN.GBK");	//�������ػ����÷���
	wcout.imbue(loc);	//Ϊwcout���ñ��뷽��
	wifstream in("ϰ��9-10����.txt");	//�����ļ���������
	wofstream out("ϰ��9-10���.txt");	//�����ļ���������
	in.imbue(loc);		//Ϊin���ñ��뷽��
	out.imbue(loc);		//Ϊout���ñ��뷽��
	wstring line;		//�����洢һ������
	map<wchar_t, int> counter;
	
	while(getline(in,line))
	{
		for(int i=0; i<line.length(); ++i)
		{
			counter[line[i]] ++;
		}
	}

	map<wchar_t, int>::iterator itor;
	int i = 1;
	for(itor=counter.begin(); itor != counter.end(); ++itor, ++i)
	{
		out<<itor->first<<"\t"<<itor->second<<"\t";
		if(i%4 == 0)
		{
			out<<endl;
		}
	}
	in.close();
	out.close();
	return 0;
}
