/* �й� �� �̸� : 2016101453 ��ǻ���к� ������							   		     */
/* ���� �� ����:  ����1<�迭����>												     */
/* �������೯¥: 2018.03.01(��)												         */
/* �������� �� ���泻��:													         */
/* �̽�: Visual Studio 2017�� ���Ȼ� bufferoverflow ���輺���� ���� �Լ������ ����, */
/*	    ���� #pragma warning(disable: 4996) ����Ͽ� ������ ���� ��������		     */
/* ���α׷� �ۼ�ȯ�� �� ����ȯ��: OS: Window's 10   IDE: Visual Studio 2017          */
/* �����: C���															         */

#include <stdio.h>
#pragma warning(disable: 4996)

int function_input(int []); /* ������ ���� 5���� �迭�� �̿��� �Է¹޴� �Լ�*/
int function_print(); /* */


void main()
{
	int array[] = { 0,0,0,0,0 };
	function_input(array);
}



/* scanf�� �̿��� ���� 5���� �Է¹޴� �Լ� */
int function_input(int array[5])
{
	//array[5] = {0,0,0,0,0};
	int i = 0;

	printf("���� 5���� �Է����ּ���.\n\n");


	for (i = 0; i < 5; i = i + 1)
	{
		printf("%d��° ���ڸ� �Է����ּ���.\n", i+1);
		scanf("%d", &array[i]);
	}
	return 0;
}


int function_print();
{

}

