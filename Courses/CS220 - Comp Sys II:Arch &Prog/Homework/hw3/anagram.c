#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int minFact(int factor);

int main (int argc, char **argv){
	if(argc < 3){
		printf("Please invoke as %s str1, str2 \n",argv[0]);
		return 1;
	}
	
	int counter1=0;
	int counter2=0;

	int lstr1 = strlen(argv[1]);
	int lstr2 = strlen(argv[2]);

	char str1[lstr1];
	char str2[lstr2];

	strcpy(str1,argv[1]);
	strcpy(str2,argv[2]);

	for(int i = 0; i<lstr1; i++){
		if(str1[i] != '_'){
			counter1 +=tolower(str1[i]);
		}
	}
	for(int i = 0; i<lstr2; i++){
		if(str2[i] != '_'){
			counter2 +=tolower(str2[i]);		
		}
	}
	if(counter1 != counter2){
		printf("%s and %s ARE NOT anagram \n",str1,str2);
		return 1;
	}
	else{
		printf("%s and %s ARE anagram \n",str1,str2);
		return 0;
	}
}
