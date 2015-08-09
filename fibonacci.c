/*
	高效的斐波那契算法
*/
#include <stdio.h>
#include <stdlib.h>
int Fibonacci(int N){
	int i,last,nexttolast,result;
	if(N<=1) return 1;
	last=nexttolast=1;
	for(i=2;i<=N;i++){
		result=last+nexttolast;
		nexttolast=last;
		last=result;
	}
	return result;
}
int main()
{
	int a=4;
	printf("%d\n",Fibonacci(a));
	return 0;
}