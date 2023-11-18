#include <stdio.h>
#include <stdlib.h>
struct abc
{
    int data;
    struct abc *next;
};
struct abc *InsertB(struct abc *head, int m)
{
    struct abc *t1;
    t1 = (struct abc *)malloc(sizeof(struct abc));
    t1->data = m;
    t1->next = NULL;
    t1->next = head;
    head = t1;
    return head;
}
void InsertE(struct abc *head)
{
    struct abc *p, *t2;
    p = head;
    t2 = (struct abc *)malloc(sizeof(struct abc));
    printf("\nEnter data for node\t");
    scanf("\n%d", &t2->data);
    t2->next = NULL;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = t2;
    head = p;
}
void InsertM(struct abc *head, int d)
{
    struct abc *p, *q, *t2;
    t2 = (struct abc *)malloc(sizeof(struct abc));
    printf("\nEnter data for node\t");
    scanf("\n%d", &t2->data);
    t2->next = NULL;
    p = head;
    q = head->next;
    while (p->data != d)
    {
        p = p->next;
        q = q->next;
    }
    p->next = t2;
    t2->next = q;
}
void deleteB(struct abc *head)
{
    struct abc *p;
    p = head;
    head = head->next;
    p->next = NULL;
    free(p);
}
void deleteE(struct abc *head)
{
    struct abc *p;
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = NULL;
}
void deleteM(struct abc *head, int h)
{
    struct abc *p, *q;
    p = head;
    while (p->data != h)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    p->next = NULL;
    free(p);
}
void print(struct abc *head)
{
    while (head != NULL)
    {
        printf("%d\t", head->data);
        head = head->next;
    }
}
int main()
{
    struct abc *head, *p, *t1;
    head = (struct abc *)malloc(sizeof(struct abc));
    printf("\nEnter data for node\t");
    scanf("\n%d", &head->data);
    head->next = NULL;
    t1 = (struct abc *)malloc(sizeof(struct abc));
    printf("\nEnter data for node\t");
    scanf("\n%d", &t1->data);
    t1->next = NULL;
    head->next = t1;
    int h, z, d, m, ans;
    do
    {
        printf("\nEnter the choice:\n1.Insert Begin\n2.Insert Middle\n3.Insert End\n4.Display\n5.Delete Begin\n6.Delete middle\n7.Delete end\n");
        scanf("\n%d", &z);
        switch (z)
        {
        case 1:
            printf("\nEnter the data\n");
            scanf("\n%d", &m);
            head = InsertB(head, m);
            break;
        case 2:
            printf("\nEnter data after which u need to insert\n");
            scanf("%d", &d);
            InsertM(head, d);
            break;
        case 3:
            InsertE(head);
            break;
        case 4:
            print(head);
            break;
        case 5:
            deleteB(head);
            break;
        case 6:
            printf("\nEnter data after which u need to delete\n");
            scanf("%d", &h);
            deleteM(head, h);
            break;
        case 7:
            deleteE(head);
            break;
        default:
            printf("\n Wrong choice");
            break;
        }
        printf("\n Do u want to continue[0/1]");
        scanf("\n%d", &ans);
    } while (ans == 1);
}
