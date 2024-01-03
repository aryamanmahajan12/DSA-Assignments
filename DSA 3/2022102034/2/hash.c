#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Hash.h"

int palindrome(char *s, int l, int r)
{
    int j = r - 1;
    for (int i = l - 1; i <= l - 1 + (r - l) / 2; i++)
    {
        if (s[i] == s[j])
        {
            j--;
            continue;
        }
        else
            return 0;
    }
    return 1;
}