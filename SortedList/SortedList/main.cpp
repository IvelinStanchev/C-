#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef struct Element * po;

struct Element {
	int data;
	po next;
};

int main() {
    string input;
    int inputNumber;

    po first = NULL;
    po next = NULL;

    bool isFirstInput = true;

    po firstElement = NULL;

    stringstream stream;

    cout<<"Enter number for the list (Enter EOF to stop entering): ";
    while (cin>>input) {

        if (input == "EOF") {
            break;
        }

        stream.clear();
        stream.str(input);
        stream>>inputNumber;

        if (!isFirstInput) {

            if (inputNumber < firstElement->data) {
                po newElement = new Element;
                newElement->data = inputNumber;
                newElement->next = firstElement;

                firstElement = newElement;
            } else {
                if (firstElement->next != NULL) {

                    po helpElement = firstElement;
                    while (helpElement != NULL) {
                        if (helpElement->next != NULL) {
                            if (inputNumber <= helpElement->next->data) {
                                po insertElement = new Element;
                                insertElement->data = inputNumber;
                                insertElement->next = helpElement->next;

                                helpElement->next = insertElement;
                                break;
                            }
                        } else {
                            po insertElement = new Element;
                            insertElement->data = inputNumber;
                            insertElement->next = NULL;

                            helpElement->next = insertElement;
                            break;
                        }

                        helpElement = helpElement->next;
                    }
                } else {
                    next = new Element;
                    next->data = inputNumber;
                    next->next = NULL;

                    first->next = next;
                    first = next;
                }
            }
        }
        else {
            first = new Element;

            first->data = inputNumber;
            first->next = NULL;

            firstElement = first;
            isFirstInput = false;
        }

        cout<<"Enter number for the list: ";
    };

    while (firstElement != NULL) {
        cout<<firstElement->data<<endl;
        firstElement = firstElement->next;
    }

    return 0;
}
