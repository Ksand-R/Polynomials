#pragma once
#include <stdexcept>


	struct Monom
	{
		double coef;
		int deg;
		Monom* next;

		Monom(double coef_ = 0.0, int deg_ = 0) {
			if (deg_ > 999999) {
				throw std::logic_error("Int overflow");
			}
			else {
				coef = coef_;
				deg = deg_;
			}
		}

		int deg_z() { return (deg % 100); }
		int deg_y() { return ((deg / 100) % 100); }
		int	deg_x() { return (deg / 10000); }

		Monom operator + (Monom m) {
			Monom sum;
			if (deg == m.deg) {
				sum = m;
				sum.coef += coef;
			}
			return sum;
		}
		Monom operator * (Monom m) {
			Monom sum = * this;
			sum.coef *= m.coef;
			sum.deg += m.deg;
			if (sum.deg > 999999) {
				throw std::logic_error("Int overflow");
			}
			return sum;
		}
		Monom operator - (Monom m) {
			Monom sum;
			if (deg == m.deg) {
				sum = *this;
				sum.coef -= m.coef;
			}
			return sum;
		}

		/*~Monom() {
			deg = 0;
			coef = 0.0;
		}*/


	};
	//тесты 

