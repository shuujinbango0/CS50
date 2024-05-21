from pyfiglet import Figlet
import sys
import random

figlet = Figlet()
fontlist = figlet.getFonts()
text =input("Text:")

if len(sys.argv) == 1:
    randomfont = random.choice(fontlist)
    figlet.setFont(font=randomfont)
    print(figlet.renderText(text))

elif len(sys.argv) == 3:
    if (sys.argv[1] == "-f" or sys.argv[1] == "--font") and sys.argv[2] in fontlist:
        figlet.setFont(font=sys.argv[2])
        print(figlet.renderText(text))
    else:
        print("incorrect input")
        sys.exit()
else:
    print("please input two command line arguments: -f and the font name")
    sys.exit()



