#include <stdio.h>
#include <string.h>
#include <stdlib.h>   //提供 exit() 函数支持  
#define SIZE 100000
//#include"conio.h"

//声明函数原型
void finput();    //存入数据
void flist();     //输出数据
void fsearch();   //查找数据
void ftaxis();    //数据排序

//定义结构体 
struct student 
{
	int num;        //存放
	char name[10];  //定义名字数组变量
	int C;          //C 语言成绩
	int Maths;      //数学课成绩
	int En;         //英语课成绩
	float ave;      //三门课平均成绩
} stu[SIZE];        //在定义结构体时同时声明结构体变量

int main() 
{
	int n;
	
		printf("  Please choose your function:(1-7):");          //功能选择 
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
主函数部分结束 
*/ 


/*
下面是模块化设计
每个功能对应一个函数 
*/ 

//part 1 : 进行信息录入 
void finput() 
{
	FILE *fp;            //声明指针变量 
	int i,p;
	fp=fopen("grades","wb");          //首次打开文件， 若没有文件将会自动创建新文件 
	for(i=0; i<SIZE; i+1) 
	{
		printf("1 to continue and 0 to end input: ");        //询问是否继续输入 
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
	fclose(fp);         //记得关闭文件，这是一个好习惯！ 
}


//part 2: 将结果输出 
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
		此处采用字宽输入比加空格更好， 因为若是使用空格输入，当学号或者名字前后输入的长度不一致时，格式会乱掉，导致无法对其格式 
		*/ 
	printf("|___________________________________________________________________________________________________|\n\n");
	fclose(fp);
}

//part 3：查找数据 
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
			printf("____________________________________________________________________________________________________\n");//与上文采用相同的输出格式，会显得统一整洁 
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
//part 6：按平均成绩进行排序 
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



