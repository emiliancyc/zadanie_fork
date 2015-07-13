#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
//#include <sys/types.h>

void *funkcja(void* unused){
	printf("Start funkcji z watku\n");
	pid_t child_pid, parent_pid;
	if(child_pid=fork()){
		//child_pid=getpid();

		printf("Jestem rodzicem procesu %d! Moje PID to %d\n", (int)child_pid, (int)getpid());
		//wait(3);
		//return 0;
	}
	else
	{
		child_pid=getpid();
		parent_pid=getppid();
		printf("Jestem %d, a moj rodzic to %d\n", (int)child_pid, (int)parent_pid);
	}
	//return 0;
}


int main(int argc, const char *argv[])
{
	//const char* name = "Roman";

	//struct person* p = create(0);
	//p->set_name(p->pd, name);
	//printf("Person name: %s\n", p->get_name(p->pd));
	//destroy(p);


	printf("Hello\n");
	//pthread_t threads[2];
	pthread_t thread_id;
	int wynik;
	pthread_create(&thread_id, NULL, &funkcja, NULL );
    pthread_join(thread_id, (void*)&wynik);
    printf("Watek zwrocil: %d\n", wynik);


	return 0;
}
