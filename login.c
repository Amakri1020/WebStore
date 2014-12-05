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
		if(strcmp(id_Data,id) == 0 && strcmp(password_Data,password) == 0){
			printf("<div class=\"current-page\">Catalogue<hr><br></div><form action=\"Purchase.py\" method = \"post\" target=\"_blank\"><!--	Trottier--><div class=\"catalogue-item\"><h2 style=\"text-align:center\">Lorne M. Trottier</h2><br><img style=\"border:2px solid black\" src=\"http://www.imtl.org/image/big/mcGill_Lorne-M.-Trottier.jpg\" alt=\"Trottier building\" id=\"circle\"><p class=\"cat-text\">Inaugurated in 2004, this building was named after Lorne Trottier, winner of the Prix Lionel-Boulet for leadership in scientific advancement, who donated $10 million towards the its construction. It is a recent addition to McGill's Tech Square (and could soon be yours!).</p><input type=\"hidden\" name = \"username\" value=\"%s\"><p> Price:  $7,500,000.00 CAD </p><p> Quantity Desired:<input type=\"text\" name=\"input_quantity0\" value=\"\"></p><img style=\"float:right; width: 30%; height: 30%\" src=\"http://www.wp-handyhints.com/wp-content/gallery/add-to-cart-buttons/add_1_1_grey.png\"><br><input style=\"float:right\" type=\"checkbox\" name=\"checkbox0\" value=\"Trottier\"><br><br><br><br></div><br><br><!--	McConnell--><div class=\"catalogue-item\"><h2 style=\"text-align:center\">McConnell Engineering Building</h2><br><img style=\"border:2px solid black\" src=\"http://www.photonics.ece.mcgill.ca/Plant/dvp_images/McConnellEngineeringBuilding_L.jpg\" alt=\"McConnell\" id=\"circle\"><p>The construction of the McConnell Engineering Building in 1959 doubled the space available to the Faculty of Engineering, which had greatly expanded in the years following World War II. The building, named after John W. McConnell, provides a connection to the other Engineering buildings, creating a complete, joined circuit for the Faculty and its schools.</p><p> Price:  $2,000,000.00 CAD </p><p> Quantity Desired: <input type=\"text\" name=\"input_quantity1\" value=\"\"></p><img style=\"float:right; width: 30%; height: 30%\" src=\"http://www.wp-handyhints.com/wp-content/gallery/add-to-cart-buttons/add_1_1_grey.png\"><br><input style=\"float:right\" type=\"checkbox\" name=\"checkbox2\" value=\"McConnell\"><br><br><br><br></div><br><!-- MacDonald --><div class=\"catalogue-item\"><h2 style=\"text-align:center\">MacDonald Engineering Building</h2><br><img style=\"border:2px solid black\" src=\"http://www.imtl.org/image/big/mcgill.jpg\" alt=\"MacDonald\" id=\"circle\"><p class=\"cat-text\">After the original Macdonald Engineering Building was gutted by fire in 1907, the current building was constructed with function and safety taking precedence over design. One focal design feature was included, however: a phoenix rising from the ashes was carved on the south wall as a reminder of the fire and a symbol of rebirth.</p><p> Price:  $1,000,000.00 CAD </p><p> Quantity Desired:<input type=\"text\" name=\"input_quantity2\" value=\"\"></p><img style=\"float:right; width: 30%; height: 30%\" src=\"http://www.wp-handyhints.com/wp-content/gallery/add-to-cart-buttons/add_1_1_grey.png\"><br><input style=\"float:right\" type=\"checkbox\" name=\"checkbox3\" value=\"MacDonald\"><br><br><br><br></div><br><br><!-- Leacock --><div class=\"catalogue-item\"><h2 style=\"text-align:center\">Leacock</h2><br><img style=\"border:2px solid black\" src=\"http://www.archives.mcgill.ca/pictures/pr015176.gif\" alt=\"Leacock\" id=\"circle\"><p class=\"cat-text\">Constructed in 1965, this building was named after Stephen Leacock, a professor of economics at McGill and a well-known Canadian humorist and author. A plaque on the wall of the Leacock building commemorates the observatory that once stood on the site. A glass-walled corridor connects the Leacock Building to the Arts Building.</p><p> Price:  $250,000.00 CAD </p><p> Quantity Desired:<input type=\"text\" name=\"input_quantity3\" value=\"\"></p><img style=\"float:right; width: 30%; height: 30%\" src=\"http://www.wp-handyhints.com/wp-content/gallery/add-to-cart-buttons/add_1_1_grey.png\"><br><input style=\"float:right\" type=\"checkbox\" name=\"checkbox4\" value=\"Leacock\"><br><br><br><br></div><br><br><!-- McIntyre --><div class=\"catalogue-item\"><h2 style=\"text-align:center\">McIntyre Medical Building</h2><br><img style=\"border:2px solid black\" src=\"http://www.imtl.org/image/big/McIntyre_Medical_Sciences.jpg\" alt=\"McIntyre\" id=\"circle\"><p class=\"cat-text\">Built in 1965, the McIntyre Medical Building is easily recognizable due to its circular shape. It has a connecting bridge to the Stewart Biology Building and a link to the Life Sciences Complex.</p><p> Price:  $45,000.00 CAD </p><p> Quantity Desired:<input type=\"text\" name=\"input_quantity4\" value=\"\"></p><img style=\"float:right; width: 30%; height: 30%\" src=\"http://www.wp-handyhints.com/wp-content/gallery/add-to-cart-buttons/add_1_1_grey.png\"><br><input style=\"float:right\" type=\"checkbox\" name=\"checkbox5\" value=\"McIntyre\"><br><br><br><br></div><br><br><div style = \"text-align:center\"><input type = \"submit\" style = \"color:black; width:150px;height:50px; font-family: 'Arvo',serif; font-size: 1.2em\" value = \"Checkout!\"></div></form></div><br><br>",id);
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
