[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/B3ZPAbP9)
[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/fa6OjJPw)
# Assignment-2

## Chapter 3

### Exercise 1 (20 points)

Write a program that prompts the user to enter a date (ex. 3/20/2015) and outputs the day of the week corresponding to that date. You should use the following functions in your implementation: bool isLeapYear(int year); This function should return true if year is a leap year and false if it is not. 

Here is pseudocode to determine a leap year: leap_year = ((year divisible by 400) or (year divisible by 4 and year not divisible by 100)) 

int getCenturyValue(int year); This function should take the first two digits of the year (i.e., the century), divide by 4, and save the remainder. Subtract the remainder from 3 and return this value multiplied by 2. For example, the year 2008 becomes (20/4) = 5 remainder 0. 3 - 0 = 3. Return 3 * 2 = 6. 

int getYearValue(int year); This function computes a value based on the years since the beginning of the century. First, extract the last two digits of the year. For example, 08 is extracted for 2008. Next, factor in leap years. 

Divide the value from the previous step by 4 and discard the remainder. Add the two results together and return this value. For example, from 2008 we extract 08. Then (8/4) = 2 remainder 0. Return 2 + 8 = 10. 

int getMonthValue(int month, int year); This function should return a value based on the following table and will require invoking the isLeapYear function: MONTH RETURN VALUE January 0 (6 if year is a leap year) February 3 (2 if year is a leap year) March 3 April 6 May 1 June 4 July 6 August 2 September 5 October 0 November 3 December 5

Your main function should compute the day of the week using this formula:
(day of month) + (getMonthValue) + (getYearValue) + (getCenturyValue)
Then, divide this sum by 7 and save the remainder. The value of the remainder
corresponds to the day of the week.

Sunday = 0
Monday = 1
Tuesday = 2
Wednesday = 3
Thursday = 4
Friday = 5
Saturday = 6

Print the corresponding day in English.


## Chapter 4
### Exercise 2 (20 points)

Write a program that prompts the user to enter an amount of change between 1 and 99
cents and prints out what coins can be used to make that change. 

Use coin denominations
of 25 cents (quarters), 10 cents (dimes), and 1 cent (pennies). Do not use nickels
and half-dollar coins. Your program should implement the following function (among others):
void computeCoin(int coinValue, int& number, int& amountLeft);

// Precondition: 0 < coinValue < 100; 0 <= amountLeft < 100.

// Postcondition: number has been set equal to the maximum number

// of coins of denomination coinValue cents that can be obtained

// from amountLeft cents. amountLeft has been decreased by the

// value of the coins, that is, decreased by (number * coinValue).

For example, if the value of the variable amountLeft is 86, after the following call:
computeCoins(25,number,amountLeft);

the value of number will be 3 and the value of amountLeft will be 11, because if you take
3 quarters from 86 cents, that leaves 11 cents.
Make sure your program allows the user to calculate change from multiple values. Prompt the
user to enter 'Y' to calculate another value and any other value to quit.

### Exercise 3 (20 points)

Write a program that prompts the user to enter a running pace in minutes and
seconds and kilometers per hour and converts it to miles per hour.

You should use an overloaded function called convertToMPH. The first definition
should take two integers (minutes and seconds) and return the speed in MPH as
a double. The second definition should take kilometers per hour as a double and
return the speed in MPH as a double. HINT: 1 mile is approximately 1.61 kilometers.
