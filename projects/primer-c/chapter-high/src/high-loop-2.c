#include <stdio.h>
int main(void)
{	
	int a,b,c,x,y,temp;
	printf("请输入两个数\n");
	printf("数字1:");
	scanf("%d",&a);
	printf("数字2:");
	scanf("%d",&b);
	x = a;
	y = b;
	if(a < b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	while(b != 0)
	{
		temp=a;
		a=b;
		b=temp%b;
	}
	c = x*y/a;
	printf("它们的最小公倍数为%d\n",c);
	printf("它们的最大公约数为%d\n",a);
	return 0;
}