import csv

from cs50 import SQL

# Open database
db = SQL("sqlite:///prophecy.db")

# Open CSV file
with open("students.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)
    header = reader.fieldnames

    data = list(reader)
    assign_idvalue = 1
    houseidvalue = 1
    house_ids = {}

    for char in data:
#try inserting the student id into the students table.
        student_exists = db.execute("SELECT id FROM students WHERE id = :id_value",
                                    id_value=char['id'])
        if not student_exists:
            db.execute("INSERT INTO students(id, student_name) VALUES(:id_value, :student_name_value)",
                        id_value=char['id'], student_name_value=char['student_name'])

        if char['house'] not in house_ids:
            db.execute("INSERT INTO houses(house_id, house, head) VALUES(:house_id, :house_name, :head_value)",
                       house_id=houseidvalue, house_name=char['house'], head_value=char['head'])
            house_ids[char['house']] = houseidvalue
            houseidvalue += 1

        house_id = house_ids[char['house']]

        db.execute("INSERT INTO assignment(assign_id, student_id, house_id) VALUES(:assign_id, :student_id, :house_id)",
                    assign_id=assign_idvalue, student_id=char['id'], house_id=house_id)

        assign_idvalue += 1
