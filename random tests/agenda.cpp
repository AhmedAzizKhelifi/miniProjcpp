// A C++ Program to Implement a Calendar
// of an year
#include<bits/stdc++.h>
using namespace std;

/*A Function that returns the index of the day
  of the date- day/month/year
  For e.g-

  Index     Day
  0         Sunday
  1         Monday
  2         Tuesday
  3         Wednesday
  4         Thursday
  5         Friday
  6         Saturday*/
int dayNumber(int day, int month, int year)
{

    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
                       4, 6, 2, 4 };
    year -= month < 3;
    return ( year + year/4 - year/100 +
             year/400 + t[month-1] + day) % 7;
}

/*
  A Function that returns the name of the month
  with a given month number

  Month Number     Name
  0                January
  1                February
  2                March
  3                April
  4                May
  5                June
  6                July
  7                August
  8                September
  9                October
  10               November
  11               December */
string getMonthName(int monthNumber)
{
    string months[] = {"Janvier", "Fevrier", "Mars",
                       "Avril", "Mai", "Juin",
                       "Juillet", "Aout", "Septembre",
                       "Octobre", "Novembre", "Decembre"
                      } ;

    return (months[monthNumber]);
}

/* A Function to return the number of days in
   a month

  Month Number     Name        Number of Days
  0                January     31
  1                February    28 (non-leap) / 29 (leap)
  2                March       31
  3                April       30
  4                May         31
  5                June        30
  6                July        31
  7                August      31
  8                September   30
  9                October     31
  10               November    30
  11               December    31

*/
int numberOfDays (int monthNumber, int year)
{
    // January
    if (monthNumber == 0)
        return (31);

    // February
    if (monthNumber == 1)
    {
        // If the year is leap then February has
        // 29 days
        if (year % 400 == 0 ||
                (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
    }

    // March
    if (monthNumber == 2)
        return (31);

    // April
    if (monthNumber == 3)
        return (30);

    // May
    if (monthNumber == 4)
        return (31);

    // June
    if (monthNumber == 5)
        return (30);

    // July
    if (monthNumber == 6)
        return (31);

    // August
    if (monthNumber == 7)
        return (31);

    // September
    if (monthNumber == 8)
        return (30);

    // October
    if (monthNumber == 9)
        return (31);

    // November
    if (monthNumber == 10)
        return (30);

    // December
    if (monthNumber == 11)
        return (31);
    return 0;
}

// Function to print the calendar of the given year
void printCalendar(int year)
{
    printf ("         Calendar - %d\n\n", year);
    int days;

    // Index of the day from 0 to 6
    int current = dayNumber (1, 1, year);

    // i --> Iterate through all the months
    // j --> Iterate through all the days of the
    //       month - i
    for (int i = 0; i < 12; i++)
    {
        days = numberOfDays (i, year);

        // Print the current month name
        printf("\n  ------------%s-------------\n",
               getMonthName (i).c_str());

        // Print the columns
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print appropriate spaces
        int k;
        for (k = 0; k < current; k++)
            printf("     ");

        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);

            if (++k > 6)
            {
                k = 0;
                printf("\n");
            }
        }

        if (k)
            printf("\n");
        if (i==0)
        {
            cout<<"\n 01 Janvier : Nouvel An "<<endl;
            cout<<"\n 14 Janvier : Jour anniversaire de la Revolution tunisienne "<<endl;
        }
        if (i==2)
            cout<<"\n 20 Mars : Fete de l’Independance de la Tunisie "<<endl;
        if (i==3)
            cout<<"\n 09 Avril : Jour des Martyrs "<<endl;
        if (i==4)
            cout<<"\n 01 Mai : Fete du Travail "<<endl;
        if (i==6)
            cout<<"\n 25 Juillet : Fete de la Republique "<<endl;
        if (i==7)
            cout<<"\n 13 Aout : Fete de la femme "<<endl;
        if (i==9)
            cout<<"\n 15 Octobre : Fete de l'evacuation "<<endl;
/*
// ce sont le dates de 2020 //
        if (i==3)
            cout<<"\n 25 Avril : 1er jour de Ramadan "<<endl;
        if (i==4)
            cout<<"\n 24 Mai : Aid al-Fitr "<<endl;
        if (i==6)
            cout<<"\n 31 Juillet : Aid al-Adha "<<endl;
        if (i==7)
            cout<<"\n 20 Aout : Fete du Ras El Am El Hijri "<<endl;
        if (i==9)
            cout<<"\n 29 Octobre : Mouled Mubarek "<<endl;
*/

        current = k;
    }

    return;
}

int main(){
    printCalendar(2021);
}
// Driver Program to check above funtions

