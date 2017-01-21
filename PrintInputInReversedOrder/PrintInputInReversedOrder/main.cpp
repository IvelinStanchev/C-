#include <iostream>
#include <string>

using namespace std;

typedef struct Element * po;

struct Element{
	string data;
	po next;
};

int main()
{
	po na = NULL;
	po p = NULL;
	po q = NULL;
	string input = "";

	while (getline(cin, input))
    {
		if (input.empty())
        {
            break;
        }
		else
        {
            p = new Element;
            p->data = input;
            p->next = na;
            na = p;
        }
	}

    cout<<na->data<<endl;;

	na = na->next;

	p = na;

	while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
	}

	delete p;

	return 0;
}

