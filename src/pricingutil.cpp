#include "pricingutil.h"

PricingUtil::PricingUtil() : val(0) {}

float PricingUtil::getVal() {
    return val;
}

float PricingUtil::calcVal(float prevPrice, float interest, float oleoConstant) {
    // Theoretical Value = (Previous Price * (0.9 + Interest Rate)) * Oleo Constant.
    float value = prevPrice * (0.9 + interest) * oleoConstant;
    val = value;
    return value;
}


