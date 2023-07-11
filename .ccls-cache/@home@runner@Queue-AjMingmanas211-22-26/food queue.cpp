#include <iostream>
#include "queue.h"

int getPrice(int order, int quantity) {
	if (order > 3 || order < 1) return 0;
	int prices[] = { 0, 100, 20, 50 };
	return prices[order] * quantity;
}

int main(int argc, char* argv[]) {
	Queue q;
	int customer = 1;

	for (int i = 1; i < argc; i += (argv[i][0] == 'x' ? 1 : 2)) {
		if (argv[i][0] == 'x') {
			if (q.front() == 0)
				std::cout << (q.dequeue() || true ? "No food" : "") << std::endl;
			else {
				int price = q.dequeue();
				std::cout << "Customer " << customer++ << " has to pay " << price << std::endl;
				int cash;
				do {
					std::cout << "Cash: ";
					std::cin >> cash;
				} while (cash < price);
				if (cash - price) {
					std::cout << "Change is: " << cash - price << std::endl;
				}
			}
		}
		else {
			int order = atoi(argv[i]);
			int quantity = atoi(argv[i + 1]);
			q.enqueue(getPrice(order, quantity));
		}
	}

	if (q.getSize())
		std::cout << q.getSize() << " customers left in the queue." << std::endl;

	return 0;
}
