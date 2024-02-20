/*
이번 가을학기에 '문제 해결' 강의를 신청한 학생들은 텀 프로젝트를 수행해야 한다. 프로젝트 팀원 수에는 제한이 없다. 
심지어 모든 학생들이 동일한 팀의 팀원인 경우와 같이 한 팀만 있을 수도 있다. 
프로젝트 팀을 구성하기 위해, 모든 학생들은 프로젝트를 함께하고 싶은 학생을 선택해야 한다. 
(단, 단 한 명만 선택할 수 있다.) 혼자 하고 싶어하는 학생은 자기 자신을 선택하는 것도 가능하다.

학생들이(s1, s2, ..., sr)이라 할 때, r=1이고 s1이 s1을 선택하는 경우나, s1이 s2를 선택하고, s2가 s3를 선택하고,..., 
sr-1이 sr을 선택하고, sr이 s1을 선택하는 경우에만 한 팀이 될 수 있다.

예를 들어, 한 반에 7명의 학생이 있다고 하자. 학생들을 1번부터 7번으로 표현할 때, 선택의 결과는 다음과 같다.

1	2	3	4	5	6	7
3	1	3	7	3	4	6
위의 결과를 통해 (3)과 (4, 7, 6)이 팀을 이룰 수 있다. 1, 2, 5는 어느 팀에도 속하지 않는다.

주어진 선택의 결과를 보고 어느 프로젝트 팀에도 속하지 않는 학생들의 수를 계산하는 프로그램을 작성하라.
*/
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int match[100001] = { 0 };
int adjacants[100001] = { 0 };
int visited[100001] = { 0 };
int cnt = 0;
void DFS(int here)
{

    visited[here] = 1;
    int next = adjacants[here];
    if (visited[next] == 0)
    {
        DFS(next);
    }
    else if (match[next] == 0) // visited == 1 && match == 0 // 끝까지 간후 연결된건지 시작.
    {
        cnt++;
        for (int i = next; i != here; i = adjacants[i]) // for문 이렇게 쓸수도 있네;;;;;;
            // 사이클이 맞나? 결국 자기자신으로 돌아오나 체크
        {
            cnt++;
        }
    }
    match[here] = 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        memset(match, 0, sizeof(match));
        memset(adjacants, 0, sizeof(match));
        memset(visited, 0, sizeof(match));
        int M;
        cin >> M;

        for (int j = 0; j < M; j++)
        {
            int to;
            cin >> to;
            adjacants[j] = (to - 1);
        }
        cnt = 0;
        for (int j = 0; j < M; j++)
        {
            if (visited[j] == 0)
            {
                DFS(j);
            }
        }
        cout << M - cnt << "\n";
    }

}
