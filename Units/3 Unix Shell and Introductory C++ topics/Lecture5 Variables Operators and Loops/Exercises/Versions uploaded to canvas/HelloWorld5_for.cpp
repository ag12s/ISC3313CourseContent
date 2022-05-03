//This code uses a for loop to print hello world! 5 times

#include <stdio.h>

int main()
{
	//A for loop in c++ has the general syntax 
	//    for(statement 1, statement 2, statement 3).
	//        - Where statement 1 is executed 1 time before anything in
	//          the for loop block (between the {}) is computed.,
	//        - statement 2 defines the stop condition for the block. 
	//	    Here, we want to tell the loop to run this block for every
	//          i that is less than 5. 
	//        - statement 3 is executed every time after the block has been 
	//          executed. i.e. after the block has been executed for the
	//          the first time, the conditional statement (2nd statement) looks
	//          like 1<5. Which is true. This loop coninues until i = 5.
	//          The conditional for i=5 looks like 5<5, which is false.
	// 	    This stops the loop.

	//Let's code the loop, replacing the ?? with values you would expect.
	//Just like for int main() {}, we need to include the opening {
	//and closing }. This is called the for loop code block. The
	//for loop will execute all code in this block.

	for(int i = ??; i<??; i++)
	{
		printf("Hello world!");
	}
}
