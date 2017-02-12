#pragma once
#include <stdexcept>


	struct Monom
	{
		double coef;
		int deg;
		Monom* next;

		Monom(double coef_ = 0.0, int deg_ = 0, Monom* next_ = NULL) {
			if (deg_ > 999999) {
				throw std::logic_error("Int overflow");
			}
			else {
				coef = coef_;
				deg = deg_;
				next = next_;

			}
		}

	};
