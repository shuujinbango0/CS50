def get_int():
    while True:
        try:
            height = int(input("Height:"))
            if height >= 1 and height <= 8:
                return height
        except ValueError:
            print("please input a value between 1 and 8")


def main():
    height = get_int()
    # what s the value of spaces?
    spaces = height - 1
    bricks = 1
    for _ in range(height):
        print(" " * spaces + "#" * bricks)
        spaces -= 1
        bricks += 1


main()
