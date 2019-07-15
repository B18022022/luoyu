#include <stdio.h>
int main(void){
	int n,i,sum = 0;
	int a[100] = {0};
	printf("请输入n个整数！");
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		printf("请输入第%d个整数：",i+1);
		scanf("%d",&a[i]);
		sum += a[i];
	}
	printf("和为%d\n",sum);
	return 0;
}