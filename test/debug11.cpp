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
pthread_mutex_t lock1;
pthread_mutex_t lock2;
pthread_mutex_t lock3;
pthread_mutex_t lock4;

void* FirstReader(void *arg)
{
	while(1) {
		
		for (i = 0; i<10; i++)
			printf("%d", g);
		printf("%d\n", g * 2);
		pthread_mutex_unlock(&lock1);
	}
}

void* SecondReader(void *arg)
{
	
	while (1) {
		pthread_mutex_lock(&lock2);
		printf("%d\n", g);
		pthread_mutex_unlock(&lock2);
	}
	
}

void* FirstWriter(void *arg)
{
	while(1) {
		pthread_mutex_lock(&lock3);
		for (i = 0; i<10; i++);
			g += i;
		pthread_mutex_unlock(&lock3);
	}
}

void* SecondWriter(void *arg)
{
	while(1) {
		pthread_mutex_lock(&lock4); 
		for (i = 0; i<10; i++);
			g *= 2;		
		pthread_mutex_unlock(&lock4);
	}
}

int main(void)
{
	int i = 0;
	int err;

	pthread_mutex_init(&lock1, NULL);
	pthread_mutex_init(&lock2, NULL);
	pthread_mutex_init(&lock3, NULL);
	pthread_mutex_init(&lock4, NULL);

	err = pthread_create(&(tidFReader), NULL, &FirstReader, NULL);
	err = pthread_create(&(tidSReader), NULL, &SecondReader, NULL);
	err = pthread_create(&(tidFWriter), NULL, &FirstWriter, NULL);		
	err = pthread_create(&(tidSWriter), NULL, &SecondWriter, NULL);		

	pthread_join(tidFReader, NULL);
	pthread_join(tidSReader, NULL);
	pthread_join(tidFWriter, NULL);
	pthread_join(tidSWriter, NULL);

	pthread_mutex_destroy(&lock1);
	pthread_mutex_destroy(&lock2);
	pthread_mutex_destroy(&lock3);
	pthread_mutex_destroy(&lock4);
	
	return 0;
}
