#include <stdlib.h>
#include <stdio.h>
#include <bdduser.h>

int main (int argc, char* argv[])
{
	// Create the universe..
	bdd_manager bddm = bdd_init();	

	// make 8 variables x1, x2, x3, x4, f, c (in that order)
	bdd x1 = bdd_new_var_last(bddm);
	bdd x2= bdd_new_var_last(bddm);
	bdd x3 = bdd_new_var_last(bddm);
	bdd x4 = bdd_new_var_last(bddm);
	
	// compute f for sequential circuit1
	bdd c = bdd_or(bddm, x1, x2);
	bdd f1 = bdd_or(bddm, x3, x4);
	bdd f = bdd_or(bddm, f1, c);
	
	bdd f_1_then = bdd_then(bddm, f);
	bdd f_1_else = bdd_else(bddm, f);
	
  bdd c_1_then = bdd_then(bddm, c);
	bdd c_1_else = bdd_else(bddm, c);
	
	if(c_1_then = bdd_one(bddm)
	{
	    printf("then branch of c is one"\n);
	    bdd fx_op_cx = bdd_or(bddm, f_1_then) ;
	}
	
	
	
	bdd f_1_else_then = bdd_then(bddm, f_1_else);
	bdd f_1_else_else = bdd_else(bddm, f_1_else);
	
  bdd c_1_else_then = bdd_then(bddm, c_1_else);
	bdd c_1_else_else = bdd_else(bddm, c_1_else);
	
		if(c_1_else_else = bdd_zero(bddm)
	{
	    printf(""\n);
	    bdd fx_op_cx = bdd_or(bddm, f_1_then) ;
	}
	
	bdd a1 = bdd_or(bddm, 
	
	bdd op = bdd_or (bddm, f_1_else
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		return (0);
	}
