#include<iostream>
#include<string>
#include<iomanip>
#include<cstring>
#include<ios>
#include "myDate.h"
#define underline "\033[4m"
#define endline "\033[0m"
using namespace std;

const int SIZE = 10;

struct Student
{
    char name[20];
    int ID;
    char grade;
    myDate birthday;
    string hometown;
};

myDate randomBday(myDate start, myDate end)
{
    start = myDate(1,1,1995);
    end = myDate(12,31,2005);
    int x = end.daysBetween(start); //range of numbers for date
    int randJD = 0 + rand() % (( x + 1 ) - 0);
    myDate date = myDate(1,1,1995);
    date.increaseDate(randJD);
    return date;
}

void populate(Student **sptr)
{
    srand(time(NULL));
    char name0[20] = "Bob Bobson";
    char name1[20] = "John Johnson";
    char name2[20] = "Robert Robbingson";
    char name3[20] = "Bippy Boppins";
    char name4[20] = "Jimmy Neutron";
    char name5[20] = "Carl Weezer";
    char name6[20] = "Sheen Estavez";
    char name7[20] = "Patrick Star";
    char name8[20] = "Timmy Turner";
    char name9[20] = "Maximus Martin";
    for(int i = 0; i < SIZE; i++)
    {
        sptr[i] = new Student;
    }
    strcpy(sptr[0]->name, name0);
    sptr[0]->ID = 9000 + rand() % (( 9999 + 1 ) - 9000);
    sptr[0]->grade = 'A';
    sptr[0]->birthday = randomBday( myDate(1,1,1995), myDate(12,31,2005) ) ;
    sptr[0]->hometown = "Los Angeles";

    strcpy(sptr[1]->name, name1);
    sptr[1]->ID = 9000 + rand() % (( 9999 + 1 ) - 9000);
    sptr[1]->grade = 'C';
    sptr[1]->birthday = randomBday( myDate(1,1,1995), myDate(12,31,2005) );
    sptr[1]->hometown = "Irvine";

    strcpy(sptr[2]->name, name2);
    sptr[2]->ID = 9000 + rand() % (( 9999 + 1 ) - 9000);
    sptr[2]->grade = 'B';
    sptr[2]->birthday = randomBday( myDate(1,1,1995), myDate(12,31,2005) );
    sptr[2]->hometown = "Santa Ana";

    strcpy(sptr[3]->name, name3);
    sptr[3]->ID = 9000 + rand() % (( 9999 + 1 ) - 9000);
    sptr[3]->grade = 'D';
    sptr[3]->birthday = randomBday( myDate(1,1,1995), myDate(12,31,2005) );
    sptr[3]->hometown = "Pomona";

    strcpy(sptr[4]->name, name4);
    sptr[4]->ID = 9000 + rand() % (( 9999 + 1 ) - 9000);
    sptr[4]->grade = 'A';
    sptr[4]->birthday = randomBday( myDate(1,1,1995), myDate(12,31,2005) );
    sptr[4]->hometown = "Norwalk";

    strcpy(sptr[5]->name, name5);
    sptr[5]->ID = 9000 + rand() % (( 9999 + 1 ) - 9000);
    sptr[5]->grade = 'C';
    sptr[5]->birthday = randomBday( myDate(1,1,1995), myDate(12,31,2005) );
    sptr[5]->hometown = "Riverside";

    strcpy(sptr[6]->name, name6);
    sptr[6]->ID = 9000 + rand() % (( 9999 + 1 ) - 9000);
    sptr[6]->grade = 'F';
    sptr[6]->birthday = randomBday( myDate(1,1,1995), myDate(12,31,2005) );
    sptr[6]->hometown = "Fullerton";

    strcpy(sptr[7]->name, name7);
    sptr[7]->ID = 9000 + rand() % (( 9999 + 1 ) - 9000);
    sptr[7]->grade = 'C';
    sptr[7]->birthday = randomBday( myDate(1,1,1995), myDate(12,31,2005) );
    sptr[7]->hometown = "San Diego";

    strcpy(sptr[8]->name, name8);
    sptr[8]->ID = 9000 + rand() % (( 9999 + 1 ) - 9000);
    sptr[8]->grade = 'D';
    sptr[8]->birthday = randomBday( myDate(1,1,1995), myDate(12,31,2005) );
    sptr[8]->hometown = "Tustin";

    strcpy(sptr[9]->name, name9);
    sptr[9]->ID = 9000 + rand() % (( 9999 + 1 ) - 9000);
    sptr[9]->grade = 'F';
    sptr[9]->birthday = randomBday( myDate(1,1,1995), myDate(12,31,2005) );
    sptr[9]->hometown = "Long Beach";
}


void sortByName(Student **sptr)
{
    int i;
    int j;
    for (i = 0; i < SIZE-1; i++)
      for (j = 0; j < SIZE-i-1; j++)
    {
       {   Student **s1 = &sptr[j];
           Student **s2 = &sptr[j+1];
           if( strcmp( (*s1)->name,(*s2)->name) > 0 )
           {  
              Student *temp = sptr[j];  
              sptr[j] = sptr[j+1];
              sptr[j+1] = temp;
           }
       }
   }
}

void sortByID(Student **sptr)
{
    int i;
    int j;
    for (i = 0; i < SIZE-1; i++)
      for (j = 0; j < SIZE-i-1; j++)
    {
       {   Student **s1 = &sptr[j];
           Student **s2 = &sptr[j+1];
           if( (*s1)->ID > (*s2)->ID )
           {  
              Student *temp = sptr[j];  
              sptr[j] = sptr[j+1];
              sptr[j+1] = temp;
           }
       }
   }
}

void sortByGrade(Student **sptr)
{
    int i;
    int j;
    for (i = 0; i < SIZE-1; i++)
      for (j = 0; j < SIZE-i-1; j++)
    {
       {   Student **s1 = &sptr[j];
           Student **s2 = &sptr[j+1];
           if( (*s1)->grade > (*s2)->grade )
           {  
              Student *temp = sptr[j];  
              sptr[j] = sptr[j+1];
              sptr[j+1] = temp;
           }
       }
   }
}

void sortByBirthday(Student **sptr)
{
    int i;
    int j;
    for (i = 0; i < SIZE-1; i++)
      for (j = 0; j < SIZE-i-1; j++)
    {
       {   Student **s1 = &sptr[j];
           Student **s2 = &sptr[j+1];
           if( (*s1)->birthday.daysBetween( (*s2)->birthday ) < (*s2)->birthday.daysBetween( (*s1)->birthday ) )
           {  
              Student *temp = sptr[j];  
              sptr[j] = sptr[j+1];
              sptr[j+1] = temp;
           }
       }
   }
}

void sortByHometown(Student **sptr)
{
    int i;
    int j;
    for (i = 0; i < SIZE-1; i++)
      for (j = 0; j < SIZE-i-1; j++)
    {
       {   Student **s1 = &sptr[j];
           Student **s2 = &sptr[j+1];
           if( (*s1)->hometown > (*s2)->hometown )
           {  
              Student *temp = sptr[j];  
              sptr[j] = sptr[j+1];
              sptr[j+1] = temp;
           }
       }
   } 
}

void display(Student **sptr)
{
    cout << underline << "Name" << endline << setw(25) << underline << "Student ID" << endline << setw(16) << underline << "Grade" << endline << setw(16) << underline << "Birthday" << endline << setw(20) << underline << "Home Town" << endline << endl;
    for(int i = 0; i < SIZE; i++)
    {
        int betweenNameID = 29 - strlen(sptr[i]->name);
        int betweenIDGrade = strlen(sptr[i]->name) + betweenNameID - 10;
        int betweenGradeBday = sptr[i]->birthday.toString().length() + strlen(sptr[i]->name) + betweenIDGrade + betweenNameID - 32;
        int betweenBdayHometown = sptr[i]->hometown.length() + ( 33 - sptr[i]->birthday.toString().length() ) - 9;
        cout << sptr[i]->name << setw(betweenNameID) << sptr[i]->ID << setw(betweenIDGrade) << sptr[i]->grade << setw(betweenGradeBday) << sptr[i]->birthday.toString() << setw(betweenBdayHometown) << sptr[i]->hometown << endl;
    }
}

int main()
{
    Student *sptrArr[SIZE];
    Student **sptr = sptrArr;
    int choice;
    string menu = "1. Display list sorted by Name\n2. Display list sorted by Student ID\n3. Display list sorted by Grade\n4. Display list sorted by Birthday\n5. Display list sorted by Home Town\n6. Exit";
    populate(sptr);
    cout << menu << endl;
    cin >> choice;
    
    switch(choice)
    {
        case 1:
            sortByName(sptr);
            display(sptr);
            break;
        case 2:
            sortByID(sptr);
            display(sptr);
            break;
        case 3:
            sortByGrade(sptr);
            display(sptr);
            break;
        case 4:
            sortByBirthday(sptr);
            display(sptr);
            break;
        case 5:
            sortByHometown(sptr);
            display(sptr);
            break;
        case 6:
            break;
        default:
            cout << "Please enter a valid choice." << endl;
    }
    return 0;
}