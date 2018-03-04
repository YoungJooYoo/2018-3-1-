/*
 
 출처: http://kin.naver.com/qna/detail.nhn?d1Id=1&dirId=1040101&docId=296446989&mobile
 누가 학교과제를 여기다가 물어보셨네 감사하게도!
 작성환경: 맥 + xcode
 
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * link;
};
struct node * initNode(struct node * pNode) {
    pNode->data = 0;
    pNode->link = NULL;
    return pNode;
}
struct node * extendNode(struct node * pNode) {
    if (pNode->link == NULL) {
        pNode->link = (struct node *)malloc(sizeof(struct node));
        initNode(pNode->link);
    }
    return pNode->link;
}
struct node * destroyNode(struct node * pNode) {
    if (pNode != NULL) {
        if (pNode->link != NULL) {
            pNode->link = destroyNode(pNode->link);
            free(pNode->link);
        }
    }
    return pNode;
}
int main(int argc, const char * argv[]) {
    struct node * head = NULL;
    struct node * temp = NULL;
    int i;
    head = (struct node *)malloc(sizeof(struct node));
    temp = head;
    initNode(temp);
    for (i = 0; i < 5; i++) {
        printf("Input an integer (%d) >> ", i + 1);
        scanf("%d", &temp->data);
        if (i < 4) {
            temp = extendNode(temp);
            initNode(temp);
        }
    }
    temp = head;
    // 제시된 while 문은 5번째 노드를 출력하지 못하고 종료하는 문제가 있습니다.
    // node->link가 NULL일 때는 출력도 안 하고 그냥 건너뛰니까요.
    // 다음과 같이 바꿔봤습니다.
    do {
        printf("Address = %p, Data = %d\n", temp, temp->data);
        temp = temp->link;
    } while (temp != NULL);
    temp = NULL;
    head = destroyNode(head);
    return 0;
}
