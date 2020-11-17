// Not written by me
// Provided by professor Bhanu Kapoor

#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t ntid;

void printids (const char *s) {
	pid_t pid;
	pthread_t tid;
	pid = getpid();
	tid = pthread_self();
	printf("%s pid %lu tid %lu (0x%lx)\n", s, (unsigned long) pid, (unsigned long) tid, (unsigned long) tid);
}

void *thr_fn (void *arg) {
	printids("new thread: ");
	return ((void *)0);
}

int main (void) {
	int err;
	err = pthread_create(&ntid, NULL, thr_fn, NULL);
	if (err != 0)
		printf("%d can't create thread \n", err);
	printids("main thread:");
	sleep(1);
	exit(0);
}