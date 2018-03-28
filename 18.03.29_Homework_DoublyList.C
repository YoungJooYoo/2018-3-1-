/*
 * 작성자 정보 : 2016101453 컴퓨터학부 유영주
 * 목적 및 개요:  3-1학기 자료구조 과제  <제 5주 이중연결리스트 구현>
 * 과제수행날짜: 시작: 2018.03.28(수) => 종료: 2018.03.29(목)
 * 프로그램 특징:이중연결리스트 구현
 * 참조자료 : https://gist.github.com/mycodeschool/7429492
 * 사용언어: C언어
 * 프로그램 작성환경 및 실행환경:
 *   OS: OSX High Sierra 10.13.3
 *   IDE: Xcode 9.2
 *   Compiler: gcc 4.2.1
 *   Text Encoding: UTF-8
 */


/*
 * 숙제사항: 1.노드 생성을 함수화할 것
 *         2.순차 출력과, 역순 출력 둘다 할 것
 *         3.변수와 노드들의 시작주소를 출력할 것
 */



/*
 
 5개의 숫자 값을 콘솔에서 입력받아(scanf()) 연결하는 이중 연결리스트를 구현하고,
 노드를 가르키는 포인터 변수 temp를 선언하여 head 로부터 연결된 노드의 data 값을 하나씩 출력하는데,
 5개의 값을 rlink로 연결된 값들을 차례로 출력한 후,
 마지막 노드에서는 llink로 연결된 값들을 차례로(역순으로) 출력하도록 하는 프로그램을 작성하세요.
 
 ( 예, head -> 11 <-> 12 <-> 13<-> 14 <-> 15 로 5개의 숫자로 이중연결리스트를 만들고,
 11, 12, 13, 14, 15를 출력한 후, 14, 13, 12, 11 을 출력하도록 구현하세요. )
 */

#include<stdio.h>
#include<stdlib.h>
#define max 5

struct Node  {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;// 헤드로 쓸 노드하나를 선언한다.

// 이중 연결 리스트의 구조체 메모리를 할당하고, 초기화한다.
struct Node* GetNewNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    printf("입력된 값 = %d\n",x);
    printf("변수 data의 시작주소 = %d\n",&newNode->data);
    printf("포인터변수 prev 시작주소 = %d\n",&newNode->prev);
    printf("포인터변수 next 시작주소 = %d\n",&newNode->next);
    printf("포인터 구조체 변수 newNode의 주소 = %p\n",&newNode);
    printf("newNode가 가진 구조체의 주소 = %d\n\n",newNode);
    
    return newNode; // 새로 생성한 Node의 주소값을 반환한다.
}

// 이중 연결리스트의 헤드노드를 삽입한다.
void InsertAtHead(int x) {
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        return; //void함수는  return을 컴파일러에서 선언해주는 함수므로, 작성자가 원하는 부분에서 종료할 수 있다.
    }
     // 초기에 생성된 헤드는 자기 자신을 가르킨다.
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

// 본격적으로 노드를 덧붙인다.
void InsertAtTail(int x) {
    struct Node* temp = head;
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    while(temp->next != NULL) temp = temp->next; // 마지막노드를 검색한다.
    temp->next = newNode; // 검색된 마지막 노드를 지금 만든 노드와 붙인다.
    newNode->prev = temp;
}

// 순차적으로 생성된 노드를 출력한다.
void Print() {
    struct Node* temp = head;
    printf("Forward: ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//생선된 노드를 역순으로 출력한다.
void ReversePrint() {
    struct Node* temp = head;
    if(temp == NULL) return; // 헤드가 NULL이면 종료
    
    // 맨 끝부터 출력해야하니 일단, temp위치를 맨 끝으로 보낸다.
    while(temp->next != NULL) {
        temp = temp->next;
    }
    // temp가 맨 끝에 있으니 다시 돌아오면서 출력 한다.
    printf("Reverse: ");
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->prev; // 끝에서부터 처음으로 돌아오는 작업  head의 prev는 NULL이다.
    }
    printf("\n");
}

 // 프로그램 초기화 함수, 전역변수를 선언하기 싫어, 포인터를 사용해 매개변수를 받는다.
 // 배열을 포인터로 넘겨 받아, 값을 받고 출력한다.
 void Input_Func(int *arr){
 printf("이중연결리스트를 구현하는 프로그램입니다.\n");
 printf("숫자를 5개 입력해주세요\n");
 for(int i=0; i<5; i++){
 scanf("%d",&arr[i]);
 }
 printf("입력하신 숫자입니다.\n");
 for(int i=0; i<5; i++){
 printf("%d ",arr[i]);
 }
 printf("\n\n");
 }


int main(int argc, const char * argv[]) {
    
    int node_data[max];
    Input_Func(node_data); // 배열을 매개변수로 넘긴다.
    
    head = NULL; // 헤드를 NULL로 초기화한다.
    
    for(int i=0; i<max; i++){
    InsertAtTail(node_data[i]);
    }
    
    Print();
    ReversePrint();
    
}
