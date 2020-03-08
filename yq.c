#include<stdio.h>
#include<string.h>
#include<windows.h>
struct
{
    char province[10];
    char city[10];
    int num;
} Info[1000];
int Sum=0;
char out_province[100][20];
int  out_num=0;
int Find_province(char in[])
{
    int i;
    for(i=0; i<out_num; i++)
    {
        if(strcmp(in,out_province[i])==0)
        {
            return 0;
        }
    }
    return 1;
}

void begin()
{
    char com[20];
    while(gets(com))
    {
        if(strcmp(com,"yq yq_in.txt")==0)
        {
            return ;
        }
        else
        {
            printf("请输入yq yq_in.txt\n");
        }
    }
}
void input()
{
    if(freopen("yq_in.txt","r",stdin)==0)
    {
        printf("文件打开失败 请将yq_in.txt移动至当前目录下\n");
        exit(0);
    }
    while(scanf("%s %s %d",Info[Sum].province,Info[Sum].city,&Info[Sum].num)!=EOF)
    {

        Sum++;
    }
    fclose(stdin);
}

void output()
{
    int i,j;
    for(i=0; i<Sum; i++)
    {
        if(Find_province(Info[i].province))
        {
            printf("%s\n",Info[i].province);
            for(j=0; j<Sum; j++)
            {
                if(strcmp(Info[i].province,Info[j].province)==0)
                {
                    printf("%s %d\n",Info[j].city,Info[j].num);
                }
            }
            printf("\n");
            strcpy(out_province[out_num],Info[i].province);
            out_num++;
        }
    }
}

int main()
{
    begin();
    input();
    output();
    return 0;

}

