#pragma once
#include "Monom.h"

//struct Monom_list
//{
//	Monom mon_;
//	Monom* next;
//};



class Polynomial {
private:
	Monom* mon_ptr;

	Polynomial(char* str) {
		//долго писать, потом, запуш € этим займусь, это по анологии, ка» € в польскую запись переводил, только тут чутка по другому
	}

	void Print_poly(Monom* mon_ptr_) {
		Monom* pointer = mon_ptr;
		while (pointer->next != 0) {
			printf("%lf x^%i y^%i z^%i", pointer->coef, (*pointer)., pointer.deg_y, pointer.deg_z);//не понимаю как степень вызвать
			if ( (pointer->next != 0) && (pointer->coef > 0) ) {
				printf(" + ");
			}
			pointer = pointer->next;
		}
	}

	void Scan_poly(char* str);

	Polynomial operator - (Monom m);
	Polynomial operator + (Monom m);
	Polynomial operator * (Monom m);

	~Polynomial() {
		//чЄ то придЄтс€ удалать
	}

};