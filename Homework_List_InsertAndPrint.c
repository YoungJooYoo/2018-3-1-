/* �й� �� �̸� : 2016101453 ��ǻ���к� ������		 			                       */
/* ���� �� ����:  ����1<�迭����>							                           */
/* �������೯¥: 2018.03.01(��)					                                      */	                               
/* �̽�: Visual Studio 2017�� ���Ȼ� bufferoverflow ���輺���� ���� �Լ������ ����,  */
/*	    ���� #pragma warning(disable: 4996) ����Ͽ� ������ ���� ��������	          */
/* ���α׷� �ۼ�ȯ�� �� ����ȯ��: OS: Window's 10   IDE: Visual Studio 2017          */
/* �����: C���															         */

#pragma warning(disable: 4996) // scanf ���� ���ø� ���� ��� ���ø� �߰�.

#include <stdio.h>
#include <stdlib.h>

main()
{
	//����ü �������� ������ ������ ������ �����Ѵ�.
	struct node {
		int data;
		struct node *link;
	};
	typedef struct node node;

	// ���ο� ����ü ������ new_node�� head�� �����Ѵ�.
	node *new_node = NULL, *head = NULL;

	// ����� �����ͺ����� �ּҿ� ������ ���� Ȯ���غ���.
	printf("*new_node  �� �ּ�= %d, ������= %x \n", &new_node, new_node);
	printf("*head      �� �ּ�= %d, ������= %x \n\n", &head, head);


	// ����� ������ ������ ��Ʈ ������ ��ŭ�� �޸𸮸� �������� �Ҵ��Ѵ�
	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("memory allocation error\n\n");
	};


	// ����� ����ü ���ֿ��� �����ͷ� �����ϸ� ������ ���� �־��ش�.
	new_node->data = 10;
	new_node->link = NULL;
	head = new_node;
	// ������ �־��� �� ����� ���� ���� Ȯ���Ѵ�.
	printf("new_node ���� ���� ������(1) = %d \n", new_node);
	printf("new_node->dad \n", &new_node->link, new_node->link);
	printf("head �� ������= %d \n\n", head);


	// ����� ������ ������ ��Ʈ ������ ��ŭ�� �޸𸮸� �������� �Ҵ��Ѵ� Ÿ��def�� node�� ���������� �� Ÿ���� ���ϰ� node�� ���� ���������� �״�� �ִ´�.
	new_node = malloc(sizeof(node));
	if (new_node == NULL) {
		printf("memory allocation error\n\n");
		exit(1);
	};

	// �̹����� 20�� ���� �ִ´�.
	new_node->data = 20;
	new_node->link = head->link;
	head->link = new_node;
	printf("new_node ���� ���� ������(2) = %d \n", new_node);
	printf("new_node->data�� �ּ�= %d, ������= %d \n", &new_node->data, new_node->data);
	printf("new_node->link�� �ּ�= %d, ������= %d \n", &new_node->link, new_node->link);
	printf("head->link �� ������= %d \n\n", head->link);

	printf("ù ��° ����� �� = %d\n", head->data);
	printf("�� ��° ����� �� = %d\n\n", head->link->data);

	free(head);
	head = new_node;
	printf("������ �� ù ��° ����� �� = %d\n\n", head->data);
	//system(��pause��);
}