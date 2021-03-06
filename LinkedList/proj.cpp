// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

struct def {
	int data;
	def * nextNode;
};

void test1() {

	LinkedList<def> a;
	a.getData()->data = 9;

	cout << a.getData()->data << endl;

	a.addData(new def());

	cout << a.getData()->data << endl;

	a.getData(1)->data = 5;

	cout << endl << a.getData()->data << endl << a.getData(1)->data << endl;

	a.getData()->data = 3;

	cout << endl << a.getData()->data << endl << a.getData(1)->data << endl;

}

void test2() {

	LinkedList<int> a;
	a.setData(9);

	cout << a.getValue() << endl;

	a.addData(new int());

	cout << a.getValue() << endl;

	a.setData(5, 1);

	cout << endl << a.getValue() << endl << a.getValue(1) << endl;

	a.setData(3);

	cout << endl << a.getValue() << endl << a.getValue(1) << endl;

}

int comparator(int a, int b) {
	return b-a;
}

void test3() {
	LinkedList<int> a;
	a.setData(0, 0);
	
	for (int i = 1; i < 10; i++) {
		a.addData(i);
	}
	cout << a.getLenght() << endl;

	a.sort(comparator);

	for (int i = 0; i < 10; i++) {
		cout << a.getValue(i) << endl;
	}
}



int main()
{
	test3();


	system("pause");
    return 0;
}

