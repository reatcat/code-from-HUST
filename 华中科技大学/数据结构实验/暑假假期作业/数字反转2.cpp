#include<stdio.h>
#include<string.h>
int main()
{
int len,d,i,e=0,j;
char data[600];
gets(size);
chang=d=strlen(size);
for(i=0;i<chang;i++)
	if(size[i]=='/'||size[i]=='.'||size[i]=='%')
		d=i;
for(i=d-1;i>=0;i--){
	if(e==0&&size[i]=='0') continue;
	e+=1; 
	printf("%c",size[i]);
}//������Ǽ򵥵İѷ���ǰ�ķ�ת 
	if(e==0&&i==-1) {printf("0");}
	e=0;
	printf("%c",size[d]);//	���ǰ��û�����־����0 
if(d!=chang-1||d!=chang){
//��Ϊ�����Ŀ��'/'�е�ӣ���ĸǰ�治����0 
	if(size[d]=='/'){
		for(i=chang-1;i>d;i--){
			if(e==0&&size[i]=='0') continue;
			break; 
		}
		for(j=i;j>d;j--)
		printf("%c",size[j]);
	return 0;
	}else{
	for(i=d+1;i<chang;i++){
		if(e==0&&size[i]=='0'){size[i]=' ';continue;}
		e+=1;
		}
	for(i=d+1;i<=chang;i++){
		if(size[i]=='0') continue;
		if(i==chang&&size[chang-1]==' ') size[chang-1]='0';
	}
    
//ʣ�µľ�������Ȼ�������ֻ�����������е�ȡ�ɣ���'0'������' 
	for(i=chang-1;i>d;i--)
		printf("%c",size[i]);
	return 0;}
}
}
