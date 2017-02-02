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

	Polynomial& operator = (const Polynomial p) {
		if (this == &p) {
			return *this;
		}
		
		while (head)
		{
			Monom* temp = head->next;
			delete head;
			head = temp;
			size--;
		}

		Monom* temp = p.head;
		while (temp)
		{
			Monom* new_node = new Monom(temp->coef, temp->deg, temp->next);
			temp = temp->next;

		}
		
		return *this;
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
		Monom *tmp_ptr = p.head;
		Polynomial res = *this;
		while (tmp_ptr) {
			res = res + *tmp_ptr;
			tmp_ptr = tmp_ptr->next;
		}
		return res;
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
		while (head)
		{
			Monom* temp = head->next;
			delete head;
			head = temp;
			size--;
		}
	}

};
//удалить звено
