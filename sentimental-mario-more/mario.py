def get_int():
    while True:
        try:
            n = int(input("Height:"))
            if n >= 1 and n <= 8:
                return n
        except ValueError:
            print("please input a value between 1 and 8")


def main():
    height = get_int()
    bricks = 1
    gap = 2
    spaces = height - 1
    for _ in range(height):
        print(" " * spaces + "#" * bricks + " " * gap + "#" * bricks)
        spaces -= 1
        bricks += 1


main()
