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
#include <sys/types.h>
#include <unistd.h>

int main()
{	
	int pid1, pid2;
	// lock resource in the process of father,
	// avoid that the screen are  grabbed
	lockf(1, 1, 0);
	// the process of father uses the screen
	printf ("Parent process:a\n");
	// if the first process of son fails, it works
	if ((pid1 = fork()) < 0)
	{
		printf ("Chlid1 fail create\n");
		return 1;
	}
	// in the first process of son
	else if (pid1 == 0)
	{	
		// lock the resource in the first process of son
		// avoid that screen are grabbed by the second process of son
		lockf(1, 1, 0);
		printf ("This is child1(pid = %d) process:b\n", getpid());
		// unlock the resource so that other process can use it
		lockf(1, 0, 0);
		return 0;
	}
	// as same as the first process of son
	if ((pid2 = fork()) < 0)
	{
		printf ("Child2 fail create\n");
		return 1;
	}
	// as same as the first process of son
	else if (pid2 == 0)
	{
		lockf(1, 1, 0);
		printf ("This is child2(pid = %d) process:c\n", getpid());
		lockf(1, 0, 0);
		return 0;
	}
}
