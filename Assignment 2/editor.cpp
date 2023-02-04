#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>

#include "doubly_list.h"
#include "myconsole.h"
#include "editor.h"

using namespace std;

//-------------------------------Color Codes------------------------------//
// Color Codes Hexadecimal values for both Fore Ground and Back Ground //ForeGround|BackGround
int B_BLACK = 0x00;
int B_Royal_Blue = 0x10;
int B_Dark_Green = 0x20;
int B_Tale_Blue = 0x30;
int B_Dark_Red = 0x40;
int B_Purple = 0x50;
int B_Tale_Green = 0x60;
int B_Light_Grey = 0x70;
int B_Dark_Gray = 0x80;
int B_Light_Blue = 0x90;
int B_Light_Green = 0xA0;
int B_Sky_Blue = 0xB0;
int B_Red = 0xC0;
int B_Pink = 0xD0;
int B_Yellow = 0xE0;
int B_White = 0xF0;

int F_BLACK = 0x00;
int F_Royal_Blue = 0x01;
int F_Dark_Green = 0x02;
int F_Tale_Blue = 0x03;
int F_Dark_Red = 0x04;
int F_Purple = 0x05;
int F_Tale_Green = 0x06;
int F_Light_Grey = 0x07;
int F_Dark_Gray = 0x08;
int F_Light_Blue = 0x09;
int F_Light_Green = 0x0A;
int F_Sky_Blue = 0x0B;
int F_Red = 0x0C;
int F_Pink = 0x0D;
int F_Yellow = 0x0E;
int F_White = 0x0F;

//-------------------------------POINT CLASS------------------------------//
// initialize MaxPoint
point point::MaxPoint(MAX_X, MAX_Y);
bool point::incrementX()
{
    bool returnValue = true;
    if (x < MaxPoint.x)
        x++;
    else if (y < MaxPoint.y)
    {
        x = 0;
        y = y + 1;
    }
    else
        returnValue = false;

    return returnValue;
}

bool point::incrementY()
{
    bool returnValue = true;
    if (y < MaxPoint.y)
        y++;
    else
        returnValue = false;

    return returnValue;
}
bool point::decrementX()
{
    bool returnValue = true;
    if (x > 0)
        x--;
    else if (y > 0)
    {
        y--;
        x = MaxPoint.x;
    }
    else
        returnValue = false;

    return returnValue;
}
bool point::decrementY()
{
    bool returnValue = true;
    if (y > 0)
        y--;
    else
        returnValue = false;

    return returnValue;
}

//-------------------------------END OF POINT CLASS------------------------------------------------//

//--------------------------The function Where you will write code--------------------------------//
int mainEditor()
{
    int key = 0;
    bool stop = false;
    point currentPosition(0, 0);
    currentPosition.setMaxPoint(MAX_X, MAX_Y);
    bool specialKey = false;
    // !MYCODE
    doubly_list<char> list;
    doubly_list<char>::iterator cursor;
    while (!stop)
    {
        key = CheckWhichKeyPressed(specialKey);
        // escape key
        if (key == ESCKEY)
            stop = true;
        // printable character...only adds to the end of text
        // this will not do insertions in between text
        // add code here to insert characters within text
        else if (!specialKey && key >= 32 && key <= 126)
        {
            list.insert(cursor, (char)key);
            ClearScreen();
            list.display();
            if (currentPosition.getX() < MAX_X)
            {
                // cout << (char)key;
                // You can change color of text by calling this function
                SetColorAtPoint(currentPosition.getX(), currentPosition.getY(), F_BLACK | B_White); // ForeGround|BackGround
                currentPosition.incrementX();
            }
            else if (currentPosition.getY() < MAX_Y)
            {
                currentPosition.incrementY();
                currentPosition.setX(0);
            }
        }
        else if (specialKey && key == LEFTKEY)
        {
            doubly_list<char>::iterator temp = cursor;
            if (--temp != NULL)
            {
                --cursor;
                currentPosition.decrementX();
            }
        }
        else if (specialKey && key == RIGHTKEY)
        {
            doubly_list<char>::iterator temp = cursor;
            if (++temp != NULL)
            {
                ++cursor;
                currentPosition.incrementX();
            }
        }
        else if (specialKey && key == UPKEY)
            currentPosition.decrementY();
        else if (specialKey && key == DOWNKEY)
        { // Update it so that cursur not move downword if it is at last line of text.
            currentPosition.incrementY();
        }
        else if (key == ENTERKEY)
        {
            cout << ('\n');
            currentPosition.setX(0);
            currentPosition.incrementY();
        }
        else if (key == DELKEY)
        {
            // call a function to handle
        }
        else if (key == BACKSPACE)
        {
            cout << '\0';
            // handle backspace here
            if (!currentPosition.decrementX() && currentPosition.getY() > 0)
            {
                cout << '\0';
                currentPosition.decrementY();
                currentPosition.setX(MAX_X);
            }
        }
        else if (key == F1KEY || key == F2KEY || key == F3KEY)
        {
            // handle search here
            // you can take the cursor at the bottom of the screen and get some input
            // for searching
            PlaceCursor(0, MAX_Y);
            for (int i = 0; i < MAX_X; i++)
            {
                cout << '\0';
                currentPosition.incrementX();
            }

            PlaceCursor(0, MAX_Y);
            cout << "Enter Search Query: " << endl;
            currentPosition.setX(0 + strlen("Enter Search Text : "));
            currentPosition.setY(MAX_Y);

            if (key == F1KEY)
            {
                // Search for one instance of string and move cursor there
            }
            else if (key == F1KEY)
            {
                // Search for all instances of string and Highlight them
            }
            else
            {
                // Search for all instances of string
                // Take a second input string
                // and replace all instances of first string with second string
            }
        }
        else if (key == F4KEY)
        {
            //! MY_CODE
            ofstream fout("output.txt");
            doubly_list<char>::iterator i = list.begin();
            while (i != NULL)
                fout << *i++;
            fout << "\nCursor Position: " << *cursor << endl;
        }
        PlaceCursor(currentPosition.getX(), currentPosition.getY());
    }

    return 0;
}

//-------------------------------------------End Main Editor--------------------------//
int main()
{
    mainEditor();
    return 0;
}