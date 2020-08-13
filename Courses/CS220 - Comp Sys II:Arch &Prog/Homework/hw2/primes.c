#include <stdio.h>
#include <stdlib.h>

int minFact(int factor);

int main (int argc, char **argv){
	if(argc < 2){
		printf("Please invoke as %s num1 \n",argv[0]);
		return 1;
	}
	int user, result;

	user = atoi(argv[1]);
	if(user<=0){
		printf("Error, too small.");
		return 1;
	}
	printf("%d = ", user);
	while(user>1){
		result = minFact(user);
		user = user/result;
		if(user != 1){printf("%d X ", result);}
		else{printf("%d", result);}	
	}
	printf("\n");
	return 0;
}

int minFact(int factor){
	for(int i=2; i<factor; i++){
		if(factor%i==0){
			return i;
		}
	}
	return factor;
}
