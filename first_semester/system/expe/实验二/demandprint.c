#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000];
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        char c=str[i];
        printf("%x ",c);
        if(c>='a'&&c<='z')
            printf("%c ",c-32);
        if(c>='A'&&c<='Z')
            printf("%c ",c+32);

        printf("\n");
    }

    return 0;
}