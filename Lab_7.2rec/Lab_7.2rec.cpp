#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void CreateRow(int** a, const int rowNo, const int n, const int Low, const int High, int colNo);
void CreateMatrix(int** a, const int k, const int n, const int Low, const int High, int rowNo);
void PrintRow(int** a, const int rowNo, const int n, int colNo);
void PrintMatrix(int** a, const int k, const int n, int rowNo);
void FindMinMaxInCol(int** a, const int k, const int j, int row, int& minIdx, int& maxIdx);
void SwapMaxMinInOddCols(int** a, const int k, const int n, int col);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -10, High = 10;
    int k, n;

    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    // Створюємо і виводимо початкову матрицю
    CreateMatrix(a, k, n, Low, High, 0);
    PrintMatrix(a, k, n, 0);

    // Міняємо місцями максимальний і мінімальний елементи непарних стовпців
    SwapMaxMinInOddCols(a, k, n, 1); // Починаємо з 1-го стовпця (непарний)

    // Виводимо модифіковану матрицю
    PrintMatrix(a, k, n, 0);

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void CreateRow(int** a, const int rowNo, const int n, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < n - 1)
        CreateRow(a, rowNo, n, Low, High, colNo + 1);
}

void CreateMatrix(int** a, const int k, const int n, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, n, Low, High, 0);
    if (rowNo < k - 1)
        CreateMatrix(a, k, n, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int n, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < n - 1)
        PrintRow(a, rowNo, n, colNo + 1);
    else
        cout << endl;
}

void PrintMatrix(int** a, const int k, const int n, int rowNo)
{
    PrintRow(a, rowNo, n, 0);
    if (rowNo < k - 1)
        PrintMatrix(a, k, n, rowNo + 1);
    else
        cout << endl;
}

void FindMinMaxInCol(int** a, const int k, const int j, int row, int& minIdx, int& maxIdx)
{
    if (row == 0)
    {
        minIdx = maxIdx = 0;
    }
    else
    {
        if (a[row][j] < a[minIdx][j])
            minIdx = row;
        if (a[row][j] > a[maxIdx][j])
            maxIdx = row;
    }
    if (row < k - 1)
        FindMinMaxInCol(a, k, j, row + 1, minIdx, maxIdx);
}

void SwapMaxMinInOddCols(int** a, const int k, const int n, int col)
{
    if (col < n)
    {
        int minIdx = 0, maxIdx = 0;
        FindMinMaxInCol(a, k, col, 0, minIdx, maxIdx);

        // Міняємо місцями, якщо індекси не однакові
        if (minIdx != maxIdx)
        {
            int temp = a[minIdx][col];
            a[minIdx][col] = a[maxIdx][col];
            a[maxIdx][col] = temp;
        }

        SwapMaxMinInOddCols(a, k, n, col + 2); // Переходимо до наступного непарного стовпця
    }
}