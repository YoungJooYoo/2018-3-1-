/* 학번 및 이름 : 2016101453 컴퓨터학부 유영주							   		     */
/* 목적 및 개요:  과제1<배열수행>												     */
/* 과제수행날짜: 2018.03.01(목)												         */
/* 개선사항 및 변경내역:													         */
/* 이슈: Visual Studio 2017이 보안상 bufferoverflow 위험성으로 인한 함수사용을 제한, */
/*	    따라서 #pragma warning(disable: 4996) 사용하여 컴파일 에러 무시적용		     */
/* 프로그램 작성환경 및 실행환경: OS: Window's 10   IDE: Visual Studio 2017          */
/* 사용언어: C언어															         */

#include <stdio.h>
#pragma warning(disable: 4996)

int function_input(int []); /* 정수형 숫자 5개를 배열을 이용해 입력받는 함수*/
int function_print(); /* */


void main()
{
	int array[] = { 0,0,0,0,0 };
	function_input(array);
}



/* scanf를 이용한 숫자 5래를 입력받는 함수 */
int function_input(int array[5])
{
	//array[5] = {0,0,0,0,0};
	int i = 0;

	printf("숫자 5개를 입력해주세요.\n\n");


	for (i = 0; i < 5; i = i + 1)
	{
		printf("%d번째 숫자를 입력해주세요.\n", i+1);
		scanf("%d", &array[i]);
	}
	return 0;
}


int function_print();
{

}

