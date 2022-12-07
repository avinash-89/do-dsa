#include <bits/stdc++.h>
using namespace std;

int NumberOfSetBits(int n)
{
    int countSetBits = 0;
    while (n)
    {
        cout << n << "before\n";
        n = n & (n - 1);
        cout << n << "after\n";
        countSetBits++;
    }
    return countSetBits;
}

int bitsetTable256[256];

void LookUpInitalize()
{
    bitsetTable256[0] = 0;
    for (int i = 0; i < 256; i++)
    {
        bitsetTable256[i] = (i & 1) + bitsetTable256[i / 2];
    }
}

int countSetBitFromTable(int n)
{
    return (bitsetTable256[n & 0xff] + bitsetTable256[(n >> 8) & 0xff] + bitsetTable256[(n >> 16) & 0xff] + bitsetTable256[n >> 24]);
}

int main()
{
    int n;
    cin >> n;
    cout << NumberOfSetBits(n);
    cout << countSetBitFromTable(n);
    return 0;
}