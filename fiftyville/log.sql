-- Keep a log of any SQL queries you execute as you solve the mystery.
-- First I m getting a report of the crime
SELECT description
FROM crime_scene_reports
WHERE year = 2023
AND month = 07
AND day = 28
AND street = 'Humphrey Street';
-- | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
-- | Littering took place at 16:36. No known witnesses.
-- Now that i have more information on the crime scene reports for that day i know the report for my crime for that day is with three witnesses at the bakery. Let s see what they say
 SELECT transcript
 FROM interviews
 WHERE year = 2023
 AND month = 07
 AND day = 28;
 -- Now we check for the plates that where at the bakery within 10 minutes of the crime following the interview transcripts
 SELECT license_plate
 FROM bakery_security_logs
 WHERE year = 2023
 AND month = 07
 AND day = 28
 AND hour = 10
 AND minute BETWEEN 15 and 25;
 -- And i want all the information on the people with those plates:
 SELECT id,name,phone_number,passport_number
 FROM people
 WHERE license_plate IN('5P2BI95','94KL13X','6P58WS2','4328GD8','G412CB7','L9
3JTIZ','322W7JE','0NTHK55');
-- now I m checking who withdrew money in that area:
SELECT transaction_type,amount,account_number
FROM atm_transactions
WHERE year = 2023
AND month = 07
AND day = 28
AND atm_location = 'Humphrey Lane'
AND transaction_type = 'withdraw';
-- Now I m going to cross check those info
SELECT DISTINCT people.id, people.name, people.phone_number, people.passport_number, bank_accounts.account_number
FROM people JOIN bank_accounts
ON people.id = bank_accounts.person_id
JOIN atm_transactions
ON atm_transactions.account_number = bank_accounts.account_number
WHERE people.id IN (221103,243696,396669,398010,467400,514354,560886,6
86048);
-- now checking who is going that day for the flight:
SELECT passport_number,flights.id,origin_airport_id,destination_airport_id,hour,minute FROM passengers JOIN flights ON flights.id =
passengers.flight_id WHERE passport_number IN (7049073643,8496433585,3
592750733,5773159633) AND year = 2023 AND month = 07 AND day = 29 ORDE
R BY hour ASC;
-- now i will check who is the thief and the accomplice:
SELECT phone_number, name
FROM people
WHERE passport_number IN (5773159633,8496433585);
-- checking the phone calls:
SELECT caller,receiver
FROM phone_calls
WHERE year = 2023 AND month = 07 AND day = 28
AND caller IN('(389) 555-5198','(367) 555-5533')
AND duration <= 60;
--checking the thief's city
SELECT city FROM airports WHERE id = 4;
