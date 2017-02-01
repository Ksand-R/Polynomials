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

	void Print_poly() {
		Monom* temp = head;

		while (head) {
			cout << temp->coef << "x^" 
				<< temp->deg / 10000 << "y^" 
				<< temp->deg / 100 % 100 << "z^" 
				<< temp->deg % 100;

			if ( (temp->next) && (temp->coef > 0) ) {
				printf("+");
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
			}
			else {
				tail->next = new_node;
				tail = new_node;
				size++;
			}
			cout << "Is Input ended? // 0 means no, 1 means yes " << endl;
			cin >> f;
			

		}
	}

	//Polynomial operator - (Monom m);
	//Polynomial operator + (Monom m);
	//Polynomial operator * (Monom m);

	~Polynomial() {
	}

};