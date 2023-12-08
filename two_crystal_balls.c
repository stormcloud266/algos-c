#include <stdbool.h>
#include <stdio.h>
#include <math.h>

int find_break_point(int size, bool *array);

int main()
{
    bool floors[9] = {false, false, false, true, true, true, true, true, true};
    int size = sizeof(floors) / sizeof(floors[0]);

    int break_point = find_break_point(size, floors);

    printf("The crystal balls will break if dropped from floor %d", break_point);
    
    return 0;
}

int find_break_point(int size, bool *floors)
{
    int jump = floor(sqrt(size));
    int i = 0;

    for (; i < size; i += jump)
    {
        if (floors[i])
        {
            if (i == 0)
                return 0;
            break;
        }
    }

    i -= jump;

    for (int j = 0; j <= jump && i < size; j++, i++)
    {
        if (floors[i])
            return i;
    }

    return -1;
}