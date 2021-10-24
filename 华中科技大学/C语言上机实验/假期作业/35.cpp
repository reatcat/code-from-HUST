#include <stdio.h>
void BubbleSort(int nums[], int n)
{
	int i,j,temp;
	for (i= 0;i<n;i++)
	{
		for (j=0;j<n-i-1;j++)
		{
			if (nums[j]>nums[j + 1])
			{
				temp=nums[j];
				nums[j]=nums[j+1];
				nums[j+1]=temp;
			}
		}
	}
}
int main()
{
	int nums[3];
	char str[4];
	scanf("%d%d%d",&nums[0],&nums[1],&nums[2]);
	BubbleSort(nums, 3);
	scanf("%s", str);
	int i;
	for (i=0;str[i]!= 0;i++)
	{
		switch(str[i]-'A')
		{
		case 0:
			printf("%d ", nums[0]);
			break;
		case 1:
			printf("%d ", nums[1]);
			break;
		case 2:
			printf("%d ", nums[2]);
			break;
		}
	}
	printf("\n");

	return 0;
}
