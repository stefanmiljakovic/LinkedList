#pragma once

template<typename T>
class LinkedList
{
private:
	T data;
	LinkedList * nextNode;
	void rebind(LinkedList<T>*, LinkedList<T>*);

public:
	LinkedList();
	~LinkedList();

	int getLenght();

	LinkedList<T> * getElementAt(int);

	T* getData();
	T* getData(int);

	T getValue();
	T getValue(int);

	void addData();
	void addData(T*);
	void addData(T);
	
	void setData(T*);
	void setData(T*, int);

	void setData(T);
	void setData(T, int);

	void sort(int(* callback)(T a, T b));

};

template<typename T>
LinkedList<T>::LinkedList()
{
	this->data = data;
	this->nextNode = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList()
{}

template<typename T>
LinkedList<T> * LinkedList<T>::getElementAt(int i) {
	LinkedList<T> * temp = this;

	while (i) {
		
		if (temp->nextNode != nullptr)
			temp = temp->nextNode;

		i--;
	}

	return temp;
}


template<typename T>
int LinkedList<T>::getLenght() {

	LinkedList<T> * temp = this;

	int i = 0;
	while (temp != nullptr) {
		i++;
		temp = temp->nextNode;
	}

	return i;
}
template<typename T>
T* LinkedList<T>::getData() {
	return &data;
}


// overload to support id
template<typename T>
T* LinkedList<T>::getData(int i) {
	LinkedList* temp = this;


	// if it goes over maxIndex, will return lastIndex
	while (i > 0 && temp->nextNode != nullptr) {
		temp = temp->nextNode;
		i--;
	}

	return &temp->data;
}

template<typename T>
T LinkedList<T>::getValue() {
	return data;
}

template<typename T>
T LinkedList<T>::getValue(int i) {
	return *this->getData(i);
}

template<typename T>
void LinkedList<T>::addData(T* data) {
	LinkedList<T>* temp = this;

	// find end of linked list
	while (temp->nextNode != nullptr) {
		temp = temp->nextNode;
	}

	LinkedList<T>* newEntry = new LinkedList();
	temp->nextNode = newEntry;
	newEntry->data = *data;
}

template<typename T>
void LinkedList<T>::addData(T data) {
	addData(&data);
}

// overload for empty data
template<typename T>
void LinkedList<T>::addData() {
	LinkedList<T>* temp = this;

	// find end of linked list
	while (temp->nextNode != nullptr) {
		temp = temp->nextNode;
	}

	LinkedList<T>* newEntry = new LinkedList();
	temp->nextNode = newEntry;
}

template<typename T>
void LinkedList<T>::setData(T* data, int i) {
	this->getData(i) = data;
}

template<typename T>
void LinkedList<T>::setData(T* data) {
	this->data = *data;
}

template<typename T>
void LinkedList<T>::setData(T data, int i) {
	*this->getData(i) = data;
}

template<typename T>
void LinkedList<T>::setData(T data) {
	*this->getData() = data;
}

template<typename T>
void LinkedList<T>::sort(int(*comparator)(T a, T b))
{
	LinkedList<T>* begin;
	LinkedList<T>* temp;
	LinkedList<T>* tempBefore = nullptr;

	int len = this->getLenght();

	// BubbleSort
	for (int i = 0; i < len-1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (
				comparator(getElementAt(j)->data, getElementAt(j + 1)->data) > 0
				) {
				rebind(getElementAt(j), getElementAt(j + 1));
			}
		}
	}
	
}

template<typename T>
void LinkedList<T>::rebind(LinkedList<T>* a, LinkedList<T>* b) {

	T temp = *a->getData();
	a->setData(b->getData());
	b->setData(temp);
}
