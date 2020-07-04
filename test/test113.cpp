#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <atomic>

pthread_t tidReader;
pthread_t tidWriter;

atomic<int> value;

pthread_mutex_t lock;

void Reader(void *arg)
{
	while(1) {
		pthread_mutex_lock(&lock);
		for (i = 0; i<10; i++)
			printf("%d", value.load());
	}
}

void Writer(void *arg)
{
	while(1) {
		pthread_mutex_lock(&lock); 
		int g = value;
		for (i = 0; i<10; i++){
			g += i;
			value.store(g);
		}
		pthread_mutex_unlock(&lock);
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

	err = pthread_create(&(tidReader), NULL, &Reader, NULL);
	err = pthread_create(&(tidWriter), NULL, &Writer, NULL);		

	pthread_join(tidReader, NULL);
	pthread_join(tidWriter, NULL);

	pthread_mutex_destroy(&lock);

	return 0;
}
