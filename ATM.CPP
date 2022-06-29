#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
struct per           //定义结构体
{
 char name[20];
  char ID[20];
  int money;
  char mima[6];
  struct per * next;
};
typedef struct person    //定义另一结构体
{
 struct per kehu;
 struct person *next;
}L;
 
void chaxun(struct per *head);    //各个函数的声明
void kaihu(struct per *head);
void denglu(struct per *head);
void caidan(struct per *head);
void qukuan(struct per *head);
void xgmm(struct per *head);
void cunkuan(struct per *head);
void zhuanzhang(struct per *head);
void chuangjian(struct person **Phead);
void shuchu(struct person *Phead);
void shanchu(struct person **Phead);
void zengjia(struct person **Phead);
void chaxun1(struct person *Phead);
void chaxun2(struct person *Phead);
void chaxun3(struct person *Phead);
void tuichu();
void menu();
 
 
 
 
/*主函数*/
//
 
int main()
{
 char x;
 char choose; //choose为定义输入选择的变量
 int flag=1;
 struct person *Phead=NULL; //Phead为定义二层头指针
 struct per *head=NULL;  system("color 21");  //head为定义一层头指针
 printf("*****************************\n");
 printf("**欢迎使用ATM自动取款机系统**\n");
 printf("*****************************\n");
    printf("——————————————\n");
 printf("|    1  开户                |\n");
    printf("——————————————\n");
 printf("|    2  登陆                |\n");
    printf("——————————————\n");
 printf("|    3  前台客户信息查询中心|\n");
    printf("——————————————\n");
 printf("|    4  请选择您的需求      |\n");
    printf("——————————————\n");
 scanf("%s",&x);
 system("cls");
 
 switch(x)
 {
 case '1':system("cls");
          kaihu(head);   //调用开户函数
    break;
 
 case '2':system("cls");
          denglu(head);   //调用登陆函数
    break;
 
 case '3':system("cls");
          menu();   //调用后台菜单函数
    break;
 }
 while(flag)
 {
  system("cls");
  menu();       //调用后台菜单函数
  choose=getchar();
  switch(choose)
  {
  case '1':chuangjian(&Phead);
        shuchu(Phead); //调用后台输出函数
     system("pause");
     system("cls");
     break;
     case '2':chaxun1(Phead); //调用后台卡号查询函数
     system("pause");
     system("cls");
     break;
     case '3':chaxun2(Phead); //调用后台姓名查询函数
     system("pause");
     system("cls");
     break;
     case '4':
        chaxun3(Phead); //调用后台余额查询函数
     system("pause");
     system("cls");
     break;
     case '5':shanchu(&Phead); //调用后台删除用户函数
     system("pause");
     system("cls");
     break;
     case '6':
        zengjia(&Phead); //调用后台增加用户函数
     system("pause");
     system("cls");
     break;
     case '7':shuchu(Phead); //调用后台输出函数函数
     system("pause");
     system("cls");
     break;
     case '8':shuchu(Phead); 
     system("pause");
     system("cls");
     break;
     case '0':flag=0;
        printf("The end.\n");
     break;
  }
 }
 return 0;
}
   /*开户函数*/
 
void kaihu(struct per *head)
{
 head=NULL;
 FILE *fp;   //定义文件指针
 struct per *p1=NULL,*p2=NULL;   //p1,p2为定义链表指针
 p1=(struct per*)malloc(sizeof(struct per));  //开辟内存单元
       printf("请输入您的姓名：\n");  //请数据输入链表中
    scanf("%s",p1->name);
    printf("请设置您的卡号：\n");
    scanf("%s",p1->ID);
    printf("请设置您银行卡密码：\n");
    scanf("%s",p1->mima);
    p1->money=0;
    p1->next=NULL;
    printf("您的个人信息为");
       printf("姓名：%s \n卡号：%s \n余额：%4d\n",p1->name,p1->ID,p1->money);
          if(NULL==head)           //为新用户开辟内存单元
    {
     head=(struct per *)malloc(sizeof(struct per));
     head->next=p1;    //进行头插法，将其作为第一个节点
    }
    else    //为新增客户开辟内存单元
    {
     for(p2=head;p2->next!=NULL;p2=p2->next); //进行尾插
     p2->next=p1;
    }
    if((fp=fopen("save.txt","ab+"))==NULL) //打开文件
    {
     printf("cannot poen file\n");
     return;
    }
    if(fwrite(p1,sizeof(struct per),1,fp)!=1)  //将链表信息写入文件中
     printf("file write error\n");
        fclose(fp);
     printf("\n");
     printf("恭喜您开户成功，请登录\n");
     system("pause");
     system("cls");
     denglu(head);
}
 
 
//登陆函数

void denglu(struct per *head)
{
 char d[20];
 char mima[20];
 int i,j;
 FILE *fp;     //定义文件指针
 struct per *p,*q=NULL;
 if((fp=fopen("save.txt","rb+"))==NULL)   //打开一个二进制文件，为读方式
 {
  printf("不能打开文件\n");   //如不能打开，则结束程序
 }
 p=(struct per*)malloc(sizeof(struct per));   //申请空间
 head=p;
 while(!feof(fp))       //循环读数据直到文件尾结束
 
 {
  if(1!=fread(p,sizeof(struct per),1,fp))
   break;   //如果没读到数据，跳出循环
  p->next=(struct per *)malloc(sizeof(struct per));  //为下一个结点申请空间
  q=p;  //保存当前节点的指针，作为下一结点的前驱
  p=p->next;  //指针后移，新读入数据链到当前表尾
  
 }
 q->next=NULL;  //最后一个结点的后继指针为空
 fclose(fp);
 printf("  **********************\n");
 printf("  ***欢迎来到建设银行***\n");
 printf("  **********************\n");
 for(j=1;j<4;j++)      //限制卡号输入的次数的循环
 {
  printf("请输入您的卡号\n");
  scanf("%s",d);
  for(q=head;q!=NULL;q=q->next)   //遍历链表
  {
   if(strcmp(q->ID,d)!=0)  //核对账号
   {
   continue;   //跳出循环
   }
     else
  {
   for(i=1;i<4;i++)   //限制密码输入的次数的循环
   {
    printf("\n\n请输入您的密码\n");
    scanf("%s",mima);
    if(strcmp(q->mima,mima)!=0)      //核对密码
    {
     printf("密码不正确。请重新输入密码\n");
     system("pause");
     system("cls");
     continue;    //若密码不对，跳出循环
    }
    else
    {
     system("cls");
     caidan(head);   //调用菜单函数
    }
   }
   printf("\n\n\n您输入密码三次错误，谢谢光临\n");
   system("pause");
   system("cls");
   exit(0);
  }
 }
  
 
 printf("\n\n\n您输入的卡号有误，请重试\n");
 system("pause");
 system("cls");
}
printf("您的卡号三次输入错误，谢谢使用\n");
exit(0);
}
 
 
 
//银行菜单函数/
void caidan(struct per *head)
{
 head=NULL;
 int i;      //i为客户选择输入的变量
 while(1)
 {
  printf("请选择您需要的业务\n");      //银行业务菜单
  printf("*********************************\n");
  printf("**  1 取款   *****   2 查询    **\n");
  printf("*********************************\n");
  printf("**  3 转账   *****   4 修改密码**\n");
  printf("*********************************\n");
  printf("**  5 存款   *****   6 退出    **\n");
  printf("*********************************\n");
  scanf("%d",&i);
  if(i<6||i>0)
  {
   switch(i)
   {
   case 1:qukuan(head);       //调用银行取款函数
          system("pause");
       system("cls");
       break;
   case 2:system("cls");
       chaxun(head);  //调用银行查询函数
       break;
            case 3:system("cls");
       zhuanzhang(head);  //调用银行转账函数
       break;
            case 4:system("cls");
       xgmm(head);  //调用银行修改密码函数
       break;
            case 5:system("cls");
       cunkuan(head);  //调用银行存款函数
       break;
            case 6:system("cls");
       tuichu();  //调用银行退出函数
       break;
   }
  }
  else
  {
   printf("您的输入有误\n");
   system("pause");
   system("cls");
  }
 }
}
 
 
//银行取款函数
//
void qukuan(struct per *head)
{
 head=NULL;   //head为链表头指针
 int i;
 FILE *fp;          //定义文件指针
 struct per *p,*q=NULL;
 if((fp=fopen("save.txt","rb+"))==NULL) //打开一个二进制文件，为读方式
 {
  printf("不能打开文件\n");  //如不能打开，则结束程序
 }
 p=(struct per*)malloc(sizeof(struct per));  //申请空间
 head=p;
 while(!feof(fp))   //循环读数据直到文件尾结束
 {
  if(1!=fread(p,sizeof(struct per),1,fp))
   break;   //如果没有读到数据，跳出循环
  p->next=(struct per *)malloc(sizeof(struct per));  //为下一个结点申请空间
  q=p;   //保存当前结点的指针，作为下一个结点的前驱
  p=p->next;  //指针后移，新读入数据链到当前表尾
 }
 q->next=NULL;  //最后一个结点的后继指针为空
 fclose(fp);
 system("cls");
 printf("************************************\n");
    printf("**  1: 100元    *****    2:200元  **\n");
 printf("************************************\n");
    printf("**  3: 300元    *****    4:400元  **\n");
 printf("************************************\n");
    printf("**  5: 500元    *****    6:600元  **\n");
 printf("************************************\n");
    printf("请按要求选择您要取款的金额\n");
 scanf("%d",&i);
 if(i>6||i<=0)    //限制输入范围
 {
  printf("对不起，您的输入有误\n\n");
  return;
 }
 else
 {
  i=100*i;  //对应选项乘以一百为取款金额
  if(i>q->money)
  {
   printf("对不起，您的金额不足\n");
   system("pause");
   system("cls");
   caidan(head);   //调用取款机菜单函数
  }
  else
  {
   q->money-=i;  //对金额进行处理
   if((fp=fopen("save.txt","wb+"))==NULL)  //打开文件
   {
    printf("cannot open file\n");
    return;
   }
   if(fwrite(q,sizeof(struct per),1,fp)!=1) //将修改的信息重新写入文件
    printf("file write error\n");
   printf("您已经成功取走%d元\n",i);
   q->next=NULL;
   fclose(fp);    //关闭文件
  }
  
 }
}
 
 
//银行转账函数//
void zhuanzhang(struct per *head)
{
 head=NULL;
 FILE *fp;  //定义文件指针
 struct per *p,*q=NULL;
 if((fp=fopen("save.txt","rb+"))==NULL)  //打开一个二进制文件，为读方式
 {
  printf("不能打开文件\n");  //如不能打开，则结束程序
 }
 p=(struct per*)malloc(sizeof(struct per));   //申请空间
 head=p;
 while(!feof(fp))    //循环读数据直到文件尾结束
 {
  if(1!=fread(p,sizeof(struct per),1,fp))
   break;    //如果没读到数据，跳出循环
  p->next=(struct per *)malloc(sizeof(struct per));  //为下一个结点申请空间
  q=p;   //保存当前结点的指针，作为下一个结点的前驱
  p=p->next;   //指针后移，新读入数据链到当前表尾
 }
 q->next=NULL;   //最后一个结点的后继指针为空
 fclose(fp);
 int i,j,k;
 printf("请输入帐号号码\n");
 scanf("%d",&i);
 printf("请再次输入帐号号码\n");   //核对卡号
 scanf("%d",&j);
 if(i!=j)
 {
  printf("两次账号不同，请重新输入\n");
  zhuanzhang(head);
 }
 else
 {
  system("cls");
 printf("************************************\n");
    printf("**  1: 100元    *****    2:200元  **\n");
 printf("************************************\n");
    printf("**  3: 300元    *****    4:400元  **\n");
 printf("************************************\n");
    printf("**  5: 500元    *****    6:600元  **\n");
 printf("************************************\n");
    printf("请输入转账金额\n");
 scanf("%d",&k);
 if(k>6||k<=0)
 {
  printf("对不起，您的输入有误\n\n");
  return;
 }
 else
 {
  k=k*100;
  if(k>q->money)    //对余额进行判断
  {
   printf("对不起，您的余额不足\n");
   system("pause");
   system("cls");
   caidan(head);
  }
  else
  {
   printf("您已成功转账%d元\n",k);
   q->money-=k;
   if((fp=fopen("save.txt","wb+"))==NULL)
   {
    printf("cannot open file\n");
    return;
   }
   if(fwrite(q,sizeof(per),1,fp)!=1)  //将数据重新写入文件
    printf("file write error\n");
   q->next=NULL;
   fclose(fp);
   system("pause");
   system("cls");
  }
 }
 }
}
 
 
 
//银行查询函数//
void chaxun(struct per *head)
{
 head=NULL;  //链表头指针
 FILE *fp;  //定义文件指针
 struct per *p,*q=NULL;
 if((fp=fopen("save.txt","rb+"))==NULL)  //打开一个二进制文件，为读方式
 {
  printf("不能打开文件\n");  //如不能打开，则结束程序
 }
 p=(struct per*)malloc(sizeof(struct per));   //申请空间
 head=p;
 while(!feof(fp))    //循环读数据直到文件尾结束
 {
  if(1!=fread(p,sizeof(struct per),1,fp))
   break;    //如果没读到数据，跳出循环
  p->next=(struct per *)malloc(sizeof(struct per));  //为下一个结点申请空间
  q=p;   //保存当前结点的指针，作为下一个结点的前驱
  p=p->next;   //指针后移，新读入数据链到当前表尾
 }
 q->next=NULL;   //最后一个结点的后继指针为空
 fclose(fp);
 printf("您卡上原有余额%d元\n\n",q->money);
 system("pause");
 system("cls");
}
 
 
//银行修改密码函数
//
 
void xgmm(struct per *head)
{
 head=NULL;          //链表头指针
 char mima[20];
 FILE *fp;  //定义文件指针
 struct per *p,*q=NULL;
 if((fp=fopen("save.txt","rb+"))==NULL)  //打开一个二进制文件，为读方式
 {
  printf("不能打开文件\n");  //如不能打开，则结束程序
 }
 p=(struct per*)malloc(sizeof(struct per));   //申请空间
 head=p;
 while(!feof(fp))    //循环读数据直到文件尾结束
 {
  if(1!=fread(p,sizeof(struct per),1,fp))
   break;    //如果没读到数据，跳出循环
  p->next=(struct per *)malloc(sizeof(struct per));  //为下一个结点申请空间
  q=p;   //保存当前结点的指针，作为下一个结点的前驱
  p=p->next;   //指针后移，新读入数据链到当前表尾
 }
 q->next=NULL;   //最后一个结点的后继指针为空
 fclose(fp);
 printf("请输入您的原密码\n");
 scanf("%s",mima);
 if(strcmp(q->mima,mima)==0)   //核对密码
 {
  {
   printf("密码正确\n");
   printf("请输入您的新密码:\n");
   scanf("%s",q->mima);
   if((fp=fopen("save.txt","wb+"))==NULL)  //文件头指针
   {
    printf("cannot open file\n");
   }
   if(fwrite(q,sizeof(struct per),1,fp)!=1)    //将修改的密码重新写入文件
    printf("file write error\n");
   fclose(fp);
   printf("修改密码成功\n\n\n\n\n");
  }
 }
 else
 {
  printf("您输入的密码与原密码不同\n");
  return;
  system("pause");
 }
 q->next=NULL;
}
 
 
//银行存款函数
 
 
 
void cunkuan(struct per *head)
{
 int i;
 head=NULL;   //链表头指针
 FILE *fp;  //定义文件指针
 struct per *p,*q=NULL;
 if((fp=fopen("save.txt","rb+"))==NULL)  //打开一个二进制文件，为读方式
 {
  printf("不能打开文件\n");  //如不能打开，则结束程序
 }
 p=(struct per*)malloc(sizeof(struct per));   //申请空间
 head=p;
 while(!feof(fp))    //循环读数据直到文件尾结束
 {
  if(1!=fread(p,sizeof(struct per),1,fp))
   break;    //如果没读到数据，跳出循环
  p->next=(struct per *)malloc(sizeof(struct per));  //为下一个结点申请空间
  q=p;   //保存当前结点的指针，作为下一个结点的前驱
  p=p->next;   //指针后移，新读入数据链到当前表尾
 }
 q->next=NULL;   //最后一个结点的后继指针为空
 fclose(fp);
 system("cls");
 printf("您卡上原有余额%d元\n",q->money);   
 printf("************************************\n");
    printf("**  1: 100元    *****    2:200元  **\n");
 printf("************************************\n");
    printf("**  3: 300元    *****    4:400元  **\n");
 printf("************************************\n");
    printf("**  5: 500元    *****    6:600元  **\n");
 printf("************************************\n");
    printf("请选择您要存入的余额\n");
 scanf("%d",&i);
 if(i>6||i<=0)
 {
  printf("对不起，您的输入有误\n\n");
  return;
 }
 else
 {
  i=100*i;
  q->money+=i;
  if((fp=fopen("save.txt","wb+"))==NULL)   //打开文件
  {
   printf("cannot open file\n");
  }
  if(fwrite(q,sizeof(struct per),1,fp)!=1)  //将修改的密码重新写入文件
   printf("file write error\n");
      printf("您已经成功存取%d元\n",i);
   q->next=NULL;
   fclose(fp);
   system("pause");
   system("cls");
 }
}
 
 
 
//退出银行函数
///
void tuichu()
{
 printf("谢谢使用\n");
 exit(0);
}
 
//后台运行菜单函数
///
void menu()
{
 printf("****************欢迎来到建设银行取款机系统****************\n\n\n\n");
 printf("**************************************************\n");
 printf("**** 1 建立信息并显示  ******  2 卡号查询信息 ****\n");
 printf("**************************************************\n");
 printf("**** 3 姓名查询信息    ******  4 余额查询信息 ****\n");
 printf("**************************************************\n");
 printf("**** 5 删除某卡号信息  ******  6 增加新的用户 ****\n");
 printf("**************************************************\n");
 printf("**** 7 按余额降序输出  ******  8 输出         ****\n");
 printf("**************************************************\n");
 printf("**** 0 退出            ******    谢谢光临     ****\n");
 printf("**************************************************\n");
 printf("请选择您需要的业务\n\n");
}
 
 
 
//后台运行创建链表函数
 
void chuangjian(struct person **Phead)  //*(*Phead)为指向结构体指针的地址
{
 struct person *p,*t;    //定义操作指针
 char n[20];
 char a[20];
 int s;
 if(*Phead) *Phead=NULL;
 printf("请输入卡号 姓名 余额 （若要结束请输入三个为零）\n");
 printf("请输入卡号\n");
 scanf("%s",n);
 printf("请输入姓名\n");
 scanf("%s",a);
 printf("请输入预存金额\n");
 scanf("%d",&s);
 if(s==0) return;
 p=(L *)malloc(sizeof(L));     //将信息输入链表中
 strcpy(p->kehu.ID,n);
 strcpy(p->kehu.name,a);
 *Phead=p;    //将指针重新指向头指针
 printf("请输入卡号\n");
 scanf("%s",n);
 printf("请输入姓名\n");
 scanf("%s",a);
 printf("请输入预存金额\n");
 scanf("%d",&s);
 while(s)
 {
  t=p;      //将p的值赋给t,p又可以储存下一个结点
  p=(L *)malloc(sizeof(L));   //为新结点开辟新的内存
        strcpy(p->kehu.ID,n);
     strcpy(p->kehu.name,a);
  p->kehu.money=s;
  p->next=NULL;
  t->next=p;   //将p的值接在t(即上一个结点的后面)
     printf("请输入卡号\n");  //尾插法
      scanf("%s",n);
     printf("请输入姓名\n");
     scanf("%s",a);
     printf("请输入预存金额\n");
     scanf("%d",&s);
 }
}
 
 
 
//后台运行输出链表函数/
void shuchu(struct person *Phead)
{
 printf("\n\n");
 if(NULL==Phead)
 {
  printf("没有客户信息可输出！\n");  //若头指针指向空，则没有客户信息
  return;
 }
 while(Phead)  //遍历输出链表中所有客户信息
 {
  printf("卡号:%s\n姓名:\n余额:%d\n",Phead->kehu.ID,Phead->kehu.name,Phead->kehu.money);
  Phead=Phead->next;
 }
 printf("\n\n");
}
 
 
 //后台运行卡号查询函数
 ///
 
void chaxun1(struct person*Phead)
{
 char m[20];   //定义输入查找客户卡号的变量
 if(NULL==Phead)   //若头指针向空，则没有客户信息
 {
 printf("没有客户信息可查询！\n");
 return;
 }
 printf("请输入要查询的客户卡号：\n");  
 scanf("%s",m);
 while(NULL!=Phead&&strcmp(Phead->kehu.ID,m)!=0)  //在链表中遍历寻找中，直到链表存在并且卡号核对无误
  Phead=Phead->next;
 if(Phead==NULL)  //若指针指最后指向空，则没有客户信息
  printf("对不起，没有该用户！\n");
 else
  printf("卡号:%s\n姓名:\n余额:%d\n",Phead->kehu.ID,Phead->kehu.name,Phead->kehu.money);
 
}    //若找到，则输出客户信息
 
 
 
//后台运行姓名查询函数/
 
 
 
void chaxun2(struct person *Phead)
{
 char m[20];   //定义输入查找客户卡号的变量
 if(NULL==Phead)   //若头指针向空，则没有客户信息
 {
 printf("没有客户信息可查询！\n");
 return;
 }
  printf("请输入要查询的客户姓名：\n");  
  scanf("%s",m);
 while(NULL!=Phead&&strcmp(Phead->kehu.name,m)!=0)  //在链表中遍历寻找中，直到链表存在并且姓名核对无误
 Phead=Phead->next;
 if(Phead==NULL)  //若指针指最后指向空，则没有客户信息
  printf("对不起，没有该用户！\n");
 else
  printf("卡号:%s\n姓名:\n余额:%d\n",Phead->kehu.ID,Phead->kehu.name,Phead->kehu.money);
 
}    //若找到，则输出客户信息
 
 
//后台运行余额查询函数//
 
void chaxun3(struct person *Phead)
{
 long x;   //定义输入查找客户余额的变量
 if(NULL==Phead)   //若头指针向空，则没有客户信息
 {
 printf("没有客户信息可查询！\n");
 return;
 }
  printf("请输入要查询的客户信息的余额：\n");  
  scanf("%ld",&x);
 while(NULL!=Phead&&Phead->kehu.money!=x)  //在链表中遍历寻找中，直到链表存在并且余额核对无误，继续寻找
  Phead=Phead->next;
 if(Phead==NULL)  //若指针指最后指向空，则没有客户信息
  printf("对不起，没有该用户！\n");
 else
  printf("该客户的信息为\n");
  printf("卡号:%s\n姓名:\n余额:%d\n",Phead->kehu.ID,Phead->kehu.name,Phead->kehu.money);
 
}    //若找到，则输出客户信息
 
 
//后台运行删除客户信息函数
///
void shanchu(struct person **Phead)   //*(*Phead)为指向结构体指针的地址
{
 char k[20];    //定义输入查找客户姓名卡号的变量
 struct person *p=*Phead,*t;
 if(NULL==(*Phead))     //若指针最后指向空，则没有客户信息
 {
  printf("没有客户信息可删除！\n");
  return;
 }
 printf("请输入要删除的客户卡号：\n");
 scanf("%s",k);
 if(p->kehu.ID==k)  //若第一个客户就是，则让头指针指向下一个结点
  *Phead=(*Phead)->next,free(p);
 else
 {
  while(NULL==p->next&&p->next->kehu.ID!=k)   //遍历寻找，核对客户卡号
   p=p->next;   //当p->next没指向空，并且客户的卡号还没找到，则继续寻找
  if(p->next==NULL)
   printf("对不起，没有该客户！\n");
  else
  {
   t=p->next;  //如果找到，则把p->next的值赋给t
   p->next=p->next->next;
  }
 }
}
 
//后台运行增加用户信息函数
 
void zengjia(struct person **Phead)  //*(*Phead) 为指向结构体指针的地址
{
 char n[20];   //定义输入增加客户卡号的变量
 char a[20];   //定义输入增加客户姓名的变量
 int s;
 L *p,*t,*k;   //定义操作指针变量
 printf("请输入要插入的客户信息\n");
        printf("请输入卡号\n");  //尾插法
      scanf("%s",&n);
     printf("请输入姓名\n");
     scanf("%s",a);
     printf("请输入预存金额\n");
     scanf("%d",&s);
  p=(L *)malloc(sizeof(L));    //开辟空间
  strcpy(p->kehu.ID,a);   //将新的客户信息写入链表
  p->kehu.money=s;
  strcpy(p->kehu.name,n);
  if(NULL==(*Phead))   //如果是空链表，则把新客户信息作为第一个结点
  {
   *Phead=p;   //头插法
   (*Phead)->next=NULL;
   return ;
  }
  else
  {
   p->next=(*Phead);   //头插法
   (*Phead)=p;
  }
}