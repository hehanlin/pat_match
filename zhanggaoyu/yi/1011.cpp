#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	long **a;
	int n=0;
	// printf("������n\n");
	scanf("%d",&n);
	a=(long**)malloc(n*sizeof(long*));
	for (int i = 0; i < n; ++i){
		a[i]=(long*)malloc(3*sizeof(long));
	}
	for (int i = 0; i < n; ++i){
		scanf("%ld%ld%ld",&a[i][0],&a[i][1],&a[i][2]);
	}
	for (int i = 0; i < n; ++i){
		printf("Case #%d: ", i+1);
		if (a[i][0] > a[i][2] - a[i][1]){				//��Ϊ  +  �������ֵ����Ŀ��ܣ����Բ�����    -    ��
			printf("true\n");
		}else{
			printf("false\n");
		}
	}

	// system("pause");
	return 0;
}