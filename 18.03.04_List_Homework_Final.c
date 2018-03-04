/*
+학번 및 이름 : 2016101453 컴퓨터학부 유영주
* 목적 및 개요:  과제2<리스트과제 수행>
* 과제수행날짜: 2018.03.04(일)
* 이슈: 1)Visual Studio 2017이 보안상 bufferoverflow 위험성으로 인한 함수사용을 제한,
*	  따라서 #pragma warning(disable: 4996) 사용하여 컴파일 에러 무시적용
* 프로그램 작성환경 및 실행환경: OS: Window's 10   IDE: Visual Studio 2017
* 사용언어: C언어
* 프로그램 특징: 정수값 입력만을 받아서 리스트를 구현
*/

#pragma warning(disable: 4996) // scanf 에러 무시를 위해 경고 무시를 추가.

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int i;//노드의 구성요소 첫번째. 값
	struct _node *nextadd;//노드의 구성요소 두번째. 다음 값을 가리키는 주소
}NODE;

NODE *firstnode = NULL;//첫번째 노드
NODE *lastnode = NULL;//마지막 노드

void add(int num) {//맨 뒤에 추가함
	NODE *newnode = (NODE *)malloc(sizeof(NODE));//먼저 생성하고 보자
	newnode->i = num;  // 입력값이 여기에 저장
	newnode->nextadd = NULL;   // 지금 추가된 것이 마지막 노드이니 NULL값 가르킨다.

	if (firstnode == NULL) {//처음으로 이 함수가 실행되면
		firstnode = newnode;
		lastnode = newnode;
	}
	else {//처음이 아니면 뒤에 계속 추가. lastnode가 계속 바뀐다
		lastnode->nextadd = newnode;//원래 lastnode가 가리키는 곳이 새로 생성된 노드의 값을 가리키게 한 하고. 원래 라스트가 지금 노드를 가르키게
		lastnode = newnode;//방금 생성한 노드가 맨 끝자리에 추가했으므로 방금 생성한 노드가 lastnode가 된다.
	}
}

void show() {
	int i;
	if (firstnode == NULL) {
		printf("값이 없어습니다.\n");
		return;
	}
	else {
		NODE *temp = firstnode;
		for (i = 1; temp != NULL; ++i) {
			printf("%d번째 값 : %d\n", i, temp->i);
			// 밑에 두줄이 추가구문
			printf("주소 = %d, 데이터 =%d\n", &temp, temp->i); 
			printf("주소 = %d\n", &temp->i);
			temp = temp->nextadd;

			

			
			


		}
	}
}





int main() {
	int select, i, input, input_num;
	while (1) {
		printf("\n\n0 : 종료\n");
		printf("1 : 노드 생성\n");
		printf("2 : 노드 보기\n");
		printf("0~2 선택 : ");
		scanf("%d", &select);
		printf("\n");

		if (select == 0) {
			return 0;
		}
		else if (select == 1) {
			printf("몇개 생성하시겠습니까? : ");
			scanf("%d", &input);
			for (i = 1; i <= input; ++i) {
				printf("%d번째 생성중입니다....\n값을 입력해주세요 : ", i);
				scanf("%d", &input_num);
				add(input_num);
			}
		}
	
		
		else if (select == 2) {
			show();
		}
	}
}



