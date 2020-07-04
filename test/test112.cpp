#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tidFReader;
pthread_t tidSReader;
pthread_t tidFWriter;
pthread_t tidSWriter;

int g;
pthread_mutex_t lock;

void* FirstReader(void *arg)
{
	while(1) {
		pthread_mutex_lock(&lock);
		for (i = 0; i<10; i++)
			printf("%d", g);
		printf("%d\n", g * 2);
		pthread_mutex_unlock(&lock);
	}
}

void* SecondReader(void *arg)
{
	while (1) {
		pthread_mutex_lock(&lock);
		printf("%d\n", g);
		pthread_mutex_unlock(&lock);
	}
}

void* FirstWriter(void *arg)
{
	while(1) {
		pthread_mutex_lock(&lock);
		for (i = 0; i<10; i++);
			g += i;
		pthread_mutex_unlock(&lock);
	}
}

void* SecondWriter(void *arg)
{
	while(1) {
		pthread_mutex_lock(&lock); //
		for (i = 0; i<10; i++);
			g *= 2;		
	}
}

int main(void)
{
	int i = 0;
	int err;

	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("\n mutex init failed\n");
		return 1;
	}

	err = pthread_create(&(tidFReader), NULL, &FirstReader, NULL);
	err = pthread_create(&(tidSReader), NULL, &SecondReader, NULL);
	err = pthread_create(&(tidFWriter), NULL, &FirstWriter, NULL);		
	err = pthread_create(&(tidSWriter), NULL, &SecondWriter, NULL);		

	pthread_join(tidFReader, NULL);
	pthread_join(tidSReader, NULL);
	pthread_join(tidFWriter, NULL);
	pthread_join(tidSWriter, NULL);

	pthread_mutex_destroy(&lock);

	return 0;
}
