#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define sz(x) (sizeof(x) / sizeof(x[0]))

void solve(void)
{
char *M[5] = {"TOI", "Hindu", "ET", "BM", "HT"};
double prices[5] = {26, 20.5, 34, 10.5, 18};
int n;
scanf("%d", &n);


int ansset[5];
bool taken[5] = {0};

for (int i = 0; i < 5; i++)
{
    if (prices[i] <= n)
    {
        taken[i] = true;
        ansset[i] = i;
        n -= prices[i];
    }
    else
    {
        taken[i] = false;
        ansset[i] = -1;
    }
}

bool flag = false;
for (int i = 0; i < 5; i++)
{
    if (taken[i])
    {
        if (flag)
        {
            printf(",");
        }
        printf("{");
        printf("\"%s\"", M[i]);
        flag = true;
        for (int j = i + 1; j < 5; j++)
        {
            if (taken[j])
            {
                printf(",\"%s\"", M[j]);
            }
        }
        printf("}");
    }
}
}

int main(void)
{
solve();
return 0;
}