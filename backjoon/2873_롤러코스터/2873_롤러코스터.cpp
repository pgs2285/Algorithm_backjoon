#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    int** pleasure = new int* [R];
    // 2차원 배열 동적할당
    for (int i = 0; i < R; i++) {
        pleasure[i] = new int[C];
    }

    pair <int, int> blank;
    int min = 1001; // 최대값 설정
    // 배열 입력 및 최소값 위치 찾기
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> pleasure[i][j];
            if (min > pleasure[i][j] && (i + j) % 2 == 1) {
                min = pleasure[i][j];
                blank.first = i;
                blank.second = j;
            }
        }
    }

    // R이 홀수일 때의 이동 경로 출력
    if (R % 2 == 1) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C - 1; j++) {
                if (i % 2 == 0)
                    cout << 'R'; // 오른쪽 방향
                else
                    cout << 'L'; // 왼쪽 방향
            }
            if (i != R - 1)
                cout << 'D'; // 아래쪽 방향
        }
    }
    // C가 홀수일 때의 이동 경로 출력
    else if (C % 2 == 1) {
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < R - 1; j++) {
                if (i % 2 == 0)
                    cout << 'D'; // 아래쪽 방향
                else
                    cout << 'U'; // 위쪽 방향
            }
            if (i != C - 1)
                cout << 'R'; // 오른쪽 방향
        }
    }
    // R과 C가 모두 짝수일 때의 이동 경로 출력
    else {
        int r = (blank.first % 2 == 1) ? blank.first - 1 : blank.first; // blank 위치를 기준으로 상단 경로 설정
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < C - 1; j++) {
                if (i % 2 == 0)
                    cout << 'R';
                else
                    cout << 'L';
            }
            cout << 'D';
        }

        int c = blank.second; // blank 위치를 기준으로 좌우 경로 설정
        for (int i = 0; i < c; i++) {
            if (i % 2 == 0)
                cout << "DR";
            else
                cout << "UR";
        }
        for (int i = c; i < C - 1; i++) {
            if (i % 2 == 0)
                cout << "RD";
            else
                cout << "RU";
        }

        for (int i = r + 2; i < R; i++) { // blank 아래의 경로 설정
            cout << 'D';
            for (int j = 0; j < C - 1; j++) {
                if (i % 2 == 0)
                    cout << 'L';
                else
                    cout << 'R';
            }
        }
    }

    return 0;
}
