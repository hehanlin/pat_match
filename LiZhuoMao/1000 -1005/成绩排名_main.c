#include <stdio.h>
#include <stdlib.h>

/*��Ŀ���� ���ɼ�����
  ʱ������ ��400ms
  �ڴ����� ��65536kb
  ���볤�� ��8000b
  ����	   ����׿ï
  ����     ��2018.1.14 
*/ 

/*��ĿҪ�� ��
 ����n��ѧ����������ѧ�š��ɼ����ֱ�����ɼ���ߺͳɼ�
 ���ѧ����������ѧ�š�
�����ʽ��ÿ�������������1��������������ʽΪ
  ��1�У�������n
  ��2�У���1��ѧ�������� ѧ�� �ɼ�
  ��3�У���2��ѧ������
  ... ... ...
  ��n+1�У���n��ѧ�������� ѧ�� �ɼ�
����������ѧ�ž�Ϊ������10���ַ����ַ������ɼ�Ϊ0��100֮���һ�����������ﱣ֤��һ�����������û������ѧ���ĳɼ�����ͬ�ġ�

�����ʽ����ÿ�������������2�У���1���ǳɼ����ѧ����������ѧ�ţ���2���ǳɼ����ѧ����������ѧ�ţ��ַ�������1�ո�
*/ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct student{
	char name[11];
	char number[11];
	int score;
}; //����ѧ���������ݵĽṹ�� 
int main(int argc, char *argv[]) 
{
	unsigned int num; //�����ѧ����
	printf("������Ҫ�����ѧ����");
	while (scanf("%ud", &num) != 1) //������� 
	{
		puts("������һ��������");
		while (getchar() != '\n')
			continue;
	} 
	struct student stu[num]; //����һ��ѧ������ 
	int i = 0, j = 0; //ѭ������  
	for (i = 0; i < num; i++)
	{
		while (scanf("%s %s %d", &stu[i].name, &stu[i].number, &stu[i].score) != 3 || stu[i].score > 100 || stu[i].score < 0)
			{
				fflush(stdin);
				puts("������ĸ�ʽ���󣡣� ���������롣");
				while (getchar() != '\n')
					continue;
			}
//      scanf("%s %s %d", &stu[i].name, &stu[i].number, &stu[i].score);

	}
	for (i = 0; i < num - 1; i++) //�Է����������� 
	{
		for (j = 0; j < num - 1 - i; j++) 
		{
			if (stu[j].score > stu[j + 1].score)
			{
				int temp = stu[j].score;
				stu[j].score = stu[j + 1].score;
				stu[j + 1].score = temp;
			}
		}
	}	
	printf("%s %s", stu[0].name ,stu[0].number);
	printf("\n%s %s", stu[num - 1].name, stu[num - 1].number);	
	return 0;
}
