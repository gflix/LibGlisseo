#include <gtest/gtest.h>
#include <glisseo/Glisseo.h>

TEST(Glisseo, PackageInfo)
{
    EXPECT_EQ(Glisseo::Glisseo::getPackageInfo(), "libglisseo 0.8.1");
}
