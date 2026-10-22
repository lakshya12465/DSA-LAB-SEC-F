include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *f, *r;
int dequeue(void)
{
int x = -1;
struct node *p;
if (f == NULL)
{
printf("Queue is empty\n");
}
else
{
p = f;
f = f->next;
if (f == NULL)
{
r = NULL;
}
x = p->data;
free(p);
p = NULL;
}
return x;
}
void enqueue(int y)
{
struct node *new;
new = (struct node *)malloc(sizeof(struct node));
new->data = y;
new->next = NULL;
if (f == NULL)
{
f = new;
r = new;
}
else
{
r->next = new;
r = new;
}
}
void main()
{
enqueue(10);
enqueue(20);
enqueue(30);
printf("%d\n", dequeue());
printf("%d\n", dequeue());
printf("%d\n", dequeue());
}
