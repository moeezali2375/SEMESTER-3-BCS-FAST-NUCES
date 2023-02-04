#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include "stacks.h"
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
template <typename T>
void my_print(doubly_list<T> &a, point &b, typename doubly_list<T>::iterator &cursor, point &currentPosition)
{
    ClearScreen();
    // PlaceCursor(0, 0);
    int x = 0;
    int y = 0;
    typename doubly_list<T>::iterator temp = a.begin();
    while (temp != NULL)
    {
        if (*temp == '\n')
        {
            y++;
            x = 0;
        }
        else
            x++;
        char check = *temp;
        OutputString(x, y, &check);
        temp++;
    }
    typename doubly_list<T>::iterator temp2 = cursor;
    ++temp2;
    if (temp2 == NULL)
        ;
    else
        // SetColorAtPoint(currentPosition.getX(), currentPosition.getY(), F_BLACK | B_White); // ForeGround|BackGround
        b.set(x, y);
}

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
    doubly_list<char>::iterator *cursor_array = new doubly_list<char>::iterator[50];
    Stack<doubly_list<char> > undo(200);
    int current_line = 0;
    int total_end_lines = 0;
    int my_x[100] = {0};
    int current_x = 0;
    int my_y[100] = {0};
    int current_y = 0;
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
            undo.push(list);
            if (currentPosition.getX() < MAX_X)
            {
                // cout << (char)key;
                // You can change color of text by calling this function
                // SetColorAtPoint(currentPosition.getX(), currentPosition.getY(), F_BLACK | B_White); // ForeGround|BackGround
                currentPosition.incrementX();
            }
            else if (currentPosition.getY() < MAX_Y)
            {
                currentPosition.incrementY();
                currentPosition.setX(0);
            }
            list.insert(cursor, (char)key);
            my_x[current_line]++;
            current_x++;
            my_print(list, currentPosition, cursor, currentPosition);
        }
        else if (specialKey && key == LEFTKEY)
        {
            doubly_list<char>::iterator temp = cursor;
            --temp;
            if (temp != NULL)
            {
                if (*temp == '\n')
                {
                    --cursor;
                    --cursor;
                    current_line--;
                    current_y--;
                    current_x = my_x[current_line] - 1;
                    currentPosition.decrementY();
                }
                else
                {
                    --cursor;
                    current_x--;
                    currentPosition.decrementX();
                }
            }
        }
        else if (specialKey && key == RIGHTKEY)
        {
            doubly_list<char>::iterator temp = cursor;
            ++temp;
            if (temp != NULL)
            {
                if (*temp == '\n')
                {
                    ++cursor;
                    current_line++;
                    current_x = 0;
                    current_y++;
                    currentPosition.incrementY();
                }
                else
                {
                    ++cursor;
                    current_x++;
                    currentPosition.incrementX();
                }
            }
        }
        else if (specialKey && key == UPKEY)
        {
            if (current_line > 0 && current_line < 50)
            {
                current_line--;
                currentPosition.decrementY();
                while (*cursor != '\n')
                {
                    currentPosition.decrementX();
                    --cursor;
                }
                --cursor;
                current_x = my_x[current_line];
                current_y--;
                currentPosition.decrementX();
            }
        }
        else if (specialKey && key == DOWNKEY)
        {
            if (current_line >= 0 && current_line < 50 && current_line < total_end_lines)
            {
                current_line++;
                currentPosition.incrementY();
                while (*cursor != '\n')
                {
                    currentPosition.incrementX();
                    ++cursor;
                }
                current_x = 0;
                current_y++;
            }
        }
        else if (key == ENTERKEY)
        {
            undo.push(list);
            current_line++;
            total_end_lines++;
            list.insert(cursor, '\n');
            my_print(list, currentPosition, cursor, currentPosition);
            int flag = 0;
            for (int i = total_end_lines; i > current_line; i--)
            {
                my_x[i + 1] = my_x[i];
                flag = 1;
            }
            if (flag)
                my_x[current_line + 1] = 0;
            current_x = 0;
            current_y++;
            currentPosition.setX(0);
            currentPosition.incrementY();
        }
        else if (key == F5KEY)
        {
            undo.push(list);
            doubly_list<char>::iterator temp = cursor;
            ++temp;
            if (temp != NULL)
            {
                list.delete_node(temp);
            }
            my_print(list, currentPosition, cursor, currentPosition);
        }
        else if (key == BACKSPACE)
        {
            // cout << '\0';
            doubly_list<char>::iterator temp = cursor;
            --temp;
            undo.push(list);
            if (cursor != &list.dummy_head)
            {
                if (temp != NULL)
                {
                    if (*cursor == '\n')
                    {
                        list.delete_node(cursor);
                        my_print(list, currentPosition, cursor, currentPosition);
                        current_y--;
                        current_line--;
                        current_x = my_x[current_line];
                    }
                    else
                    {
                        list.delete_node(cursor);
                        current_x--;
                        my_x[current_line]--;
                        my_print(list, currentPosition, cursor, currentPosition);
                    }
                }
                // handle backspace here
                if (!currentPosition.decrementX() && currentPosition.getY() > 0)
                {
                    // // cout << '\0';
                    // current_line--;
                    currentPosition.decrementY();
                    currentPosition.setX(MAX_X);
                    // current_x = my_x[current_line];
                }
            }
        }
        else if (key == CTRL_Z)
        {
            undo.topp(list);
            undo.pop();
            current_x = 1;
            current_y = 0;
            cursor = list.begin();
            my_print(list, currentPosition, cursor, currentPosition);
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
            //! MY_CODE

            doubly_list<char>::iterator *iterator_array;
            int iterator_size;
            doubly_list<char>::iterator search_temp = list.begin();
            int i = 0;
            int search_x = 1;
            int search_y = 0;
            int search_line = 0;
            if (key == F1KEY)
            {
                char search;
                cin >> search;
                iterator_array = list.search_multiple(search, iterator_size);
                while (search_temp != NULL)
                {
                    if (*search_temp == search)
                    {
                        break;
                    }
                    search_x++;
                    if (*search_temp == '\n')
                    {
                        search_x = 1;
                        search_y++;
                        search_line++;
                    }
                    search_temp++;
                }
                current_x = search_x;
                current_y = search_y;
                cursor = search_temp;
                current_line = search_line;
            }
            else
            {
                if (key == F2KEY)
                {
                    char search[100];
                    cin.getline(search, 100);
                    iterator_array = list.search_multiple(search[0], iterator_size);
                    doubly_list<char>::iterator search_temp2;
                    while (search_temp != NULL && i < iterator_size)
                    {
                        if (search_temp == iterator_array[i])
                        {
                            search_temp2 = search_temp;
                            int j = 0;
                            int k = 0;
                            int flag = 0;
                            while (search_temp2 != NULL && !flag && k < strlen(search))
                            {
                                if (*search_temp2 != search[k])
                                {
                                    flag = 1;
                                    break;
                                }
                                search_temp2++;
                                k++;
                            }
                            if (!flag)
                            {
                                int temp_search_x = search_x;
                                i++;
                                while (k > 0)
                                {
                                    SetColorAtPoint(temp_search_x++, search_y, F_BLACK | B_Yellow);
                                    k--;
                                }
                            }
                        }
                        else if (*search_temp == '\n')
                        {
                            search_y++;
                            search_x = 0;
                        }
                        search_temp++;
                        search_x++;
                    }
                }
                else
                {
                    undo.push(list);
                    char search[100];
                    cin.getline(search, 100);
                    iterator_array = list.search_multiple(search[0], iterator_size);
                    cout << "Enter the text you want to replace it for: \n";
                    char replace[100];
                    cin.getline(replace, 100);
                    doubly_list<char>::iterator search_temp2;
                    current_y = 0;
                    while (search_temp != NULL && i < iterator_size)
                    {
                        if (*search_temp == '\n')
                        {
                            search_line++;
                            current_y++;
                        }
                        if (*search_temp == search[0])
                        {
                            search_temp2 = search_temp;
                            int j = 0;
                            int k = 0;
                            int flag = 0;
                            while (search_temp2 != NULL && !flag && k < strlen(search))
                            {
                                if (*search_temp2 != search[k])
                                {
                                    flag = 1;
                                    break;
                                }
                                search_temp2++;
                                k++;
                            }
                            if (!flag)
                            {
                                i++;
                                my_x[search_line] -= k;
                                current_x -= k;
                                search_temp2--;
                                while (k-- > 0)
                                {
                                    list.delete_node(search_temp2);
                                }
                                // --search_temp2;
                                k = strlen(replace);
                                my_x[search_line] += k;
                                current_x += k;
                                while (k-- > 0)
                                {
                                    list.insert(search_temp2, replace[j++]);
                                }
                            }
                        }
                        else if (*search_temp == '\n')
                        {
                            search_y++;
                            search_x = 0;
                        }
                        search_temp++;
                        search_x++;
                    }
                    PlaceCursor(1, 0);
                    cursor = list.begin();
                    current_line = 0;
                    current_x = 1;
                    current_y = 0;
                }
            }
        }
        else if (key == F4KEY)
        {
            //! MY_CODE
            ofstream fout("myeditor.txt");
            doubly_list<char>::iterator i = list.begin();
            // if (i != &list.dummy_head)
            {
                while (i != NULL)
                    fout << *i++;
            }
        }
        PlaceCursor(current_x, current_y);
    }
    return 0;
}

//-------------------------------------------End Main Editor--------------------------//
int main()
{
    mainEditor();
    return 0;
}
