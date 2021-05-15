#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000

int dp[1000][1000], chains[1000];

int func(int start, int end)
{
    if(end - start == 1)
        return 0;

    if(dp[start][end] != -1)
        return dp[start][end];

    int min_ = inf, left, right;

    for(int i = start + 1; i < end; ++i)
    {
        left = func(start, i);
        right = func(i, end);
        min_ = min(min_, left + (chains[start] * chains[i] * chains[end]) + right);
    }

    return dp[start][end] = min_;
}

void printAnswer(int start, int end)
{
    if(end - start == 1) {
        printf("M%d", end);
        return ;
    }

    int min_ = inf, index, left, right;

    for(int i = start + 1; i < end; ++i)
    {
        left = dp[start][i];
        right = dp[i][end];
        if(min_ > left + (chains[start] * chains[i] * chains[end]) + right)
        {
            min_ = left + chains[start] * chains[i] * chains[end] + right;
            index = i;
        }
    }

    if(index - start == 1) {
        printAnswer(start, index);
    }
    else
    {
        printf("(");
        printAnswer(start, index);
        printf(")");
    }

    if(end - index == 1) {
        printAnswer(index, end);
    }
    else
    {
        printf("(");
        printAnswer(index, end);
        printf(")");
    }
    return ;
}

int main()
{
    int n, t;

    scanf("%d", &t);
    while(t--)
    {
        memset(dp, -1, sizeof(dp));

        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &chains[i]);
        }

        printf("Answer: %d\n", func(0, n - 1));
        printAnswer(0, n - 1);
        printf("\n");
    }
    return 0;
}

/*
3
5
40 20 30 10 30
5
10 20 30 40 30
3
10 20 30
*/
