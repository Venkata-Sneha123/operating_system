#include<stdio.h>
#include<pthread.h>


pthread_mutex_t mutex;
int n=0;


void *even(void *ptr)
{
	pthread_mutex_lock(&mutex);
	while(n<=100)
	{
		if(n%2==0)
		{
			printf("%d ",n);
			n++;
		}
		else
			pthread_mutex_unlock(&mutex);
	}
}


void *odd(void *ptr)
{
	pthread_mutex_lock(&mutex);
	while(n<=100)
	{
		if(n%2!=0)
		{
			printf("%d ",n);
			n++;
		}
		else
			pthread_mutex_unlock(&mutex);
	}
}


int main()
{
	pthread_t new_thread[2];
	pthread_create(&new_thread[0],NULL,odd,NULL);
	pthread_create(&new_thread[1],NULL,even,NULL);

	pthread_join(new_thread[0],NULL);
	pthread_join(new_thread[1],NULL);
	printf("\n");
	return 0;
}
