#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int seq;
    char name[30];
    struct queue *next;
};
struct queue *f = NULL;
struct queue *r = NULL;
void insert(int s)
{
    struct queue *new = (struct queue *)malloc(sizeof(struct queue));
    if (new == NULL)
    {
        printf("Memory allocation failed. Unable to insert.\n");
        return;
    }
    printf("Enter Patient Name: ");
    scanf("%s", new->name);
    new->seq = s;
    new->next = NULL;
    if (f == NULL)
    {
        f = new;
        r = new;
    }
    else if (s < f->seq)
    {
        new->next = f;
        f = new;
    }
    else if (s >= r->seq)
    {
        r->next = new;
        r = new;
    }
    else
    {
        struct queue *p = f;
        while (p->next != NULL && p->next->seq <= s)
        {
            p = p->next;
        }
        new->next = p->next;
        p->next = new;
    }
}
void delete()
{
    struct queue *p = f;

    if (f == NULL)
    {
        printf("Queue is empty !!\n");
    }
    else if (f == r)
    {
        f = NULL;
        r = NULL;
        free(p);
    }
    else
    {
        f = f->next;
        free(p);
    }
}
void display()
{
    struct queue *t;
    t = f;
    while (t != NULL)
    {
        printf("%s\t", t->name);
        t = t->next;
    }
}
void displayf()
{
    if (f == NULL)
    {
        printf("No patient\n");
    }
    else
        printf("Patient %s is at fist\n", f->name);
}
void displayr()
{
    if (r == NULL)
    {
        printf("No patient\n");
    }
    else
        printf("Parient %s is at last\n", r->name);
}
int main()
{
    int ch, d, y;
    do
    {
 printf("1.Add Patient \n2.Delete\n3.Display complete list\n4.Display first patient\n5.Display Last Patient\n");
 scanf("%d",&ch);
 switch (ch)
 {
        case 1:
            printf("Enter Priority(Serious=1 || Medium=2 || General=3 ):");
            scanf("%d", &d);
            insert(d);
            break;
        case 2:
            delete ();
        case 3:
            display();
            break;
        case 4:
            displayf();
            break;
        case 5:
            displayr();
            break;

        default:
            break;
 }
 printf("You want to continue (YES=1||NO=0)");
 scanf("%d",&y);
    } while (y == 1);
}
