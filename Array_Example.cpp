#include <stdio.h>


/* �й� �� �̸� : 2016101453 ��ǻ���к� ������								   */
/* ���� �� ����:  2018.02.28(��) �ڷᱸ�� ���� �迭 �����ڵ� ����			   */
/* �������೯¥: 2018.03.01(��)												   */
/* �������� �� ���泻��:													   */
/* �̽�: system("pause"); ������ ���� �ּ�ó��								   */
/* ���α׷� �ۼ�ȯ�� �� ����ȯ��: OS: Window's 10   IDE: Visual Studio 2017    */
/* �����: C���															   */



int total_hap(int a[], int n)
{
	int i = 0, hap = 0;
	printf("hap�� �ּ�= %d, ������= %x \n", &hap, hap);
	printf("  i �� �ּ�= %d, ������= %x \n", &i, i);

	for (i = 0; i < n; ++i)
		hap = hap + a[i];
	return(hap);
}

void main()
{
	int sum = 0;
	int i = 0;
	int a[10] = { 22, 35, 45, 91, 18, 31, 44, 51, 83, 28 };

	printf("sum�� �ּ�= %d, ������= %x \n", &sum, sum);
	printf("  i �� �ּ�= %d, ������= %x \n", &i, i);

	for (i = 0; i < 10; i++)
		printf("a[%d]�� �ּ�= %d, ������= %d \n", i, &a[i], a[i]);

	/* a�� �迭�� ù ��° ����� �ּҸ� ���� ������ ��� */
	printf("\n\n");
	sum = total_hap(a, 10);
	printf("\n\n");
	printf("sum = %d\n", sum);
	printf("\n\n");
	printf("2016101453 ������ �迭 �����ڵ� ����ȭ��\n");
	//system(��pause��);          * ������ ������ �߻��Ͽ� �ּ�ó�� ��
}


 
