#pragma once
#include <stdexcept>


	struct Monom
	{
		double coef;
		int deg;
		Monom* next;

			Monom(const Monom& m) {
				next = new Monom (*m.next);
				coef = m.coef;
				deg = m.deg;
			}




		Monom(double coef_ = 0.0, int deg_ = 0, Monom* next_ = NULL)
		{
			if (deg_ > 999999) {
				throw std::logic_error("Int overflow");
			}
			else {
				coef = coef_;
				deg = deg_;
				next = next_;

			}
		}

		bool Monom::operator==(const Monom& rhs) const {
			return (this->coef == rhs.coef && this->deg == rhs.deg );
		}

		bool Monom::operator!=(const Monom& rhs) const {
			if (*this == rhs)
			{
				return false;
			}
			else { return true; }
		}	
	};
