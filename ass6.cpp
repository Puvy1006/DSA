#include <iostream>
using namespace std;

struct Node {
	int coef;   
	int exp;    
	Node* next;
};

// Create new node
Node* createNode(int coef, int exp) {
	Node* newNode = new Node;
	newNode->coef = coef;
	newNode->exp = exp;
	newNode->next = nullptr;
	return newNode;
}

// Insert term into polynomial in descending order of exponent
void insertTerm(Node*& head, int coef, int exp) {
	if (coef == 0) return;

	// If list is empty or new term has higher exponent than head
	if (head == nullptr || head->exp < exp) {
    	Node* newNode = createNode(coef, exp);
    	newNode->next = head;
    	head = newNode;
    	return;
	}

	Node* curr = head;
	Node* prev = nullptr;

	// Traverse to find position or term with same exponent
	while (curr != nullptr && curr->exp > exp) {
    	prev = curr;
    	curr = curr->next;
	}

	if (curr != nullptr && curr->exp == exp) {
    	// Combine like terms
    	curr->coef += coef;
    	if (curr->coef == 0) {
        	// Remove the node
        	if (prev == nullptr) {
            	head = curr->next;
        	} else {
            	prev->next = curr->next;
        	}
        	delete curr;
    	}
	} else {
    	// Insert new node between prev and curr
    	Node* newNode = createNode(coef, exp);
    	if (prev != nullptr) {
        	prev->next = newNode;
    	}
    	newNode->next = curr;
    	if (prev == nullptr) head = newNode; // New head if inserted at front
	}
}

// Display polynomial
void displayPolynomial(Node* head) {
	if (head == nullptr) {
    	cout << "0\n";
    	return;
	}
	Node* curr = head;
	bool first = true;
	while (curr != nullptr) {
    	if (curr->coef != 0) {
        	if (!first && curr->coef > 0) cout << " + ";
        	else if (curr->coef < 0) cout << " - ";

        	int absCoef = abs(curr->coef);
        	if (absCoef != 1 || curr->exp == 0) cout << absCoef;
        	else if (curr->coef == -1 && curr->exp != 0) cout << "";

        	if (curr->exp > 0) {
            	cout << "x";
            	if (curr->exp > 1) cout << "^" << curr->exp;
        	}
        	first = false;
    	}
    	curr = curr->next;
	}
	cout << "\n";
}

// Add two polynomials and return result polynomial
Node* addPolynomials(Node* poly1, Node* poly2) {
	Node* result = nullptr;
	Node* p1 = poly1;
	Node* p2 = poly2;

	// Traverse both lists
	while (p1 != nullptr && p2 != nullptr) {
    	if (p1->exp > p2->exp) {
        	insertTerm(result, p1->coef, p1->exp);
        	p1 = p1->next;
    	} else if (p2->exp > p1->exp) {
        	insertTerm(result, p2->coef, p2->exp);
        	p2 = p2->next;
    	} else {
        	// Same exponent, add coefficients
        	int sumCoef = p1->coef + p2->coef;
        	if (sumCoef != 0)
            	insertTerm(result, sumCoef, p1->exp);
        	p1 = p1->next;
        	p2 = p2->next;
    	}
	}

	// Add remaining terms from poly1
	while (p1 != nullptr) {
    	insertTerm(result, p1->coef, p1->exp);
    	p1 = p1->next;
	}
	// Add remaining terms from poly2
	while (p2 != nullptr) {
    	insertTerm(result, p2->coef, p2->exp);
    	p2 = p2->next;
	}

	return result;
}

// Delete polynomial list and free memory
void deletePolynomial(Node*& head) {
	while (head != nullptr) {
    	Node* temp = head;
    	head = head->next;
    	delete temp;
	}
}

int main() {
	Node* poly1 = nullptr;
	Node* poly2 = nullptr;
	Node* result = nullptr;

	int choice;
	while (true) {
    	cout << "\nPolynomial Operations\n";
    	cout << "1. Insert term into Polynomial 1\n";
    	cout << "2. Insert term into Polynomial 2\n";
    	cout << "3. Display Polynomial 1\n";
    	cout << "4. Display Polynomial 2\n";
    	cout << "5. Add Polynomial 1 and Polynomial 2\n";
    	cout << "6. Display Result Polynomial\n";
    	cout << "7. Exit\n";
    	cout << "Enter choice: ";
    	cin >> choice;

    	if (choice == 1 || choice == 2) {
        	int coef, exp;
        	cout << "Enter coefficient: ";
        	cin >> coef;
        	cout << "Enter exponent: ";
        	cin >> exp;
        	if (choice == 1) {
            	insertTerm(poly1, coef, exp);
        	} else {
            	insertTerm(poly2, coef, exp);
        	}
    	} else if (choice == 3) {
        	cout << "Polynomial 1: ";
        	displayPolynomial(poly1);
    	} else if (choice == 4) {
        	cout << "Polynomial 2: ";
        	displayPolynomial(poly2);
    	} else if (choice == 5) {
        	deletePolynomial(result);
        	result = addPolynomials(poly1, poly2);
        	cout << "Polynomials added.\n";
    	} else if (choice == 6) {
        	cout << "Result Polynomial: ";
        	displayPolynomial(result);
    	} else if (choice == 7) {
        	break;
    	} else {
        	cout << "Invalid choice, try again.\n";
    	}
	}

	deletePolynomial(poly1);
	deletePolynomial(poly2);
	deletePolynomial(result);
	return 0;
}
