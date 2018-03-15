/*
 * 학번 및 이름 : 2016101453 컴퓨터학부 유영주
 * 목적 및 개요:  3-1학기  자료구조 과제 <연결리스트로 큐 구현하기>
 * 과제수행날짜: 2018.03.14(수)
 * 프로그램 특징:
 *
 * 사용언어: C언어
 * 프로그램 작성환경 및 실행환경:
 *   OS: OSX High Sierra 10.13.3
 *   IDE: Xcode 9.2
 *   Compiler gcc 4.2.1
 *   Text Encoding : UTF-8
 */



/*
        정말 과제로 인해 급하게 짜느라 코드가 가독성과 질이 개판인 것은 인정합니다 ㅠㅠ
        잘못된 부분이 있다면, 언제든 태클 환영합니다!!!
 */


//주의사항  배열로 변경후 c% => %s 해야지 스트링으로 제대로 나온다. 안그러면 숫자출력

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct queue_node {
    char name[10];   // 과제요구사항, 배열을 사용할 것
    struct queue_node *link;
} queue_node;

queue_node *front = NULL, *rear = NULL, *new_node = NULL, *ptr = NULL;
char temp[10] = "0"; // 배열로선언 후 초기화




void insertQ(char dat[10]){   // name[10]이다 즉 길게 받으려고 했으니 여기 매개변수도 길게 문자 받을 수 있게!
    new_node = malloc(sizeof(queue_node));
    
    printf("데이터가 추가되었습니다.\n");
    printf("동적할당으로 추가된 구조체의 주소 = %d\n", new_node); // new_node는 포인터 변수이므로 구조체의 "주소값"을 가지고 있다.
    printf("포인터변수 new_node(구조체큐노드)의 주소 = %d\n", &new_node); // 포인터 변수 new_node의 주소는 나타낸다.
    printf("구조체 내부 name 변수의 주소 = %d\n", &new_node->name);
    printf("구조체 내부 *link 포인터변수의 주소 = %d\n\n", &new_node->link);
    // 구조체 new_node의 주소는 짧고 = 4192 , 구조체 내부 변수 주소들과는 주소가 상당히 다르다. data 주소4196352
    // data 주소4196352  link포인터변수의 주소 = 4196368
    // 따리서 서로 변수가 선언된 영역이 다르다는 것을 알 수 있다.
    // new_node는 Heap 영역에 배정 받고, 변수들은 정적영역이다.  그래서 주소값 번지가 완전히 다르게 나온다.
    
    if (new_node == NULL) {
        printf("memory allocation error\n");
        exit(1);
    }
    strcpy(new_node->name,dat);  //매개변수 dat를 받은 것을 strcpy함수로 복사해준다. 구조체 속 배열에는 이것이 편하다
    new_node->link = NULL;
    if (front == NULL)
        front = new_node;
    else
        rear->link = new_node;
    rear = new_node;
}

// 여기 까지는
//              이상 무



char deleteQ() {
    
    if (front==NULL) {
        printf("queue empty.\n");
        exit(1);
    }
    strcpy(temp,front->name);
    //temp = front->name;
    ptr = front;
    front = front->link;
    free(ptr);
    if (front==NULL) rear = NULL;
    return temp;  //전역변수. temp에 name을 넣어 char타입으로 반환한다.
}




int main() {
    
    int  suntaek;
    char item[100] = "0";
    
    for (;;) {
        fflush(stdin);                              /* 키보드버퍼를 비운다 */
        printf("\n 1:insertQ  2:deleteQ   3:종료 ...? \n");
        scanf("%d", &suntaek);
        
        switch (suntaek)
        {
            case 1:
                printf("넣고 싶은 문자형 자료를 입력해주세요.\n");
                scanf("%s", &item);
                printf("\n");
                insertQ(item);
                printf("insert후의 rear의 값 = %d\n", rear);
                printf("insert후의 rear의 주소값 = %d\n", &rear);
                printf("insert되어 삽입된 data = %s\n",  item);
                break;
                
            case 2:
            
                strcpy(item,front->name); // 이 함수에 어떻게 못하나?
                deleteQ();
                //item=deleteQ();
                printf("delete후의 포인터변수 front의 값 = %d\n", front );
                printf("delete되어 삭제된 data = %s\n", item);
               // printf("delete되어 삭제된 data = %s\n", deleteQ());
                break;
                
            case 3:
                return 0;
        }
    }
    printf("\n 프로그램 종료\n");
}

