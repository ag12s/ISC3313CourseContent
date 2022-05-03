//This code prints "Hello World! 5 times using a while loop

#include <stdio.h>

int main()
{
	//The first thing we need to do is initialize and define 
	//our counter variable i.
	//I am calling it a counter variable because we are counting 
	//how many times we loop over the printf statement.
	int i = 0;
	//Now we are going to start our while loop. 
	//The following line says while i is less than 5, I will
	//continue to loop over the printf statement. When i is 
	//not less than 5, I will stop the loop.
	while(i<5)
	//Just like the int main() {} we need to add an opening
	//{ and a closing }. The while loop will execute everything
	//between them.
	{
		printf("Hello World!");
		//The following line translates to adding 1 to the
		//current value of i. So, i = i+1. This updates at the 
		//end of every loop and the new i is passed into the 
		//while() statement. i.e. after the first loop is 
		//completed, the while loop condition would look 
		//like while(1<5). The second while(2<5), 3rd 
		//while(3<5), 4th while(4<5). These are all true so the 
		//loop continues. However, when i=5, while(5<5) is now 
		//false and the loop breaks.
		i++;
	}
}
