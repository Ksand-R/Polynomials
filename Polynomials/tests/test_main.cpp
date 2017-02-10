#include <gtest.h>
#include "Polynomial.h"

int main(int argc, char **argv) {/*::testing::InitGoogleTest(&argc, argv);*/

	Polynomial m1;
	m1.Input_poly();

	Polynomial m2;
	m2.Input_poly();
	
	Polynomial m3;
	m3 = m1 * m2;
	m3.Print_poly();
	m2.Print_poly();
	m1.Print_poly();
	//return RUN_ALL_TESTS();
	return 0;
}
