#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
    FILE *fp;
    FILE *tp;
    char str[100];
	int tag = 1;
	char temp[20];
	int tag2 = 1;
	int tag3 = 1;
	char infname[50];
	char outfname[50];
	char sheng[50];
	char c[20]="all";
	printf("输入文件名:");
	scanf("%s",infname);
	printf("输出文件名:");
	scanf("%s",outfname);
	printf("查询省份(全部数据输入all):");
	scanf("%s",sheng);


	tp=fopen(outfname,"w");
    if ((fp = fopen(infname, "r")) == NULL){
        printf("打开文件失败 %d: %s\n", errno, strerror(errno));
        exit(-1);//找不到文件 ；
    }

    while(fgets(str, sizeof(str), fp)){
        str[strlen(str)-1] = '\0';//读入一整行 ；
    	char a[20],b[20],x[20];//a[]为省，b[]为市，x[]为人数；
		sscanf(str, "%s %s %s",a,b,x); //将一行分成三个元素；
		if(!strcmp(c, sheng)){
		tag3=-1	;
		}
		if(tag3==-1)
		strcpy(sheng, a);
		if(!strcmp(a, sheng)) {

		if(tag2 == 1){
			fprintf(tp,"%s\n",a);
			tag2 = -1;
		}
		if(tag == 1) {
		tag = -1;
		strcpy(temp,a);
	}
		if(strcmp(a, temp)){
			tag=1;
		fprintf(tp,"\n");
		fprintf(tp,"%s\n" ,a);

		}
		fprintf(tp,"%s %s\n",b,x);
    }

    }

    fclose(tp);
    return 0;
}
