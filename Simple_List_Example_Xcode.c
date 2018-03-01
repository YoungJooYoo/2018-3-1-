/*
* Simple_List_Homework
* 학번 및 이름 : 2016101453 컴퓨터학부 유영주
* 목적 및 개요:  과제2<리스트 과제>
* 과제수행날짜: 2018.03.01(목)
* 이슈: 개인 노트북이 Apple 노트북인 Macbook을 사용하는 관계로 OSX과 Xcode를 이용해 과제진행
* 프로그램 작성환경 및 실행환경:
    Language : C language
    OS: OSX High Sierra 10.13.3
    IDE: Xcode 9.2
    Compiler: gcc 4.2.1
*/



#include <stdio.h>
#include <stdlib.h>

void main()
{
    //구조체 선언으로 변수와 포인터 변수를 선언한다.
    struct node {
        int data;
        struct node *link;  //포인터 변수는 4바이트
    };
    typedef struct node node;
    
    // 새로운 구조체 포인터 new_node와 head를 선언한다.
    node *new_node = NULL, *head = NULL;
    
    // 선언된 포인터변수의 주소와 데이터 값을 확인해본다.
    // %x는 16진수 출력
    // 그리고 malloc을 하기전까지 메모리에 할당 "준비"만을 한 것이기에 일단 프린트문으로 메모리 할당 되었는지 확인 변수는 자동초기화
    // 메모리에 할당이 안되어 주소가 이상하게 나온다.
    printf("*new_node  의 주소= %d, 데이터= %x \n", &new_node, new_node);
    printf("*head      의 주소= %d, 데이터= %x \n", &head, head);
    printf("--------메모리 주소할당 전 ------\n\n");
    
    // 뉴노드 포인터 변수에 노트 사이즈 만큼의 메모리를 동적으로 할당한다
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("memory allocation error\n\n");
    };
    
    
    // 선언된 구조체 변수에게 포인터로 접근하며 변수를 직접 넣어준다.
    // 헤드는 뉴노드를 가르키게 하고, 뉴노드에 데이터는 10이 들어간다.
    new_node->data = 10;
    new_node->link = NULL;
    head = new_node;
    // 변수를 넣어준 후 출력을 통해 값을 확인한다.
    printf("new_node 생성 후의 데이터(1) = %d \n", new_node);
    printf("new_node->data의 주소= %d, 데이터= %d \n", &new_node->data, new_node->data);
    printf("new_node->link의 주소= %d, 데이터= %d \n", &new_node->link, new_node->link);
    printf("head 의 데이터= %d \n", head->data);
    printf("-----메모리 주소할당 후 데이터1 ----\n\n");
    // 헤드값에는 뉴노드 넣었으니 당연히 주소값이 같게 출력이 된다.
    
    
    // 뉴노드 포인터 변수에 노트 사이즈 만큼의 메모리를 동적으로 할당한다 타입def로 node로 선언했으니 이 타입을 정하고 node로 변수 선언했으니 그대로 넣는다.
    new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        printf("memory allocation error\n\n");
        exit(1);
    };
    
    // 이번에는 20을 집어 넣는다.
    new_node->data = 20;
    new_node->link = head->link;
    head->link = new_node;  // 위에 선언했던 노드를 한번 거친 다음에 이 노드! 즉, 연결
    
    // 다시 리스트등의 값들을 출력한다.
    printf("new_node 생성 후의 데이터(2) = %d \n", new_node);
    printf("new_node->data의 주소= %d, 데이터= %d \n", &new_node->data, new_node->data);
    printf("new_node->link의 주소= %d, 데이터= %d \n", &new_node->link, new_node->link);
    printf("head->link 의 데이터= %d \n", head->link);
    printf("-----메모리 주소할당 후 데이터2 ----\n\n");
    //출력 창을 보면 헤드가 이제 20을 가르키는 노드를 가리키고 있다.
    
    printf("첫 번째 노드의 값 = %d\n", head->data);  // 헤드-노드1-노드2 구조라서 헤드에 데이터 한번 링크타면 10이 나오지
    printf("두 번째 노드의 값 = %d\n\n", head->link->data); // 헤드-노드1-노드2 링크탔으니 당연히 20이 나오지
    
    free(head);  // 헤드를 메모리에서 해제
    head = new_node; //헤드는 노트2를 연결
    printf("삭제된 후 첫 번째 노드의 값 = %d\n\n", head->data);
    //system(“pause”);
}

