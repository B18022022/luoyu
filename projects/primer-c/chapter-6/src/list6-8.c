#include <stdio.h>
int min_of(const int v[],int n)
{
    int min, i;
    min = v[0];
    for (i = 0; i < n; i++) {
        if (min > v[i])
            min = v[i];
    }
    printf("您输入的数组中最小值为%d\n", min);
    return 0;

}
int main() {
    int i,n;
    int v[100];
    printf("请输入数组的个数:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	printf("第%d个数字:",i+1);
    	scanf("%d",&v[i]);
    }
    min_of(v,n);
    return 0;
}
