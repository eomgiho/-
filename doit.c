#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// 후보자 제한
#define MAX 9

// 후보자들은 이름과 투표수를 가짐
typedef struct
{
    char name[100];
    int votes;
} candidate;

// 후보자 배열
candidate candidates[MAX];

// 후보자 수
int candidate_count;

// 함수 원형
bool vote(char *name);
void print_winner(void);

int main(int argc, char *argv[])
{
    // 잘못 입력 확인
    if (argc < 2)
    {
        printf("Usage : plurality [candidate ...]\n");
        return 1;
    }

    // 후보자 배열 채우기
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %d\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
}