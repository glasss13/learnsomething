#include <gtest/gtest.h>
#include <pricingutil.h>

TEST(sampleTest, sample) {
    EXPECT_EQ(4, 4);
}

TEST(PricingUtilTest, NormalInput) {
    PricingUtil util = PricingUtil();
    
    ASSERT_NEAR(util.calcVal(100.0, 0.05, 1.0), 95.0, 1e-4);
    ASSERT_NEAR(util.getVal(), 95.0, 1e-4);
}

TEST(PricingUtilTest, ZeroInterest) {
    PricingUtil util = PricingUtil();

    ASSERT_NEAR(util.calcVal(100, 0.00, 1.0), 90.0, 1e-4);
    ASSERT_NEAR(util.getVal(),90.0, 1e-4 );
}


TEST(PricingUtilTest, NegativePrevPrice) {
    PricingUtil util = PricingUtil();

    ASSERT_NEAR(util.calcVal(-100.0, 0.05, 1.0), -95.0, 1e-4);
    ASSERT_NEAR(util.getVal(), -95.0, 1e-4);
}


TEST(PricingUtilTest, ZeroOleoConstant) {
    PricingUtil util = PricingUtil();

    ASSERT_NEAR(util.calcVal(100.0, 0.05, 0.00), 0.0, 1e-4);
    ASSERT_NEAR(util.getVal(), 0.0, 1e-4);
}


TEST(PricingUtilTest, NegativeOleoConstant) {
    PricingUtil util = PricingUtil();

    ASSERT_NEAR(util.calcVal(100.0, 0.05, -1.0), -95.0, 1e-4);
    ASSERT_NEAR(util.getVal(), -95, 1e-4);
}

// Test case with all zeros.
TEST(PricingUtilTest, AllZeros) {
    PricingUtil util = PricingUtil();

    ASSERT_NEAR(util.calcVal(0.0, 0.00, 0.0), 0.0, 1e-4);
    ASSERT_NEAR(util.getVal(), 0.0, 1e-4);
}
