#include <iostream>

using namespace std;

typedef struct Element * po;

struct Element {
	int data;
	po next;
};

int main() {
	po na = NULL;
	po p = NULL;
	po q = NULL;
	int inputNumber = 0;

	while (cin>>inputNumber && inputNumber >= 0) {
		p = new Element;
		p->data = inputNumber;
		p->next = na;
		na = p;
	}

	cout<<na->data<<endl;

	na = na->next;
	p = na;

	while (p != NULL) {
        cout << p->data << endl;
        p = p->next;
	}

	delete p;
	return 0;
}

