#include<stdio.h>
#include<string.h>
void RemoveDuplicate(char* s);
int main()
{
	char str[200];
	printf("Input strings,end of Ctrl+Z\n");
	while (fgets(str, 200, stdin) != NULL)
	{
		RemoveDuplicate(str);
		printf("%s", str);
	}
	return 0;
}
void RemoveDuplicate(char* s)
{
	int r, w, i, len;
	len = strlen(s);
/*	for (r = w = 0;r < len;r++)
	{
		if (s[r] != '\0')
		{
			s[w++] = s[r];
			for (i = r + 1;i < len;i++)
				if (s[i] == s[r])
					s[i] = '\0';
		}
	}
	s[w] = '\0';*/
	char temp[256] = {1};
	for (r =w= 0;r < len;r++)
	{
		temp[s[r]-1]++;
		if (temp[s[r]-1] <2)//ÓÐÎÊÌâ£¡£¡
			s[w++] = s[r];
	}
	
	s[w] = '\0';
}