import string
import re


# Coleman-Liau index is computed as
# 0.0588 * L - 0.296 * S - 15.8
# L :average number of letters per 100 words
# S :average number of sentences per 100 words
# L : count the number of spaces + 1
def get_string():
    s = input("Text:")
    return s


def main():
    text = get_string()
    wordlist = text.split()
    total_slist = re.findall(r".*?[?!.]", text)
    words = len(wordlist)
    total_s = len(total_slist)
    total_l = 0
    for char in text:
        if char.isalpha():
            total_l += 1
    Letters = float((total_l / words) * 100)
    Sentences = float((total_s / words) * 100)
    Grade = round(0.0588 * Letters - 0.296 * Sentences - 15.8)
    if Grade < 1:
        print("Before Grade 1")
    elif Grade >= 1 and Grade <= 16:
        print("Grade", Grade)
    elif Grade > 16:
        print("Grade 16+")


main()
