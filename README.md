CSCI1-Salary_Calculator_From_DB
==============================

Reading data from text file based data base to execute the calculator


ID block ---------------------------------------+  <br>
Programmer : Davis Yi + <br>
Course : Computer Science 1 +<br> 
Assignment : Assignment 3 + <br>
Due Date : April 21 2009 + <br>
+---------------------------------------------------- <br>

/*<br>
Program statement * This program will calculate salary for four different types of hourly employee. *<br> ************************ Analysis *****************************<br>

Data needed<br>
Name (Full name first and last)<br>
ddress (street, City, states, zip code)<br>
SSN (No – needed read it as a long number)<br>
Hours worked Hourly pay rate<br>
Type of Benefit<br>
Skill level<br>

Constants given Skill level <br>
1 – $15.00<br>
2 – $25.00 <br>
3 – $72.00 <br>
4 – $125.00 <br>

Type of Benefits<br>
0 - $0 <br>
1 - $32.50 <br>
2 - $52.50 <br>
3 - $62.50 <br>

Overtime rate <br>
40 ~ 50 – 1.5*(Pay rate*Hour) <br>
50 ~ 60 – 2*(Pay rate*Hour) <br>
Retirement plan for only Skill level 4 Up to 5% from original salary(2digit) <br>

Tax rate<br>
0 – 2000 = 0% <br>
2000.01 – 3000.00 = 3% of amount <br>
over $2000 3000.01 – 4000.00 = 1% of first $3000 + 5% of the remainder <br>
4000.01 – 5000.00 = 1% of first $3000 + 5% of the next $1000 + 7% of the remainder Over <br>
5000.01 =1% of first $3000 + 5% of the next $1000 + 7% of the next $1000 + 1% for every $1000 over $5000 <br>

Calculations<br>
Overtime rate <br>
IF (Hour > 40) -> Hour – 40= Hour_2<br>
If (Hour_2 =< 10 ) -> 1.5*Hour_2<br>
if (Hour_2 =< 20) -> (1.5*10) + ((Hour_2-10) * 2)<br>
Pay_rate = ((Original Hour-Over hour)*Payment of the skill rate) + Overtime rate <br>

Retirement plan<br>
If skill level 4 only<br>
Pay rate * retirement rate = Retire contribution<br>

Subtotal = Pay rate - Benefit – Retire contribution<br>
Tax Calculation<br>
if Sub total is..<br>
less than 2000 - skip<br>
2000.01 - 3000.00 = (sub total - 2000.01)*3%<br>
3000.01 - 4000.00 = (3000*1%) + {(sub total -3000)*5%}<br>
4000.01 - 5000.00 = (3000*1%) + (1000*5%) +{(sub total -4000)*7%}<br>
Over 5000.01 = (3000*1%) + (1000*5%) +{1000*7%} + {X(1000*1%)} <br>
X= Pay_rate-5000 for over 5000.01 only, X must drop the decimals.<br>

Print results Full name of the Employee Tax ID(SSN)<br>
Adress<br>
Skill level<br>
Type of Benefit<br>
Tax amount owed<br>
Gross Salary<br>
Net Salary<br>
Retirement Contribution percentage(0 if not participating)<br>

************************ Algorithm *****************************<br>
<b>Step 1 - Input<br></b>
Prompt name and directory of Input text file<br>
Prompt name and directory of output text file<br>
Prompt name and directory of extra credit output text file<br>
Error for Input text file<br>
Error for Bad datas<br>

<b>Step 2 - Process<br></b>
Overtime rate(Over_Pay) <br>
for over 40 hour -> (Hour – 40)= Hour_2<br>
If (Hour_2 =< 10 ) -> 1.5*Hour_2<br>
if (Hour_2 =< 20) -> (1.5*10) + ((Hour_2-10) * 2)<br>

Gross Salary<br>
Gross_Sal = ((Hour-Hour_2)*Pay_rate) + Over_Pay<br>
Retirement plan If skill level 4 only<br> 
Gross_Sal * rate_retire_con = retire_con_pay<br>

Subtotal<br>
Sub_tot = Gross_Sal – benefit – Retire_con_pay<br>
Tax Calculation if Sub total is..<br> 
less than 2000 = 0 2000.01 - 3000.00 = (sub_tot - 2000.01).03 <br>
3000.01 - 4000.00 = (3000.01) + {(sub_tot -3000).05}<br>
4000.01 - 5000.00 = (3000.01) + (1000*.05) +{( sub_tot -4000).07} <br>
Over 5000.01 = (3000.01) + (1000*.05) +{1000*.07} + {X(1000*.01)}<br> 
{X= Pay_rate-5000} - for over 5000.01 only, X must drop the decimals. <br>

<b>Step 3 - Output <br></b>
*Regular output<br>
- Print The guideline for how to read the data<br>
-Print Full Name, gross salary, benefit, contribution cost, taxes, net salary for each worker in each one of the lines <br>
-print Total gross salaries paid<br>
-print total benefit collected<br>
-print total contributions to retirement funds<br>
-print total Taxes collected<br>
-print total net salaries paid<br>

*Extra credit<br>
-print full name<br>
-print Gross salary<br>
-print Medical Benefits<br>
-Print Retirement Contribution(rate, company, employee, total)<br>
-print Taxes owed<br>
-print net salary<br>

*Errors<br>
-Print error message when user gave wrong input text file<br>
-print error message called “Bad data” instead of any data for regular input when user gave wrong data input<br>
************************ End of Algorithm *****************************/<br>
