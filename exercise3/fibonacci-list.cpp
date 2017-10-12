#include <iostream>
using namespace std;

int rabbits (int);

int main ()
{
int x, month, result, counter = 0, rab_now, rab_lastmonth = 1, rab_twomonthsago = 0;

cout << "Please enter the month \n\n";
cin >> month;
cout << "\n";

result = rabbits (month);

while (counter <= month - 1)
{
      rab_now = rab_lastmonth + rab_twomonthsago;

      x = rab_lastmonth;
      rab_lastmonth = rab_now;
      rab_twomonthsago = x;

      counter++;
}

cout << "At the end of month " << month << ", there will be " << rab_lastmonth << "      
pairs of rabbits" << endl;

system("PAUSE");
return 0;
}

int rabbits (int month)

{
if (month == 0)
{
    return 0;
}
else if (month == 1)
{
    return 1;
}
else
{
    return (rabbits (month + 1) + rabbits (month - 2));
}
}
