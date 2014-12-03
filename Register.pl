#!/usr/bin/perl

use CGI;

my $q = new CGI;

my $name = $q->param( 'name' );
my $username = $q->param( 'username' );
my $pass1 = $q->param( 'password1' );
my $pass2 = $q->param( 'password2' );
