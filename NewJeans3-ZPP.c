#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "winmm.lib")

#define RED (FOREGROUND_RED | FOREGROUND_INTENSITY)
#define GREEN (FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define BLUE (FOREGROUND_BLUE | FOREGROUND_INTENSITY)

#define PINK (RED | BLUE)
#define WHITE (RED | GREEN | BLUE)
#define YELLOW (RED | GREEN)
#define SKYBLUE (GREEN | BLUE)

#include <stdio.h>
#include <Windows.h>
#include <MMSystem.h>

int add(int, int);
int sub(int, int);
int mul(int, int);
double divide(int, int);
void discount();

void main() {

	int add_result, sub_result, mul_result;
	double div_result;

	int a;
	int b;
	int option;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hStdOut, YELLOW);
	printf("a 값 입력 : \n");
	PlaySound(TEXT("a 값 입력하세요.wav"), NULL, SND_FILENAME | SND_ASYNC );
	SetConsoleTextAttribute(hStdOut, PINK);
	scanf("%d", &a);
	SetConsoleTextAttribute(hStdOut, YELLOW);
	printf("b 값 입력 : \n");
	PlaySound(TEXT("b 값 입력하세요.wav"), NULL, SND_FILENAME | SND_ASYNC );
	SetConsoleTextAttribute(hStdOut, PINK);
	scanf("%d", &b);
                 SetConsoleTextAttribute(hStdOut, YELLOW);
	printf("특별한 메뉴 : \n");
	PlaySound(TEXT(" 특별한 메뉴입력하세요.wav"), NULL, SND_FILENAME | SND_ASYNC );
	SetConsoleTextAttribute(hStdOut, PINK);
	scanf("%d", &특별한 메뉴);

	do {
		SetConsoleTextAttribute(hStdOut, SKYBLUE);
		puts("원하는 메뉴를 선택하세요. : ");
		PlaySound(TEXT("원하는 메뉴를 선택하세요.wav"), NULL, SND_FILENAME | SND_ASYNC );
		puts("=========================================");
		puts("덧  샘 : 1 ");
		puts("뺄  샘 : 2 ");
		puts("곱  샘 : 3 ");
		puts("나눗샘 : 4 ");
		puts("할인값 출력 : 5 ");
                                   puts("특별한 메뉴 : 6 ");
		puts("=========================================");
		//SetConsoleTextAttribute(hStdOut, WHITE);
		//printf("선택 (메뉴번호를 입력하세요.) : ");
		//PlaySound(TEXT("메뉴번호를 입력하세요.wav"), NULL, SND_FILENAME | SND_ASYNC );
		do {
			scanf("%d", &option);
			if  (  ( option < 1) || (option >6) ) {
				SetConsoleTextAttribute(hStdOut, PINK);
				PlaySound(TEXT("1 부터 6 까지의 숫자를 입력하세요.wav"), NULL, SND_FILENAME | SND_ASYNC );
				printf("1~6 까지의 숫자를 입력하세요.\n\n");
				//SetConsoleTextAttribute(hStdOut, GREEN);
				//PlaySound(TEXT("메뉴번호를 입력하세요.wav"), NULL, SND_FILENAME | SND_ASYNC );
				//printf("선택 (메뉴번호를 입력하세요.) : ");
			}
		}while( (option < 1) || (option > 6) );

		switch(option) {
		case 1 :
				add_result = add(a, b);
				SetConsoleTextAttribute(hStdOut, YELLOW);
				PlaySound(TEXT("덧샘의 결과는 다음과 같습니다.wav"), NULL, SND_FILENAME | SND_ASYNC );
				printf("\n덧샘의 결과 : %d \n\n", add_result);
				break;
		case 2 :
				sub_result = sub(a, b);
				SetConsoleTextAttribute(hStdOut, YELLOW);
				PlaySound(TEXT("뺄샘의 결과는 다음과 같습니다.wav"), NULL, SND_FILENAME | SND_ASYNC );
				printf("\n뺄샘의 결과 : %d \n\n", sub_result);
				break;
		case 3 :
			    mul_result = mul(a, b);
				SetConsoleTextAttribute(hStdOut, YELLOW);
				PlaySound(TEXT("곱샘의 결과는 다음과 같습니다.wav"), NULL, SND_FILENAME | SND_ASYNC );
			    printf("\n곱샘의 결과 : %d \n\n", mul_result);
				break;
		case 4 :
				div_result = divide(a, b);
				SetConsoleTextAttribute(hStdOut, YELLOW);
				PlaySound(TEXT("나눗샘의 결과는 다음과 같습니다.wav"), NULL, SND_FILENAME | SND_ASYNC );
			    printf("\n나눗샘의 결과 : %f \n\n", div_result);
				break;
		case 5 :
				discount();
				break;
                                   case 6 :
				Special Menu();
				break;

		default :
			    puts("");
				SetConsoleTextAttribute(hStdOut, YELLOW);
				puts("1~4 까지의 숫자를 골라주세요. 제발 정신챙기세요.\n\n");
				puts("");
				break;
		}
	}while( ! (  (option <= 1) && (option >= 4))  );
 
}

int add(int x, int y) {
	int temp;
	temp = x + y;
	return temp;
}

int sub(int x, int y) {
	int temp;
	temp = x - y;
	return temp;
}

int mul(int x, int y) {
	int temp;
	temp = x * y;
	return temp;
}

double divide(int x, int y) {
	double temp;
	temp =  (double)( (double)x / (double)y ) ;
	return temp;
}

void discount() {

   double dc_price ;
   int price;
   int rate;

   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

   SetConsoleTextAttribute(hStdOut, SKYBLUE);
   printf("\n원가 입력 : ");
   scanf("%d", &price);

   SetConsoleTextAttribute(hStdOut, SKYBLUE);
   printf("\n할인율 입력 : ");
   scanf("%f", &rate);

   SetConsoleTextAttribute(hStdOut, SKYBLUE);
   printf("\n :특별한 메뉴 입력  ");
   scanf("%f", &rate);

   dc_price = (double)price - ( (double)price * (double)rate * 0.01 ) ;
   
   PlaySound(TEXT("계산하실 금액은 다음과 같습니다.wav"), NULL, SND_FILENAME | SND_ASYNC );
   printf("\n계산할 금액 : %.1f \n\n", dc_price);
}


