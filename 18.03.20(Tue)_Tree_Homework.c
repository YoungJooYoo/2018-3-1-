/*
 * 학번 및 이름 : 2016101453 컴퓨터학부 유영주
 * 목적 및 개요:  3-1학기  자료구조 과제 <연결리스트를 이용한 트리 구현>
 * 과제수행날짜: 2018.03.19(월)
 * 프로그램 특징: 트리를 이용한 가족의 가계도 구현
 * 사용언어: C언어
 * 프로그램 작성환경 및 실행환경:
 *   OS: OSX High Sierra 10.13.3
 *   IDE: Xcode 9.2
 *   Compiler: gcc 4.2.1
 *   Text Encoding: UTF-8
 */

/*
   과제 시간에 쫓기느라 코드 품질이 점점.....네.. 엄청난 태클은 언제나 환영입니다!
*/

#include <stdio.h>
#define max 20

// 트리를 위한 구조체 선언
// 특징은 오른쪽 왼쪽에 포인터로 트리를 구현
typedef struct node {
    struct node *lchild;
    char male[max];
    char female[max];     //한 노드에 엄마 아빠를 추가하기 위해 데이터 필드를 2개를 넣었다.
    struct node *rchild;
} node;


// 트리 시작점 root와, 노드가 생성될때 임시로 사용할 temp, 생성된 노드의 주소를 계속 반환해주는 ptr변수 선언
node *root, *temp, *ptr;




// 노드 생성을 완전히 함수화 시켰고, 반환타입이 구조체형이고, 새로 생성된 포인터의 주소를 반환한다.
node* makeTree(char data_male[],char data_female[]) {//노드를 만든다
    ptr = (node*)malloc(sizeof(node));
    strcpy(ptr->male,data_male);   // 포인터 매개변수를 설정하고 여기에 문자열을 받고 노드 자체 내장된 male과 female에 넣는다.
    strcpy(ptr->female,data_female);
    ptr->lchild = NULL;
    ptr->rchild = NULL;
    return ptr;
}



int main(int argc, const char * argv[]){
    
    printf("가족가계도 할아버지부터 손자까지 \n\n");
    node *r1 = makeTree("Father","Mother");
    node *r2 = makeTree("Sun1","Empty");
    node *r3 = makeTree("Sun2","Empty");
    node *r4 = makeTree("Grandson1","Empty");
    node *r5 = makeTree("Grandson2","Empty");
    node *r7 = makeTree("Grandson3","Empty");
    
    root = r1;
    r1->lchild = r2;
    r1->rchild = r3;
    r2->lchild = r4;
    r2->rchild = r5;
    r3->rchild = r7;
    
    printf("root의 주소 =%d, root의 가족data = %s\n", &root, root->male);
    printf("root의 주소 =%d, root의 가족data2 = %s\n\n", &root, root->female);
    temp = root;
    temp = temp->lchild;
    
    printf("root의 lchild의 주소 =%d,  가족data = %s\n", &temp, temp->male);
    printf("root의 lchild의 주소 =%d,  가족data2 = %s\n\n", &temp, temp->female);
    
    printf("B 데이터의 lchild의 주소 =%d, 가족data = %s\n", &temp->lchild, temp->lchild->male);
    printf("B 데이터의 lchild의 주소 =%d, 가족data2 = %s\n", &temp->lchild, temp->lchild->female);
    printf("B 데이터의 rchild의 주소 =%d, 가족data = %s\n", &temp->rchild, temp->rchild->male);
    printf("B 데이터의 rchild의 주소 =%d, 가족data2 = %s\n\n", &temp->rchild, temp->rchild->female);
    
    temp = root;
    temp = temp->rchild;
    
    printf("root의 rchild의 주소 =%d,  가족data = %s\n", &temp, temp->male);
    printf("root의 rchild의 주소 =%d,  가족data2 = %s\n\n", &temp, temp->female);
    
    printf("C 데이터의 lchild의 주소 =%d, 가족data = %s\n", &temp->lchild, temp->lchild);
    printf("C 데이터의 rchild의 주소 =%d, 가족data2 = %s\n", &temp->rchild, temp->rchild->male);
    printf("C 데이터의 rchild의 주소 =%d, 가족data2 = %s\n", &temp->rchild, temp->rchild->female);
    
    printf("\n");
    //system("pause");
    return 0;
}

