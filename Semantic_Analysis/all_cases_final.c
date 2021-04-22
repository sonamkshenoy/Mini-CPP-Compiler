#include<stdio.h>

int main()
{

	int b= 5,a[1][2][3],c;	
	
	int d;
	 
	b += 1;					
	c = 2*b+1; 
	
	d = b + c;
	while(d < 10)
	{
		c = c + 1;
		d = d + 1;
	}
	
	switch(b)
	{
		case 1:	c = b + d; c = b - d; break;
		case 2:	switch(d)				
			{
				case 1: c = 2;break;
				case 5:	c +=2;break;
				case 4: c-=2;break;
				default: c--;break;
			}
			break;
		default: c++;

	}
	

}


