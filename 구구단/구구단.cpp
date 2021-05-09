#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


/*int main()
{
    int i, j;
    for (i = 1; i < 10; i++) {
        for (j = 1; j < 10; j++) {
            printf("%d*%d=%d \n", i, j, i * j);
        }
    }

    int garo, sero;
    for (garo = 0; garo < 5; garo++) {
        for (sero = 0; sero <= garo; sero++) {
            printf("*");
        }
        printf("\n");
    }
    
    for (int a = 0; a < 5; a++) {
        for (int b = a; b < 4; b++) {
            printf(" ");
        }
        for (int c = 0; c <=a; c++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int floor;
    printf("몇층?");
    scanf_s("%d", &floor);
    for (int i = 0; i < floor; i++) {
        for (int j = i; j < floor -1; j++ ) {
            printf(" ");
        }
        for (int k = 0; k < i*2+1; k++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

int main(void) {
    srand(time(NULL));
    int i = rand() % 3; 
    printf("가위바위보! \n\n");
    switch (i) {
    case 0: printf("가위"); break;
    case 1: printf("바위"); break;
    case 2: printf("보"); break;
    defalut:printf("??"); break;
    }
    return 0;
}*/
/*int main(void) {
    srand(time(NULL));
    int num = rand() % 100+1;
    printf("숫자 : %d\n", num);
    int answer = 0; //정답
    int chance = 5; //기회
    while (chance > 0) {
        printf("남은기회 %d번", chance--);
        printf("무엇일까요(1-100)?");
        scanf_s("%d", &answer);
        if (answer < num) {
            printf("UP! 정답이 아닙니다.");
        }
        else if (answer == num) {
            printf("정답입니다.");
            break;
        }
        else if (answer > num) {
            printf("DOWN! 정답이 아닙니다.");
        }
        else {
            printf("범위 안의 숫자를 입력해주세요..");
        }
    }Sleep(2000);


int getRandomnumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();


int main(void) {
    srand(time(NULL));
    int count = 0;
    for (int i = 1; i < 9999; i++) {
        int num1 = getRandomnumber(i);
        int num2 = getRandomnumber(i);
        //printf("%d*%d의 값은 얼마입니까? : ", num1, num2);
        showQuestion(i, num1, num2);
        
        int answer = -1;
        scanf_s("%d", &answer);
        if (answer == -1)
        {
            printf("종료합니다\n");
            exit(0);
        }
        else if (answer == num1 * num2) {
            success();
            count++;
        }
        else {
            fail();
        }
    }
    printf("당신은 %d개의 문제를 맞추었습니다.", count);
}

int getRandomnumber(int level)
{
    return rand() & (level * 7) + 1;
}

void showQuestion(int level, int num1, int num2)
{
    printf("\n\n\n\n########%d번째 비밀번호#########\n", level);
    printf("\n\t%d*%d는? \n\n", num1, num2);
    printf("###############################");
    printf("\n비밀번호를 입력하세요(종료:-1) : ");
}

void success() {
    printf("\n--->  GOOD정답입니다!");
}

void fail() {
    printf("\n--->    NOPE오답입니다!");
}
}

int main(void) {
    srand((unsigned int)time(NULL));
    printf("\n\n=============머머리 발모제 게임=============\n\n"); //제목
    int answer;     //입력값
    int treatment = rand() % 4; //발모제 선택값
    int cntB = 0; //이번에 보여줄 병개수
    int prevB = 0; //다음에 보여줄 병개수
    while (1) {
        for (int i = 1; i <= 3; i++)
        {
            int bottle[4] = { 0,0,0,0 }; // 병의 갯수를 배열로 4개 지정
            do
            {
                cntB = rand() % 2 + 2; //0~1의 값이 나오는 것을 수정해서 2~3개의 값이 나오도록 조정
            } while (cntB == prevB);

            prevB = cntB;
            int isincluded = 0; // 보여주는 병 안에 발모제가 포함되었는지 확인
            printf(" > %d번째 시도 : ", i);

            //보여줄 병 종류를 선택
            for (int j = 0; j < cntB; j++)
            {
                int randBottle = rand() % 4; //0~3
                if (0 == bottle[randBottle])
                {
                    bottle[randBottle] = 1;
                    if (randBottle == treatment)
                    {
                        isincluded = 1;     //발모제를 골랐을때
                    }
                }
                else
                {
                    j--;
                }
            }
            for (int k = 0; k < 4; k++)
            {
                if (bottle[k] == 1)
                    printf(" %d ", k + 1);      // 몇번째 도전인지 기록
            }
            printf(" 물약을 머머리에 바릅니다.\n\n");

            if (isincluded == 1)
            {
                printf("    >>성공! 머리가 났어요!! \n\n");
            }
            else
            {
                printf("    >>실패! 머리가 사라졌어요!! \n\n");
            }
            printf("계속 하려면 ENTER키를 누르세요\n\n");
            getchar();
        }

        printf("\n\n발모제는 몇 번 일까요? : ");
        scanf_s("%d", &answer);

        if (answer == treatment + 1)
        {
            printf("\n  >>>>정답!\n");
        }
        else
        {
            printf("\n>>>>실패! 정답은 %d입니다.\n", treatment + 1);
        }
    }
    return 0;
}*/

/*int main(void) {
    int num;
    int i, j, k;
    printf("입력 : ");
    scanf_s("%d", &num);
    for (i=1; i <= num; i++) {
        for (j = i-1; j < num - 1; j++) {
            printf(" ");
        }
        for (k = 2; k < i*2+1; k++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;    
}*/

int main(void) {

}

