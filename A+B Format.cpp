#include<stdio.h>

int main()
{	

	int a,b,c,i,d[10];
 	
 	
	scanf("%d %d",&a,&b);
	c = a + b ;
	if(c<0)
	{
	c=-c;
	b = -1;
	}
	else
	b = 1;
	
		for(i=0;i<10;i++)
		d[i]=10;
			
	
			for(i=0;;i++)
			{d[i] = c % 10;
			c/=10;
			if(c<1)
			break;}
			
			d[i] = d[i] * b;
		
				for(i=0,c=0;i<10;i++)
				if(d[i]!=10)
				c++;
				
					
						b=c%3;
						a=1;
						for(i=c-1,c/=3;i>=0;i--)
						{printf("%d",d[i]);
						
							if(c==0)
							continue;
							
							if(c==1)
								if(a==b)
								printf(",");
								
							if(c==2)
								if(a==b||a==b+3)
								printf(",");
						
							if(c==3)
								if(a==b||a==b+3||a==b+6)
								printf(",");
						
						a++;}
						
						
						
						
		return 0;
}
