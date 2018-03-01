#include <stdio.h>


/* 학번 및 이름 : 2016101453 컴퓨터학부 유영주								   */
/* 목적 및 개요:  2018.02.28(수) 자료구조 수업 배열 예제코드 실행			   */
/* 과제수행날짜: 2018.03.01(목)												   */
/* 개선사항 및 변경내역:													   */
/* 이슈: system("pause"); 에러로 인한 주석처리								   */
/* 프로그램 작성환경 및 실행환경: OS: Window's 10   IDE: Visual Studio 2017    */
/* 사용언어: C언어															   */



int total_hap(int a[], int n)
{
	int i = 0, hap = 0;
	printf("hap의 주소= %d, 데이터= %x \n", &hap, hap);
	printf("  i 의 주소= %d, 데이터= %x \n", &i, i);

	for (i = 0; i < n; ++i)
		hap = hap + a[i];
	return(hap);
}

void main()
{
	int sum = 0;
	int i = 0;
	int a[10] = { 22, 35, 45, 91, 18, 31, 44, 51, 83, 28 };

	printf("sum의 주소= %d, 데이터= %x \n", &sum, sum);
	printf("  i 의 주소= %d, 데이터= %x \n", &i, i);

	for (i = 0; i < 10; i++)
		printf("a[%d]의 주소= %d, 데이터= %d \n", i, &a[i], a[i]);

	/* a는 배열의 첫 번째 요소의 주소를 갖는 포인터 상수 */
	printf("\n\n");
	sum = total_hap(a, 10);
	printf("\n\n");
	printf("sum = %d\n", sum);
	printf("\n\n");
	printf("2016101453 유영주 배열 예제코드 실행화면\n");
	//system(“pause”);          * 컴파일 오류가 발생하여 주석처리 함
}


 
