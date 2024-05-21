import string


def get_int():
    while True:
        n = input("Card Number:")
        for char in n:
            if (
                char in string.ascii_letters
                or char in string.punctuation
                or char == " "
            ):
                print("INVALID")
                exit()

            else:
                return int(n)


def checksum(number):
    temp_other = 0
    sum_other = 0
    sum_rest = 0
    tempnum_a = number
    tempnum_b = number
    while tempnum_a > 0:
        tempnum_a //= 10
        temp_other = 0
        temp_other = (tempnum_a % 10) * 2
        while temp_other > 0:
            sum_other += temp_other % 10
            temp_other //= 10
        tempnum_a //= 10
    while tempnum_b > 0:
        sum_rest += tempnum_b % 10
        tempnum_b //= 100
    if (sum_other + sum_rest) % 10 == 0:
        return True
    else:
        return False


def main():
    card_number = get_int()
    temp = card_number
    length = len(str(temp))
    if checksum(card_number) == False:
        print("INVALID")
    if length != 13 and length != 15 and length != 16:
        print("INVALID")
    if checksum(card_number) == True:
        temp15 = card_number // 10000000000000
        temp16 = card_number // 1000000000000000
        temp16Master = card_number // 100000000000000
        temp13 = card_number // 1000000000000
        if length == 15:
            if temp15 == 34 or temp15 == 37:
                print("AMEX")
            else:
                print("INVALID")
        if length == 16:
            if temp16Master >= 50 and temp16Master <= 55:
                print("MASTERCARD")
            elif temp16 == 4:
                print("VISA")
            else:
                print("INVALID")
        if length == 13:
            if temp13 == 4:
                print("VISA")
            else:
                print("INVALID")


main()
