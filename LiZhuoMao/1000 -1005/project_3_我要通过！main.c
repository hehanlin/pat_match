#include <stdio.h>
#include <stdlib.h>
/*��Ŀ3    ����Ҫͨ����
  ʱ������ ��400ms
  �ڴ����� ��655356kb
  ���볤�� ��8000b
  ����	   ����׿ï  
  ����	   ��2018.1.6	
*/
/*
������ȷ�����Զ�����ϵͳ�����������˻�ϲ�Ļظ�����������PAT�ġ�����ȷ�������� ���� 
ֻҪ������ַ�����������������ϵͳ�����������ȷ��������������𰸴��󡱡�
�õ�������ȷ���������ǣ�
1. �ַ����б������P, A, T�������ַ��������԰��������ַ���
2. �������� xPATx ���ַ��������Ի�á�����ȷ�������� x �����ǿ��ַ�����
�����ǽ�����ĸ A ��ɵ��ַ�����
3. ��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ����� a, b, c �������ǿ��ַ�����
�����ǽ�����ĸ A ��ɵ��ַ�����
���ھ�����ΪPATдһ���Զ����г����ж���Щ�ַ����ǿ��Ի�á�����ȷ���ġ�

�����ʽ�� ÿ�������������1��������������1�и���һ����Ȼ��n (<10)������Ҫ�����ַ���������
������ÿ���ַ���ռһ�У��ַ������Ȳ�����100���Ҳ������ո�
�����ʽ��ÿ���ַ����ļ����ռһ�У�������ַ������Ի�á�����ȷ���������YES���������NO��
*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int num; //�����ַ����ĸ��� 
	printf("������Ҫ������ַ����ĸ���");
	while (scanf_s("%d", &num) != 1 || num > 10)
	{
		printf("������һС��10������");
		while (getchar() != '\n')
			continue;
	}
	char str[num + 1][101]; //�洢������ַ� 
	int judeg[num + 1]; //�洢�жϵĶԴ� 
	int i; //ѭ������
	for (i = 0; i <= num; i++)
	{
		int j = 0; //�������� 
		if (fgets(str[i], 100, stdin)) //ѭ�������ַ���	
		{
			while (str[i][j] != '\0' &&str[i][j] != '\n')
				j++;
			if (str[i][j] == '\n')
				str[i][j] = '\0';
		}
	} 
	for (i = 1; i <= num; i++) //ѭ��num�� 
	{
	int sum, sum_A_a = 0, sum_A_b = 0, sum_A_c = 0; //���������������ַ����� a�����A�ַ�������ʼ��Ϊ0��b�����A�ַ��ĸ����� c�����A�ַ��ĸ��� 		
		if (str[i][0] == 'P') //�жϵ�һ���ַ��Ƿ�Ϊ P �� ���Ϊ P�ж���һ���ַ��Ƿ�Ϊ A  �����Ϊ P�ж��Ƿ�Ϊ A ������¼ A�ĸ��� ��Ϊsum_A_a 
		{
			if (str[i][1] == 'A') //�жϵڶ����ַ��Ƿ�Ϊ A, ���Ϊ A��¼������ �� 1�� A�ж���һ���ַ��Ƿ�Ϊ T �������Ϊ 1��¼����  ��¼ A�ĸ��� ��Ϊ sum_A_b 
			{
				if (str[i][2] == 'T') //�жϵ������ַ��Ƿ�Ϊ T�� ���Ϊ T�ж���һ���ַ��Ƿ�Ϊ NULL �����Ϊ T����� A�ĸ���Ϊ 0����Ϊ 0��Ϊ�� Ϊ 0Ϊ�� 
				{
					if (str[i][3] == '\0') //���ĸ��ַ�Ϊ NULL����� ���ж�λ��Ϊ 1�� 
					{
						judeg[i] = 1; 
						continue;
					}
					else //���ĸ��ַ���Ϊ NULL����� ���ж�λ��Ϊ 0�� 
					{
						judeg[i] = 0;
						continue;
					}

				}
				else if (str[i][3] == 'A') //�������ַ���Ϊ A������� ��������� T֮ǰȫΪ A�������һ�׶Σ� ���������ַ��ж�λ�� 0�� 
				{
					sum = 3;
					while (str[i][sum] == 'A') //�����Ϊ A�������ֱ��������Ϊ A���ַ� 
					{
						++sum;
					}
					if (str[i][sum] == 'T') //���Ϊ T�ж���һλ�Ƿ�Ϊ NULL ��Ϊ NULL���ж�λ�� 1����Ϊ NULL���ж�λ�� 0�� 
					{
						if (str[i][sum + 1] == '\0') //Ϊ NULL����� 
						{
							judeg[i] = 1;
							continue;
						}
						else //��Ϊ NULL����� 
						{
							judeg[i] = 0;
							continue;	
						} 
					}
					else //��Ϊ T�� A����� 
					{
						judeg[i] = 0;
						continue;
					}
					
				}
				else //�������ַ�����Ϊ AҲ��Ϊ T����� 
				{
					judeg[i] = 0;
					continue;
				}
			} 
			else //�ڶ����ַ���Ϊ A����� 
			{
				judeg[i] = 0;
				continue;
			}
		}
		else if (str[i][0] == 'A') //��һ���ַ�Ϊ A����� ��¼ A�ĸ������ж���һ���ַ�Ϊ A���� P�� 
		{
			sum = 0;
			while (str[i][sum] == 'A') //��¼A�ĸ�������Ϊsum_A_a; 
			{
				++sum;
				++sum_A_a;
			}
			if (str[i][sum] == 'P') //�ж���һ���ַ��Ƿ�Ϊ P �� ���Ϊ P�ж���һ���ַ��Ƿ�Ϊ P  �����Ϊ P�ж��Ƿ�Ϊ A ������¼ A�ĸ��� ��Ϊsum_A_a 
			{
				if (str[i][sum + 1] == 'A') //�жϵڶ����ַ��Ƿ�Ϊ A, ���Ϊ A��¼������ �� 1�� A�ж���һ���ַ��Ƿ�Ϊ T �������Ϊ 1��¼����  ��¼ A�ĸ��� ��Ϊ sum_A_b 
				{
					++sum_A_b;
					if (str[i][sum + 2] == 'T') //�жϵ������ַ��Ƿ�Ϊ T��
					{
						if (str[i][sum + 3] == 'A') //�ж���һ���ַ��Ƿ�Ϊ A
						{
							++sum_A_c;
							while (str[i][sum + 4])
							{
								++sum;
								++sum_A_c;
							}
							if (sum_A_a == sum_A_c) //���a�����ַ���������b�����ַ������ 
							{
								judeg[i] = 1;
								continue;	
							} 
							else
							{
								judeg[i] = 0;
								continue;
							}
						}
						else 
						{
							judeg[i] = 0;	
							continue;
						} 

					}
					else if (str[i][sum + 2] == 'A') //�������ַ���Ϊ A�������  
					{
						++sum_A_b;
						while (str[i][sum + 3] == 'A') //�����Ϊ A�������ֱ��������Ϊ A���ַ� ����¼A�ĸ��� 
						{
							++sum_A_b;
							++sum;
						}
						if (str[i][sum + 3] == 'T') //���Ϊ T�ж���һλ�Ƿ�Ϊ NULL ��Ϊ NULL���ж�λ�� 1����Ϊ NULL���ж�λ�� 0�� 
						{
							if (str[i][sum + 4] == 'A')
							{
								++sum_A_c;
								while (str[i][sum + 5] == 'A')
								{
									++sum_A_c;
									++sum;
								}
								int sum_A_ab = sum_A_a + sum_A_b; 
								if (sum_A_c == sum_A_ab)
								{
									judeg[i] = 1;
									continue;
								}
								else
								{
									judeg[i] = 0;
									continue;
								}
							}
							else
							{
								judeg[i] = 0;
								continue;
							}
						}
						else //��Ϊ T�� A����� 
						{
							judeg[i] = 0;
							continue;
						}
						
					}
					else //�������ַ�����Ϊ AҲ��Ϊ T����� 
					{
						judeg[i] = 0;
						
						continue;
					}
				} 
				else //�ڶ����ַ���Ϊ A����� 
				{
					judeg[i] = 0;
					continue;
				}
			}
		}
	}
	for (i = 1; i <= num; i++)
	{
		if(judeg[i] == 1)
		{
			puts("yes");
		}
		else 
		{
			puts("no");
		}
	}
	
	
	
	return 0;
}
