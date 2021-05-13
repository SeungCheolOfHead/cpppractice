#include<stdio.h>
#include<time.h>
#include <stdlib.h>
//����� 6���� ����, �縷�̶� ���� ������ �Ѵ�! ���� �پ��� ���� ������ ������ �����!

int level;
int* cursor;
int arrayFish[6];
int checkFishAlive();
void initData();
void printfFishes();
void decreaseWater(long elapsedTime);

int main(void) 
{
	long startTime = 0;	//���ӽ��۽ð�
	long totalTime = 0;	//�� ����ð�
	long prevTime = 0;	//�ֱٿ� ���� �� �ð� ����
	int num;	// ��� ���׿� ���� �� ������
	initData();

	cursor = arrayFish;

	startTime = clock();

	while (1) 
	{
		printfFishes();
		printf("�� �� ���׿� ���� �ֳ���? : ");
		scanf_s("%d", &num);
		if (num < 1 || num>6) 
		{
			printf("�Է°��� �߸��Ǿ����ϴ�.\n");
			continue;
		}
		totalTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("�Ѱ�� �ð��� : %ld ��\n", totalTime);

		//������ ���� �� �ð� üũ
		prevTime = totalTime - prevTime;
		printf("�ֱ� ��� �ð� : %ld ��\n", prevTime);

		//������ ���� ���ҽ�Ŵ
		decreaseWater(prevTime);

		//����ڰ� �Է��� ���׿� ���� ��
		//1.������ ���� 0�̸�?	 ���� ���� �ʴ´�.
		if (cursor[num - 1] <= 0) 
		{
			printf("%d�� ������ �̹�... ����߽��ϴ�. ���� ���� ������...\n", num);
		}
		//2.������ ���� 0�� �ƴϸ�! ���� �ش� 100�� ���� �ʰ� üũ���ش�
		else if (cursor[num - 1] + 1 <= 100) 
		{
			printf("%d�� ���׿� ���� �ݴϴ�.\n\n", num);
			cursor[num - 1] += 1;
		}
		//level up�� �� ������
		if (totalTime / 20 > level - 1) 
		{
			level++;
			printf("���� %d�������� %d������ ���׷��̵�!\n", level - 1, level);
			if (5 == level)
			{
				printf("�ְ��� �޼�! ���� ����");
				exit(0);
			}			
		}

		//����Ⱑ �� �׾����� Ȯ��
		if (0==checkFishAlive()) 
		{
			printf("���ְν��ϴ�...\n");
			exit(0);
		}
		else
		{
			printf("���� ����ֽ��ϴ�.\n");
		}
		prevTime = totalTime;
	}

	return 0;
}
void initData() 
{
	level = 1;	//���ӷ���
	for (int i = 0; i < 6; i++) 
	{
		arrayFish[i] = 100;	//���� ����
	}
}

void printfFishes() 
{
	printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++) 
	{
		printf(" %4d ", arrayFish[i]);
	}
	printf("\n\n");
}

void decreaseWater(long elapsedTime) 
{
	for (int i = 0; i < 6; i++) 
	{
		arrayFish[i] -= (level*3*(int) elapsedTime);	//3�� ���̵� ������
		if (arrayFish < 0) 
		{
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive() 
{
	for (int i = 0; i < 6; i++) 
	{
		if (arrayFish[i] > 0) 
		{
			return 1;
		}
	}
	return 0;
}