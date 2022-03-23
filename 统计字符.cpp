#include<stdio.h>
#include<string.h>
void main()
{
	char a[10000];
	char b[1000];
	char *p=a;
	int c=0;
	printf("主人，请输入字符串:");
	gets(a);
	strlwr(a);
	printf("\n");
	printf("主人，请输入您想要查找的句子:");
	gets(b);
	printf("\n");
	while((p=strstr(p,b))!=NULL)
	{
      c++;
		p++;
	}
	printf("亲爱的主人，查找内容的个数为：%d\n",c);
 }
