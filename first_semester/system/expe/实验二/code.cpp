#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void code(char * p)
{
    const char *key="I'm a sdu student";
    while(*p)
    {
        (*p)=(*p)^(*key);
        p++;
        key++;
    }
}

int main()
{
   char str[60];
   FILE * fp = fopen("origin.txt" , "r");
   FILE * lp = fopen("result.txt","w");
   if(fp == NULL) {
      perror("打开文件时发生错误");
      return(-1);
   }
   if( fgets (str, 60, fp)!=NULL ) 
   {
      printf("从origin.txt文件输入内容为\n");
      puts(str);
   }
   fclose(fp);
   code(str);
   printf("加密内容为\n");
   puts(str);
   fputs(str,lp);

   fclose(lp);
   printf("加密成功,文件已保存到result.txt文件");
   return(0);
}
