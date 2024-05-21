import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):

    previous_cases = {}
    new_cases = {}
    rows = list(reader)
    row_index = 0

    for row_index in range(len(rows)):
        current_row = rows[row_index]
        state = current_row['state']
        cases = int(current_row['cases'])
        if state in previous_cases:
            new_cases[state] = []
            previous_cases[state].append(cases)
        else:
            previous_cases[state] = [cases]

        if len(previous_cases[state]) > 14:
            previous_cases[state].pop(0)
        if len(previous_cases[state]) > 1:
            for i in range(1, len(previous_cases[state])):
                difference = float(previous_cases[state][i] - previous_cases[state][i - 1])
                new_cases[state].append(difference)

    return new_cases
# TODO: Calculate and print out seven day average for given state


def comparative_averages(new_cases, states):
    change = {}
    avg8to14 = {}
    avg0to7 = {}
    for state in states:
        totalweek8to14 = sum(new_cases[state][0:7])
        avg8to14[state] = totalweek8to14 / 7
        totalweek0to7 = sum(new_cases[state][8:14])
        avg0to7[state] = totalweek0to7 / 7
        try:
            change[state] = ((avg8to14[state] - avg0to7[state]) / avg8to14[state]) * 100
            rounded_change = round(change[state])
            rounded_avg8to14 = round(avg8to14[state])
        except ZeroDivisionError:
            print("zero division error")

        print(f"{state} had a 7-day average of {str(rounded_avg8to14)}, a decrease of {str(rounded_change)}%.")


main()
