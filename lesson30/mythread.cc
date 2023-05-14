#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
using namespace std;


// void* Routine(void* arg)
// {
//     char* msg = (char*)arg;
//     while(1)
//     {
//         printf("我是 %s\n", msg);
//         sleep(1);
//     }
// }
// int main()
// {
//     pthread_t tid;
//     pthread_create(&tid, NULL,Routine, (void*)"thread 1");
//     while(1)
//     {
//         cout << "我是主线程" << endl;
//         sleep(2);
//     }
//     return 0;
// }

// void* Routine(void* arg)
// {
//     char* msg = (char*)arg;
//     while(1)
//     {
//         printf("I am %s...pid: %d, ppid: %d\n", msg, getpid(), getppid());
//         sleep(1);
//     }
// }
// int main()
// {
//     pthread_t tid[5];
//     for(int i = 0;i < 5;i++)
//     {
//         char* buffer = (char*)malloc(64);
//         sprintf(buffer,"thread %d", i);
//         pthread_create(&tid[i], NULL, Routine, buffer);
//         printf("%s ....................tid is %lu\n", buffer, tid[i]);
//     }
//     while(1)
//     {
//         printf("我是主线程 pid : %d , ppid : %d\n",getpid(), getppid());
//         sleep(2);
//     }
// }

// int count = 0;
// void* Routine(void* arg)
// {
//     while(1)
//     {
//         count++;
//         sleep(1);
//     }
//     pthread_exit((void*)0);
// }
// int main()
// {
//     pthread_t tid;
//     pthread_create(&tid, NULL,Routine, NULL);
//     while(1)
//     {
//         printf("count: %d\n",count);
//         sleep(1);
//     }
//     pthread_join(tid,NULL);
//     return 0;
// }
// #include <stdio.h>
// #include <unistd.h>
// #include <pthread.h>

// int tickets = 1000;
// void* TicketGrabbing(void* arg)
// {
// 	const char* name = (char*)arg;
// 	while (1){
// 		if (tickets > 0){
// 			usleep(10000);
// 			printf("[%s] get a ticket, left: %d\n", name, --tickets);
// 		}
// 		else{
// 			break;
// 		}
// 	}
// 	printf("%s quit!\n", name);
// 	pthread_exit((void*)0);
// }
// int main()
// {
// 	pthread_t t1, t2, t3, t4;
// 	pthread_create(&t1, NULL, TicketGrabbing, (void*)"thread 1");
// 	pthread_create(&t2, NULL, TicketGrabbing, (void*)"thread 2");
// 	pthread_create(&t3, NULL, TicketGrabbing, (void*)"thread 3");
// 	pthread_create(&t4, NULL, TicketGrabbing, (void*)"thread 4");
	
// 	pthread_join(t1, NULL);
// 	pthread_join(t2, NULL);
// 	pthread_join(t3, NULL);
// 	pthread_join(t4, NULL);
// 	return 0;
// }

#include <iostream>
#include <cstdio>
#include <pthread.h>
using namespace std;
pthread_mutex_t mutex;
pthread_cond_t cond;
void* Routine(void* arg)
{
	pthread_detach(pthread_self());
	std::cout << (char*)arg << " run..." << std::endl;
	while (true){
		pthread_cond_wait(&cond, &mutex); //阻塞在这里，直到被唤醒
		std::cout << (char*)arg << "活动..." << std::endl;
	}
}
int main()
{
	pthread_t t1, t2, t3;
	pthread_mutex_init(&mutex, nullptr);
	pthread_cond_init(&cond, nullptr);
	
	pthread_create(&t1, nullptr, Routine, (void*)"thread 1");
	pthread_create(&t2, nullptr, Routine, (void*)"thread 2");
	pthread_create(&t3, nullptr, Routine, (void*)"thread 3");
	
	while (true){
		getchar();
		pthread_cond_signal(&cond);
	}

	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
	return 0;
}
