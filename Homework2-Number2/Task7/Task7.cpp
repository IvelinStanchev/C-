#include <iostream>

using namespace std;

int getSize(char *word)
{
    int size = 0;
    while(word[size] != '\0')
    {
        size++;
    }

    return size;
}

bool existsHorizontallyAndVertically(char *word, char matrix[][11])
{
    int matrixSize = 10;
    int wordSize = getSize(word);

    int rowCopy = 0;
    int colCopy = 0;
    int wordIndex = 0;

    for (int row = 0; row < matrixSize; row++)
    {
        for (int col = 0; col < matrixSize; col++)
        {
            rowCopy = row;
            colCopy = col;
            wordIndex = 0;

            if (row + wordSize - 1 < matrixSize)//check down
            {
                while((matrix[rowCopy][colCopy] == word[wordIndex]) && wordIndex < wordSize)
                {
                    rowCopy++;
                    wordIndex++;
                }

                if (wordIndex == wordSize)
                {
                    return true;
                }
            }

            rowCopy = row;
            wordIndex = 0;

            if (row - wordSize + 1 >= 0)//check up
            {
                while((matrix[rowCopy][colCopy] == word[wordIndex]) && wordIndex < wordSize)
                {
                    rowCopy--;
                    wordIndex++;
                }

                if (wordIndex == wordSize)
                {
                    return true;
                }
            }

            rowCopy = row;
            wordIndex = 0;

            if (col - wordSize + 1 >= 0)//check left
            {
                while((matrix[rowCopy][colCopy] == word[wordIndex]) && wordIndex < wordSize)
                {
                    colCopy--;
                    wordIndex++;
                }

                if (wordIndex == wordSize)
                {
                    return true;
                }
            }

            colCopy = col;
            wordIndex = 0;

            if (col + wordSize - 1 < matrixSize)//check right
            {
                while((matrix[rowCopy][colCopy] == word[wordIndex]) && wordIndex < wordSize)
                {
                    colCopy++;
                    wordIndex++;
                }

                if (wordIndex == wordSize)
                {
                    return true;
                }
            }
        }
    }
}

bool existsDiagonally(char *word, char matrix[][11])
{
    int matrixSize = 10;
    int wordSize = getSize(word);

    int rowCopy = 0;
    int colCopy = 0;
    int wordIndex = 0;

    for (int row = 0; row < matrixSize; row++)
    {
        for (int col = 0; col < matrixSize; col++)
        {
            rowCopy = row;
            colCopy = col;
            wordIndex = 0;

            if ((row + wordSize - 1 < matrixSize) && (col + wordSize - 1 < matrixSize))//check down right
            {
                while((matrix[rowCopy][colCopy] == word[wordIndex]) && wordIndex < wordSize)
                {
                    rowCopy++;
                    colCopy++;
                    wordIndex++;
                }

                if (wordIndex == wordSize)
                {
                    return true;
                }
            }

            rowCopy = row;
            colCopy = col;
            wordIndex = 0;

            if ((row + wordSize - 1 < matrixSize) && (col - wordSize + 1 >= 0))//check down left
            {
                while((matrix[rowCopy][colCopy] == word[wordIndex]) && wordIndex < wordSize)
                {
                    rowCopy++;
                    colCopy--;
                    wordIndex++;
                }

                if (wordIndex == wordSize)
                {
                    return true;
                }
            }

            rowCopy = row;
            colCopy = col;
            wordIndex = 0;

            if ((row - wordSize + 1 >= 0) && (col + wordSize - 1 < matrixSize))//check up right
            {
                while((matrix[rowCopy][colCopy] == word[wordIndex]) && wordIndex < wordSize)
                {
                    rowCopy--;
                    colCopy++;
                    wordIndex++;
                }

                if (wordIndex == wordSize)
                {
                    return true;
                }
            }

            rowCopy = row;
            colCopy = col;
            wordIndex = 0;

            if ((row - wordSize + 1 >= 0) && (col - wordSize + 1 >= 0))//check up left
            {
                while((matrix[rowCopy][colCopy] == word[wordIndex]) && wordIndex < wordSize)
                {
                    rowCopy--;
                    colCopy--;
                    wordIndex++;
                }

                if (wordIndex == wordSize)
                {
                    return true;
                }
            }
        }
    }
}

bool exists(char *word, char matrix[][11])
{
    if (existsHorizontallyAndVertically(word, matrix) ||
        existsDiagonally(word, matrix))
    {
        return true;
    }
}

bool isVowel(char letter)
{
    if(letter == 'a' || letter == 'e' || letter == 'i' ||
       letter == 'o' || letter == 'u') {
        return true;
    }

    return false;
}

int countAllWords(char matrix[][11])
{
    int allWords = 0;
    int matrixSize = 10;

    int rowCopy = 0;
    int colCopy = 0;
    int currentIndex = 0;

    for (int row = 0; row < matrixSize; row++)
    {
        for (int col = 0; col < matrixSize; col++)
        {
            //check right direction
            rowCopy = row;
            colCopy = col;
            currentIndex = 0;

            if (isVowel(matrix[rowCopy][colCopy]))
            {
                while(colCopy + 1 < matrixSize)
                {
                    colCopy++;
                    currentIndex++;

                    if ((currentIndex % 2 != 0) && isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && !isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && isVowel(matrix[rowCopy][colCopy]) && currentIndex >= 2)
                    {
                        allWords++;
                    }
                }
            }
            else
            {
                while(colCopy + 1 < matrixSize)
                {
                    colCopy++;
                    currentIndex++;

                    if ((currentIndex % 2 != 0) && !isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 != 0) && isVowel(matrix[rowCopy][colCopy]) && currentIndex >= 1)
                    {
                        allWords++;
                    }
                }
            }

            //check left direction
            rowCopy = row;
            colCopy = col;
            currentIndex = 0;

            if (isVowel(matrix[rowCopy][colCopy]))
            {
                while(colCopy - 1 >= 0)
                {
                    colCopy--;
                    currentIndex++;

                    if ((currentIndex % 2 != 0) && isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && !isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && isVowel(matrix[rowCopy][colCopy]) && currentIndex >= 2)
                    {
                        allWords++;
                    }
                }
            }
            else
            {
                while(colCopy - 1 >= 0)
                {
                    colCopy--;
                    currentIndex++;

                    if ((currentIndex % 2 != 0) && !isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 != 0) && isVowel(matrix[rowCopy][colCopy]) && currentIndex >= 1)
                    {
                        allWords++;
                    }
                }
            }

            //check down direction
            rowCopy = row;
            colCopy = col;
            currentIndex = 0;

            if (isVowel(matrix[rowCopy][colCopy]))
            {
                while(rowCopy + 1 < matrixSize)
                {
                    rowCopy++;
                    currentIndex++;

                    if ((currentIndex % 2 != 0) && isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && !isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && isVowel(matrix[rowCopy][colCopy]) && currentIndex >= 2)
                    {
                        allWords++;
                    }
                }
            }
            else
            {
                while(rowCopy + 1 < matrixSize)
                {
                    rowCopy++;
                    currentIndex++;

                    if ((currentIndex % 2 != 0) && !isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 != 0) && isVowel(matrix[rowCopy][colCopy]) && currentIndex >= 1)
                    {
                        allWords++;
                    }
                }
            }

            //check up direction
            rowCopy = row;
            colCopy = col;
            currentIndex = 0;

            if (isVowel(matrix[rowCopy][colCopy]))
            {
                while(rowCopy - 1 >= 0)
                {
                    rowCopy--;
                    currentIndex++;

                    if ((currentIndex % 2 != 0) && isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && !isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && isVowel(matrix[rowCopy][colCopy]) && currentIndex >= 2)
                    {
                        allWords++;
                    }
                }
            }
            else
            {
                while(rowCopy - 1 >= 0)
                {
                    rowCopy--;
                    currentIndex++;

                    if ((currentIndex % 2 != 0) && !isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 != 0) && isVowel(matrix[rowCopy][colCopy]) && currentIndex >= 1)
                    {
                        allWords++;
                    }
                }
            }

            //check diagonal down right
            rowCopy = row;
            colCopy = col;
            currentIndex = 0;

            if (isVowel(matrix[rowCopy][colCopy]))
            {
                while(rowCopy + 1 < matrixSize && colCopy + 1 < matrixSize)
                {
                    rowCopy++;
                    colCopy++;
                    currentIndex++;

                    if ((currentIndex % 2 != 0) && isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && !isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && isVowel(matrix[rowCopy][colCopy]) && currentIndex >= 2)
                    {
                        allWords++;
                    }
                }
            }
            else
            {
                while(rowCopy + 1 < matrixSize && colCopy + 1 < matrixSize)
                {
                    rowCopy++;
                    colCopy++;
                    currentIndex++;

                    if ((currentIndex % 2 != 0) && !isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 != 0) && isVowel(matrix[rowCopy][colCopy]) && currentIndex >= 1)
                    {
                        allWords++;
                    }
                }
            }

            //check diagonal down left
            rowCopy = row;
            colCopy = col;
            currentIndex = 0;

            if (isVowel(matrix[rowCopy][colCopy]))
            {
                while(rowCopy + 1 < matrixSize && colCopy - 1 >= 0)
                {
                    rowCopy++;
                    colCopy--;
                    currentIndex++;

                    if ((currentIndex % 2 != 0) && isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && !isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && isVowel(matrix[rowCopy][colCopy]) && currentIndex >= 2)
                    {
                        allWords++;
                    }
                }
            }
            else
            {
                while(rowCopy + 1 < matrixSize && colCopy - 1 >= 0)
                {
                    rowCopy++;
                    colCopy--;
                    currentIndex++;

                    if ((currentIndex % 2 != 0) && !isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 != 0) && isVowel(matrix[rowCopy][colCopy]) && currentIndex >= 1)
                    {
                        allWords++;
                    }
                }
            }

            //check diagonal up right
            rowCopy = row;
            colCopy = col;
            currentIndex = 0;

            if (isVowel(matrix[rowCopy][colCopy]))
            {
                while(rowCopy - 1 >= 0 && colCopy + 1 < matrixSize)
                {
                    rowCopy--;
                    colCopy++;
                    currentIndex++;

                    if ((currentIndex % 2 != 0) && isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && !isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && isVowel(matrix[rowCopy][colCopy]) && currentIndex >= 2)
                    {
                        allWords++;
                    }
                }
            }
            else
            {
                while(rowCopy - 1 >= 0 && colCopy + 1 < matrixSize)
                {
                    rowCopy--;
                    colCopy++;
                    currentIndex++;

                    if ((currentIndex % 2 != 0) && !isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 != 0) && isVowel(matrix[rowCopy][colCopy]) && currentIndex >= 1)
                    {
                        allWords++;
                    }
                }
            }

            //check diagonal up left
            rowCopy = row;
            colCopy = col;
            currentIndex = 0;

            if (isVowel(matrix[rowCopy][colCopy]))
            {
                while(rowCopy - 1 >= 0 && colCopy - 1 >= 0)
                {
                    rowCopy--;
                    colCopy--;
                    currentIndex++;

                    if ((currentIndex % 2 != 0) && isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && !isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && isVowel(matrix[rowCopy][colCopy]) && currentIndex >= 2)
                    {
                        allWords++;
                    }
                }
            }
            else
            {
                while(rowCopy - 1 >= 0 && colCopy - 1 >= 0)
                {
                    rowCopy--;
                    colCopy--;
                    currentIndex++;

                    if ((currentIndex % 2 != 0) && !isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 == 0) && isVowel(matrix[rowCopy][colCopy]))
                    {
                        break;
                    }

                    if ((currentIndex % 2 != 0) && isVowel(matrix[rowCopy][colCopy]) && currentIndex >= 1)
                    {
                        allWords++;
                    }
                }
            }
        }
    }

    return allWords;
}

int main()
{

    char matrix[][11] = { "acflsadraa",
                          "aasgsoecaa",
                          "asfsgsaaaa",
                          "worawaaaaa",
                          "agsagasdag",
                          "asgasarags",
                          "sdhssowytt",
                          "anmaahnoad",
                          "cacaaasgra",
                          "agsaaaagad" };


    char *a = "word";

    if(exists(a, matrix))
    {
        cout<<a<<" exists"<<endl;
    }
    else
    {
        cout<<a<<" does NOT exist"<<endl;
    }

    cout<<"All words: "<<countAllWords(matrix)<<endl;

    return 0;
}
