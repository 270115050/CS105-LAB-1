//Programmer:       Jay Anino
//Student ID:       270115050
//School:           Yoobee College
//Due Date:         03/08/2021
//Reference:    CS105 Lab 1
//Description:    This program ask the user for the location of the ship using Latitude and Longtitue and displays it accordling
//Guarantee:    Program works to full specifications


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//This class holds the coordinates of an object
class Location {
public:
    int longtitute, latitute;
    float longMinutes, latMinutes;
    char longDirection, latDirection;

    //This function prompts the user to enter the coordinates
    void getpos() {
        cout << "\n\t|------------------------------|"
            << "\n\t|    Longtitute Coordinates    |"
            << "\n\t|------------------------------|\n\n";
        do {
            cout << "\tInput degress between 0 and 180: ";
            cin >> longtitute;
            if (longtitute >= 0 && longtitute <= 180)
                break;
            else
                cout << "\tInvalid input, Please try again..\n\n";
        } while (true);
        do {
            cout << "\tInput minutes between 0 and 60: ";
            cin >> longMinutes;
            if (longMinutes >= 0 && longMinutes <= 60)
                break;
            else
                cout << "\tInvalid input, Please try again..\n\n";
        } while (true);
        do {
            cout << "\tInput direction (E/W/N/S) : ";
            cin >> longDirection;
            if (tolower(longDirection) == 'e' || tolower(longDirection) == 'w' || tolower(longDirection) == 'n' || tolower(longDirection) == 's')
                break;
            else
                cout << "\tInvalid input, Please try again..\n\n";
        } while (true);

        cout << "\n\t|------------------------------|"
            << "\n\t|     Latitute Coordinates     |"
            << "\n\t|------------------------------|\n\n";

        do {
            cout << "\tInput degress between 0 and 180: ";
            cin >> latitute;
            if (latitute >= 0 && latitute <= 180)
                break;
            else
                cout << "\tInvalid input, Please try again..\n\n";
        } while (true);
        do {
            cout << "\tInput minutes between 0 and 60: ";
            cin >> latMinutes;
            if (latMinutes >= 0 && latMinutes <= 60)
                break;
            else
                cout << "\tInvalid input, Please try again..\n\n";
        } while (true);
        do {
            cout << "\tInput direction (E/W/N/S) : ";
            cin >> latDirection;
            if (tolower(latDirection) == 'e' || tolower(latDirection) == 'w' || tolower(latDirection) == 'n' || tolower(latDirection) == 's')
                break;
            else
                cout << "\tInvalid input, Please try again..\n\n";
        } while (true);
    }
};

//This class is used to create the object Yatch and uses the Location class to call the getpos member to enter the coordinates of the yatch
class Yatch {
public:
    Location location;
    int serialNum = 0;
    //This function displays the coordinates that user entered

    void display() {
        cout << "\n\tThe ship serial number is : " << serialNum
            << "\n\tand it's position is : " << location.latitute << "\xF8" << location.latMinutes << "'" << (char)toupper(location.latDirection) << " Latitute " 
            << location.longtitute << "\xF8" << location.longMinutes << "'" << (char)toupper(location.longDirection) << " Longtitute\n";
    }
};

int main()
{
    const int SIZE = 3;
    Yatch yatch[SIZE];
    Location l;

    cout << "\n\t|----------------------------------|"
        << "\n\t|       Ocean Race 2021-22         |"
        << "\n\t|----------------------------------|\n";

    for (int i = 0; i < SIZE; i++) {
        cout << "\n|--------------------------------------------------|"
            << "\n|         Enter the Location of the " << i + 1 << " ship:         |"
            << "\n|--------------------------------------------------|\n";
        yatch[i].serialNum = i + 1;
        yatch[i].location.getpos();
    }

    cout << "\n\n|---------------------------------------------|"
        << "\n|       Welcome to Ocean Race 2021-22         |"
        << "\n|---------------------------------------------|";

    for (int i = 0; i < SIZE; i++) {
        yatch[i].display();
    }

    return 0;
}