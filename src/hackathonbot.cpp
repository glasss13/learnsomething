//
// Created by Ethan on 9/13/2023.
//

#include "hackathonbot.h"

static float raisePercentage(float newPrice, float oldPrice) {
    return (newPrice - oldPrice) / oldPrice * 100;
}

static float dropPercentage(float newPrice, float oldPrice) {
    return -raisePercentage(newPrice, oldPrice);
}

HackathonBot::HackathonBot()
    : balance(0)
    , holding(true)
    , daysUpInARow(0)
    , daysDownInARow(0)
    // Assume the initial stock cost was 100
    , purchasePrice(100)
    , prices { 100 }
    , windowsHolding(1)
    , lowFluctuationStreak(0) { }

void HackathonBot::takeAction(float price) {
    if (price > prices.back()) {
        daysUpInARow++;
        daysDownInARow = 0;
    } else if (price < prices.back()) {
        daysDownInARow++;
        daysUpInARow = 0;
    }

    prices.push_back(price);

    // check sell conditions
    if (holding) {
        if (windowsHolding >= 2 && std::abs(raisePercentage(prices[prices.size() - 1], prices[prices.size() - 2])) <= 5) {
            lowFluctuationStreak++;
        }

        // If the stock goes up in price for 52 windows, sell
        if (daysUpInARow == 52) {
            sell(price);
        }
        // If the stock goes down in price for 47 windows, sell
        else if (daysDownInARow == 47) {
            sell(price);
        }
        // If the stock drops by over 62% from the purchase price bought, sell
        else if (price < 0.38 * purchasePrice) {
            sell(price);
        }
        // If the stock raises by over 89% from the purchase price bought, sell
        else if (price > 1.89 * purchasePrice) {
            sell(price);
        }
        // If (after buying) the stock raises by >= 20%, drops by <= 15%,
        // raises again by >= 30%,
        // and the percent change in the 3 series window is up by >= 50% sell
        else if (windowsHolding >= 3
            && raisePercentage(prices[prices.size() - 3], prices[prices.size() - 4]) >= 20
            && dropPercentage(prices[prices.size() - 2], prices[prices.size() - 3]) <= 15
            && raisePercentage(prices[prices.size() - 1], prices[prices.size() - 2]) >= 30
            && raisePercentage(prices[prices.size() - 1], prices[prices.size() - 3]) >= 50) {
            sell(price);
        }
        // If (after buying) the stock drops by <= 15%, raises by >= 15%,
        // drops again by >= 25% and the percent change OVERALL is down by >= 45% sell
        else if (windowsHolding >= 3
            && dropPercentage(prices[prices.size() - 3], prices[prices.size() - 4]) <= 15
            && raisePercentage(prices[prices.size() - 2], prices[prices.size() - 3]) >= 15
            && dropPercentage(prices[prices.size() - 1], prices[prices.size() - 2]) >= 25
            && dropPercentage(prices[prices.size() - 1], purchasePrice) >= 45) {
            sell(price);
        }
        // If stock stays +-5% for 10 cycles (after buying), sell
        else if (lowFluctuationStreak == 10) {
            sell(price);
        }
    } else {
        // If the stock price is less than 52, buy
        if (price < 52) {
            buy(price);
        } else if (daysDownInARow == 5) {
            buy(price);
        }
    }

    if (holding) {
        windowsHolding++;
    }
}

void HackathonBot::buy(float price) {
    balance -= price;
    holding = true;
    daysUpInARow = 0;
    daysDownInARow = 0;
    purchasePrice = price;
    windowsHolding = 0;
    lowFluctuationStreak = 0;
}

void HackathonBot::sell(float price) {
    balance += price;
    holding = false;
    daysUpInARow = 0;
    daysDownInARow = 0;
    windowsHolding = 0;
    lowFluctuationStreak = 0;
}

double HackathonBot::getBalance() {
    return balance;
}
bool HackathonBot::isHolding() {
    return holding;
}
