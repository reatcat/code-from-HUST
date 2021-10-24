#include<stdio.h>
#include<string.h>
#define MAXSIZE 1000
int main()
{
	int len,d,i=0,e=0,j;
	char c;
	char data[600];
//	while((c=getchar())!=EOF){
//		data[i]=c;
//		i++;
//	}
	gets(data);
	len=strlen(data);
	for(i=0;i<len;i++)
	if(data[i]=='/'||data[i]=='.'||data[i]=='%')
		d=i;//表示特殊 遍历 
	for(i=d-1;i>=0;i--){
	if(e==0&&data[i]=='0') 
	continue;//当首元素为0 
	e+=1; 
	printf("%c",data[i]);
	}//直接用数组进行反转 
	if(e==0&&i==-1) 
	printf("0");
	e=0;
	printf("%c",data[d]);//前面没有数字就输出0 
	if(d!=len-1||d!=len){
	if(data[d]=='/'){
		for(i=len-1;i>d;i--){
			if(e==0&&data[i]=='0') 
			continue;
			break; 
		}
		for(j=i;j>d;j--)
		printf("%c",data[j]);
		return 0;
	}
	else{
	for(i=d+1;i<len;i++){
		if(e==0&&data[i]=='0')
		{
		data[i]=0;
		continue;
		}
		e+=1;
		}
	for(i=d+1;i<=len;i++){
		if(data[i]=='0') continue;
		if(i==len&&data[len-1]==0) 
		data[len-1]='0';
	}
	for(i=len-1;i>d;i--)
		printf("%c",data[i]);
		return 0;
	}

	}
	return 0;
}

