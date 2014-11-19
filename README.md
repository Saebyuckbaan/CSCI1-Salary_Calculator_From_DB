CSCI1-Salary_Calculator_From_DB
==============================

Reading data from text file based data base to execute the calculator


//A complete program 

ID block ---------------------------------------+ 
Programmer : Davis Yi + 
Course : Computer Science 1 + 
Assignment : Assignment 3 + 
Due Date : April 21 2009 + 
+---------------------------------------------------- 

/*
Program statement * This program will calculate salary for four different types of hourly employee. * ************************ Analysis *****************************

Data needed
Name (Full name first and last)
ddress (street, City, states, zip code)
SSN (No – needed read it as a long number)
Hours worked Hourly pay rate
Type of Benefit
Skill level

Constants given Skill level 
1 – $15.00
2 – $25.00 
3 – $72.00 
4 – $125.00 

Type of Benefits
0 - $0 
1 - $32.50 
2 - $52.50 
3 - $62.50 

Overtime rate 
40 ~ 50 – 1.5*(Pay rate*Hour) 
50 ~ 60 – 2*(Pay rate*Hour) 
Retirement plan for only Skill level 4 Up to 5% from original salary(2digit) 

Tax rate
0 – 2000 = 0% 
2000.01 – 3000.00 = 3% of amount 
over $2000 3000.01 – 4000.00 = 1% of first $3000 + 5% of the remainder 
4000.01 – 5000.00 = 1% of first $3000 + 5% of the next $1000 + 7% of the remainder Over 
5000.01 =1% of first $3000 + 5% of the next $1000 + 7% of the next $1000 + 1% for every $1000 over $5000 

Calculations
Overtime rate 
IF (Hour > 40) -> Hour – 40= Hour_2
If (Hour_2 =< 10 ) -> 1.5*Hour_2
if (Hour_2 =< 20) -> (1.5*10) + ((Hour_2-10) * 2)
Pay_rate = ((Original Hour-Over hour)*Payment of the skill rate) + Overtime rate 

Retirement plan
If skill level 4 only
Pay rate * retirement rate = Retire contribution

Subtotal = Pay rate - Benefit – Retire contribution
Tax Calculation
if Sub total is..
less than 2000 - skip
2000.01 - 3000.00 = (sub total - 2000.01)*3%
3000.01 - 4000.00 = (3000*1%) + {(sub total -3000)*5%}
4000.01 - 5000.00 = (3000*1%) + (1000*5%) +{(sub total -4000)*7%}
Over 5000.01 = (3000*1%) + (1000*5%) +{1000*7%} + {X(1000*1%)} X= Pay_rate-5000 for over 5000.01 only, X must drop the decimals.

Print results Full name of the Employee Tax ID(SSN)
Adress
Skill level
Type of Benefit
Tax amount owed
Gross Salary
Net Salary
Retirement Contribution percentage(0 if not participating)

************************ Algorithm *****************************
Step 1 - Input
Prompt name and directory of Input text file
Prompt name and directory of output text file
Prompt name and directory of extra credit output text file
Error for Input text file
Error for Bad datas

Step 2 - Process
Overtime rate(Over_Pay) 
for over 40 hour -> (Hour – 40)= Hour_2
If (Hour_2 =< 10 ) -> 1.5*Hour_2
if (Hour_2 =< 20) -> (1.5*10) + ((Hour_2-10) * 2)

Gross Salary
Gross_Sal = ((Hour-Hour_2)*Pay_rate) + Over_Pay
Retirement plan If skill level 4 only 
Gross_Sal * rate_retire_con = retire_con_pay

Subtotal
Sub_tot = Gross_Sal – benefit – Retire_con_pay
Tax Calculation if Sub total is.. 
less than 2000 = 0 2000.01 - 3000.00 = (sub_tot - 2000.01).03 
3000.01 - 4000.00 = (3000.01) + {(sub_tot -3000).05}
4000.01 - 5000.00 = (3000.01) + (1000*.05) +{( sub_tot -4000).07} 
Over 5000.01 = (3000.01) + (1000*.05) +{1000*.07} + {X(1000*.01)} 
{X= Pay_rate-5000} - for over 5000.01 only, X must drop the decimals. 

Step 3 - Output 
*Regular output
- Print The guideline for how to read the data
-Print Full Name, gross salary, benefit, contribution cost, taxes, net salary for each worker in each one of the lines -print Total gross salaries paid
-print total benefit collected
-print total contributions to retirement funds
-print total Taxes collected
-print total net salaries paid

*Extra credit
-print full name
-print Gross salary
-print Medical Benefits
-Print Retirement Contribution(rate, company, employee, total)
-print Taxes owed
-print net salary

*Errors
-Print error message when user gave wrong input text file
-print error message called “Bad data” instead of any data for regular input when user gave wrong data input
************************ End of Algorithm *****************************/
