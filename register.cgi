#!/usr/bin/perl

use CGI;

# #test code 
# print "Content-type: text/html\n\n";
# print "<html>";
# print "blah\n";
# print "</html>";
# #test code

my $q = new CGI;
my $o = new CGI;

my $name = $q->param( 'name' );
my $user = $q->param( 'username' );
my $pass1 = $q->param( 'password1' );
my $pass2 = $q->param( 'password2' );

$error = 0;

#Check two passwords are the same
if ($pass1 ne $pass2){
    #print error
    ErrorPasswordMismatch();
}

#Open Members.csv
#Check to see if username already exists
open (MEMBEROPEN, "<Members.csv") || ErrorOpen('csv');
@csv = <MEMBEROPEN>;
close (MEMBEROPEN);
foreach $row (@csv) {
	if ($row =~ /,$user,/) {
		ErrorUsernameExists();
	}
}

if ($error == 0) {
	#If tests pass, then write to Members.csv
	open (MEMBERS, ">>Members.csv") || ErrorOpen('csv');
	print MEMBERS "$name,$user,$pass2\n";
	close (MEMBERS);
}

print "Content-type:text/html\n\n";

print $o->start_html( -title => "Selling McGill Buildings", -style=>{'src'=>'webstore.css'});

open (REDIRECT, "<login.html") || ErrorOpen('login.html');
@contents = <REDIRECT>;
close (REDIRECT);

foreach $line (@contents) {
	if (($line =~ /Login/)&&($line !~ /Login Page/)) {
		if ($error == 0) {
			print "Success! Login using your new username and password";
		}
		else {
			print "<font color=\"red\">$error_message</font>";
		}
	}
	else {
		print "\n $line";
	}
}

# print $o->end_html;

sub ErrorPasswordMismatch {
	# print "Content-type:text/html\n\n";
	# print "<html>";
	# print "Error: there is a password mismatch.\n";
	# print "</html>";
	# exit;
	$error = 1;
	$error_message = "Error: there is a password mismatch.\n";
}

sub ErrorOpen {
	print "Content-type: text/html\n\n";
	print "<html>";
	print "Error: Can't open $_[0] file.\n";
	print "</html>";
	exit;
}

sub ErrorUsernameExists {
	# print "Content-type: text/html\n\n";
	# print "<html>";
	# print "Error: Username already exists. Please pick a different username.\n";
	# print "</html>";
	# exit;
	$error = 1;
	$error_message = "Sorry, username already exists. Please try a different username.\n";
}