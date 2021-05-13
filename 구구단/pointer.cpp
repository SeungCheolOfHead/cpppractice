#include<stdio.h>
#include<time.h>
#include <stdlib.h>
//물고기 6마리 어항, 사막이라서 물이 증발을 한다! 물이 줄어들기 전에 열심히 눌러서 살려라!

int level;
int* cursor;
int arrayFish[6];
int checkFishAlive();
void initData();
void printfFishes();
void decreaseWater(long elapsedTime);

int main(void) 
{
	long startTime = 0;	//게임시작시간
	long totalTime = 0;	//총 경과시간
	long prevTime = 0;	//최근에 물을 준 시간 간격
	int num;	// 몇번 어항에 물을 줄 것인지
	initData();

	cursor = arrayFish;

	startTime = clock();

	while (1) 
	{
		printfFishes();
		printf("몇 번 어항에 물을 주나요? : ");
		scanf_s("%d", &num);
		if (num < 1 || num>6) 
		{
			printf("입력값이 잘못되었습니다.\n");
			continue;
		}
		totalTime = (clock() - startTime) / CLOCKS_PER_SEC;
		printf("총경과 시간은 : %ld 초\n", totalTime);

		//직전에 물을 준 시간 체크
		prevTime = totalTime - prevTime;
		printf("최근 경과 시간 : %ld 초\n", prevTime);

		//어항의 물을 감소시킴
		decreaseWater(prevTime);

		//사용자가 입력한 어항에 물을 줌
		//1.어항의 물이 0이면?	 물을 주지 않는다.
		if (cursor[num - 1] <= 0) 
		{
			printf("%d번 물고기는 이미... 운명했습니다. 물을 주지 마세요...\n", num);
		}
		//2.어항의 물이 0이 아니면! 물을 준다 100을 넘지 않게 체크해준다
		else if (cursor[num - 1] + 1 <= 100) 
		{
			printf("%d번 어항에 물을 줍니다.\n\n", num);
			cursor[num - 1] += 1;
		}
		//level up을 할 것인지
		if (totalTime / 20 > level - 1) 
		{
			level++;
			printf("기존 %d레벨에서 %d레벨로 업그레이드!\n", level - 1, level);
			if (5 == level)
			{
				printf("최고레벨 달성! 게임 종료");
				exit(0);
			}			
		}

		//물고기가 다 죽었는지 확인
		if (0==checkFishAlive()) 
		{
			printf("다주겄습니다...\n");
			exit(0);
		}
		else
		{
			printf("아직 살아있습니다.\n");
		}
		prevTime = totalTime;
	}

	return 0;
}
void initData() 
{
	level = 1;	//게임레벨
	for (int i = 0; i < 6; i++) 
	{
		arrayFish[i] = 100;	//물의 높이
	}
}

void printfFishes() 
{
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
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
		arrayFish[i] -= (level*3*(int) elapsedTime);	//3이 난이도 조절값
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