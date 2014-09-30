#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b)
{
    char t=*a;
    *a = *b;
    *b = t;
}

void reverse(char *a, char *b)
{
    while(a<b)
    {
        swap(a++, b--);
    }
}

int next_perm(char a[])
{
    char *pEnd = a + strlen(a);
    if(a == pEnd)
        return 0;

    char *p, *q, *pFind;
    pEnd--;
    p = pEnd;
    while(p != a)
    {
        q = p;
        --p;
        if(*p < *q)
        {
            pFind = pEnd;
            while(*pFind <= *p)
                --pFind;
            swap(pFind, p);
            reverse(q, pEnd);
            return 1;
        }
    }
    reverse(p, pEnd);
    return 0;
}

int qsortcmp(const void *pa, const void *pb)
{
    return *(char *)pa - *(char *)pb;
}

int main()
{
    printf("no digui :\n");
    char szTextStr[] = "abc";
    printf("%s permutation is : \n", szTextStr);
    qsort(szTextStr, strlen(szTextStr), sizeof(szTextStr[0]), qsortcmp);
    int i = 1;
    do
    {
        printf("the %3d perm is --> %s\n", i++, szTextStr);
    }while(next_perm(szTextStr));

    return 0;
}
