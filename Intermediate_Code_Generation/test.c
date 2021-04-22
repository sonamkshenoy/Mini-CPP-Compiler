#include<stdio.h>

int main()
{
	int a, b, c, d;
	int temp;
	int i = 0;
	a = 10;
	b = 20;
	c = a*b;
	d = a + c;
	while(i<b)
	{
		d = d + 1;
		i = i + 1;
	}

	switch(a)
	{
		case 1: temp = 1;
		break;
		
		case 2: temp = 2;
		break;

		default: temp = 3;	
	}

}
