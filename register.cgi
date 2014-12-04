#!/usr/local/bin/perl

use CGI;

#test code 
print "Content-type: text/html\r\n\n";
print "<html>";
print "blah\n";
print "</html>";
#test code

my $q = new CGI;

my $name = $q->param( 'name' );
my $user = $q->param( 'username' );
my $pass1 = $q->param( 'password1' );
my $pass2 = $q->param( 'password2' );


#Check two passwords are the same
if ($pass1 ne $pass2){
    #print error
    print "Content-type:text/html\r\n\n";
    ErrorPasswordMismatch();
}

#Open Members.csv
open (MEMBERS, ">>Members.csv") || ErrorOpen();
print MEMBERS "$name, $user, $pass1, $pass2\n";
close (MEMBERS);

sub ErrorPasswordMismatch {
	print "Content-type:text/html\r\n\n";
	print "<html>";
	print "Error: there is a password mismatch.\n";
	print "</html>";
	exit;
}

sub ErrorOpen {
	print "Content-type: text/html\r\n\n";
	print "Error: Can't open database file.\n";
	exit;
}