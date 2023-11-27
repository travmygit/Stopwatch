#include "Stopwatch.h"

int main()
{
    {
        Stopwatch sw("Activity");
        int sum = 0;
        int n = 100000000;
        for (int i = 0; i < n; ++i)
        {
            sum += i;
        }
    }
    return 0;
}