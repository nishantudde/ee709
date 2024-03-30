#include <stdlib.h>
#include <stdio.h>
#include <bdduser.h>

int main (int argc, char* argv[])
{
	// Create the universe..
	bdd_manager bddm = bdd_init();	

	// 6 variables x0,x1,x2 (in that order)
	bdd x1 = bdd_new_var_last(bddm);
	bdd x2 = bdd_new_var_last(bddm);
	bdd x3 = bdd_new_var_last(bddm);
	bdd x4 = bdd_new_var_last(bddm);
	bdd x5 = bdd_new_var_last(bddm);
	bdd x6 = bdd_new_var_last(bddm);

	bdd a  = bdd_and (bddm,x1,x2);
	bdd b  = bdd_and (bddm,x3,x4);
	bdd c  = bdd_and (bddm,x5,x6);

	bdd d  = bdd_not (bddm,a);
	bdd e  = bdd_not (bddm,b);
	bdd f  = bdd_not (bddm,c);

	bdd g  = bdd_and (bddm,d,e);
	bdd y  = bdd_and (bddm,g,f);

	
	printf("----------------------------------------------------\n");

	// print y
	bdd_print_bdd(bddm,y,NULL, NULL,NULL, stdout);

	return(0);
}

