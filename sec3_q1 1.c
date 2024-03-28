#include <stdlib.h>
#include <stdio.h>
#include <bdduser.h>
int main (int argc, char* argv[])
{
	// Create the universe..
	bdd_manager bddm = bdd_init();	

	// make 8 variables s0, s1, s2, s3, t0, t1, x, r (in that order)
	bdd s0 = bdd_new_var_last(bddm);
	bdd s1 = bdd_new_var_last(bddm);
	bdd s2= bdd_new_var_last(bddm);
	bdd s3 = bdd_new_var_last(bddm);
	bdd t0 = bdd_new_var_last(bddm);
 	bdd t1 = bdd_new_var_last(bddm);
	bdd x = bdd_new_var_last(bddm);
	bdd r = bdd_new_var_last(bddm);

  bdd s3_not = bdd_not (bddm, s3);
	bdd s2_not = bdd_not (bddm, s2);
	bdd s1_not = bdd_not (bddm, s1);
//	bdd s0_not = bdd_not (bddm, s0);	
//	bdd t1_not = bdd_not (bddm, t1);
//	bdd t0_not = bdd_not (bddm, t0);
	bdd r_not = bdd_not (bddm, r);
	bdd x_not = bdd_not (bddm, x);
	
	// compute output y1 for sequential circuit1
	bdd y1  = bdd_and (bddm, r_not, x);
	bdd y2  = bdd_and (bddm, y1, s3);	
  bdd y3  = bdd_and (bddm, r_not, x_not);
  bdd y4  = bdd_and (bddm, y3, s1);
  bdd y_seq_1  = bdd_or (bddm, y2, y4);
  
  // compute output y2 for sequential circuit1
	bdd y5  = bdd_and (bddm, r_not, x);
	bdd y6 = bdd_xnor (bddm, t0, t1);
	bdd y7  = bdd_and (bddm, y5, y6);	
  bdd y8  = bdd_and (bddm, r_not, x_not);
	bdd y9 = bdd_xor (bddm, t0, t1);
  bdd y10  = bdd_and (bddm, y8, y9);	
  bdd y_seq_2  = bdd_or (bddm, y7, y10);
  
	// compute state1
	bdd st1 = bdd_and (bddm, s3_not, s2_not);
	bdd st2 = bdd_and (bddm, s1_not, s0);
  bdd state1 = bdd_and (bddm, st1, st2);
	
	bdd y1_state = bdd_and (bddm, y_seq_1, state1);
	bdd y2_state = bdd_and (bddm, y_seq_2, state1);

	printf("----------------------------------------------------\n");

	// print y
	//bdd_print_bdd(bddm,y,NULL, NULL,NULL, stdout);
 bdd z = bdd_xor(bddm, y1_state, y2_state);
 bdd_print_bdd(bddm,z,NULL, NULL,NULL, stdout);

	//check that whether y1_state and y2_state are same or not?
	if (y1_state == y2_state)
	{
		printf("Both the machines are same\n");
	}	
	else
	{
		printf("Both the machines are not same\n");
	}
	return (0);
	}
