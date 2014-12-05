#include <stdio.h>
#include <string.h>



int main(){
	char buff[1024];      // the input line
	char newbuff[1024];   // the results of any editing
	char doubleQuote[] = "\"";
	char hiddenField[] = "<input type=\"hidden\" name = \"username\" value=\"\">";
	char id[] = "sm";	//sample username
	FILE *in, *out;

	in = fopen("catalogue.html", "r");
	out = fopen("new.html","w");

	while (fgets(buff, 1024, in) != NULL) {
		if (strstr(buff, doubleQuote) != NULL) {
			// do the replacement for the double quote to be recognizable
			strcpy(newbuff, "\"");
		}
		if (strstr(buff, hiddenField) != NULL) {
			// fill the username into the hidden field
			char temp[] = "<input type=\"hidden\" name = \"username\" value=\"";
			strcat(temp, id);
			strcat(temp, "\">");
			strcpy(newbuff, temp);
		}
		else {
			// nothing to do - the input line is the output line
			strcpy(newbuff, buff);
		}
		fputs(newbuff, out);
		fputs(newbuff, stdout);
	}

	fclose(in);
	fclose(out);
	getchar();
	getchar();
	return 0;
}