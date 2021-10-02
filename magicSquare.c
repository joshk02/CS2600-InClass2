#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>


int columnTotal;
int rowTotal;
int numberAttempts = 0;

int const columns = 3;
int const rows = 3;
int magicSquare[rows][columns] = {
    {},
    {},
    {}
};

int magicSquare1D[9];

int randomize1DArray(){

int i;

for (i = 0; i < 10; i++){
    magicSquare1D[i] = i + 1;
}

for (i = 0; i < 10; i++){
    int randIndex = rand() % 10;
    int temp = magicSquare1D[i];
    magicSquare1D[i] = magicSquare1D[randIndex];
    magicSquare1D[randIndex] = temp;
}

return 0;
}

int fill2DArray(){
    magicSquare[0][0] = magicSquare1D[0];
    magicSquare[0][1] = magicSquare1D[1];
    magicSquare[0][2] = magicSquare1D[2];
    magicSquare[1][0] = magicSquare1D[3];
    magicSquare[1][1] = magicSquare1D[4];
    magicSquare[1][2] = magicSquare1D[5];
    magicSquare[2][0] = magicSquare1D[6];
    magicSquare[2][1] = magicSquare1D[7];
    magicSquare[2][2] = magicSquare1D[8];
    
return 0;
}


int printArray(){
//print out values in given array
for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < columns; j++)
    {
        printf("%d ", magicSquare[i][j]);
    }
    printf("\n");
}
return 0;
}

// checks diagonals
bool diagonalCheck()
{

int diagonalSum1 = magicSquare[0][0] + magicSquare[1][1] + magicSquare[2][2];
int diagonalSum2 = magicSquare[0][2] + magicSquare[1][1] + magicSquare[2][0];

if ((diagonalSum1 && diagonalSum2 == 15) && (diagonalSum1 == diagonalSum2))
{
    return true;
}
else
{
    return false;
}
}

bool columnCheck2(){
    int columnSum1 = magicSquare[0][0] + magicSquare[1][0] + magicSquare[2][0];
    int columnSum2 = magicSquare[0][1] + magicSquare[1][1] + magicSquare[2][1];
    int columnSum3 = magicSquare[0][2] + magicSquare[1][2] + magicSquare[2][2];

    if ((columnSum1 == columnSum2 == columnSum3) && (columnSum1 && columnSum2 && columnSum3 == 15))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool rowCheck2(){
    int rowSum1 = magicSquare[0][0] + magicSquare[0][1] + magicSquare[0][2];
    int rowSum2 = magicSquare[1][0] + magicSquare[1][1] + magicSquare[1][2];
    int rowSum3 = magicSquare[2][0] + magicSquare[2][1] + magicSquare[2][2];

    if ((rowSum1 == rowSum2 == rowSum3) && (rowSum1 && rowSum2 && rowSum3 == 15))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// checks all criteria
int finalCheck(){

    do {
        printf("This is not a working magic square.\n");
        printArray();
        printf("This is attempt: %d\n", numberAttempts);
        numberAttempts++;
        randomize1DArray();
        fill2DArray();
        
    }
    while (!(columnCheck2() == true && diagonalCheck() == true && rowCheck2() == true));

    printf("This is a working magic square: \n");
    printArray();
    printf("The number of attempts was: %d", numberAttempts);

return 0;
}

int main(){

time_t t;
srand((unsigned)time(&t));

randomize1DArray();
fill2DArray();
finalCheck();


return 0;

}