/*A complete program 
ID block  ---------------------------------------+ 
+ Programmer : 	Davis Yi  	           	+ 
+ Course     : 	Computer Science 1    	+ 
+ Assignment : 	Assignment 3	      	+ 
+ Due Date   : 	April 21 2009          	+
+----------------------------------------------------
Program statement *  
This program will calculate salary four different types of hourly employee. 
* ************************ Analysis *****************************	  
1. Data needed 	
Name (Full name first and last) 	
Address (street, City, states, zip code) 	
SSN (No – needed read it as a number) 	
Hours worked 	
Hourly pay rate 	
Type of Benefit 	
Skill level  

2. Constants given 

Skill level  
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

Retirement plan
only Skill level 4 Up to 5% from original salary(2digit)  

Tax rate  
0 – 2000 = 0% 
2000.01 – 3000.00 = 3% of amount over $2000 
3000.01 – 4000.00 = 1% of first $3000 + 5% of the remainder 
4000.01 – 5000.00 = 1% of first $3000 + 5% of the next $1000 + 7% of the remainder
Over 5000.01 =1% of first $3000 + 5% of the next $1000 + 7% of the next $1000 + 1%, every $1000 over $5000 

3. Calculations 	
*Overtime rate 	
	If the work hour is over 40 hours then “Work Hour – 40= over work hour”
	If the overwork hour is less than 10 hours then
	Overtime Pay rate = 1.5* over work hour
	If the overwork hour is more than 10 hours and less than 20 hours then 
	Over time Pay rate = pay rate[(1.5* 10hr) +(2.0* rest of overwork hour)]  Pay rate = ((Original Hour-Over hour)*Payment of the skill rate) + Overtime rate 	
*Retirement plan 	
skill level 4 only 		   
Pay rate * retirement rate = Retire contribution

*Subtotal = Pay rate - Benefit – Retire contribution 	 	
*Tax Calculation 	
Sub total is.. 	
less than 2000 - skip 	
2000.01 - 3000.00 = (sub total - 2000.01)*3% 	
3000.01 - 4000.00 = (3000*1%) + {(sub total -3000)*5%} 
4000.01 - 5000.00 = (3000*1%) + (1000*5%) +{(sub total -4000)*7%} 	
Over 5000.01 =  (3000*1%) + (1000*5%) +{1000*7%} + {X(1000*1%)} X= Pay_rate-5000, over 5000.01 only, X must drop the decimals.  	  

4. Print results
*Regular 	
Full name of the Employee
Tax amount owed
Gross Salary
Net Salary
Benefit cost
Retirement Contribution cost (N/A  not participating)
Total Gross Salaries
Total Benefit collected
Total Contribution to Retirement Funds
Total Taxes Collected
Total Net Salaries Paid

*Extra credit part
Full Name of Worker
Gross Salary
Medical Benefit cost
Retirement Contribution (N/A does not participate)
Taxed owed
Net Sarary

********* Algorithm *********	
Step 1
Input
Prompt name and directory of Input text file
Prompt name and directory of output text file
Prompt name and directory of extra credit output text file
Error Input text file
Error  Bad datas

Step 2
Process
*Overtime rate(Over_Pay) 		over 40 hour -> (Hour – 40)= Hour_2
		If (Hour_2 =< 10 ) -> 1.5*Hour_2
     	If (Hour_2 =< 20) -> (1.5*10) + ((Hour_2-10) * 2)
	
*Gross Salary
Gross_Sal = (40*Pay_rate) + Over_Pay
   	*Retirement plan 	If skill level 4 only 		   Gross_Sal * Cont_percent = Con_bution
	
*Net salary
Net_sal = Gross_Sal – benefit – con_bution 
*Tax Calculation If Net_sal is.. less than 2000 = 0 2000.01 - 3000.00 = (Net_sal - 2000.01)*.03 3000.01 - 4000.00 = (3000*.01) + {( Net_sal -3000)*.05} 4000.01 - 5000.00 = (3000*.01) + (1000*.05) +{( Net_sal -4000)*.07} Over 5000.01 =  (3000*.01) + (1000*.05) +{1000*.07} + {X(1000*.01)}	 {X= Pay_rate-5000} - for over 5000.01 only, X must drop the decimals. 	(use Static_cast<int> to drop the decimal)
Step 3
Output
*Regular output
- Print The guideline how to read the data
-Print Full Name, gross salary, benefit, contribution cost, taxes, net salary each worker in each one of the lines -print Total gross salaries paid
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
-print error message called “Bad data” instead of any data regular input when user gave wrong data input

End of Algorithm
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int main()
{

	//*Declaration of identifier*//
	double  Gross_sal;
	float Benefits, con_bution, cont_percent, net_sal, tax, hour_2, pay_rate, over_pay, Gross_sal_retire;
	string Ful_name, fin, fout;
	float total_gross, total_benefit, total_cont, total_tax, total_netsal;//Total Identifier series.
	int skill_lvl, ben_code, Hour_work;
	long ssn;

	//*Open File*//
	ifstream fin_input;
	ofstream fout_output, fout_excredit;

	
	cout<<"\n\n"<<setw(60)<<"Welcome to Davis's Assignment 3! Please Enjoy!."<<endl;
	cout<<setw(60)<<"Just made the name of Output text files."<<endl;
	cout<<setw(60)<<"It will be automatically created."<<"\n\n\n"<<endl;

	cout<<left<<setprecision(2);
	//* fin open status *//
	cout<<setw(57)<<"Enter the name of the input text file : ";
	cin>>fin;
	fin_input.open(fin.c_str());
	if(fin_input.fail())
	{
		cout<<setw(57)<<"Textfile cannot be found, please try it again"<<endl;
		return 0;
	}

	cout<<setw(57)<<"Enter the name of the output text file : ";
	cin>>fout;
	fout_output.open(fout.c_str());
	if(fout_output.fail())
	{
		cout<<setw(57)<<"Textfile cannot be found, please try it again"<<endl;
		return 0;
	}

	cout<<setw(57)<<"Enter the name of the extra-credit output text file : ";
	cin>>fout;
	fout_excredit.open(fout.c_str());
	if(fout_excredit.fail())
	{
		cout<<setw(57)<<"Textfile cannot be found, please try it again"<<endl;
		return 0;
	}
		
	//*Output description*//
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<left<<setprecision(2)<<fixed;
	fout_output<<left<<setprecision(2)<<fixed;
	fout_output<<setw(15)<<"Name"<<setw(13)<<"Gross Salary"<<setw(12)<<"Benefits"<<setw(15)<<"Contribution"<<setw(10)<<"Tax"<<setw(12)<<"Net Salary"<<endl;
	cout<<setw(15)<<"Name"<<setw(13)<<"Gross Salary"<<setw(12)<<"Benefits"<<setw(15)<<"Contribution"<<setw(10)<<"Tax"<<setw(12)<<"Net Salary"<<endl;
	fout_excredit<<"\n\n"<<setw(60)<<"**********Bad Data will be Automatically Skip. Please fix your Bad datas.**********"<<"\n\n\n"<<endl;


	total_gross=0;
	total_benefit=0;
	total_cont=0;
	total_tax=0;
	total_netsal=0;
	con_bution=0;

	//*Looping*//
	fin_input>>skill_lvl;
	while(!fin_input.eof())
	{
		cont_percent = 0.0;
		ben_code = 0;
		con_bution = 0;
		fin_input>>ben_code>>cont_percent>>Hour_work>>ssn;
		fin_input.ignore(10,' ');
		getline(fin_input,Ful_name);
		
		//*Bad Data*//
		if(skill_lvl > 4 || skill_lvl < 1 || Hour_work > 60 || Hour_work < 0
			|| ben_code > 3 || ben_code < 0 || cont_percent > 5.0 || cont_percent < 0.0)
		{
			cout<<setw(15)<<Ful_name<<setw(15)<<"Bad Data"<<endl;
			fout_output<<setw(15)<<Ful_name<<setw(15)<<"Bad Data"<<endl;
		}
		else
		{
			// FUNCTION FOR CALCULATION FROM ASSIGNMENT 2

			//*Benefit Declaration*//
			switch(ben_code)
			{
				case 0:
					Benefits = 0;
					break;
				case 1:
					Benefits = 32.50;
					break;
				case 2:
					Benefits = 52.50;
					break;
				case 3:
					Benefits = 62.50;
					break;
			}

			switch(skill_lvl)
			{
				case 1:
					pay_rate = 15.00;
					break;
				case 2:
					pay_rate = 25.00;
					break;
				case 3:
					pay_rate = 72.00;
					break;
				case 4:
					pay_rate = 125.00;
					break;
			}

			//*Overpay*//
			if (Hour_work > 40)
			{
				hour_2 = Hour_work - 40;
				if (hour_2 <= 10)
				{
					over_pay = (1.5 * pay_rate) * hour_2;
				}
				else if(hour_2 <= 20)
				{
					over_pay = (1.5 * pay_rate) * 10;
					over_pay = over_pay + ((hour_2 - 10) * (pay_rate*2));
				}
			}

			//*Gross Payment*//
			if(Hour_work > 40)
			{
				Gross_sal = (40 * pay_rate) + over_pay;
			}
			else
			{
				Gross_sal = (Hour_work * pay_rate);
			}
			

			if(skill_lvl == 4)
			{
				Gross_sal_retire = Gross_sal;
				cont_percent = cont_percent / 100;
				con_bution = Gross_sal_retire * cont_percent;

				//*gross salary*//
				Gross_sal = Gross_sal - con_bution;
			}
			if(skill_lvl == 0)
			{
				Benefits = 0;
			}
				Gross_sal = Gross_sal - Benefits;
			
				//*Tax Calculation*//
			if(Gross_sal >= 0 && Gross_sal <= 2000)
			{
				tax = 0;
			}
			else if(Gross_sal >= 2000.01 && Gross_sal <= 3000.00)
			{
				tax = .03 * Gross_sal;
			}
			else if(Gross_sal >= 3000.01 && Gross_sal <= 4000.00)
			{
				tax = (.01 * 3000) + (.05 * (Gross_sal - 3000));
			}
			else if(Gross_sal >= 4000.01 && Gross_sal <= 5000.00)
			{	
				tax = (.01 * 3000) + (.05 * 1000) + (.07 * (Gross_sal - 4000));
			}
			else if(Gross_sal >= 5000.01)
			{
				tax= (.01*3000)+(.05*1000)+(.07*1000)+(.01*(1000*static_cast<int>((Gross_sal-5000)/1000)));
			}

			net_sal = Gross_sal - tax;

			//******************************************funtion for calculation*******************************************************//

			//*Total Calculation looping*//
			total_gross += Gross_sal;
			total_benefit += Benefits;
			total_cont += con_bution;
			total_tax += tax;

			total_netsal += net_sal;
			//*end of Total calculation*//

			//*output& Warning*//
			if(skill_lvl == 4)
			{	
				fout_output<<setw(15)<<Ful_name<<"$"<<setw(12)<<Gross_sal_retire<<"$"<<setw(11)<<Benefits<<"$"<<setw(14)<<con_bution<<"$"<<setw(9)<<tax<<"$"<<setw(11)<<net_sal<<endl;
				cout<<setw(15)<<Ful_name<<"$"<<setw(12)<<Gross_sal_retire<<"$"<<setw(11)<<Benefits<<"$"<<setw(14)<<con_bution<<"$"<<setw(9)<<tax<<"$"<<setw(11)<<net_sal<<endl;
			}
			else if(skill_lvl <= 3 && skill_lvl >= 1)
			{	
				fout_output<<setw(15)<<Ful_name<<"$"<<setw(12)<<Gross_sal<<"$"<<setw(11)<<Benefits<<setw(15)<<"N/A"<<"$"<<setw(9)<<tax<<"$"<<setw(11)<<net_sal<<endl;
				cout<<setw(15)<<Ful_name<<"$"<<setw(12)<<Gross_sal<<"$"<<setw(11)<<Benefits<<setw(15)<<"N/A"<<"$"<<setw(9)<<tax<<"$"<<setw(11)<<net_sal<<endl;
			}
			//*warning*//
			
			//*extra-credit part*//
			fout_excredit<<left<<setprecision(2)<<fixed;
			fout_excredit<<setw(50)<<"**************************************************"<<endl;
			fout_excredit<<setw(30)<<"Name:"<<setw(15)<<Ful_name<<endl;
			fout_excredit<<setw(30)<<"Gross Salary:"<<"$"<<setw(15)<<Gross_sal<<endl;
			fout_excredit<<setw(30)<<"Medical Benefits:"<<"$"<<setw(15)<<Benefits<<endl;

			if(skill_lvl == 4)
			{
				fout_excredit<<setw(30)<<"Retirement Contribution:  "<<(cont_percent*100)<<"%"<<endl;
				fout_excredit<<setw(10)<<""<<setw(15)<<"Company:"<<"$"<<setw(10)<<con_bution<<endl;
				fout_excredit<<setw(10)<<""<<setw(15)<<"Employee:"<<"$"<<setw(10)<<con_bution<<endl;
				fout_excredit<<setw(10)<<""<<setw(15)<<"Total:"<<"$"<<setw(10)<<(con_bution*2)<<endl;
			}
			else if(skill_lvl < 4)
			{
				fout_excredit<<setw(30)<<"Retirement Contribution:"<<setw(15)<<"N/A"<<endl;
				fout_excredit<<setw(10)<<""<<setw(15)<<"Company:"<<setw(10)<<"N/A"<<endl;
				fout_excredit<<setw(10)<<""<<setw(15)<<"Employee:"<<setw(10)<<"N/A"<<endl;
				fout_excredit<<setw(10)<<""<<setw(15)<<"Total:"<<setw(10)<<"N/A"<<endl;
			}

			fout_excredit<<setw(30)<<"Tax Owed:"<<"$"<<setw(15)<<tax<<endl;
			fout_excredit<<setw(30)<<"Net Salary:"<<"$"<<setw(15)<<net_sal<<endl;
			fout_excredit<<setw(50)<<"**************************************************"<<"\n\n\n"<<endl;
			//*extra-credit part*//

		} //*If not bad data end*//
		
		fin_input>>skill_lvl;
	}
	
	//*total output*//
	cout<<endl;
	fout_output<<endl;
	fout_output<<setw(70)<<"**********************************************************************"<<endl;
	cout<<setw(70)<<"**********************************************************************"<<endl;
	cout<<setw(50)<<"Total Gross Salaries:"<<"$"<<setw(15)<<total_gross<<endl;
	cout<<setw(50)<<"Total Benefits collected:"<<"$"<<setw(15)<<total_benefit<<endl;
	cout<<setw(50)<<"Total Contribution to retirement Fund:"<<"$"<<setw(15)<<total_cont<<endl;
	cout<<setw(50)<<"Total Taxes Collected:"<<"$"<<setw(15)<<total_tax<<endl;
	cout<<setw(50)<<"Total Net Salaries Paid:"<<"$"<<setw(15)<<total_netsal<<endl;//end of total output
	fout_output<<setw(50)<<"Total Gross Salaries:"<<"$"<<setw(15)<<total_gross<<endl;
	fout_output<<setw(50)<<"Total Benefits collected:"<<"$"<<setw(15)<<total_benefit<<endl;
	fout_output<<setw(50)<<"Total Contribution to retirement Fund:"<<"$"<<setw(15)<<total_cont<<endl;
	fout_output<<setw(50)<<"Total Taxes Collected:"<<"$"<<setw(15)<<total_tax<<endl;
	fout_output<<setw(50)<<"Total Net Salaries Paid:"<<"$"<<setw(15)<<total_netsal<<endl;
	fout_output<<setw(70)<<"**********************************************************************"<<endl;
	cout<<setw(70)<<"**********************************************************************"<<"\n\n\n"<<endl;//end of total output
	fout_excredit.close();
	fout_output.close();
	fin_input.close();
	return 0;
}
