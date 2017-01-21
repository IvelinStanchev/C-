#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

void printIndexOfCardByName(int sizeOfDeck, string deck[], string name)
{
    for (int i = 0; i < sizeOfDeck; i++)
    {
        if (deck[i] == name)
        {
            cout<<"The card with name "<<name<<" is at index "<<i;
        }
    }

    cout<<endl<<endl;
}

void printTopCard(int sizeOfDeck, string deck[])
{
    cout<<deck[sizeOfDeck - 1];
    cout<<endl<<endl;
}

void sortDeck(int sizeOfDeck, string deck[], string originalDeck[])
{
    for (int i = 0; i < sizeOfDeck; i++)
    {
        deck[i] = originalDeck[i];
    }
}

void printDeck(int sizeOfDeck, string deck[])
{
    for (int i = 0; i < sizeOfDeck; i++)
    {
        cout<<deck[i]<<"   ";

        if (i % 8 == 0 && i != 0)
        {
            cout<<endl;
        }
    }

    cout<<endl<<endl;
}

void shuffle(int sizeOfDeck, string deck[])
{
    for (int i = sizeOfDeck - 1; i >= 0; i--)
    {
        int randomIndex = (rand() % 51) + 1;
        string first = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = first;
    }
}

int main()
{
    srand((int)time(0));

    int sizeOfDeck = 52;

    string originalDeck[52] =
    {
        "C - 2", "C - 3", "C - 4", "C - 5", "C - 6", "C - 7", "C - 8", "C - 9", "C - 10", "C - Jack", "C - Queen", "C - King", "C - Ace",
        "D - 2", "D - 3", "D - 4", "D - 5", "D - 6", "D - 7", "D - 8", "D - 9", "D - 10", "D - Jack", "D - Queen", "D - King", "D - Ace",
        "H - 2", "H - 3", "H - 4", "H - 5", "H - 6", "H - 7", "H - 8", "H - 9", "H - 10", "H - Jack", "H - Queen", "H - King", "H - Ace",
        "S - 2", "S - 3", "S - 4", "S - 5", "S - 6", "S - 7", "S - 8", "S - 9", "S - 10", "S - Jack", "S - Queen", "S - King", "S - Ace"
    };

    string deck[52] =
    {
        "C - 2", "C - 3", "C - 4", "C - 5", "C - 6", "C - 7", "C - 8", "C - 9", "C - 10", "C - Jack", "C - Queen", "C - King", "C - Ace",
        "D - 2", "D - 3", "D - 4", "D - 5", "D - 6", "D - 7", "D - 8", "D - 9", "D - 10", "D - Jack", "D - Queen", "D - King", "D - Ace",
        "H - 2", "H - 3", "H - 4", "H - 5", "H - 6", "H - 7", "H - 8", "H - 9", "H - 10", "H - Jack", "H - Queen", "H - King", "H - Ace",
        "S - 2", "S - 3", "S - 4", "S - 5", "S - 6", "S - 7", "S - 8", "S - 9", "S - 10", "S - Jack", "S - Queen", "S - King", "S - Ace"
    };

    shuffle(sizeOfDeck, deck);
    printDeck(sizeOfDeck, deck);
    shuffle(sizeOfDeck, deck);
    printDeck(sizeOfDeck, deck);

    printTopCard(sizeOfDeck, deck);

    sortDeck(sizeOfDeck, deck, originalDeck);
    printDeck(sizeOfDeck, deck);

    shuffle(sizeOfDeck, deck);
    printDeck(sizeOfDeck, deck);

    printIndexOfCardByName(sizeOfDeck, deck, "H - 7");

    return 0;
}
