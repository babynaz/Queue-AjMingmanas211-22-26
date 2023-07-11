#include "node.h"
#include <iostream>

class Queue {
private:
	Node* head = nullptr;
	Node* tail = nullptr;
	int size = 0;

public:
	Queue();
	int front();
	void enqueue(int);
	int dequeue();
	void printAll();
	~Queue();
	int getSize() { return this->size; }
};

Queue::Queue() {
	this->head = nullptr;
	this->tail = nullptr;
	this->size = 0;
}

int Queue::front() {
	return this->head->getValue();
}

void Queue::enqueue(int value) {
	this->size++;
	Node* newNode = new Node(value);
	if (this->head == nullptr) {
		this->head = newNode;
		this->tail = newNode;
		return;
	}
	this->tail->setNext(newNode);
	this->tail = this->tail->getNext();
}

int Queue::dequeue() {
	this->size--;
	if (this->head == nullptr)
		return -2147483648;
	if (this->head == this->tail)
		this->tail = nullptr;
	Node* temp = this->head;
	int value = temp->getValue();
	this->head = this->head->getNext();
	delete temp;
	return value;
}

void Queue::printAll() {
	for (Node* temp = this->head; temp != nullptr; temp = temp->getNext())
		std::cout << temp->getValue() << " -> ";
	std::cout << "X" << std::endl;
}

Queue::~Queue() {
	for (Node* temp = this->head; this->head != nullptr; temp = this->head) {
		this->head = temp->getNext();
		delete temp;
		this->size--;
	}
}
