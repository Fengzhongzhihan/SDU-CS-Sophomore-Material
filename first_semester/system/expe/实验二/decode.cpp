#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void decode(char * p)
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
   FILE *fp;
   char str[60];
   /* 打开用于读取的文件 */
   fp = fopen("result.txt" , "r");
   if(fp == NULL) {
      perror("打开文件时发生错误");
      return(-1);
   }
   if( fgets (str, 60, fp)!=NULL ) 
   {
      /* 向标准输出 stdout 写入内容 */
      printf("从result.txt文件中读取加密内容为:\n");
      puts(str);
   }
   fclose(fp);
    printf("解密内容为:");
   decode(str);
   puts(str);
   return(0);
}
