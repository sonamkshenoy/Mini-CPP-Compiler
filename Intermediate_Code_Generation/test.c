#include<stdio.h>

int main()
{
	int a, b, c, d,e;
	int temp,s;
	s = 1;
	temp = 0;
	int i = 0;
	a = 10;
	b = a;
	c = b;
	s = 10*20*30;
	d = a*b + c;
	e = a*b + temp;
	while(i<c)
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
