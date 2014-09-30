#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char t=*a;
    *a = *b;
    *b = t;
}

int isSwap(char *pszStr, int nBegin, int nEnd)
{
    int i = 0;
    for(i=nBegin; i<nEnd; i++)
    {
        if(pszStr[i] == pszStr[nEnd])
            return 0;
    }
    return 1;
}

void AllRange(char *pszStr, int k, int m)
{
    int i = 0;
    if(k == m)
    {
        static int s_i = 1;
        printf("the %3d perm\t--> %s\n", s_i++, pszStr);
    }
    else
    {
        for(i=k; i<=m; i++)
        {
            if(isSwap(pszStr, k, i))
            {
                swap(pszStr+k, pszStr+i);
                AllRange(pszStr, k+1, m);
                swap(pszStr+k, pszStr+i);
            }
        }
    }
}

void Foo(char *pszStr)
{
    AllRange(pszStr, 0, strlen(pszStr)-1);
}


int main()
{
    printf(" permutation sequence all\n");
    char szTextStr[] = "122";
    printf("%s permutation is:\n", szTextStr);
    Foo(szTextStr);
    return 0;
}
