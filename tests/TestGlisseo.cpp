#include <gtest/gtest.h>
#include <glisseo/Glisseo.h>

TEST(Glisseo, PackageInfo)
{
    EXPECT_EQ(Flix::Glisseo::getPackageInfo(), "libglisseo 0.3.3");
}
