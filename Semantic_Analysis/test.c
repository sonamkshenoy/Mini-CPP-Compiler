#include<stdio.h>

int main()
{
	int b= 5,a[1][2][3],c;	
	int temp;
	int d;
	 
	b += 1;					
	c = 2*b+1; 
	
	d = b + c;
	while(d < 10)
	{
		c = c + 1;
		d = d + 1;
	}

	switch(d)
	{
		case 1: temp = 1;
		break;
		
		case 2: temp = 2;
		break;

		default: temp = 3;	
	}

}
