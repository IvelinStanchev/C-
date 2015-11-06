#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string currentWord)
{
    if (currentWord.length() > 2)
    {
        for (int i = 0, length = currentWord.length(); i < length / 2; i++)
        {
            if (currentWord[i] != currentWord[length - i - 1])
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }

    return true;
}

int main()
{
    string sentence = "";

    cout<<"Enter the sentence: ";
    std::getline(std::cin, sentence);

    string currentWord = "";
    for (int i = 0, length = sentence.length(); i <= length; i++)
    {
        if (isalpha(sentence[i]) && i < length)
        {
            currentWord += sentence[i];
        }
        else
        {
            if (currentWord != "")
            {
                if (isPalindrome(currentWord))
                {
                    cout<<currentWord<<endl;
                }
            }

            currentWord = "";
        }
    }

    return 0;
}
