#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define L 50
#define C 50

void InputMatrixRand(int Array[L][C], int Lines, int Colums);
void PrintMatrix(int Array[L][C], int Lines, int Colums);
void PrintResult(int Array[L][C], int Lines, int Colums);



int main() 
{
    int Lines;
    int Colums;

    printf("How many lines do you want to see in your Matrix?\n");
    scanf("%d", &Lines);

    printf("How many columns do you want to see in your Matrix?\n");
    scanf("%d", &Colums);

    int Array[L][C];

    InputMatrixRand(Array, Lines, Colums);
    PrintMatrix(Array, Lines, Colums);
    PrintResult(Array, Lines, Colums);

    return 0;
};

void InputMatrixRand(int Array[L][C], int Lines, int Colums) 
{
    srand(time(NULL));
   
    for(int i = 0; i < Lines; i++)
    {
        for(int j = 0; j < Colums; j++)
        {
            Array[i][j] = rand() % 201 - 100;
        }
    }
};

void PrintMatrix(int Array[L][C], int Lines, int Colums) 
{
    printf("\nYour Matrix look like: \n");
    for(int i = 0; i < Lines; i++)
    { 
        for(int j = 0; j < Colums; j++)
        {
            printf("%10d", Array[i][j]);
        }
        printf("\n");
    }
};

void PrintResult(int Array[L][C], int Lines, int Colums)
{
    printf("\nElements in the order: ");
    int i = 0, j = 0;
    for (int k = 0; k < Lines + Colums - 1; k++) // проходимо по всім елементам діагоналі
    {
        if (k % 2 != 0) // якщо індекс діагоналі парний
        {
            // виводимо елементи з нижнього рядка до верхнього вздовж діагоналі
            while (i >= 0 && j < Colums) // доки не досягнуто початку діагоналі або кінця рядка
            {
                printf("%d ", Array[i][j]); // виводимо поточний елемент
                i--; // зменшуємо індекс рядка
                j++; // збільшуємо індекс стовпця
            }
            if (j < Colums) // якщо ще не досягли кінця рядка
            {
                i++; // збільшуємо індекс рядка
            }
            else // якщо досягли кінця рядка
            {
                i += 2; // переходимо до наступного рядка
                j--; // зменшуємо індекс стовпця
            }
        }
        else // якщо індекс діагоналі не парний
        {
            // виводимо елементи з верхнього рядка до нижнього вздовж діагоналі
            while (i < Lines && j >= 0) // доки не досягнуто кінця діагоналі або початку стовпця
            {
                printf("%d ", Array[i][j]); // виводимо поточний елемент
                i++; // збільшуємо індекс рядка
                j--; // зменшуємо індекс стовпця
            }
            if (i < Lines) // якщо ще не досягли кінця діагоналі
            {
                j++; // збільшуємо індекс стовпця
            }
            else // якщо досягли кінця діагоналі
            {
                i--; // зменшуємо індекс рядка
                j += 2; // переходимо до наступного стовпця
            }
        }
    }
    printf("\n");
};
