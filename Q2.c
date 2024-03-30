#include <stdlib.h>
#include <stdio.h>
#include <bdduser.h>

int main (int argc, char* argv[])
{
	// Create the universe..
	bdd_manager bddm = bdd_init();	

	// make 4 variables u3,u2,u1,u0 (in that order)
	bdd u3 = bdd_new_var_last(bddm);
	bdd u2 = bdd_new_var_last(bddm);
	bdd u1 = bdd_new_var_last(bddm);
	bdd u0 = bdd_new_var_last(bddm);
	
	// not of u3,u2,u1,u0
	bdd u3_not = bdd_not (bddm, u3);
	bdd u2_not = bdd_not (bddm, u2);
	bdd u1_not = bdd_not (bddm, u1);
	bdd u0_not = bdd_not (bddm, u0);
	
	bdd w0 = bdd_and (bddm, u3_not, u2_not);
	bdd w1 = bdd_and (bddm, u1_not, u0);
	bdd w = bdd_and (bddm, w0, w1);
	
	bdd x0 = bdd_and (bddm, u3_not, u2_not);
	bdd x1 = bdd_and (bddm, u0_not, u1);
	bdd x = bdd_and (bddm, x0, x1);
	
	bdd y0 = bdd_and (bddm, u1_not, u0_not);
	bdd y1 = bdd_and (bddm, u3_not, u2);
	bdd y = bdd_and (bddm, y0, y1);
	
	bdd z0 = bdd_and (bddm, u1_not, u0_not);
	bdd z1 = bdd_and (bddm, u2_not, u3);
	bdd z = bdd_and (bddm, z0, z1);
	
	bdd e1 = bdd_or (bddm, w, x);
	bdd e2 = bdd_or (bddm, y, z);
	bdd e_spec = bdd_or (bddm, e1, e2);
	
	bdd c1_spec = bdd_or (bddm, y,z);
        bdd c0_spec = bdd_or (bddm, z,x);
	
	bdd e3 = bdd_or(bddm, u3, u2);
	bdd e4 = bdd_or(bddm, u1, u0);
	bdd e_imp = bdd_or(bddm, e3, e4);
	
	bdd c0_imp = bdd_or(bddm, u3, u1);
	bdd c1_imp = bdd_or(bddm, u3, u2);
  
        bdd e_check =  bdd_xnor(bddm, e_spec, e_imp);
        bdd c0_check =  bdd_xnor(bddm, c0_spec, c0_imp);
        bdd c1_check =  bdd_xnor(bddm, c1_spec, c1_imp);

 // starting of check 
 printf("----------------e_check-----------------\n"); 
 bdd_print_bdd(bddm,e_check,NULL, NULL,NULL, stdout);

 printf("----------------c1_check----------------\n");
 bdd_print_bdd(bddm,c1_check,NULL, NULL,NULL, stdout);

 printf("----------------c0_check-----------------\n");
 bdd_print_bdd(bddm,c0_check,NULL, NULL,NULL, stdout);
  
  bdd t1 = bdd_and(bddm, u3, u2);
  bdd t2 = bdd_and(bddm, u1, u0);
  bdd t3 = bdd_and(bddm, u2, u0);
  bdd t4 = bdd_and(bddm, u3, u0);
  bdd t5 = bdd_and(bddm, u2, u1);
  bdd t6 = bdd_and(bddm, u3, u1);
  
  bdd t7 = bdd_or(bddm, t1, t2);
  bdd t8 = bdd_or(bddm, t3, t4);
  bdd t9 = bdd_or(bddm, t5, t6);
  bdd t10 = bdd_or(bddm, t7, t8);
  bdd t = bdd_or(bddm, t9, t10); 
  
  bdd e = bdd_or(bddm, t, e_check);
  bdd c0 = bdd_or(bddm, t, c0_check);
  bdd c1 = bdd_or(bddm, t, c1_check);
  
  bdd M1 = bdd_and(bddm, e, c0);
  bdd Y_out = bdd_and(bddm, M1, c1);
  
  if(e == bdd_one(bddm))
  {
    printf("e_imp is equal to e_spec\n");
  }
  else
  {
    printf("e_imp is not equal to e_spec\n");
  }
  
    if(c0 == bdd_one(bddm))
  {
    printf("c0_imp is equal to c0_spec\n");
  }
  else
  {
    printf("c0_imp is not equal to c0_specp\n");
  }
  
    if(c1 == bdd_one(bddm))
  {
    printf("c1_imp is equal to c1_spec\n");
  }
  else
  {
    printf("c1_imp is not equal to c1_spec\n");
  }
  
  if(Y_out == bdd_one(bddm))
  {
    printf("---DONE---\n");
    bdd_print_bdd(bddm,Y_out,NULL, NULL,NULL, stdout);
  }
  else 
  {
    printf("---NOT DONE---\n");
  }
	
return (0);
}

