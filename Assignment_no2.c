#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct abc
{
    int prn;
    char name[50];
    struct abc *next;
};

struct abc *Add_P(struct abc *head)
{
    printf("Enter President data\n");
    struct abc *temp, *p;
    temp = (struct abc *)malloc(sizeof(struct abc));

    printf("Enter PRN of president: ");
    scanf("%d", &temp->prn);

    printf("Enter Name of President: ");
    scanf("%s", temp->name);

    temp->next = head;
    head = temp;

    return head;
}

struct abc *delete_P(struct abc *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    struct abc *p = head;
    head = head->next;
    p->next = NULL;
    free(p);

    return head;
}

void DeleteS(struct abc *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct abc *p = head;
    struct abc *q = NULL;

    while (p->next->next != NULL)
    {
        p = p->next;
    }

    q = p->next;
    p->next = NULL;
    free(q);
}

void ADD_Sec(struct abc *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct abc *p = head;
    struct abc *temp;
    temp = (struct abc *)malloc(sizeof(struct abc));

    printf("Enter the Name of secretary: ");
    scanf("%s", temp->name);

    printf("Enter PRN: ");
    scanf("%d", &temp->prn);

    temp->next = NULL;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = temp;
}

void Add_member(struct abc *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct abc *q, *p = head;
    struct abc *temp;
    temp = (struct abc *)malloc(sizeof(struct abc));

    printf("Enter the Name of Member to add: ");
    scanf("%s", temp->name);

    printf("Enter PRN: ");
    scanf("%d", &temp->prn);

    temp->next = NULL;

    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }

    q->next = temp;
    temp->next = p;
}

void Delete_member(struct abc *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter the prn of Member to Delete: ");
    int n;
    scanf("%d", &n);

    struct abc *q, *p = head;

    while (p != NULL && p->prn != n)
    {
        q = p;
        p = p->next;
    }

    if (p == NULL)
    {
        printf("Member not found\n");
        return;
    }

    q->next = p->next;
    free(p);
}

void Total_members(struct abc *head)
{
    int n = 0;
    struct abc *p = head;

    while (p != NULL)
    {
        n++;
        p = p->next;
    }

    printf("There are %d total Members\n", n);
}

void Display(struct abc *head)
{
    struct abc *p = head;

    while (p != NULL)
    {
        printf("%d\t", p->prn);
        printf("%s\n", p->name);
        p = p->next;
    }
}

struct abc *DisplayRev(struct abc *head)
{
    struct abc *p = head;
    struct abc *q, *r;
    r = p->next;
    q = r->next;

    while (r != NULL)
    {
        if (p == head)
        {
            p->next = NULL;
            r->next = p;
            p = r;
            r = q;
            if (q != NULL)
            {
                q = q->next;
            }
        }
        else
        {
            r->next = p;
            p = r;
            r = q;
            if (q != NULL)
            {
                q = q->next;
            }
        }
    }

    head = p;

    while (head != NULL)
    {
        printf("%d\t", head->prn);
        printf("%s\n", head->name);
        head = head->next;
    }

    return p;
}

int main()
{
    printf("Enter President data\n");
    struct abc *head, *p;
    head = (struct abc *)malloc(sizeof(struct abc));
    head->next = NULL;

    printf("Enter PRN of president: ");
    scanf("%d", &head->prn);

    printf("Enter Name of President: ");
    scanf("%s", head->name);

    printf("\n");

    p = head;

    printf("Number of members you want to add: ");
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        struct abc *temp1;
        temp1 = (struct abc *)malloc(sizeof(struct abc));

        printf("Enter PRN: ");
        scanf("%d", &temp1->prn);

        printf("Enter Name: ");
        scanf("%s", temp1->name);

        temp1->next = NULL;
        head->next = temp1;
        head = head->next;
    }

    printf("Enter Secretary data:\n");
    struct abc *temp;
    temp = (struct abc *)malloc(sizeof(struct abc));

    printf("Enter PRN of Secretary: ");
    scanf("%d", &temp->prn);

    printf("Enter Name of Secretary: ");
    scanf("%s", temp->name);

    temp->next = NULL;
    head->next = temp;
    head = head->next;

    head = p;

    int ch, y;

    do
    {
        printf("\n1. Add President\n2. Delete President \n3. Add Secretary\n4. Delete Secretary\n5. Add Member\n6. Delete Member\n7. Total Number of members in the club\n8. Display the members of the club\n9. Display the List in reverse order\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = Add_P(head);
            break;
        case 2:
            head = delete_P(head);
            break;
        case 3:
            ADD_Sec(head);
            break;
        case 4:
            DeleteS(head);
            break;
        case 5:
            Add_member(head);
            break;
        case 6:
            Delete_member(head);
            break;
        case 7:
            Total_members(head);
            break;
        case 8:
            Display(head);
            break;
        case 9:
            head = DisplayRev(head);
            break;
        default:
            printf("\nWrong Input");
            break;
        }

        printf("\nWant to continue (Yes=1/No=0): ");
        scanf("%d", &y);

    } while (y == 1);

    return 0;
}
