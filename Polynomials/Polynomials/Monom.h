#pragma once
#include <stdexcept>

struct Monom
{
	double coef;
	unsigned int deg;
	Monom(double coef_, unsigned int deg_) {
		if (deg_ > 999999)
			throw std::logic_error("Int overflow");
		else {
			coef = coef_;
			deg = deg_;
		}
	}


};

