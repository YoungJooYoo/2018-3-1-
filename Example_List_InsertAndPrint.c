/* 학번 및 이름 : 2016101453 컴퓨터학부 유영주		 			                       */
/* 목적 및 개요:  과제1<배열수행>							                           */
/* 과제수행날짜: 2018.03.01(목)					                                      */	                               
/* 이슈: Visual Studio 2017이 보안상 bufferoverflow 위험성으로 인한 함수사용을 제한,  */
/*	    따라서 #pragma warning(disable: 4996) 사용하여 컴파일 에러 무시적용	          */
/* 프로그램 작성환경 및 실행환경: OS: Window's 10   IDE: Visual Studio 2017          */
/* 사용언어: C언어															         */

#pragma warning(disable: 4996) // scanf 에러 무시를 위해 경고 무시를 추가.

#include <stdio.h>
#include <stdlib.h>

main()
{
	//구조체 선언으로 변수와 포인터 변수를 선언한다.
	struct node {
		int data;
		struct node *link;
	};
	typedef struct node node;

	// 새로운 구조체 포인터 new_node와 head를 선언한다.
	node *new_node = NULL, *head = NULL;

	// 선언된 포인터변수의 주소와 데이터 값을 확인해본다.
	printf("*new_node  의 주소= %d, 데이터= %x \n", &new_node, new_node);
	printf("*head      의 주소= %d, 데이터= %x \n\n", &head, head);


	// 뉴노드 포인터 변수에 노트 사이즈 만큼의 메모리를 동적으로 할당한다
	new_node = malloc(sizeof(struct node));
	if (new_node == NULL) {
		printf("memory allocation error\n\n");
	};


	// 선언된 구조체 변주에게 포인터로 접근하며 변수를 직접 넣어준다.
	new_node->data = 10;
	new_node->link = NULL;
	head = new_node;
	// 변수를 넣어준 후 출력을 통해 값을 확인한다.
	printf("new_node 생성 후의 데이터(1) = %d \n", new_node);
	printf("new_node->dad \n", &new_node->link, new_node->link);
	printf("head 의 데이터= %d \n\n", head);


	// 뉴노드 포인터 변수에 노트 사이즈 만큼의 메모리를 동적으로 할당한다 타입def로 node로 선언했으니 이 타입을 정하고 node로 변수 선언했으니 그대로 넣는다.
	new_node = malloc(sizeof(node));
	if (new_node == NULL) {
		printf("memory allocation error\n\n");
		exit(1);
	};

	// 이번에는 20을 집어 넣는다.
	new_node->data = 20;
	new_node->link = head->link;
	head->link = new_node;
	printf("new_node 생성 후의 데이터(2) = %d \n", new_node);
	printf("new_node->data의 주소= %d, 데이터= %d \n", &new_node->data, new_node->data);
	printf("new_node->link의 주소= %d, 데이터= %d \n", &new_node->link, new_node->link);
	printf("head->link 의 데이터= %d \n\n", head->link);

	printf("첫 번째 노드의 값 = %d\n", head->data);
	printf("두 번째 노드의 값 = %d\n\n", head->link->data);

	free(head);
	head = new_node;
	printf("삭제된 후 첫 번째 노드의 값 = %d\n\n", head->data);
	//system(“pause”);
}
