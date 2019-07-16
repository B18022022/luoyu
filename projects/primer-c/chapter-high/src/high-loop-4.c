#include<stdio.h>
#include<math.h>
int main(){
	int a;
	printf("请输入一个数字:");
	scanf("%d",&a);
	printf("2的%d次方为:%0.f\n",a,pow(2,a));
}