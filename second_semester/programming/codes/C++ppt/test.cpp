#include<iostream>
#include<string.h>
using namespace std;
//输出字符串
int main()
{
	char str[1000];
	gets(str);
	int n = strlen(str);
	for (int i = 0; i<n; i++)
	{
		int j = i;
		while (j < n && str[j] != ' ')j++;
		//具体逻辑
		for (int k = i; k < j; k++)cout << str[k];
		cout << endl;
		i = j;
	}
	return 0;
}
