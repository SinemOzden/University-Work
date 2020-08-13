#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *strcatm(char *dest, const char *src);
char *strcatp(char *dest, const char *src);

int main (int argc, char **argv){
	if(argc < 3){
		printf("Please invoke as %s str1, str2 \n",argv[0]);
		return 1;
	}

	char array[127];
	int lstr = strlen(argv[1]);
	strcpy(array, argv[1]);
	array[lstr] = '\0';
	strcatm(array, argv[2]);
	strcpy(array, argv[1]);
	strcatp(array, argv[2]);
	printf("strcat matrix form yields: %s \n",array);
	printf("strcat pointer form yields: %s \n",array);
	return 0;
}

char *strcatm(char *dest, const char *src){
	int h = strlen(dest) + strlen(src);
	int k=0;
	int j=0;
	while(dest[k]!='\0'){
		k++;
	}
	for(int i=k;i<strlen(src);i++){
		dest[i]=src[j];
		j++;
	}
	dest[h] = '\0';
	return dest;
}
char *strcatp(char *dest, const char *src){
	if(NULL != src && NULL != dest){
		while('\0' != *dest){
			dest = dest + 1;
		}
		while('\0' != *src){
			*dest = *src;
			src = src + 1;
			dest = dest + 1;
		}
		dest='\0';
	}
	return dest;
}
