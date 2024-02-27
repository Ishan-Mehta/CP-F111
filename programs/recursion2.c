#include <stdio.h>

int m_raised_to_n(int m, int n)
{
    if (n == 0)
        return 1;

    return m * m_raised_to_n(m, n - 1);
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    printf("%d\n", m_raised_to_n(m, n));
    return 0;
}