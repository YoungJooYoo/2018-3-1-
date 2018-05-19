/*
 * 작성자 정보: 2016101453 컴퓨터학부 유영주
 * 목적 및 개요: 3-1학기 자료구조 과제  <제11주. 그래프의 운행 프로그래밍>
 * 과제수행날짜: 2018.05.18(수)
 * 프로그램 특징: 그래프의 깊이우선 탐색과, 너비우선 탐색 구현  2.BFS(너우선탐색) 인접리스트로 구현
 * 사용언어: C언어
 * 참고자료: https://www.thecrazyprogrammer.com/2015/09/breadth-first-search-bfs-program-in-c.html
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


// 깊이우선 탐색과 다른 핵심운, 다음노드를 검색하는 것이 아니라, 반복구문을 이용해 2x2행렬의 행의 원소를 검색하는 것이
// 너비 우선탐색이다.

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

// 변수를 이름화 시켜 상태 표현에 좀 더 직관적이게 한다.
#define initial 1
#define waiting 2
#define visited 3

int n;
int adj[MAX][MAX];  // 인접행렬 선언
int state[MAX]; // 방문했는지에 대한 상태를 저장
void create_graph();
void BF_Traversal();
void BFS(int v);

int queue[MAX], front = -1,rear = -1;  // 너비우선탐색은 자료구조 큐를 자용한다.
void insert_queue(int vertex);  // 다음 함수는 자료구조 리스트로 큐를 구현할 경우 구현해야하는 삽입함수다.
int delete_queue(); // 다음 함수는 자료구조 리스트로 큐를 구현할 경우 구현해야하는 삭제함수다.
int isEmpty_queue(); // 다음 함수는 자료구조 리스트로 큐를 구현할 경우 구현해야하는 큐상태 체크함수다.

int main()
{
    create_graph();
    BF_Traversal();
    return 0;
}

void BF_Traversal()
{
    int v;
    
    for(v=0; v<n; v++)
        state[v] = initial;  // 방문 상태를 초기화 한다.
    
    printf("BFS의 시작정점을 입력하세요: \n");
    scanf("%d", &v);
    BFS(v);
    printf("탐색이 완료 되었습니다.\n");
    printf("탐색을 종료합니다\n\n");
}

void BFS(int v)
{
    int i;
    
    insert_queue(v);
    state[v] = waiting;
    printf("방문순서 출력\n");

    while(!isEmpty_queue())
    {
        v = delete_queue( );
        printf("%d -> ",v); //방문한 정점을 출력한다.
        state[v] = visited;
        
        for(i=0; i<n; i++)
        {
            if(adj[v][i] == 1 && state[i] == initial) // 그래프 연결은 되었으나, 방문하지 않았다면
            {
                insert_queue(i); // 큐에 넣어 방문한다.
                state[i] = waiting; // 큐에 대기 상태가 된다고 표시한다.
            }
        }
    }
    printf("\n");
}

void insert_queue(int vertex)
{
    if(rear == MAX-1) // 큐의 오버플로우를 체크한다.
        printf("큐의 오버플로우가 일어났습니다.\n");
    else
    {
        if(front == -1)
            front = 0;
        rear = rear+1;
        queue[rear] = vertex ;
    }
}

int isEmpty_queue() // 큐가 비었는지 확인
{
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}

int delete_queue() // 큐의 삭제함수, 큐의 뺄 값이 없는 언더플로우 체크가 중요하다.
{
    int delete_item;
    if(front == -1 || front > rear)
    {
        printf("언더플로우 입니다.\n");
        exit(1);
    }
    
    delete_item = queue[front];
    front = front+1;
    return delete_item;
}

void create_graph()
{
    int count,max_edge,origin,destin;  // origin과 destin은 이음선의 출발 지점과 도착지점을 의미
    
    printf(" 최대 정점의 개수를 입력해주세요 : ");
    scanf("%d",&n);
    max_edge = n*(n-1);  // 그래프 선연결이 가능한 최대 연결 수를 체크하기 이한 변수
    
    for(count=1; count<=max_edge; count++)
    {
        printf("이음선 입력 %d( -1 -1 입력하면 종료하고 탐색시작 ) : ",count);
        scanf("%d %d",&origin,&destin);
        
        if((origin == -1) && (destin == -1)) // -1 입력 받으면 종료 체크하는 부분
            break;
        
        if(origin>=n || destin>=n || origin<0 || destin<0) // 예외처리
        {
            printf("유효하지 않은 edge입니다!\n");
            count--;
        }
        else
        {
            adj[origin][destin] = 1;
        }
    }
}
