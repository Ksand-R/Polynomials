#include <gtest.h>
#include "Polynomial.h"

TEST(TMonom, can_add_empty_monom)
{
	Monom m1;
	ASSERT_TRUE(m1.coef == 0.0, m1.deg == 0, m1.next == NULL);
	
	
}


TEST(TMonom, can_add_monom)
{
	Monom m2;
	Monom* ptr = &m2;
	Monom m1(-2.11, 102100, ptr);
	ASSERT_TRUE(m1.coef == -2.11);
	ASSERT_TRUE(m1.deg == 102100);
	ASSERT_TRUE(m1.next == ptr);

}


TEST(TMonom, monom_deg_correct)
{
	EXPECT_ANY_THROW(Monom m1(-2.11, 1102100, NULL));
}


TEST(TPolyn, can_create_polynom) {
	Polynomial p;
	Monom m1(-2.11, 10100, NULL);
	Monom m2(-22.11, 102100, NULL);
	//Monom m3(-2.11, 1102100, NULL);

	//Nessesery to realize init_const
	ADD_FAILURE();
}

TEST(TPolyn, mult_with_chisl) {
	Polynomial p;
	Monom m1(-2.11, 10100, NULL);
	Monom m2(-22.11, 102100, NULL);
	//Monom m3(-2.11, 1102100, NULL);

	//Nessesery to realize init_const
	ADD_FAILURE();
}