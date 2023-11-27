# Stopwatch
C++ RAII implementation of Stopwatch.

Requirement: C++11

Usage:

```
{
    Stopwatch sw("Activity");
    int sum = 0;
    int n = 100000000;
    for (int i = 0; i < n; ++i)
    {
        sum += i;
    }
}
```

Output:

```
Activity: Start
Activity: Stop 481ms
```