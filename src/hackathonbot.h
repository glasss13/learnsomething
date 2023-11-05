//
// Created by Ethan on 9/13/2023.
//

#include <vector>
#include "action.h"

#ifndef LEARNSOMETHING_HACKATHONBOT_H
#define LEARNSOMETHING_HACKATHONBOT_H

class HackathonBot {
public:
    HackathonBot();
    void takeAction(float price);
    double getBalance();
    bool isHolding();
    void buy(float price);
    void sell(float price);
    size_t lowFluctuationStreak;
private:
    float balance;
    bool holding;
    size_t daysUpInARow;
    size_t daysDownInARow;
    float purchasePrice;
    std::vector<float> prices;
    size_t windowsHolding;
    
};

#endif //LEARNSOMETHING_HACKATHONBOT_H
