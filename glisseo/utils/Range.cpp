#include <glisseo/utils/Range.h>

namespace Glisseo {

bool withinRange(int value, int min, int max)
{
    return
        value >= min &&
        value <= max;
}

int restrictToRange(int value, int min, int max)
{
    if (value < min)
    {
        return min;
    }
    if (value > max)
    {
        return max;
    }
    return value;
}

} /* namespace Glisseo */
