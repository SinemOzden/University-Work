#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long floatx;

floatx doubleToFloatx(double in ,int totNumBits ,int exponent);

int main(int argc, char **argv) {
	if (argc<3) {
		printf("Please invoke as %s <order_file>\n",argv[0]);
		return 1;
	}
	int totNumBits=atoi(argv[1]);
	
	if(totNumBits<2 || totNumBits>65){
		printf("Total number of bits too big or small");
		return 1;
	}

	int exponent = atoi(argv[2]);

	 if(exponent<0 || exponent>=totNumBits-2){
		printf("Exponent is too big or small");
		return 1;
	}
	while(!feof(stdin)) {
	double in=NAN; // NAN defined in math.h
		if(1==scanf("%lf ",&in)) {
			floatx fx = doubleToFloatx(in,totNumBits,exponent);
			printf("%14.8g = floatx(%d,%d) : %016lx\n",in,totNumBits,exponent,fx);
		}
		else {
			char buf[100];
			scanf("%s ",buf);
			printf("Input : %s not recognized as a double\n",buf);
		}
	}
}
	
floatx doubleToFloatx(double in ,int totNumBits ,int exponent){
	floatx fx = 0;
	totNumBits-=2;
	int pad = 64 - totNumBits;
	int fract = totNumBits - exponent;
	double n = 0;
	int a = 0;
	int bin[64]={0};
	if(in == NAN){//hex for NAN
		fx = 0x7fffffff;
		return fx;
	}
	if(in == 0){return fx;}
	if(in<0.0){//check if signed
		in *= -1;
		bin[pad-1]=1;
	}
	if(in<2.0){ 
		int m = 1;
		double mantis = in;
		while(in*pow(2.0,m)<1){
			mantis=in*pow(2.0,m);
			m++;
		}
		int div = m;
		int ii = 63 - fract;//location of binary number
		while(div!=1){//calculate binary of exponantial
			bin[ii] = div%2;
			div/=2;
			ii--;
		}
		double i =ii;
		double exp = pow(2,m);
		int frac = in/exp;//finding fraction
		while(m<=frac && mantis>0){
			if(mantis - (1/pow(2.0,i))<0){m++;}
			else{
				mantis -= mantis/pow(2.0,i);
				bin[63-frac+m]=1;
				m++;
			}
		}
		for(int j=0; j<=63; j++){//pushing exponantial to fx
		int s=bin[j];
			//fx = fx& (~(1<<(63-j)));
			fx = (fx & (~(1 << (64-j)))) | (s << (64-j));
		
		}	
		return fx;			
	}
	else{//exponent found
		bin[pad]=1;//first one
		while(a==0){//find exponantial of 2
			if(pow(2,n)>=in){
				a=1;
			}else{
			n++;}
		}
		n--;
		int div = n;
		int i = 63 - fract-1;//location of binary number
		while(div!=1){//calculate binary of exponantial
			bin[i] = div%2;
			div/=2;
			i--;
		}
		double exp = pow(2,n);
		double frac = in/exp;//finding fraction

		if(frac == 1){
			for(int j=0; j<=63; j++){//pushing exponantial to fx
				int s=bin[j];
					//fx = fx& (~(1<<(63-j)));
					fx = (fx & (~(1 << (64-j)))) | (s << (64-j));
				
			}
			return fx;
		}
		else{//binary frac hesapla
			frac--;
			int m = 0;
			while(m<=fract && frac>0){
				if(frac - (1/pow(2.0,m))<0.0){m++;}
				else{
					frac -= (1/pow(2.0,m));
					bin[63-fract+m]=1;
					m++;
				}
			}
			for(int j=0; j<=63; j++){//pushing exponantial to fx
				int s=bin[j];
					//fx = fx& (~(1<<(63-j)));
					fx = (fx & (~(1 << (64-j)))) | (s << (64-j));
				
			}
			return fx;
		}
		
	}
}









