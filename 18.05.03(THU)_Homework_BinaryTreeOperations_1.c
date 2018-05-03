/*
 * 작성자 정보: 2016101453 컴퓨터학부 유영주
 * 목적 및 개요: 3-1학기 자료구조 과제  <제9주 이진트리의 운행 프로그램>
 * 과제수행날짜: 2018.05.02(수)
 * 프로그램 특징: 이진트리 운행을 전위, 후위, 중위운행으로 구현 그 과정을 출력
 * 사용언어: C언어
 * 프로그램 작성환경 및 실행환경:
 *   OS: OSX High Sierra 10.13.4
 *   IDE: Xcode 9.3
 *   Compiler: gcc 4.2.1
 *   Text Encoding: UTF-8
 */


/*
 * 숙제사항: 1.본인이 수식을 만들고 이를 이진트리(트리의 레벨 4 이상이 되도록)로 구현하세요.
           2.구현된 이진트리를 이용하여 inorder, preorder, postorder 함수에서
           각 함수 호출과정이 출력되도록 프로그램을 작성하세요.
 */

#include <stdio.h>
#include<stdlib.h>


typedef struct node {
    struct node *lchild;
    char data;
    struct node *rchild;
} node;
node *root, *temp, *ptr;

int funCount = 1; // 함수의 호출 횟수를 세기위한 변수

void inorder(node *current_node){
    printf("inorder 함수 호출 번호는 = %d 입니다.\n",funCount);  // 재귀 함수 호출 과정을 보기 위해 출력문 삽입
    funCount = funCount + 1;
        if(current_node != NULL){
            inorder(current_node -> lchild); /* 왼쪽 서브트리로 이동 */
            printf("%c\n", current_node -> data); /* root 노드 방문(출력) */
            inorder(current_node -> rchild);  /* 오른쪽 서브트리로 이동 */
        }; /* end if */
} /* end inorder */

void preorder(node *current_node){
    
    if(current_node != NULL){
        printf("%c", current_node -> data); /* root 노드 방문(출력) */
        inorder(current_node -> lchild); /* 왼쪽 서브트리로 이동 */
        inorder(current_node -> rchild);  /* 오른쪽 서브트리로 이동 */
    }; /* end if */
} /* end preorder */

void postorder(node *current_node){
    
    if(current_node != NULL){
        inorder(current_node -> lchild); /* 왼쪽 서브트리로 이동 */
        inorder(current_node -> rchild);  /* 오른쪽 서브트리로 이동 */
        printf("%c", current_node -> data); /* root 노드 방문(출력) */
    }; /* end if */
} /* end postorder */


node* makeTree(char data) {//노드를 만든다
    ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    ptr->lchild = NULL;
    ptr->rchild = NULL;
    return ptr;
}



int main(int argc, const char * argv[]){
    

    // 여기에 내가 만든 수식을 넣어주고
    printf("임의의 문자 ABCDE  G를 레벨순으로 차례로 입력 \n");
    node *r1 = makeTree('*'); // 트리 Level 1
    node *r2 = makeTree('/');
    node *r3 = makeTree('%'); // 트리 Level 2 끝
    node *r4 = makeTree('-');
    node *r5 = makeTree('-');
    node *r6 = makeTree('+');
    node *r7 = makeTree('*'); // 트리 Level 3 끝
    node *r8 = makeTree('1');
    node *r9 = makeTree('2');
    node *r10 = makeTree('3');
    node *r11 = makeTree('4');
    node *r12 = makeTree('5');
    node *r13 = makeTree('6');
    node *r14 = makeTree('7');
    node *r15 = makeTree('8'); // 트리 Level 4 끝
    
    root = r1;
    r1->lchild = r2;
    r1->rchild = r3;
    r2->lchild = r4;
    r2->rchild = r5;
    r3->lchild = r6;
    r3->rchild = r7;
    r4->lchild = r8;
    r4->rchild = r9;
    r5->lchild = r10;
    r5->rchild = r11;
    r6->lchild = r12;
    r6->rchild = r13;
    r7->lchild = r14;
    r7->rchild = r15;
    
    
    // 여가에 이제 위의 운행 함수를 넣어준다.
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    
    
    /*
    root = r1;
    r1->lchild = r2;
    r1->rchild = r3;
    r2->lchild = r4;
    r2->rchild = r5;
    r3->rchild = r7;
    
    printf("root의 주소 =%d, root의 data = %c\n", root, root->data);
    temp = root;
    temp = temp->lchild;
    printf("root의 lchild의 주소 =%d,  data = %c\n", temp, temp->data);
    printf("B 데이터의 lchild의 주소 =%d, data = %c\n", temp->lchild, temp->lchild->data);
    printf("B 데이터의 rchild의 주소 =%d, data = %c\n", temp->rchild, temp->rchild->data);
    
    temp = root;
    temp = temp->rchild;
    printf("root의 rchild의 주소 =%d,  data = %c\n", temp, temp->data);
    printf("C 데이터의 lchild의 주소 =%d, data = %c\n", temp->lchild, temp->lchild);
    printf("C 데이터의 rchild의 주소 =%d, data = %c\n", temp->rchild, temp->rchild->data);
    */
    
    printf("\n");
    system("pause");
}
