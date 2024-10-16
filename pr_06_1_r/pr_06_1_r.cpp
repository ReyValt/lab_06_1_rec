#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* b, const int size, const int min, const int max, int i)
{
    b[i] = rand() % (max - min + 1) + min;
    if (i < size - 1)
        Create(b, size, min, max, i + 1);
}

void Print(int* b, const int size)
{
    cout << "b = {";
    for (int i = 0; i < size; i++)
        cout << setw(4) << b[i];
    cout << " }" << endl;
}

int SumOfElements(int* b, const int size, int i)
{
    if (i == size)
        return 0;

    if (b[i] % 2 == 0 && b[i] < 0)
        return b[i] + SumOfElements(b, size, i + 1);
    else
        return SumOfElements(b, size, i + 1);
}

int CountOfElements(int* b, const int size, int i)
{
    if (i == size)
        return 0;

    if (b[i] % 2 == 0 && b[i] < 0)
        return 1 + CountOfElements(b, size, i + 1);
    else
        return CountOfElements(b, size, i + 1);
}

void ReplaceWithZeros(int* b, const int size, int i)
{
    if (i == size)
        return;

    if (b[i] % 2 == 0 && b[i] < 0)
        b[i] = 0;

    ReplaceWithZeros(b, size, i + 1);
}

int main()
{
    srand((unsigned)time(NULL));
    const int n = 24;
    const int min = -15;
    const int max = 75;
    int b[n];

    Create(b, n, min, max, 0);
    Print(b, n);

    int sum = SumOfElements(b, n, 0);
    int count = CountOfElements(b, n, 0);

    ReplaceWithZeros(b, n, 0);


    cout << "Count: " << count << endl;
    cout << "Sum: " << sum << endl;

    Print(b, n);

    return 0;
}