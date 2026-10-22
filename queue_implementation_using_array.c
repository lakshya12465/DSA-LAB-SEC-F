#include <stdio.h>
#define s 5
int q[s];
int f, r;
f = -1;
r = -1;
void enqueue(int x)
{
if (r == s - 1)
{
printf("Queue is Full\n");
}
else
{
r = r + 1;
q[r] = x;
}
if (f == -1)
{
f = 0;
}
}

int dequeue()
{
if (f == -1 && r == -1)
{
printf("Q is empty\n");
}
else
{
printf("Deleted element is %d\n", q[f]);
f = f + 1;
}
}
void main()
{
enqueue(10);
enqueue(20);
enqueue(30);
enqueue(40);
enqueue(50);
dequeue();
dequeue();
enqueue(25);
}



