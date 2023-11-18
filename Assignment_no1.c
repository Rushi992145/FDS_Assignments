#include <stdio.h>
void Union(int a[], int b[], int n, int m);
void Intersection(int a[], int b[], int r, int t);
void DevOpsstud(int a[], int b[], int r, int t);
void Blockchainstud(int a[], int b[], int r, int t);
void OnlyOneSub(int a[], int b[], int r, int t);
void Union(int a[], int b[], int n, int m)
{
    int c[100], flag = 1, i, j, count;
    for (i = 0; i < n; i++)
    {
        c[i] = a[i];
    }
    count = n;
    for (i = 0; i < m; i++)
    {
        flag = 1;
        for (j = 0; j < count; j++)
        {
            if (c[j] == b[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            c[count] = b[i];
            count++;
        }
    }
    printf("Roll Number of All studenst :\n");
    for (i = 0; i < count; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
}
void Intersection(int a[], int b[], int r, int t)
{
    int c[100], i, j, count = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < t; j++)
        {
            if (a[i] == b[j])
            {
                c[count] = a[i];
                count++;
                break;
            }
        }
    }
    printf("Students Who Opted both DevOps and Blockchain:\n");
    for (i = 0; i < count; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
}
void DevOpsstud(int a[], int b[], int r, int t)
{
    int c[100], i, j, count = 0, flag;
    for (i = 0; i < r; i++)
    {
        flag = 1;
        for (j = 0; j < t; j++)
        {
            if (a[i] == b[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            c[count] = a[i];
            count++;
        }
    }
    printf("Students who opted Only DevOps:\n");
    for (i = 0; i < count; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
}
void Blockchainstud(int a[], int b[], int r, int t)
{
    int c[100], i, j, count = 0, flag;
    for (i = 0; i < t; i++)
    {
        flag = 1;
        for (j = 0; j < r; j++)
        {
            if (a[j] == b[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            c[count] = b[i];
            count++;
        }
    }
    printf("Students who opted Only Blockchain:\n");
    for (i = 0; i < count; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
}
void OnlyOneSub(int a[], int b[], int r, int t)
{
    int c[100], i, j, count = 0, flag;
    for (i = 0; i < r; i++)
    {
        flag = 1;
        for (j = 0; j < t; j++)
        {
            if (a[i] == b[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            c[count] = a[i];
            count++;
        }
    }
    for (i = 0; i < t; i++)
    {
        flag = 1;
        for (j = 0; j < r; j++)
        {
            if (a[j] == b[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            c[count] = b[i];
            count++;
        }
    }
    printf("Students who opted Only One Stream:\n");
    for (i = 0; i < count; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
}
int main()
{
    int n, m, i;
    int o, p;
    printf("Enter vacency for DevOps and Blockchain\n");
    scanf("%d%d", &o, &p);
    int a[o];
    int b[p];
    printf("Enter Roll no of %d students for DevOps\n", o);
    for (i = 0; i < o; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter Roll no of %d students for Blockchain\n", p);
    for (i = 0; i < p; i++)
    {
        scanf("%d", &b[i]);
    }
    printf("DevOps students are : ");
    for (i = 0; i < o; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("Block Chain students are : ");
    for (i = 0; i < p; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    // Union(a,b,o,p);
    do
    {
        printf("-------------------------------------------------------------------------------------\n");
        printf("What you want to do\n");
        printf("1.All Students \n");
        printf("2.Students Opted both Subjects \n");
        printf("3.Only DevOps students\n");
        printf("4.Only Blockchain Students\n");
        printf("5.Only one Subject\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            Union(a, b, o, p);
            break;

        case 2:
            Intersection(a, b, o, p);
            break;

        case 3:
            DevOpsstud(a, b, o, p);
            break;
        case 4:
            Blockchainstud(a, b, o, p);
            break;
        case 5:
            OnlyOneSub(a, b, o, p);
            break;
        default:
            printf("Invalid Input !! \n");
        }

        printf("Want to continue(0/1)\n");
        scanf("%d", &m);
    } while (m == 1);
    return 0;
}
