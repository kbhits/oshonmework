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
	printf ("I am father!\n");
	//if return < 0, it means son of process fails
	if ((pid1 = fork()) < 0)
	{
		printf ("Child1 fail create!\n");
		return 1;
	}
	//if return 0, it means success in son of process
	else if (pid1 == 0)
	{
		//if return < 0, it means grandson of process fails
		if ((pid2 = fork()) < 0)
		{
			printf ("c fail create!\n");
			return 1;
		}
		//if return 0, it means success in grandson of process
		else if (pid2 == 0)
		{
			printf ("c\n");
			return 0;
		}
		//if return > 0, it means success in son of process
		else
		{
			printf ("I am son!\n");
			return 0;
		}
	}	
}
