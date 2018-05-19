/*
 * 작성자 정보: 2016101453 컴퓨터학부 유영주
 * 목적 및 개요: 3-1학기 자료구조 과제  <제11주. 그래프의 운행 프로그래밍>
 * 과제수행날짜: 2018.05.19()
 * 프로그램 특징: 그래프의 깊이우선 탐색과, 너비우선 탐색 구현  2.DFS(깊이우선탐색) 인접행렬로 구현
 * 사용언어: C언어
 * 참고자료 : https://www.thecrazyprogrammer.com/2014/03/depth-first-search-dfs-traversal-of-a-graph.html
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

#include<stdio.h>

void DFS(int);
int G[10][10],visited[10],n;    // 2x2인접행렬 선언

int main()
{
    int i,j;
    printf("정점의 갯수를 입력하세요:");
    scanf("%d",&n);
    
    //인접 행렬을 앍는다.
    printf("\n 그래프의 인접행렬 입력: \n");
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    
    // 방문기록을 저장하는 배열인 visitied 배열을 0으로 초기화한다.
    for(i=0;i<n;i++)
        visited[i]=0;
    
    DFS(0);
    printf("\n");
    return 0;
}

void DFS(int i)
{
    int j;
    printf("방문한 정점은 %d\n",i);
    visited[i]=1;
    printf("방문한 visited[%d] = %d\n", i, visited[i]);
    
    for(j=0;j<n;j++)
        if(!visited[j]&&G[i][j]==1)
        {
            printf("%d에서 %d로 이동\n", i, j);
            printf("\n");
            DFS(j);
        }
}
