/*
 * 작성자 정보: 2016101453 컴퓨터학부 유영주
 * 목적 및 개요: 3-1학기 자료구조 과제  <제11주. 그래프의 운행 프로그래밍>
 * 과제수행날짜: 2018.05.16(수)
 * 프로그램 특징: 그래프의 깊이우선 탐색과, 너비우선 탐색 구현  1.DFS(깊이우선탐색) 연결리스트로 구현
 * 사용언어: C언어
 * 프로그램 작성환경 및 실행환경:
 *   OS: OSX High Sierra 10.13.4
 *   IDE: Xcode 9.3
 *   Compiler: gcc 4.2.1
 *   Text Encoding: UTF-8
 */


/*
 * 숙제사항: 본인이 그래프를 만들어 이를 인접행렬과 인접리스트로 저장하세요. ( C언어 프로그램 #23-24번 참조)
 구현된 인접행렬과 인접리스트를 이용하여 너비우선탐색(BFS), 깊이우선탐색(DFS)을 구현하는 프로그램을 작성하세요.
 프로그램 구현 중 과정이 출력되도록 하여 큐와 스택의 변화과정과 vistited[] 배열값의 변화를 그림으로 그려서 설명하세요.
 */


// 결과물 유의사항 : 예를 들어 7번 방문했는데 프린트가 1번에서 2로 이동하는 메세지가 나올 때가 있다.
// 이유는 바로 깊이 우선탐색 하단이 끝나고 상단으로 다시 올라와 검색을 하기 때문에 그렇게 나오는 것이다.
// 따라서 깊이 우선 탐색이 정상적으로 작동하는 것을 볼 수 있다.

#include<stdio.h>
#include<stdlib.h>

// 그래프에 사용할 구조체 선언
typedef struct node
{
    struct node *next;
    int vertex;
}node;

node *head[20]; // 연결리스트의 head 노드 선언
int visited[20];  // 방문했다는 정보를 기록하는 배열
int n;  // 인덱스 n

void read_graph(); // 인접리스트로 그래프 구현 함수
void insert(int,int); // 인접리스트에 정점을 넣는 함수
void DFS(int); // 깊이우선 탐색 함수

int main()
{
    int i;
    read_graph(); // 방문횟수를 0으로 초기화 한다.
    
    for(i=0;i<n;i++) // 방문정보를 0으로 초기화 시킨다.
        visited[i]=0;
    
    DFS(0); // 깊이 우선 탐색을 시작한다.
    return 0;
}

void DFS(int i)
{
    node *ptr; // ptr로 사용할 node타입의 포인터 변수선언
    
    printf("\n%d",i); // 방문한 정점을 출력한다
    ptr=head[i];  // ptr변수에 첫번째 헤드 포인터를 넣어준다.
    visited[i]=1; // 방문정보 기록에 방문했다는 표시로 1을 넣어준다.
    printf("방문한 visitded[%d]= %d \n", i,visited[i]);
    while(ptr!=NULL)   // p가 null이라는 뜻은, 끝에 도달했다는 의미, 반복문으로 끝부분인 NULL이 나올때 까지 탐색한다.
    {
        printf("%d에서 ",i);
        i=ptr->vertex; // 다음을 읽어서 i에 저장한다.
        
        if(!visited[i]) // 방문하지 않았다면, DFS함수를 재귀로 다시 불러 반복을 진행한다.
        {
            printf("%d로 이동\n", ptr->vertex);
            DFS(i);
        }
        ptr=ptr->next; // 탐색에 사용할 임시변수 ptr을 다음 노드로 향하게 한다.
    }
}

void read_graph()
{
    int i;
    int vi; // 정점으로 사용할 변수
    int vj; // 정점으로 사용할 변수
    int edges;
    
    printf("정점의 갯수를 입력하세요:");
    scanf("%d",&n);
    
    // head 노드를 초기화 한다.
    for(i=0;i<n;i++)
    {
        
        head[i]=NULL;  //head를 초기화한다.
        printf("이음선의 갯수를 입력하세요:");
        scanf("%d", &edges);
        
        // 입력 받은 정점을 서로 이어준다.
        for(i=0;i<edges;i++)
        {
            printf("연결할 정점을 입력하세요(u,v):");
            scanf("%d%d",&vi,&vj);
            insert(vi,vj);
        }
    }
}

// 리스트로 이루어진 정점을 연결하는 함수
void insert(int vi,int vj)
{
    node *p,*q;
    // q에게 메모리를 할당하고, 생성된 구조체노드 scanf에서 입력 받은 값을 넣어준다.
    q=(node*)malloc(sizeof(node));
    q->vertex=vj;
    q->next=NULL;
    
    // 초기화된 head에게 메모리 할당을 받은 q의 주소를 넣어준다. 즉 null값을 가르키는 노드는 마지막 노드이다.
    // 이 마지막 노드에 새로운 노드가 생기면 덧붙여 이어주는 것이다.
    if(head[vi]==NULL)
        head[vi]=q;
    else
    {
        // 위의 다른 점은, 어느 정점이 다른 정점과 이미 연결 되어 있는 경우,
        // 탐색을 통해 null값이 나오는 그 마지막 정점에 새로 만든 노드를 더해준다.
        p=head[vi];
        
        while(p->next!=NULL)
            p=p->next;
        p->next=q;
    }
}
