#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONTENT_LENGTH getenv("CONTENT_LENGTH")
unsigned int contentlength;
char *postdata = NULL;

int main(void){
	char buffer[1024];
	char *id;
	char *password;
	char *realName;
	char *line, *id_Data, *password_Data;
	FILE *member = fopen("Members.csv", "r");
	FILE *loggedIn = fopen("LoggedIn.csv", "a");

	contentlength = atoi(CONTENT_LENGTH);

	if((postdata = malloc(sizeof(char) * contentlength + 1)) != NULL){
		if(((fread(postdata, sizeof(char), contentlength, stdin))) == contentlength){
			postdata[contentlength] = '\0';
			id = strtok(postdata,"=");
			id = strtok(NULL,"&");
			password = strtok(NULL,"=");
			password = strtok(NULL,"");
			printf("Content-Type:text/html\n\n");
			printf("<html>");
			printf("%s and %s", id, password);
			//printf("<br>");
		}
	}

	while((line=fgets(buffer,sizeof(buffer),member))!=NULL){
		id_Data = strtok(line,",");
		id_Data = strtok(NULL,",");
		password_Data = strtok(NULL,"");
		printf("%s and %s", id_Data, password_Data);
		printf("WHat?");	
		if(strcmp(id_Data,id) == 0 && strcmp(password_Data,password) == 0){
			printf("Logged in!");
			printf("</html>");
			return 0;	
   		}
	}
	printf("Login failed");
	printf("</html>");

	return 0;
}
