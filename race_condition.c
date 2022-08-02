#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


int buf=1;

void* fun1()
{
	int a=buf;
	printf("\nIn fun1 buff = %d\n",a);
	a++;
	printf("After incrementing in fun1 = %d\n",a);
	sleep(1);
	buf=a;
	printf("buf value after incrementing in fun1 = %d\n",buf);
}


void* fun2()
{
	int b=buf;
	printf("\nIn fun2 buff = %d\n",b);
	b--;
	printf("After decrementing in fun2 = %d\n",b);
	sleep(1);
	buf=b;
	printf("buf value after decrementing in fun2 = %d\n",buf);


}


int main()
{
pthread_t t[2];

pthread_create(&t[0],NULL,fun1,NULL);
pthread_create(&t[1],NULL,fun2,NULL);

pthread_join(t[0],NULL);
pthread_join(t[1],NULL);
printf("\nFinal value = %d\n",buf);
return 0;
}

/*
output:

In fun1 buff = 1
After incrementing in fun1 = 2

In fun2 buff = 1
After decrementing in fun2 = 0
buf value after decrementing in fun2 = 0
buf value after incrementing in fun1 = 2

Final value = 2



./a.out 

In fun2 buff = 1
After decrementing in fun2 = 0

In fun1 buff = 1
After incrementing in fun1 = 2
buf value after incrementing in fun1 = 2
buf value after decrementing in fun2 = 0

Final value = 0



 ./a.out 

In fun1 buff = 1
After incrementing in fun1 = 2

In fun2 buff = 1
After decrementing in fun2 = 0
buf value after incrementing in fun1 = 2
buf value after decrementing in fun2 = 0

Final value = 2

*/
