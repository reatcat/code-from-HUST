#include <stdio.h>
#include <string.h>
#include <stdlib.h>   //�ṩ exit() ����֧��  
#define SIZE 100000
//#include"conio.h"

//��������ԭ��
void finput();    //��������
void flist();     //�������
void fsearch();   //��������
void ftaxis();    //��������

//����ṹ�� 
struct student 
{
	int num;        //���
	char name[10];  //���������������
	int C;          //C ���Գɼ�
	int Maths;      //��ѧ�γɼ�
	int En;         //Ӣ��γɼ�
	float ave;      //���ſ�ƽ���ɼ�
} stu[SIZE];        //�ڶ���ṹ��ʱͬʱ�����ṹ�����

int main() 
{
	int n;
	
		printf("  Please choose your function:(1-7):");          //����ѡ�� 
		scanf("%d",&n);
		printf("\n");
		if(n>0&&n<8) {
			switch(n) {
				case 1:
					finput();
					break;
				case 2:
					flist();
					break;
				case 3:
					fsearch();
					break;
				case 6:
					ftaxis();
					break;
	
		
		}
	}
	return 0;
}
/*
���������ֽ��� 
*/ 


/*
������ģ�黯���
ÿ�����ܶ�Ӧһ������ 
*/ 

//part 1 : ������Ϣ¼�� 
void finput() 
{
	FILE *fp;            //����ָ����� 
	int i,p;
	fp=fopen("grades","wb");          //�״δ��ļ��� ��û���ļ������Զ��������ļ� 
	for(i=0; i<SIZE; i+1) 
	{
		printf("1 to continue and 0 to end input: ");        //ѯ���Ƿ�������� 
		scanf("%d",&i);
		if(i==0) 
		{
			fclose(fp);
			return;
		} 
		else {
			printf("Please inut your school number, C grade, Math grade, English grade:\n");
			scanf("%d%s%d%d%d",&stu[i].num,stu[i].name,&stu[i].C,&stu[i].Maths,&stu[i].En);
			stu[i].ave=(stu[i].C+stu[i].Maths+stu[i].En)/3.0;
			fwrite(&stu[i],sizeof(struct student),1,fp);
		}
	}
	fclose(fp);         //�ǵùر��ļ�������һ����ϰ�ߣ� 
}


//part 2: �������� 
void flist() 
{
	FILE *fp;
	int i;
	fp=fopen("grades","rb");
	printf("____________________________________________________________________________________________________\n"); 
	printf("|                                                  Report                                           |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|        ID      |    name   |    C grade    |    Math grade   |   English grade   |    Average     |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	for(i=0; fread(&stu[i],sizeof(struct student),1,fp)==1; i++) 
		printf("|%11d%15s%13d%17d%18d%19.2f\n",stu[i].num,stu[i].name,stu[i].C,stu[i].Maths,stu[i].En,stu[i].ave);
		/*
		�˴������ֿ�����ȼӿո���ã� ��Ϊ����ʹ�ÿո����룬��ѧ�Ż�������ǰ������ĳ��Ȳ�һ��ʱ����ʽ���ҵ��������޷������ʽ 
		*/ 
	printf("|___________________________________________________________________________________________________|\n\n");
	fclose(fp);
}

//part 3���������� 
void fsearch() 
{
	FILE *fp;
	int i,num
	fp=fopen("grades","rb");
	rewind(fp);
	printf("Which one are you searching? Input the School number: ");
	scanf("%d",&num);
	
	for(i=0; i<=SIZE; i++)
	{
		if(stu[i].num==num) 
		{
			printf("____________________________________________________________________________________________________\n");//�����Ĳ�����ͬ�������ʽ�����Ե�ͳһ���� 
			printf(" Here are the rusults                                                                               \n");
			printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
			printf("|        ID      |    name   |    C grade    |    Math grade   |   English grade   |    Average     \n");
			printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
			printf("|%11d%15s%13d%17d%18d%19.2f\n",stu[i].num,stu[i].name,stu[i].C,stu[i].Maths,stu[i].En,stu[i].ave);
			printf("|__________________________________________________________________________________________________|\n\n");
			flag+=1;
		}
	}
	if(flag==0)
	{
		printf("\n    ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("           error input!       \n");
		printf("    ~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	}
//	printf("___________________________________________________________________________________________________________\n\n");
	fclose(fp);
}

/
//part 6����ƽ���ɼ��������� 
void ftaxis() 
{
	int i,j,n;
	FILE *fp;
	struct student t;
	fp=fopen("grades","rb");
	printf("____________________________________________________________________________________________________ \n");
	printf("|                                                  Report                                           |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|        ID      |    name   |    C grade    |    Math grade   |   English grade   |    Average     |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	for(i=0; fread(&stu[i],sizeof(struct student),1,fp)==1; i++)
		printf("|%11d%15s%13d%17d%18d%19.2f\n",stu[i].num,stu[i].name,stu[i].C,stu[i].Maths,stu[i].En,stu[i].ave);
	printf("|___________________________________________________________________________________________________|\n\n");
	fclose(fp);
	n=i;
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
			if(stu[i].ave<stu[j].ave) {
				t=stu[i];
				stu[i]=stu[j];
				stu[j]=t;
			}
	fp=fopen("grades","wb");
	printf("\n\n\n");
	printf("_____________________________________________________________________________________________________\n");
	printf("|                                                  Report                                           |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("|        ID      |    name   |    C grade    |    Math grade   |   English grade   |    Average     |\n");
	printf("|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	for(i=0; i<n; i++) {
		fwrite(&stu[i],sizeof(struct student),1,fp);
		printf("|%11d%15s%13d%17d%18d%19.2f\n",stu[i].num,stu[i].name,stu[i].C,stu[i].Maths,stu[i].En,stu[i].ave);
	}
	printf("|___________________________________________________________________________________________________|\n");
	fclose(fp);
}



