#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 200
int arr[MAX_SIZE];

typedef struct alfa* alfaptr;

struct alfa {
	long long x;
	alfaptr next;
};
alfaptr rear = NULL, front = NULL;
void push(int x)
{
	alfaptr node;
	node = (alfaptr)malloc(sizeof(struct alfa));
	node->x = x;
	node->next = NULL; // اینجا باید مقدار next را به NULL تنظیم کنیم
	if (!front)
		front = node;
	else {
		rear->next = node;
		rear = node;
	}
}

void pop()
{
	alfaptr node;
	if (!front)
		printf("ERROR1");
	else
	{
		node = front->next;
		front = node;
		free(node); // اینجا باید حافظه مصرفی توسط node را بازگردانید
		// همچنین باید بررسی کنید که آیا front بعد از pop برابر با NULL است یا نه و در صورت برابر بودن باید rear را هم برابر با NULL قرار دهید
		if (front == NULL)
			rear = NULL;
	}
}
void search(int x)
{
	alfaptr node = front;
	int counter = 0;
	while (node)
		if (node->x == x)
			printf("%d", counter);
		else {
			printf("ERROR2");
			//break;
			return; // باید در صورت یافتن مقدار، از حلقه خارج شود
		}
	node = node->next;
}

void rpop() {//pop last element
	alfaptr node = front;
	if (!node) // اگر صف خالی باشد، هیچ کاری انجام نده
		return;
	if (!node->next) // اگر صف تنها یک عنصر داشته باشد
	{
		free(front);
		front = NULL;
		rear = NULL;
	}
	else
	{
		while (node->next->next) // پیدا کردن عنصر قبل از عنصر آخر صف
			node = node->next;
		free(rear);
		rear = node;
		rear->next = NULL;
	}
}

void set()
{
	alfaptr node = front;
	for (int i = 0; i < MAX_SIZE; i++, node = node->next)
	{
		if (node)
			arr[i] = node->x;
		else
			arr[i] = 0; // اگر تعداد عناصر کمتر از MAX_SIZE باشد، باقی خانه‌ها را با صفر پر می‌کنیم.
	}
}

int size()
{
	alfaptr node = front;
//	int count;
	int count = 0; // باید اینجا مقدار اولیه صفر را بدهیم
	while (node)
		count++; node = node->next;
	return count;
}

void show()
{
	if (!front) {
		for (int i = 0; i < MAX_SIZE; i++)
			printf("%d ", arr[i]);
	}
	else
	{
		printf("ERROR3");
	}
}

int average()
{

	alfaptr node = front;
	int sum = 0, count = 0; // باید اینجا مقدارهای اولیه صفر را بدهیم
	while (node) {
		sum += node->x;
		count++;
		node = node->next;
	}
	if (count == 0) // برای جلوگیری از تقسیم بر صفر
		return 0;
	return sum / count;
}

void main()
{
	int cmd;
	long long int x;
	while (true)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case 1://push
			scanf("%lld", &x);
			push(x);
			break;
		case 2://pop
			pop();
			break;
		case 3://rpop
			rpop();
			break;
		case 4://search
			scanf("%lld", &x);
			search(x);
			break;
		case 5://set
			set();
			break;
		case 6://show
			show();
			break;
		case 7://size
			printf("%d", size());
			break;
		case 10:
			exit(0);
		}
	}
}
