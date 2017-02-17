//#pragma comment(lib, "opengl32.lib") 
//#pragma comment(lib, "glu32.lib") 
#pragma once
#include <iostream>
#include <cstdio>
#include "Monom.h"
#include <limits>
using namespace std;

//Minus works uncorrectly

class Polynomial {
private:
	Monom* head;
	Monom* tail;
	int size; // counter of amount of monoms

	void del_monom(Monom *m) {
		Monom *ptr = this->head;
		while (ptr->next != m) {}
		ptr->next = m->next;
		delete m;
	}
	void set_head(Monom* head_) { head = head_; }

	void bring_similar() {
		Monom *ptr1 = this->head, *ptr2;
		while (ptr1) { 
		ptr2 = ptr1->next;
		while (ptr2) {
				if (ptr1->deg == ptr2->deg) {
					Monom *buf = ptr2->next;
					ptr1->coef += ptr2->coef;
					this->del_monom(ptr2);

					ptr2 = buf;
				}
				else {
					ptr2 = ptr2->next;
				}
			}
			ptr1 = ptr1->next;
		}
	}

public:

	Polynomial() { size = 0; head = tail = NULL; }
	
	
	Polynomial(const Polynomial& p) {
		size = p.size;
		head = new Monom (p.head->coef, p.head->deg, p.head->next);
		tail = head;
		tail->next = NULL;
		size = 1;

		Monom*  temp = p.head->next;  
		while (temp)
		{

			Monom* new_node = new Monom(temp->coef, temp->deg, temp->next);
			size++;

			tail->next = new_node;
			tail = new_node;

			temp = temp->next;

		}


	}
	

	void Print_poly() {
		Monom* temp = head;

		while (temp) {
			if (temp->coef == 0) { cout << '0'; break; }
			else {
				cout << temp->coef;
				if (temp->deg / 10000)
				{
					cout << "x^" << temp->deg / 10000;
				}
				if (temp->deg / 100 % 100)
				{
					cout << "y^" << temp->deg / 100 % 100;
				}
				if (temp->deg % 100)
				{
					cout << "z^" << temp->deg % 100;
				}

				if ((temp->next) && (temp->next->coef > 0)) {
					printf(" + ");
				}
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
			// need to rework input, i mean control 

			
			for (;;) {
				cout << "Enter another coefficient: " << endl;
				cin >> curr_coef;
				if (std::cin.fail())
				{
					std::cout << "Nepravilnii vvod - zapreshen vvod bykv" << '\n';
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else {
					new_node->coef = curr_coef;
					break;
				}
			}
				
			

			cout << "enter enother degree of x: " << endl;
			cin >> curr_x;
			if (std::cin.fail())
			{
				std::cout << "Nepravilnii vvod - zapreshen vvod bykv" << '\n';
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			new_node->deg = curr_x * 10000;

			cout << "enter enother degree of y: " << endl;
			cin >> curr_y;
			if (std::cin.fail())
			{
				std::cout << "Nepravilnii vvod - zapreshen vvod bykv" << '\n';
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			new_node->deg += curr_y * 100;

			cout << "enter enother degree of z: " << endl;
			scanf_s("%i", &curr_z);
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

			}
			cout << "Is Input ended? // 0 means no, 1 means yes " << endl;
			scanf_s("%i", &f);
			

		}
		this->mergeSort(&head);
		//tail->next = NULL;
		this->bring_similar();
	}

	const Polynomial& operator = (const Polynomial &p) {
		if (this == &p) {
			return *this;
		}

		while (head)
		{
			Monom* temp = head->next;
			delete head;
			head = temp;
		}

		head = new Monom(p.head->coef, p.head->deg, p.head->next);
		tail = head;
		tail->next = NULL;
	
		size = 1;

		Monom*  temp = p.head->next;
		while (temp)
		{

			Monom* new_node = new Monom(temp->coef, temp->deg, temp->next);
			size++;
			
			tail->next = new_node;
			tail = new_node;

			temp = temp->next;

		}
		
		return *this;
	}


	Polynomial operator - (Polynomial m) {
		return *this + m*(-1);
	}

	//Polynomial operator + (Monom m) {
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
	//		res.tail->next = new Monom;
	//		res.tail = res.tail->next;
	//		res.tail->coef = m.coef;
	//		res.tail->deg = m.deg;
	//		res.tail->next = 0;
	//	}
	//	return res;
	//}

	Polynomial operator + (Polynomial p) {
		Monom* m1 = this->head;
		Monom* m2 = p.head;
		Polynomial res;
		while (m1 && m2)
		{
			if (m1->deg > m2->deg) {
				res.add_monom_in_tail(m1);
				m1 = m1->next;
			}
			else if (m1->deg == m2->deg) {
				if (m1->coef != -m2->coef) {
					res.add_monom_in_tail(m1);
					res.tail->coef += m2->coef;
					
				}
				m1 = m1->next;
				m2 = m2->next;
			}
			else {
				res.add_monom_in_tail(m2);
				m2 = m2->next;
			}
		
		}
		if (m1) {
			m2 = m1;
		}
		else
		{
			m1 = m2;
		}
		while (m1) {
			res.add_monom_in_tail(m1);
			m1 = m1->next;
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
		while (pointer) {
			pointer->coef *= m.coef;
			if (pointer->deg + m.deg > 999999) { 
				throw std::logic_error("Deg overflow");
				break;
			}
			else {
				pointer->deg += m.deg;
			}	 //test on deg<=99
			pointer = pointer->next;
		}
		return res;
	}

	Polynomial operator * (Polynomial m) {
		Polynomial res;
		Monom *buf = m.head;

		res = *this * *buf;			// eweywhere add test on bad polynomial
		buf = buf->next;
		while (buf) {
			res = res + (*this * *buf);
			buf = buf->next;
		}
		return res;
	}

	void merge(Monom *a, Monom *b, Monom **c) {
    Monom tmp;
    *c = NULL;
    if (a == NULL) {
        *c = b;
        return;
    }
    if (b == NULL) {
        *c = a;
        return;
    }
    if (a->deg > b->deg) {
        *c = a;
        a = a->next;
    } else {
        *c = b;
        b = b->next;
    }
    tmp.next = *c;
    while (a && b) {
        if (a->deg > b->deg) {
            (*c)->next = a;
            a = a->next;
        } else {
            (*c)->next = b;
            b = b->next;
        }
        (*c) = (*c)->next;
    }
    if (a) {
        while (a) {
            (*c)->next = a;
            (*c) = (*c)->next;
            a = a->next;
        }
    }
    if (b) {
        while (b) {
            (*c)->next = b;
            (*c) = (*c)->next;
            b = b->next;
        }
    }
    *c = tmp.next;
}

	void split(Monom *src, Monom **low, Monom **high) {
		Monom *fast = NULL;
		Monom *slow = NULL;

		if (src == NULL || src->next == NULL) {
			(*low) = src;
			(*high) = NULL;
			return;
		}

		slow = src;
		fast = src->next;

		while (fast != NULL) {
			fast = fast->next;
			if (fast != NULL) {
				fast = fast->next;
				slow = slow->next;
			}
		}

		(*low) = src;
		(*high) = slow->next;
		slow->next = NULL;
	}

	void mergeSort(Monom **head) {
		Monom *low = NULL;
		Monom *high = NULL;
		if ((*head == NULL) || ((*head)->next == NULL)) {
			return;
		}
		split(*head, &low, &high);
		mergeSort(&low);
		mergeSort(&high);
		merge(low, high, head);
	}

	void add_monom_in_tail( Monom* m)
	{
		if (tail == NULL)
		{
			Monom* new_monom = new Monom(m->coef, m->deg, NULL);
			tail = head = new_monom;
			size++;
		}
		else {
			Monom* new_monom = new Monom(m->coef, m->deg, NULL);
			tail->next = new_monom;
			tail = new_monom;
			size++;
		}
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

