Login:
	gcc -o cgi-bin/login.cgi login.c
	chmod 755 cgi-bin/login.cgi
Permission:
	chmod 755 *
	chmod 755 cgi-bin/*
Clean:
	rm cgi-bin/login.cgi
