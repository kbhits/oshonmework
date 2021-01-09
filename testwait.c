/*opyright(c) 2020 Ocean University of China. All rights reserved.   *
*This file is create by:                                             *
* **        **             ***********           **            **    *
*  **      **              ***********           **            **    *
*   **    **               **                    **            **    * 
*    **  **                **                    **            **    *
*     ****                 **                    **            **    *
*      **                  ***********           ****************    *
*      **                  ***********           ****************    *
*      **                           **           **            **    *
*      **                           **           **            **    *
*      **                           **           **            **    *
*      **                  ***********           **            **    *
*      **                  ***********           **            **    *
*                                                                    *
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	// to get the return value of "wait()"
        pid_t pid;
        int status, i;
	// print the pid in the son of process
        if (fork() == 0)
        {
                printf ("This is the child process.pid = %d\n", getpid());
                exit(5);
        }
	// work in father of process
        else
        {
                sleep(1);
                printf ("This is the parent process, wait for child...\n");
               	// wait that son of process ends and continue print infomation
		pid = wait(&status);
		// if son of process ends, print it
                printf ("child's pid = %d. exit status = %d\n", pid, i);
        }
}

