#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
��Ŀ2    ��д�������
ʱ������ ��400ms
�ڴ����� ��65536kb
���볤�� ��8000b
����     ����׿ï
ʱ��     ��2018.1.3 
*/ 
/*��ĿҪ�� �� 
����һ����Ȼ��n���������λ����֮�ͣ��ú���ƴ��д���͵�ÿһλ���֡� 
�����ʽ��ÿ�������������1��������������������Ȼ��n��ֵ�����ﱣ֤nС��10^100��
�����ʽ����һ�������n�ĸ�λ����֮�͵�ÿһλ��ƴ�����ּ���1 �ո񣬵�һ�������һ��ƴ�����ֺ�û�пո�
*/ 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Choice_input(int number); //ѡ��������Ӧ��ƴ����� 
struct stack //����һ������
{
	char data[101];
	int top; 	
};



int main(int argc, char *argv[]) 
{
	struct stack num; //�洢�����ֵ 
	num.top = 0; //��ʼ��ջ 
	int i; //ѭ������ 
	int len; //�洢�ַ����� 
	int all_bit_sum = 0; //�洢��λ�� 
	int sum_in_bit; //�洢�͵�����һλ 
	gets(num.data); //���� 
	len = strlen(num.data); //��������ĳ��� 
	while (num.top < len)
	{
		all_bit_sum = all_bit_sum + num.data[num.top] - 48;
		num.top++;
	}
	if (all_bit_sum >= 1000)
	{
		sum_in_bit = (all_bit_sum % 10000) /1000;
		Choice_input(sum_in_bit);
		printf(" "); 
	}
	if (all_bit_sum >= 100) //�жϺ��Ƿ����100 
	{
		sum_in_bit = (all_bit_sum % 1000) / 100;
		Choice_input(sum_in_bit);
		printf(" ");
	}
	if (all_bit_sum >=10)
	{
		sum_in_bit = (all_bit_sum % 100) / 10;
		Choice_input(sum_in_bit);
		printf(" ");
	}	
	if (all_bit_sum >= 0)
	{
		sum_in_bit = (all_bit_sum % 10) / 1;
		Choice_input(sum_in_bit);
	
	}
	
	
	/*

	unsigned int number[100]; //�洢һ��С��10^100����Ȼ��
	
	
	int total_sum; //�洢��λ֮�� 
	printf("%d", sizeof(number));
	
	int sum; //�洢������� 
	printf("������һ��С��10100����Ȼ������");
	while (scanf("%u", &number[100]) != 1) //����������ж� 
	{
		printf("������С��10100����Ȼ��");
		while (getchar() != '\n')
			continue;
	}
	
	total_sum = number / 10000 + (number % 10000) / 1000 + (number % 1000) / 100 + (number % 100) / 10 + (number % 10) / 1; //�����λ֮�� 
	if (total_sum >= 100) //�жϺ��Ƿ����100 
	{
		sum = total_sum / 100;
		Choice_input(sum);
		printf(" ");
	}
	if (total_sum >=10)
	{
		sum = (total_sum % 100) / 10;
		Choice_input(sum);
		printf(" ");
	}	
	if (total_sum >= 0)
	{
		sum = (total_sum % 10) / 1;
		Choice_input(sum);		
	}
*/	
	return 0;
}


void Choice_input(int number) //ѡ��������Ӧ��ƴ����� 
{
	switch (number)
	{
		case 1:
			printf("yi");
			break;
		case 2:
			printf("er");
			break;
		case 3:
			printf("san");
			break;
		case 4:
			printf("si");
			break;
		case 5:
			printf("wu");
			break;
		case 6:
			printf("liu");
			break;
		case 7:
			printf("qi");
			break;
		case 8:
			printf("ba");
			break;
		case 9:
			printf("jiu");
			break;
		case 10:
			printf("shi");
			break;
	}
	return;
}




