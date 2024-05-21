from cs50 import get_float
import string  

def getchange():
    while True:
        try:
            n = get_float("Change:")
            if n >= 0.01:
                return n
        except ValueError:
            print("please input a value of min 0.01 (a penny)")


def main():
    coins = 0
    quarters = 25
    dimes = 10
    nickels = 5
    pennies = 1
    change = getchange()
    centsch = change * 100
    coins += int(centsch / quarters)
    if centsch >= 25:
        centsch -= quarters * (centsch // quarters)
    if centsch >= 10:
        centsch += int(centsch / dimes)
        centsch -= dimes * (centsch // dimes)
    if centsch >= 5:
        coins += int(centsch / nickels)
        centsch -= nickels * (centsch // nickels)
    if centsch >= 1:
        coins += int(centsch / pennies)
    coins = int(coins)
    print(coins)


main()
