#include<stdio.h>
#include<string.h>
void main()
{
	char a[10000];
	char b[1000];
	char *p=a;
	int c=0;
	printf("���ˣ��������ַ���:");
	gets(a);
	strlwr(a);
	printf("\n");
	printf("���ˣ�����������Ҫ���ҵľ���:");
	gets(b);
	printf("\n");
	while((p=strstr(p,b))!=NULL)
	{
      c++;
		p++;
	}
	printf("�װ������ˣ��������ݵĸ���Ϊ��%d\n",c);
 }
