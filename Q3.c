#include <stdlib.h>
#include <stdio.h>
#include <bdduser.h>
int main (int argc, char* argv[])
{
	// Create the universe..
	bdd_manager bddm = bdd_init();	

	// variables s3, s2, s1, s0, t1, t0, x, r 
	bdd s3 = bdd_new_var_last(bddm);
	bdd s2 = bdd_new_var_last(bddm);
	bdd s1 = bdd_new_var_last(bddm);
	bdd s0 = bdd_new_var_last(bddm);
	bdd t1 = bdd_new_var_last(bddm);
 	bdd t0 = bdd_new_var_last(bddm);
	bdd x = bdd_new_var_last(bddm);
	bdd r = bdd_new_var_last(bddm);

       //  NOT of these which we required
        bdd s3_not = bdd_not (bddm, s3);
	bdd s2_not = bdd_not (bddm, s2);
	bdd s1_not = bdd_not (bddm, s1);
	bdd r_not = bdd_not (bddm, r);
	bdd x_not = bdd_not (bddm, x);
	
       // for sequential circuit 1
	bdd a1  = bdd_and (bddm, r_not, x);
	bdd a2  = bdd_and (bddm, a1, s3);	
        bdd a3  = bdd_and (bddm, r_not, x_not);
        bdd a4  = bdd_and (bddm, a3, s1);
        bdd y_seq_1  = bdd_or (bddm, a2, a4);
  
       // for sequential circuit 2
	bdd b1  = bdd_and (bddm, r_not, x);
	bdd b2 = bdd_xnor (bddm, t0, t1);
	bdd b3  = bdd_and (bddm, b1, b2);	
        bdd b4  = bdd_and (bddm, r_not, x_not);
	bdd b5 = bdd_xor (bddm, t0, t1);
        bdd b6  = bdd_and (bddm, b4, b5);	
        bdd y_seq_2  = bdd_or (bddm, b3, b6);
  
	// state
	bdd st_1 = bdd_and (bddm, s3_not, s2_not);
	bdd st_2 = bdd_and (bddm, s1_not, s0);
        bdd state1 = bdd_and (bddm, st_1, st_2);

	// output of both machines with state
	bdd y1 = bdd_and (bddm, y_seq_1, state1);
	bdd y2 = bdd_and (bddm, y_seq_2, state1);

	printf("----------------------------------------------------\n");

	// print 
         bdd z = bdd_xor(bddm, y1, y2);   // final output
         bdd_print_bdd(bddm,z,NULL, NULL,NULL, stdout);

	//y1 and y2 are same or not 
	if (y1 == y2)
	{
		printf("BDD of both machines are EQUAL\n");
	}	
	else
	{
		printf("BDD of both machines are NOT EQUAL\n");
	}
	return (0);
	}
