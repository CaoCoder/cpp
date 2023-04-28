#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main()
{
  pid_t id = fork();
  if(id == 0)
  {
      //孩子
      while(1)
      {
        printf("我是子进程,我正在运行......pid: %d\n",getpid());
        sleep(1);
      }
  }
  else{
        printf("我是父进程：pid : %d 我准备等待子进程了\n", getpid());
       sleep(20);
        pid_t  ret = wait(NULL);
        
        if(ret <0)
        {
          printf("等待失败\n");
        }
        else{
          printf("等待成功: result:%d\n",ret);
        }
        sleep(20);
  }
}
