#include <gtest.h>
#include "Polynomial.h"



TEST(TPolyn, can_summ_polynoms) {
	Polynomial p1;
	Polynomial p2;
	
	Monom m1(-2.11, 10100, NULL);
	Monom m2(-22.11, 102100, NULL);
	p1.add_monom_in_tail(&m1);
	p2.add_monom_in_tail(&m2);
	Polynomial res = p1 + p2;
	//Monom m3(-2.11, 1102100, NULL);

	//Nessesery to realize init_const
	ASSERT_NO_THROW(res);
}

TEST(TPolyn, can_add_monom_in_polynom) {
	Monom m1(-2.11, 10100, NULL);
	Monom m2(-22.11, 102100, NULL);
	Polynomial p1;
	p1.add_monom_in_tail(&m1);
	ASSERT_NO_THROW(p1.add_monom_in_tail(&m2));

}

TEST(TPolyn, can_create_polynom) {
	ASSERT_NO_THROW(Polynomial p);
}

TEST(TPolyn, can_mult_on_chisl) {
	Polynomial p;
	Monom m1(-2.11, 10100, NULL);
	Polynomial p1;
	Monom m2(-4.22, 10100, NULL);


	p.add_monom_in_tail(&m1);
	p1.add_monom_in_tail(&m2);
	Polynomial res = p * 2;
		ASSERT_EQ(res, p1);



}



TEST(TPolyn, can_mult_two_polynoms) {
	Polynomial p;
	Monom m1(-2.11, 10100, NULL);
	Polynomial p1;
	Monom m2(-4.22, 10100, NULL);


	p.add_monom_in_tail(&m1);
	p1.add_monom_in_tail(&m2);

	Polynomial res = p * p1;
	Polynomial res1;
	Monom m3(8.9042, 20200, NULL);
	res1.add_monom_in_tail(&m3);
	ASSERT_EQ(res, res1);	
}


TEST(TPolyn, can_substract_two_polynoms) {
	Polynomial p;
	Monom m1(-2.11, 10100, NULL);
	Polynomial p1;
	Monom m2(-2.11, 10100, NULL);
	Polynomial res;


	p.add_monom_in_tail(&m1);
	p1.add_monom_in_tail(&m2);

	ASSERT_EQ(res, p - p1);

}