class Exchange:
    def __init__(self, initialBalance):
        self.balance = initialBalance
        self.buys = []
        self.sells = []

    def add_trade(self, trade):
        if self.side == "sell":
            self.sells.append(trade)
        elif self.side == "buy":
            self.buys.append(trade)
        else:
            raise ValueError("Invalid trade side")

        return self.match_trades()


class Trade:
    def __init__(self, quantity, price, side):
        self.quantity = quantity
        self.price = price
        self.side = side
