/*
	Input Validation with Ref Functions 
	A cleaner way to do input validation
	Validating input, an essential process.
	Source: http://stackoverflow.com/questions/514420/how-to-validate-numeric-input-c
	Keeping Dr. McMillan from breaking my code, defend against "dark side of the force",
	and/or legitimate user error. 
	//Try and Catch blocks are used in error checking
	Teacher: Dr. Tyson McMillan, Ph.D.  
  STUDENT Hawkins: 2/14/20
*/
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream>  // Provides cout, cerr, endl
                              // Extended 2-11-2016 by Dr. McMillan to add validation methods by datatype
#include<string> //for string manipulation
#include<sstream> //for string manipulation and comparison
#include<locale>
#include <iomanip>
#include <algorithm>

using namespace std;


double weeklyPay(double, double,string,int);

int main( )
{    
  cout << fixed << setprecision(2); 
  cout << weeklyPay (47.0, 505.75,"Cole",1) << endl;
  cout << endl;
  cout << weeklyPay (45.0, 55.25,"Melivin",1) << endl;
  cout << endl;
  cout << weeklyPay (15, 65.25,"Susan",2) << endl;
  cout << endl;
  cout << weeklyPay (41, 14.75,"Mika",1) << endl;  
  cout << endl; 
  cout << weeklyPay (25, 15.0,"Eldridge",2) << endl; 
  cout << endl; 
  cout << weeklyPay (55, 203.50,"Freedom",1) << endl; 
  cout << endl;
  cout << weeklyPay (32.5, 100.25,"Tyson(Dr_T)",1) << endl;  

string strLow = "\nTCC-TR IS COOL";
transform(strLow.begin(), strLow.end(), strLow.begin(), ::tolower);
cout << strLow <<endl;

string strUp = "\ni will succeed at c++";
transform(strUp.begin(), strUp.end(), strUp.begin(), ::toupper);
cout << strUp <<endl;
    
    return 0;

}


double weeklyPay(double hours, double rate, string name, int empType)
{
  double netPay = 0.0, grossPay = 0.0, taxableWages = 0.0;
  double ss = 0.062, med = 0.0145, sSwages = 0.0, medWages = 0.0;
  double FIT = 0.0, fitTax = 0.0, dental = 0.0, retirement = 0.0;
  double clockHours = 40.0, overtimeRate = 2.0, overTimeIfAny = 0.0;
  int emptype = 0;

  locale loc; 
  string status = ""; 
  string reset = "\x1b[0m";
  string color = "\x1b[" + to_string(91) + ";4m";

  cout << color << endl; 
  for(int i = 0; i < name.length(); i++ )
  {
    cout << toupper(name[i],loc); 
  }
  cout << reset << endl;

  status = (empType == 1) ? "Fulltime" : "Parttime"; 
  cout << "\nStatus: " << status << endl; 
  cout <<"Standard Pay Rate: "<< rate << endl;
  cout << "Hours Worked: " << hours << endl; 

  overTimeIfAny = ((hours - clockHours) > 0.0) ? (hours - clockHours) : 0.0;  
  if(empType == 1) 
  {
    cout << "Overtime Hours: " << overTimeIfAny << endl; 
  }

  FIT = (rate < 15.0) ? 0.12 : 0.15; 
  cout << "FIT Rate: " << FIT << endl; 
  dental = (empType == 1) ? 17.00 : 0.00;
  retirement = (empType == 1) ? 77.00 : 0.00;
  

  grossPay = (hours <= clockHours) ? (hours * rate) : 
  ((clockHours * rate) + ((overTimeIfAny) * (overtimeRate * rate))); 

  cout << "Gross Pay: $" << grossPay << endl;
  taxableWages = grossPay - (dental + retirement);
  fitTax = taxableWages * FIT;  
  
  sSwages = grossPay * ss; 
  medWages =  grossPay * med; 
 
  cout << "\nPreTax Deductions: " << endl; 
  cout << "Dental Deduction = $" << dental <<endl;
  cout << "Retirement Deduction = $" << retirement << endl;
  cout << "Taxable Wages = $" << taxableWages << endl; 
  cout << "\nDeductions: " << endl; 
  cout << "FIT Tax Amount = $" << fitTax << endl; 
  cout << "Social Security Deductions = $" << sSwages<< endl;
  cout << "Medicare Deductions = $" << medWages << endl;
  netPay = grossPay - (dental + retirement + fitTax + sSwages + medWages); 
  cout << "Net Pay for " << name << " = $"; 

  return netPay; 
}
