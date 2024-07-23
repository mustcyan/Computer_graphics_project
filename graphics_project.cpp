/**
Graphics Project, (all lab files compiled in the course)
Written by: Mustafa Haque
ID: CSE2102023106
Section: 23A
*/

#include<iostream>
#include<graphics.h>
using namespace std;

void menu();
void name_first_graphics();
void dda();
void bangladeshi_flag();

void circle_drawing();
void midpoint_circle(int x0, int y0, int r);
void plotpoint(int x0, int y0, int x, int y);

void smiley_emoji();
void moving_boat();
void moving_boat_backandforth();

int main()
{
    int loop = 100;
    while(loop >= 0)
    {
        cout << endl << "loop = " << loop;
        int choice;
        cout << endl;
        menu();
        cout << "Enter your choice: " << endl;
        cin >> choice;
        cout << endl;

        switch(choice)
        {
        case 1:
            name_first_graphics();
            break;
        case 2:
            dda();
            break;
        case 3:
            bangladeshi_flag();
            break;
        case 4:
            circle_drawing();
            break;
        case 5:
            smiley_emoji();
            break;
        case 6:
            moving_boat();
            break;
        case 7:
            moving_boat_backandforth();
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 0:
            exit(0);
            break;
        default :
            cout << "Invalid case. Please try again\n";
        }
        loop = loop - 1;
    }

    return 0;
}

void menu()
{
    cout << "================================ MENU ====================================" << endl;
    cout << "1. Name Displayed(First graphics lab)" << endl;
    cout << "2. Line Drawing using Digital Differential Analyzer" << endl;
    cout << "3. Bangladeshi Flag" << endl;
    cout << "4. Circle Drawing using Midpoint Algorithm" << endl;
    cout << "5. Smiley Emoji" << endl;
    cout << "6. Moving Boat" << endl;
    cout << "7. Moving Boat Back and Forth" << endl;
    cout << "0. Exit\n" << endl;
}

void name_first_graphics()
{
    int gd=DETECT, gm;
    //initgraph(&gd, &gm, "");

    //creates graphical window
    initwindow(1000,500, "Name First graphics");

    //M
    line(100,200,100,150);
    line(100,150,125,175);
    line(125,175,150,150);
    line(150,150,150,200);

    //U
    line(160,200,160,150);
    line(160,200,200,200);
    line(200,200,200,150);

    //S
    line(210,150,250,150);
    line(210,150,210,175);
    line(210,175,250,175);
    line(210,200,250,200);
    line(250,200,250,175);

    //T
    line(260,150,310,150);
    line(285,150,285,200);

    //A
    line(320,200,345,150);
    line(345,150,370,200);
    line(332.5,175,355,175);

    //F
    line(380,150,430,150);
    line(380,175,420,175);
    line(380,150,380,200);

    //A
    line(440,200,465,150);
    line(465,150,490,200);
    line(452,175,477,175);

    //line(200,200,240,150);

    //getch();
    //closegraph();
}

void dda()
{
    // Digital Differential Analyzer
    cout << "Enter two points. (Between 50 and 800)\n";
    cout << "Enter x1 and y1: ";
    int x1, y1, x2, y2, i;
    cin >> x1 >> y1;
    cout << "Enter x2 and y2: ";
    cin >> x2 >> y2;

    //calculating d_x and d_y
    int d_x, d_y;
    d_x = abs(x2-x1);
    d_y = abs(y2-y1);

    //finding step;
    int step;
    step = (d_x >= d_y) ? d_x : d_y;
    cout << "Step = " << step << endl;

    float x_inc = d_x/(float)step;
    float y_inc = d_y/(float)step;

    int gd=DETECT, gm;
    //initgraph(&gd, &gm, "");

    //creates graphical window
    initwindow(1000,1000, "Line Drawing using Digital Differential Analyzer");

    //loop
    float X = x1;
    float Y = y1;
    for(i=0; i<=step; i++)
    {
        //cout << "p" << i << " = " << "(" << X << " , " << Y << ")" << endl;
        putpixel(X, Y, YELLOW);
        X = X + x_inc;
        Y = Y + y_inc;
        delay(10);
    }

    //getch();
    //closegraph();
}

void bangladeshi_flag()
{
    int gd=DETECT, gm;
    //initgraph(&gd, &gm, "");

    //creates graphical window
    initwindow(1000,1000, "Bangladeshi National Flag");

    //Bangladesh national Flag

    setcolor(WHITE);
    rectangle(70,70,280,180); //Green part
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(71,71,WHITE);

    setcolor(RED);
    circle(165,125,30);     //Red part
    setfillstyle(SOLID_FILL, RED);
    floodfill(165,125, RED);

    setcolor(WHITE);
    rectangle(60,70,70,420); //Dark Gray, Pole
    setfillstyle(SOLID_FILL, DARKGRAY);
    floodfill(61,71,WHITE);

    setcolor(WHITE);
    rectangle(35,420,95,440); //Brown, Base
    setfillstyle(SOLID_FILL, BROWN);
    floodfill(41,421,WHITE);

    //getch();
    //closegraph();
}

//Circle drawing Driver function
void circle_drawing()
{
    cout << "Enter the center points of the circle: (example: 300 300)" << endl;
    int x, y, r;
    cin >> x >> y;
    cout << "Enter the radius of the circle: (example: 200)" << endl;
    cin >> r;

    int gd=DETECT, gm;
    //initgraph(&gd, &gm, "");
    initwindow(1000, 1000, "Circle Drawing using midpoint Algorithm");

    midpoint_circle(x, y, r);
    //getch();
}

// Calculates the circle points using midpoint algorithm
void midpoint_circle(int x0, int y0, int r)
{
    int x = 0;
    int y = r;
    int itr = 1;
    int p = 1-r;

    plotpoint(x0, y0, x, y);

    while(x < y)
    {
        if(p < 0)
        {
            x = x+1;
            p = p + (2*x) + 1;
            cout << "point" << itr << "(" << x << " , " << y << ")" << endl;
            itr++;
        }
        else
        {
            x = x+1;
            y = y-1;
            p = p + (2*x) + 1 - (2*y);
            cout << "point" << itr << "(" << x << " , " << y << ")" << endl;
            itr++;
        }
        plotpoint(x0, y0, x, y);
        delay(20);

    }

}

// Plots the individual points of the circle
void plotpoint(int x0, int y0, int x, int y)
{
    putpixel(x0+x, y0+y, 7);
    putpixel(x0+x, y0-y, 7);
    putpixel(x0-x, y0+y, 7);
    putpixel(x0-x, y0-y, 7);
    putpixel(x0+y, y0+x, 7);
    putpixel(x0+y, y0-x, 7);
    putpixel(x0-y, y0+x, 7);
    putpixel(x0-y, y0-x, 7);
}

void smiley_emoji()
{
    int gd = DETECT, gm;
    //initgraph(&gd, &gm, "");
    initwindow(1000, 1000, "Smiley Emoji");

    //setcolor(YELLOW);
    //outtext("Assignment 2: Emoji");

    setcolor(YELLOW);
    circle(300,250,150);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(300,250, YELLOW);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);

    circle(250, 200, 25);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(250,200, BLACK);
    circle(350, 200, 25);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(350, 200, BLACK);

    ellipse(300,290,200,340,55,35);
    ellipse(300,291,200,340,55,35);
    ellipse(300,292,200,340,55,35);
    ellipse(300,293,200,340,55,35);
    ellipse(300,294,200,340,55,35);
    ellipse(300,295,200,340,55,35);

    setfillstyle(SOLID_FILL, BLACK);
    ellipse(300,255,0,360,8,12);
    floodfill(300,250,BLACK);

    //getch();
    //closegraph;
}

void moving_boat()
{
    int gd=DETECT, gm;
    //initgraph(&gd, &gm, "");

    //creates graphical window
    initwindow(1000,800, "Moving Boat");

    for(int i=0; i<=700; i = i+10)
    {
        // Triangle
        setcolor(WHITE);
        line(125+i,150,100+i,200);
        line(125+i,150,150+i,200);
        line(100+i,200,150+i,200);
        setfillstyle(1, GREEN);
        floodfill(125+i,175, WHITE);

        // Boat body
        setcolor(WHITE);
        line(50+i,200,200+i,200);
        line(50+i,200,75+i,230);
        line(200+i,200,175+i,230);
        line(75+i,230,175+i,230);
        setfillstyle(1, BROWN);
        floodfill(100+i,210, WHITE);

        //base line
        line(10,235,900,235);

        delay(50);
        cleardevice();
    }
    //getch();
    //closegraph();
}

void moving_boat_backandforth()
{
    int gd=DETECT, gm;
    //initgraph(&gd, &gm, "");

    //creates graphical window
    initwindow(1000,800, "Moving Boat Back and Forth");


    while(true)
    {
        for(int i=0; i<=700; i = i+10)
        {
            // Triangle
            setcolor(WHITE);
            line(125+i,150,100+i,200);
            line(125+i,150,150+i,200);
            line(100+i,200,150+i,200);
            setfillstyle(1, GREEN);
            floodfill(125+i,175, WHITE);

            // Boat body
            setcolor(WHITE);
            line(50+i,200,200+i,200);
            line(50+i,200,75+i,230);
            line(200+i,200,175+i,230);
            line(75+i,230,175+i,230);
            setfillstyle(1, BROWN);
            floodfill(100+i,210, WHITE);

            //base line
            line(10,235,900,235);

            delay(50);
            cleardevice();
        }

        for(int i=700; i>=0; i = i-10)
        {
            // Triangle
            setcolor(WHITE);
            line(125+i,150,100+i,200);
            line(125+i,150,150+i,200);
            line(100+i,200,150+i,200);
            setfillstyle(1, GREEN);
            floodfill(125+i,175, WHITE);

            // Boat body
            setcolor(WHITE);
            line(50+i,200,200+i,200);
            line(50+i,200,75+i,230);
            line(200+i,200,175+i,230);
            line(75+i,230,175+i,230);
            setfillstyle(1, BROWN);
            floodfill(100+i,210, WHITE);

            //base line
            line(10,235,900,235);

            delay(50);
            cleardevice();
        }
    }
    //getch();
    //closegraph();
}
