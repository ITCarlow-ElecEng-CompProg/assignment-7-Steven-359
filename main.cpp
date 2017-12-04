/**

09/10/17
Steven O' Brien
Coordinate Conversion
Exercise 7

*/

#include <iostream>
#include <math.h>

using namespace std;

//Function declarations
void intcartesian(float r , float ang, float *ptr_x, float *ptr_y );
void intpolar(float x , float y, float *ptr_r, float *ptr_ang);

int main()
{
    //Displays Programme Title
    cout << "Coordinate Conversion" << endl;

    //Declaration of variables type char and float
    char userinput;
    float x=0, y=0, r=0, ang=0;
    float *ptr_x, *ptr_y, *ptr_r, *ptr_ang;

    // Assigned values to variables
    ptr_x = &x;
    ptr_y = &y;
    ptr_r = &r;
    ptr_ang = &ang;




    //Do While loop to display menu driven program
    do
    {
        cout << "\nEnter required program.\n"<<
            "p = Cartesian to Polar coordinates\n"<<
            "c = Polar to Cartesian\n"<<
            "q = quit program.\n" << endl ;

            cin >> userinput ;

            // Switch case statement to implement the user input
            switch(userinput)
            {
                case 'p':
                        cout <<"Enter values for x and y " << endl ;
                        cin >> x >> y ;
                        intpolar(x , y ,ptr_r, ptr_ang);
                        cout << "\nThe magnitude is : " << *ptr_r <<endl ;
                        cout << "\nThe angle is : " << *ptr_ang <<endl ;
                        break;

            case 'c':
                        cout <<"Enter magnitude for r" << endl ;
                        cin >> r ;
                        cout <<"Enter angle" << endl ;
                        cin >> ang ;
                        intcartesian(r , ang, ptr_x, ptr_y);
                        cout << "\nThe x  coordinate is: " << *ptr_x << endl ;
                        cout << "\nThe y coordinate is: " << *ptr_y << endl ;
                        break;

            case 'q': cout << "goodbye..." << endl ;
                        break;

            default : cout << "please try again..." << endl ;
                        break;
            }

    }
    while (userinput != 'q');

    return 0;
}


//Function to calculate magnitude and angle
void intpolar(float x , float y, float *ptr_r, float *ptr_ang)
{


    *ptr_r= sqrt(pow(x,2)+pow(y,2));
    *ptr_ang = atan(y/x);

    return ;


}

//Function to calculate X and Y co-ordinates
void intcartesian(float r , float ang, float *ptr_x, float *ptr_y )
{

    *ptr_x = r * cos(ang*(180/M_PI));
    *ptr_y = r * sin(ang*(180/M_PI));

    return;
}
