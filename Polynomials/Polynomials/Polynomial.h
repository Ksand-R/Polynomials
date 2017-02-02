#pragma once
#include <iostream>
#include "Monom.h"
using namespace std;


class Polynomial {
private:
	Monom* head;
	Monom* tail;
	int size; // counter of amount of monoms

public:

	Polynomial() { size = 0; head = tail = NULL; }
	
	
	Polynomial(const Polynomial& p) {
		size = p.size;
		head = p.head;
		tail = p.tail;
		Monom* temp = head;
			while (temp)
			{
				Monom* new_node = new Monom(temp->coef, temp->deg, temp->next);
				temp = temp->next;

			}


	}

	//need to overload =


	void Print_poly() {
		Monom* temp = head;

		while (temp) {
			cout << temp->coef << "x^" 
				<< temp->deg / 10000 << "y^" 
				<< temp->deg / 100 % 100 << "z^" 
				<< temp->deg % 100;

			if ( (temp->next) && (temp->next->coef > 0) ) {
				printf(" + ");
			}

			temp = temp->next;
		}
	}



	void Input_poly() {
		int f = -1;
		int curr_coef = -1;
		int curr_x = -1;
		int curr_y = -1;
		int curr_z = -1;
		
		while (f != 1) {
			Monom* new_node = new Monom();

			cout << "Enter another coefficient: " << endl;
			cin >> curr_coef;
			new_node->coef = curr_coef;

			cout << "enter enother degree of x: " << endl;
			cin >> curr_x;
			new_node->deg = curr_x * 10000;

			cout << "enter enother degree of y: " << endl;
			cin >> curr_y;
			new_node->deg += curr_y * 100;

			cout << "enter enother degree of z: " << endl;
			cin >> curr_z;
			new_node->deg += curr_z;

			new_node->next = NULL;

			if (tail == NULL)
			{
				head = tail = new_node;
				tail->next = NULL;
				size = 1;
			}
			else {
				tail->next = new_node;
				tail = new_node;
				size++;
				//tail->next = NULL;
			}
			cout << "Is Input ended? // 0 means no, 1 means yes " << endl;
			cin >> f;
			

		}
	}

	Polynomial operator - (Polynomial m) {
		return *this + m*(-1);
	}

	Polynomial operator + (Monom m) {
		Polynomial res = *this;
		int flag = 0;
		Monom *pointer = res.head;
		while (pointer && flag == 0) {
			if (pointer->deg = m.deg) {
				pointer->coef += m.coef;
				flag = 1;
			}
			pointer = pointer->next;
		}
		if (flag = 0) {
			res.size++;
			res.tail->next = new Monom;
			res.tail = res.tail->next;
			res.tail->coef = m.coef;
			res.tail->deg = m.deg;
			res.tail->next = 0;
		}
		return res;
	}

	Polynomial operator + (Polynomial p) {
		if (this == &p) {
			return p * 2;
		}
		Monom *buf = p.head;
		Polynomial res = *this;
		while (buf) {
			res = res + *buf;
			buf = buf->next;
		}
		return res;
	/*	Polynomial poly, poly_copy = p;
		Monom *pointer_poly1 = head, *pointer_poly2 = poly_copy.head, *buf1, *buf2;
		if (head == 0){
			poly = p;
		}
		else {
			if (p.head == 0) {
				poly = *this;
			}
			else {
				poly.head = new Monom;
				poly.tail = poly.head;
				poly.tail->next = 0;
				while (pointer_poly1 != 0)
				{
					int flag = 1;
					while (pointer_poly2 != 0 || flag == 1) {
						buf1 = 0;
						buf2 = pointer_poly2;
						if (pointer_poly2->deg == pointer_poly1->deg) {
							poly.size++;
							poly.head->coef = pointer_poly2->coef + pointer_poly1->coef;
							if (flag = 1) {
								poly.head->coef = pointer_poly2->coef + pointer_poly1->coef;
								flag = 0;
							}
							else {
								poly.head->coef += pointer_poly2->coef;
							}
							if (pointer_poly2->next == 0) {
								poly_copy.tail = buf1;
							}
							if (buf1 != 0) {
								buf1->next = pointer_poly2->next;
							}
							else {
								poly_copy.head = pointer_poly2->next;
							}
							delete buf2;
							pointer_poly2 = pointer_poly2->next;
							buf2 = pointer_poly2;
						}
						else {
							buf1 = pointer_poly2;
							pointer_poly2 = pointer_poly2->next;
							buf2 = pointer_poly2;
						}
					}
					if (flag == 1) {
						poly.size++;
						poly.head->coef = pointer_poly1->coef;
					}
					buf1 = new Monom;
					buf1->next = poly.head;
					poly.head = buf1;

					pointer_poly1 = pointer_poly1->next;
				}
				buf2 = buf1;
				buf1 = poly.head;
				poly.head = buf2;
				delete buf1;
				if (pointer_poly2 != 0) {
					poly_copy.tail->next = poly.head;
					poly.head = poly_copy.head;
				}
			}
		}
		return poly;*/
	}

	Polynomial operator * (double d) {
		Polynomial res = *this;
		Monom *buf = res.head;
		while (buf) {
			buf->coef *= d;
			buf = buf->next;
		}
		return res;
	}

	Polynomial operator * (Monom m) {
		if (this == 0 || m.coef == 0) {
			return *this * 0;
		}
		Polynomial res = *this;
		Monom *pointer = res.head;
		while (pointer ) {
			pointer->coef *= m.coef;
			pointer->deg + m.deg;
			pointer = pointer->next;
		}
	}

	Polynomial operator * (Polynomial m) {
		Polynomial res;
		Monom *buf = m.head;
		while (buf) {
			res = res + (*this * *buf);
			buf = buf->next;
		}
		return res;
	}

	~Polynomial() {

	}

};