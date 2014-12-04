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
	FILE *member = fopen("../Members.csv", "r");
	FILE *loggedIn = fopen("../LoggedIn.csv", "a");

	contentlength = atoi(CONTENT_LENGTH);

	if((postdata = malloc(sizeof(char) * contentlength + 1)) != NULL){
		if(((fread(postdata, sizeof(char), contentlength, stdin))) == contentlength){
			//postdata[contentlength] = '\0';
			id = strtok(postdata,"=");
			id = strtok(NULL,"&");
			password = strtok(NULL,"=");
			password = strtok(NULL,"");
			printf("Content-Type:text/html\n\n");
			printf("<html>");
			printf("<head><link rel=\"stylesheet\" type=\"text/css\" href=\"../webstore.css\"><link href=\"http://fonts.googleapis.com/css?family=Lato&subset=latin,latin-ext\" rel=\"stylesheet\" type=\"text/css\"><link href=\"http://fonts.googleapis.com/css?family=Arvo\" rel=\"stylesheet\" type=\"text/css\"><title>Selling McGill Buildings</title></head><body><h1 style=\"text-align:center\">Selling McGill Buildings</h1><ul id=\"menu\"><li class=\"menu-item\"><a class=\"menu-url\" href=\"../index.html\">Home Page</a></li><li class=\"menu-item\"><a class=\"menu-url\" href=\"../login.html\" target=\"_blank\">Login Page</a></li><li class=\"menu-item\"><a class=\"menu-url\" href=\"../catalogue.html\">Catalogue</a></li></ul><hr><br>");
		}
	}

	while((line=fgets(buffer,sizeof(buffer),member))!=NULL){
		id_Data = strtok(line,",");
		id_Data = strtok(NULL,",");
		password_Data = strtok(NULL,"\n");
	//	printf("%s and %d", id_Data, strlen(password_Data));
	//	printf("WHat?");	
		if(strcmp(id_Data,id) == 0 && strcmp(password_Data,password) == 0){
			printf("<div class=\"current-page\">Catalogue<hr></div><div class=\"catalogue\"><!--	Trottier--><h2 style=\"text-align:left\">Lorne M. Trottier</h2><a href=\"https://www.mcgill.ca/maps/trottier-building\"><img style=\"float: left;border:2px solid black;width:260px;height=355px\" src=\"http://www.imtl.org/image/big/mcGill_Lorne-M.-Trottier.jpg\" alt=\"Trottier building\"></a><p>DecriptionDecriptionDecriptionDecriptionDecriptionDescriptionDecriptionDecriptionDecriptionDecriptionDecriptionDescriptionDecriptionDecriptionDecriptionDecriptionDecriptionDescriptionDecriptionDecriptionDecriptionDecriptionDecriptionDescription</p><form action=\"Purchase.py\" method = \"post\" target=\"_blank\"><input type=\"hidden\" name = \"username\" value=\"%s\"><input style=\"float:right\" type=\"checkbox\" name=\"checkbox1\" value=\"Trottier\"><a href=\"http://www.techwyse.com/blog/wp-content/uploads/2010/09/add-to-cart-button.png\"><img style=\"float:right;width:150px;height:150px\" src=\"http://www.techwyse.com/blog/wp-content/uploads/2010/09/add-to-cart-button.png\"></a><p> Price:  $7,500,000.00 CAD </p>Quantity Desired:<input type=\"text\" name=\"quantity1\" value=\"\"><br><br><br><br><!--	McConnell--><h2 style=\"text-align:left\">McConnell Engineering Building</h2><a href=\"http://www.photonics.ece.mcgill.ca/Plant/dvp_images/McConnellEngineeringBuilding_L.jpg\"><img style=\"float: left;border:2px solid black;width:260px;height=355px\" src=\"http://www.photonics.ece.mcgill.ca/Plant/dvp_images/McConnellEngineeringBuilding_L.jpg\" alt=\"Trottier building\"></a><p>DecriptionDecriptionDecriptionDecriptionDecriptionDescriptionDecriptionDecriptionDecriptionDecriptionDecriptionDescriptionDecriptionDecriptionDecriptionDecriptionDecriptionDescriptionDecriptionDecriptionDecriptionDecriptionDecriptionDescription</p><input style=\"float:right\" type=\"checkbox\" name=\"checkbox2\" value=\"McConnell\"><a href=\"http://www.techwyse.com/blog/wp-content/uploads/2010/09/add-to-cart-button.png\"><img style=\"float:right;width:150px;height:150px\" src=\"http://www.techwyse.com/blog/wp-content/uploads/2010/09/add-to-cart-button.png\"></a><p> Price:  $2,000,000.00 CAD </p>Quantity Desired:<input type=\"text\" name=\"quantity2\" value=\"\"><br><br><br><br><!--	MacDonald--><h2 style=\"text-align:left\">MacDonald Engineering Building</h2><a href=\"http://www.imtl.org/image/big/mcgill.jpg\">",id);
			printf("</body></html>");
			if(fseek(loggedIn,-1,SEEK_CUR)==0){
				fprintf(loggedIn,",%s",id);
			}
			else{
				fprintf(loggedIn,"%s",id);
			}
			fclose(member);
			fclose(loggedIn);
			return 0;	
		}
	}		
	printf("<div class=\"current-page\">Login fail!</div>");
	printf("</body></html>");
	fclose(member);
	fclose(loggedIn);

	return 0;
}
