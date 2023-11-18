#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct tree
{
    char data;
    struct tree *left, *right, *next;
};

struct tree *top;

void inorder(struct tree *top)
{
    if (top == NULL)
    {
        return;
    }
    else
    {
        inorder(top->left);
        printf("%c", top->data);
        inorder(top->right);
    }
}

struct tree *pop()
{
    struct tree *temp;
    if (top == NULL)
    {
        return NULL;
    }
    else
    {
        temp = top;
        top = top->next;
    }
    return temp;
}

void push(struct tree *new)
{
    if (top == NULL)
    {
        top = new;
    }
    else
    {
        new->next = top;
        top = new;
    }
}

struct tree *create(char d)
{
    struct tree *temp;
    temp = (struct tree *)malloc(sizeof(struct tree));
    temp->data = d;
    temp->right = NULL;
    temp->left = NULL;
    temp->next = NULL;
    return temp;
}

int main()
{
    struct tree *new, *a, *b;
    int i = 0;
    char post[30];
    printf("Enter the postfix expression -> ");
    scanf("%s", post);
    while (post[i] != '\0')
    {
        new = create(post[i]);
        if (isalnum(post[i]))
        {
            push(new);
        }
        else
        {
            a = pop();
            b = pop();
            if (a != NULL && b != NULL)
            {
                new->right = a;
                new->left = b;
                push(new);
            }
            else
            {
                printf("Invalid postfix expression\n");
                exit(1);
            }
        }
        i++;
    }

    if (top == NULL || top->next != NULL)
    {
        printf("Invalid postfix expression\n");
        exit(1);
    }

    printf("Inorder traversal: ");
    inorder(top);

    return 0;
}
