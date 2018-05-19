/*
 * 작성자 정보: 2016101453 컴퓨터학부 유영주
 * 목적 및 개요: 3-1학기 자료구조 과제  <제11주. 그래프의 운행 프로그래밍>
 * 과제수행날짜: 2018.05.18(수)
 * 프로그램 특징: 그래프의 깊이우선 탐색과, 너비우선 탐색 구현  2.BFS(너비우선탐색) 인접행렬로 구현
 * 사용언어: C언어
 * 참고자료 : http://blog.eairship.kr/269?category=431859
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

#include <stdio.h>

int n; // 입력되는 정점의 최댓값
int rear, front; // 큐에 사용할 rear, front
int map[30][30], queue[30], visited[30]; // 인접 행렬과 큐와, 방문 배열

void BFS(int v)
{
    int i;
    
    visited[v] = 1; // 정점 v를 방문했다고 표시
    printf("%d에서 시작\n", v);
    printf("visited[%d] = %d\n", i,visited[v]);
    queue[rear++] = v; // 큐에 v를 삽입하고 후단을 1 증가시킴
    while (front < rear) // 큐가 빈경우 반복문을 나간다.
    {
        // 큐를 채워 넣는 것이다. 채워넣고 front위치를 +1 해준다.
        v = queue[front++];
        for (i = 1; i <= n; i++)
        {
            // 정점 v와 정점 i가 만나고 즉 그래프 선이 있고, 정점 i를 아직 방문하지 않은경우
            // 방문했다고 표시하고, 방문한다.
            if (map[v][i] == 1 && !visited[i])
            {
                visited[i] = 1; // 정점 i를 방문했다고 표시
                printf("%d에서 %d로 이동\n", v, i);
                printf("visited[%d] = %d\n", i,visited[i]);
                queue[rear++] = i; // 큐에 i를 삽입하고 큐가 증가했으니, rear를 1 증가시킴
            }
        }
    }
}

int main()
{
    int start; // 시작 정점을 나타내는 변수
    int v1, v2;
    
    printf("인접행렬로 BFS구현하기 \n");
    printf("정점의 갯수와 시작정점을 입력하세요. \n");
    scanf("%d%d", &n, &start);
    
    printf("연결할 정점을 입력하세요  ex)1 5\n");
    while (1)
    {
        scanf("%d%d", &v1, &v2);
        if (v1 == -1 && v2 == -1) break;
        map[v1][v2] = map[v2][v1] = 1; // 인접행렬 생성, 즉 그래프의 선을 잇는 연산식
    }
    BFS(start); // BFS 시작!
    
    return 0;
}
