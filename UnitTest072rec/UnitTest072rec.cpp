#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.2rec/Lab_7.2rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab71Rec
{
    TEST_CLASS(UnitTestLab71Rec)
    {
    public:

        TEST_METHOD(TestCreateRow)
        {
            // Ініціалізація параметрів
            int rowNo = 0;
            int colCount = 5;
            int Low = -10;
            int High = 10;

            // Створюємо рядок матриці
            int** a = new int* [1]; // Один рядок
            a[0] = new int[colCount];

            // Викликаємо функцію для заповнення рядка
            CreateRow(a, rowNo, colCount, Low, High, 0);

            // Перевіряємо, що всі елементи рядка знаходяться у діапазоні [Low, High]
            for (int j = 0; j < colCount; j++) {
                Assert::IsTrue(a[0][j] >= Low && a[0][j] <= High, L"Element out of range!");
            }

            // Звільнення пам'яті
            delete[] a[0];
            delete[] a;
        }
    };
}
