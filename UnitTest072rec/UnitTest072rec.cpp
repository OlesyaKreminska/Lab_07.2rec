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
            // ����������� ���������
            int rowNo = 0;
            int colCount = 5;
            int Low = -10;
            int High = 10;

            // ��������� ����� �������
            int** a = new int* [1]; // ���� �����
            a[0] = new int[colCount];

            // ��������� ������� ��� ���������� �����
            CreateRow(a, rowNo, colCount, Low, High, 0);

            // ����������, �� �� �������� ����� ����������� � ������� [Low, High]
            for (int j = 0; j < colCount; j++) {
                Assert::IsTrue(a[0][j] >= Low && a[0][j] <= High, L"Element out of range!");
            }

            // ��������� ���'��
            delete[] a[0];
            delete[] a;
        }
    };
}
