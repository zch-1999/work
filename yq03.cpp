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
	printf("�����ļ���:");
	scanf("%s",infname);
	printf("����ļ���:");
	scanf("%s",outfname);
	printf("��ѯʡ��(ȫ����������all):");
	scanf("%s",sheng);


	tp=fopen(outfname,"w");
    if ((fp = fopen(infname, "r")) == NULL){
        printf("���ļ�ʧ�� %d: %s\n", errno, strerror(errno));
        exit(-1);//�Ҳ����ļ� ��
    }

    while(fgets(str, sizeof(str), fp)){
        str[strlen(str)-1] = '\0';//����һ���� ��
    	char a[20],b[20],x[20];//a[]Ϊʡ��b[]Ϊ�У�x[]Ϊ������
		sscanf(str, "%s %s %s",a,b,x); //��һ�зֳ�����Ԫ�أ�
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
