/*********************************************************************
*Copyright(c) 2020 Ocean University of China. All rights reserved.   *
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
	//in order to output clealy,ignore it!
	printf ("I am father!\n");
	//if return < 0, it  means creating son of process fails
	if ((pid1 = fork()) < 0)
	{
		printf ("Child1 fail create!\n");
		return 1;
	}
	//if return 0, it means creating son of process succeeds
	else if (pid1 == 0)
	{
		printf ("I am son!\n");
		return 0;
	}
	else if (pid1 > 0)
	{
		printf ("father works 1111!\n");
	}
	// as same as pid1
	if ((pid2 = fork()) < 0)
	{
		printf ("child2 fail create!\n");
		return 1;
	}
	// as same as pid1
	else if (pid2 == 0)
	{
		printf ("I am daughter!\n");
		return 0;
	}
	// as same as pid1
	else if (pid2 > 0)
	{
		printf ("father works 2222!\n");
	}
}
