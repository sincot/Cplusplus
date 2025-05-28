#include "Stack and Queue.h"

/*
int main()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	//printf("%d ", StackSize(&st));

	/*
	for (size_t i = 0; i < 5; i++)
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	*/

	//StackDestory(&st);
	/*StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	//StackPrint(&st);
	
	return 0;
}
*/

int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 100);
	//printf("%d ", QueueFoot(&q));
	//printf("%d ", QueueSize(&q));
	QueueDestory(&q);

	/*for (size_t i = 0; i < 5; i++)
	{
		printf("%d ", QueueTop(&q));
		QueuePop(&q);
	}*/

	//QueuePop(&q);
	//QueuePrint(&q);

	return 0;
}