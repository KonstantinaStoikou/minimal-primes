/*File: minprimes.c  ergasia#1*/
#include <stdio.h>
#define MAXNUMB 100000000

int main(void){
	int i,x=11,flag1,b,num,k,y,mask,digits,max,flag3,a,flag2,flag4,flag5,flag6;
	while(x <= MAXNUMB){
		flag4 = 1;
		flag5 = 1;
		flag6 = 1;
		i=3;
		if(x%10 == 1 || x%10 == 9) flag1 = 1; //if x ends in 2,3,5 or 7 then one subsequence will be prime.If it ends in 0,4,6 or 8 then x is divided by 2 which means x is not a prime
		else flag1 = 0;
		while(i*i<= x && flag1 == 1){
			if (x%i == 0) flag1 = 0;
			i+=2;
		}
		if (flag1 == 1){
		    flag3=1;
			num=x;
			digits=0;
			max=1;
			while ( num != 0 ) {
				num /= 10;
				if (num%10 == 2 || num%10 == 3 || num%10 == 5 || num%10 == 7) flag6 = 0;
				digits++;
			}
			if (digits == 7){
					if (x/1000000 == 2 || x/1000000 == 3 || x/1000000 == 5 || x/1000000 == 7) flag4 = 0;
			}
			else if (digits == 8){
					if (x/10000000 == 2 || x/10000000 == 3 || x/10000000 == 5 || x/10000000 == 7) flag5 = 0;

			}
			for ( b = 1; b <= digits; b++ ) {
				max *= 2;
			}
			b=1;
			while(b < max-1 && flag3 == 1 && flag6 == 1){
				flag2=1;
				mask = b;
				k = 1;
				num = x;
				y=0;
				while ( num != 0) {
					if ( mask % 2 == 1 ) {
						y += num % 10 * k;
						k *= 10;
					}
					num /= 10;
					mask /= 2;

				}
				b++;
				a=2;
				while((a*a <= y || y == 1 || y == 0) && flag2 == 1){
					if(y%a == 0 || y == 1 || y == 0) flag2 = 0;
					a++;
				}
		    	if(flag2 == 0)
					flag3 = 1;
				else
					flag3 = 0;
			}
			if (flag6 == 0) flag3 = 0;
			if (flag3 == 1) printf("%d\n",x);
 		}
 		if (flag4 == 0) x+=1000000;       //for example if program reaches number 7000000 it continues with number 8000000 because subsequence 7 will be a prime
 		else if (flag5 == 0) x+=10000000;
		else x+=2;
    }
	return 0;
}
