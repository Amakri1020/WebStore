#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONTENT_LENGTH getenv("CONTENT_LENGTH")
unsigned int contentlength;
char *postdata = NULL;

int main(void){
	if (CONTENT_LENGTH != NULL) {
		contentlength = atoi(CONTENT_LENGTH);
		if((postdata = malloc(sizeof(char) * contentlength + 1)) != NULL){
			if(((fread(postdata, sizeof(char), contentlength, stdin))) == contentlength){
				postdata[contentlength] = '\0';
				printf("Content-Type:text/html\n\n");
				printf("<html>");
				printf("%s", postdata);
				printf("</html>");
			}
		}
	}
	else{
		printf("Content-Type:text/html\n\n");
		printf("<html>");
		printf("Error!");
		printf("</html>");
	}
	return 0;
}
