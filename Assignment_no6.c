#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree *left, *right;
};
struct tree *root = NULL;
struct tree *create(int d)
{
    struct tree *new;
    new = (struct tree *)malloc(sizeof(struct tree));
    new->data = d;
    new->left = NULL;
    new->right = NULL;
    return new;
}
struct tree *insert(struct tree *root, int d)
{
    if (root == NULL)
    {
        root = create(d);
        printf("Node created\n");
        return root;
    }
    else if (d <= root->data)
    {
        root->left = insert(root->left, d);
    }
    else
    {
        root->right = insert(root->right, d);
    }
    return root;
}
void inorder(struct tree *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        inorder(node->left);
        printf("%d\t", node->data);
        inorder(node->right);
    }
}
void preorder(struct tree *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        printf("%d\t", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}
void postorder(struct tree *node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d\t", node->data);
    }
}
void search(struct tree *node, int d)
{
    if (node == NULL)
    {
        printf("Not found\n");
    }
    int count = 1;
    if (node->data == d)
    {
        printf("FOUND!\nFound at %d\n", count);
    }
    else if (d < node->data)
    {
        search(node->left, d);
        count++;
    }
    else
    {
        search(node->right, d);
        count++;
    }
}
struct tree *insuc(struct tree *t)
{
    struct tree *temp;
    temp = t;
    while (temp != NULL && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
struct tree *delete(struct tree *node, int d)
{
    if (node == NULL)
    {
        printf("Not found\n");
        return NULL;
    }
    else if (d < node->data)
    {
        node->left = delete (node->left, d);
    }
    else if (d > node->data)
    {
        node->right = delete (node->right, d);
    }
    else
    {
        if (node->left == NULL && node->right == NULL)
        {
            free(node);
            return NULL;
        }
        else if (node->left == NULL)
        {
            struct tree *temp;
            temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            struct tree *temp;
            temp = node->left;
            free(node);
            return temp;
        }
        else
        {
            struct tree *temp;
            temp = insuc(node->right);
            node->data = temp->data;
            node->right = delete (root->right, temp->data);
        }
    }
    return node;
}
int main()
{
    int n;
    printf("How many nodes do you want to enter?\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Enter data you want to insert-\n");
        scanf("%d", &data);
        root = insert(root, data);
    }
    int op = 0;
    do
    {
        int ch = 0;
printf("Which operation you want to perform?\n1.Inorder\n2.Preorder\n3.Postorder\n4.Search\n5.Delete\nChoice-");
scanf("%d",&ch);
switch(ch){
        case 1:
            printf("\nInorder->");
            inorder(root);
            break;
        case 2:
            printf("\nPost orfer->");
            postorder(root);
            break;
        case 3:
            printf("\nPreorder->");
            preorder(root);
            break;
        case 4:
            printf("what do you want to search?\n->");
            int se;
            scanf("%d", &se);
            printf("Searching..\n");
            search(root, se);
            break;
        case 5:
            printf("what do you want to delete?\n->");
            int de;
            scanf("%d", &de);
            printf("Deleting..\n");
            root = delete (root, de);
            break;
        default:
            printf("Please enter correct option\n");
 }
 printf("\nDo you want to continue\n1.YES\n2.NO\n");
 scanf("%d",&op);
    } while (op == 1);
    return 0;
}
