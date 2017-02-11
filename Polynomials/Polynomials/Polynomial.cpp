//#include "Polynomial.h"
//#include "Monom.h"
//Polynomial Polynomial :: operator + (Monom m) {
//	Polynomial res = *this;
//	int flag = 0;
//	Monom *pointer = res.head;
//	while (pointer && flag == 0) {
//		if (pointer->deg == m.deg) {
//			pointer->coef += m.coef;
//			flag = 1;
//		}
//		pointer = pointer->next;
//	}
//	if (flag = 0) {
//		res.size++;
//		res.tail->next = new Monom(res.tail->coef, res.tail->deg, res.tail->next);
//		/*res.tail = res.tail->next;
//		res.tail->coef = m.coef;
//		res.tail->deg = m.deg;*/
//		res.tail->next = 0;
//	}
//	return res;
//}