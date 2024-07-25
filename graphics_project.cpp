/**
Graphics Project, (all lab files compiled in the course)
Written by: Mustafa Haque
ID: CSE2102023106
Section: 23A
*/

#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void menu();
void name_first_graphics();
void dda();
void bresenham_line_draw_driver();
void bresenham_line_draw(int x1, int y1, int x2, int y2);
void bangladeshi_flag();

void circle_drawing();
void midpoint_circle(int x0, int y0, int r);
void plotpoint(int x0, int y0, int x, int y);

void smiley_emoji();
void moving_boat();
void moving_boat_backandforth();
void table_lamp();
void football_ground();

void tictactoe_driver();
void tictactoe_design();
void dis(int turn, int p);
int tictactoe_result(char *a);
void tictactoe_computer(char *a,int turn);

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
            bresenham_line_draw_driver();
            break;
        case 4:
            bangladeshi_flag();
            break;
        case 5:
            circle_drawing();
            break;
        case 6:
            smiley_emoji();
            break;
        case 7:
            moving_boat();
            break;
        case 8:
            moving_boat_backandforth();
            break;
        case 9:
            table_lamp();
            break;
        case 10:
            football_ground();
            break;
        case 11:
            tictactoe_driver();
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
    cout << "3. Line Drawing using Bresenham's Algorithm" << endl;
    cout << "4. Bangladeshi Flag" << endl;
    cout << "5. Circle Drawing using Midpoint Algorithm" << endl;
    cout << "6. Smiley Emoji" << endl;
    cout << "7. Moving Boat" << endl;
    cout << "8. Moving Boat Back and Forth" << endl;
    cout << "9. Table Lamp" << endl;
    cout << "10. Football Ground" << endl;
    cout << "11. TicTacToe" << endl;
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

void bresenham_line_draw_driver()
{
    int gd=DETECT, gm;
    initwindow(800,600, "Bresenham's Line algorithm.\n");
    int x1, y1, x2, y2;

    cout << "Enter first point (x1,y1):\n";
    cin >> x1 >> y1;
    cout << "Enter second point (x2,y2):\n";
    cin >> x2 >> y2;
    bresenham_line_draw(x1, y1, x2, y2);

    //getch();
    //closegraph();
}

void bresenham_line_draw(int x1, int y1, int x2, int y2)
{
    int dx = x2-x1;
    int dy = y2-y1;
    float m = dy/dx;
    //cout << endl << m << endl;

    if(m < 1)
    {
        int decision_parameter = (2*dy) - dx;
        int x= x1;
        int y= y1;
        if(dx < 0)
        {
            x = x2;
            y = y2;
            x2 = x1;
        }

        putpixel(x,y,BLUE);
        while(x < x2)
        {
            if(decision_parameter >= 0)
            {
                x = x+1;
                y = y+1;
                decision_parameter = decision_parameter + 2*dy - 2*dx*(y+1-y);

            }
            else
            {
                x = x+1;
                y = y;
                decision_parameter = decision_parameter + 2*dy -2*dx*(y-y);
            }
            putpixel(x,y,BLUE);
            delay(1);
        }
    }
    else if (m > 1)
    {
        int decision_parameter = 2*dx - dy;
        int x = x1;
        int y = y1;
        if(dy < 0)
        {
            x = x2;
            y = y2;
            y2 = y1;
        }

        putpixel(x,y,BLUE);
        while(y < y2)
        {
            if(decision_parameter >= 0)
            {
                x = x+1;
                y = y+1;
                decision_parameter = decision_parameter + 2*dx - 2*dy*(x+1-x);
            }
            else
            {
                y = y+1;
                x = x;
                decision_parameter = decision_parameter + 2*dx - 2*dy*(x-x);
            }
            putpixel(x,y,BLUE);
            delay(1);
        }
    }
    else if(m == 1)
    {
        int x = x1;
        int y = y1;
        putpixel(x,y, BLUE);
        while(x < x2)
        {
            x = x+1;
            y = y+1;
            putpixel(x,y, BLUE);
            delay(1);
        }
    }
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

void table_lamp()
{
    int gd=DETECT, gm;
    //initgraph(&gd, &gm, "");

    initwindow(1000,800, "Table Lamp");    //creates graphical window


    // Base
    line(800,599,0,599);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,DARKGRAY);
    rectangle(40,549,215,599);
    floodfill(42,555,WHITE);

    // Stand
    line(150,550,150,400);
    line(115,550,115,400);


    setfillstyle(SOLID_FILL,LIGHTGRAY);
    circle(135,373,38);
    circle(135,373,12);
    floodfill(135,408,WHITE);

    line(131,335,190,235);
    line(163,350,220,255);
    line(189,235,235,265);


    arc(220,202,50, 230, 45);
    line(249,168,282,191);


    arc(345,280,50, 221, 110);
    line(413,195,262,351);
    arc(340, 270, 220, 410, 40);
    setfillstyle(SOLID_FILL,YELLOW);
    //floodfill(360,280,WHITE);

    //getch();
    //closegraph();
}

void football_ground()
{
    int gd=DETECT, gm;
    initwindow(1300,600, "Football ground");
    int i, j;

    for(i=0; i<=50; i++)
    {

        setcolor(WHITE);
        // Ground Outline
        rectangle(100, 50, 1200, 550);

        // Coloring Green
        setfillstyle(SOLID_FILL, GREEN);
        floodfill(105, 55, WHITE);


        // Ground Middle Line
        line(650, 50, 650, 550);
        line(656, 50, 656, 550);

        // Coloring White
        setfillstyle(SOLID_FILL, WHITE);
        floodfill(652, 150, WHITE);

        // Mid Circles
        circle(653, 300, 60);
        circle(653, 300, 65);
        circle(653, 300, 10);

        // Outer Rectangle Left
        rectangle(100, 200, 250, 400);
        rectangle(100, 205, 245, 395);

        // Inner Rectangle Left
        rectangle(100, 230, 200, 370);
        rectangle(100, 235, 195, 365);

        // Arc Left Side
        arc(250, 300, 270, 90, 40);
        arc(250, 300, 270, 90, 35);

        // Outer Rectangle Right
        rectangle(1200, 200, 1050, 400);
        rectangle(1200, 205, 1055, 395);

        // Inner Rectangle Right
        rectangle(1200, 230, 1100, 370);
        rectangle(1200, 235, 1105, 365);

        // Arc Right Side
        arc(1051, 300, 90, 270, 40);
        arc(1051, 300, 90, 270, 35);

        // Goal posts
        rectangle(100,340,110,260);
        rectangle(1190,340,1200,260);

        // Coloring All White
        floodfill(714, 300, 15);
        floodfill(592, 300, 15);
        floodfill(657, 300, 15);
        floodfill(645, 300, 15);
        floodfill(247, 300, 15);
        floodfill(197, 300, 15);
        floodfill(287, 300, 15);
        floodfill(1053, 300, 15);
        floodfill(1103, 300, 15);
        floodfill(1013, 300, 15);


        // Player formation
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        circle(147,300,10); //GK
        floodfill(147,300,YELLOW);

        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        circle(300+(i*2),230,10);  //LCD
        circle(300+(i*2),370,10);  //RCD
        circle(300+(i*2),140,10);  //LB
        circle(300+(i*2),470,10);  //RB
        circle(400+(i*4),220,10);  //LCM
        circle(400+(i*4),380,10);  //RCM
        circle(500+(i*6),140,10);  //LW
        circle(500+(i*6),300,10);  //CAM
        circle(500+(i*6),470,10);  //RW
        circle(600+(i*8),300,10);  //ST

        // Colouring players red
        floodfill(300+(i*2),230,RED);
        floodfill(300+(i*2),370,RED);
        floodfill(300+(i*2),140,RED);
        floodfill(300+(i*2),470,RED);
        floodfill(400+(i*4),220,RED);
        floodfill(400+(i*4),380,RED);
        floodfill(500+(i*6),140,RED);
        floodfill(500+(i*6),300,RED);
        floodfill(500+(i*6),470,RED);
        floodfill(600+(i*8),300,RED);

        if(i == 0)
        {
            delay(1000);
        }
        cleardevice();
    }

    i--; // (i==50)

    setcolor(WHITE);
    // Ground Outline
    rectangle(100, 50, 1200, 550);

    // Coloring Green
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(105, 55, WHITE);


    // Ground Middle Line
    line(650, 50, 650, 550);
    line(656, 50, 656, 550);

    // Coloring White
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(652, 150, WHITE);

    // Mid Circles
    circle(653, 300, 60);
    circle(653, 300, 65);
    circle(653, 300, 10);

    // Outer Rectangle Left
    rectangle(100, 200, 250, 400);
    rectangle(100, 205, 245, 395);

    // Inner Rectangle Left
    rectangle(100, 230, 200, 370);
    rectangle(100, 235, 195, 365);

    // Arc Left Side
    arc(250, 300, 270, 90, 40);
    arc(250, 300, 270, 90, 35);

    // Outer Rectangle Right
    rectangle(1200, 200, 1050, 400);
    rectangle(1200, 205, 1055, 395);

    // Inner Rectangle Right
    rectangle(1200, 230, 1100, 370);
    rectangle(1200, 235, 1105, 365);

    // Arc Right Side
    arc(1051, 300, 90, 270, 40);
    arc(1051, 300, 90, 270, 35);

    // Goal posts
    rectangle(100,340,110,260);
    rectangle(1190,340,1200,260);

    // Coloring All White
    floodfill(714, 300, 15);
    floodfill(592, 300, 15);
    floodfill(657, 300, 15);
    floodfill(645, 300, 15);
    floodfill(247, 300, 15);
    floodfill(197, 300, 15);
    floodfill(287, 300, 15);
    floodfill(1053, 300, 15);
    floodfill(1103, 300, 15);
    floodfill(1013, 300, 15);


    // Player formation
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    circle(147,300,10); //GK
    floodfill(147,300,YELLOW);

    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    circle(300+(i*2),230,10);  //LCD
    circle(300+(i*2),370,10);  //RCD
    circle(300+(i*2),140,10);  //LB
    circle(300+(i*2),470,10);  //RB
    circle(400+(i*4),220,10);  //LCM
    circle(400+(i*4),380,10);  //RCM
    circle(500+(i*6),140,10);  //LW
    circle(500+(i*6),300,10);  //CAM
    circle(500+(i*6),470,10);  //RW
    circle(600+(i*8),300,10);  //ST

    // Colouring players red
    floodfill(300+(i*2),230,RED);
    floodfill(300+(i*2),370,RED);
    floodfill(300+(i*2),140,RED);
    floodfill(300+(i*2),470,RED);
    floodfill(400+(i*4),220,RED);
    floodfill(400+(i*4),380,RED);
    floodfill(500+(i*6),140,RED);
    floodfill(500+(i*6),300,RED);
    floodfill(500+(i*6),470,RED);
    floodfill(600+(i*8),300,RED);

    // Ball
    bresenham_line_draw(147,300,300+(i*2),370);          // GK - RCD
    bresenham_line_draw(300+(i*2),370,400+(i*4),380);    // RCD - RCM
    bresenham_line_draw(300+(i*2),230,400+(i*4),380);    // RCM - LCD
    bresenham_line_draw(300+(i*2),230,500+(i*6),295);    // LCD - CAM
    bresenham_line_draw(500+(i*6),295,600+(i*8),305);    // CAM - ST
    bresenham_line_draw(600+(i*8),305,1200,330);         // ST - Goal!!!!

    //getch();
    //closegraph();
}


/// ======================================== Tic Tac Toe Code starts here =================================================
// Tictactoe driver code
void tictactoe_driver()
{
    //Tic Tac Toe
    initwindow(500,600,"Tic Tac Toe");
    tictactoe_design();
    int x=0;
    POINT pos;
    int turn=0;
    char b[9]= {0};
    for(int i=0; i<9; i++)
        b[i]=0;
    settextstyle(8,0,3);
    int w=textwidth("Your Turn !!");
    outtextxy((400-w)/2,500,"Your Turn !!");
    while(x==0 && turn<=9)
    {
        if(GetAsyncKeyState(VK_LBUTTON))
        {
            GetCursorPos(&pos);
            long X=mousex();
            long Y=mousey();
            int mov=0;
            if(turn%2==0)
            {
                if(X>80 && X<160 && Y>220 && Y<300 && b[0]==0)     //b1
                {
                    dis(1,1);
                    mov=1;
                    b[0]='X';
                }
                else if(X>160 && X<240 && Y>220 && Y<300 && b[1]==0)     //b2
                {
                    dis(1,2);
                    mov=1;
                    b[1]='X';
                }
                else if(X>240 && X<320 && Y>220 && Y<300 && b[2]==0)     //b3
                {
                    dis(1,3);
                    mov=1;
                    b[2]='X';
                }
                else if(X>80 && X<160 && Y>300 && Y<380 && b[3]==0)     //b4
                {
                    dis(1,4);
                    mov=1;
                    b[3]='X';
                }
                else if(X>160 && X<240 && Y>300 && Y<380 && b[4]==0)     //b5
                {
                    dis(1,5);
                    mov=1;
                    b[4]='X';
                }
                else if(X>240 && X<320 && Y>300 && Y<380 && b[5]==0)     //b6
                {
                    dis(1,6);
                    mov=1;
                    b[5]='X';
                }
                else if(X>80 && X<160 && Y>380 && Y<460 && b[6]==0)     //b7
                {
                    dis(1,7);
                    mov=1;
                    b[6]='X';
                }
                else if(X>160 && X<240 && Y>380 && Y<460 && b[7]==0)     //b8
                {
                    dis(1,8);
                    mov=1;
                    b[7]='X';
                }
                else if(X>240 && X<320 && Y>380 && Y<460 && b[8]==0)     //b9
                {
                    dis(1,9);
                    b[8]='X';
                    mov=1;
                }
                if(mov)
                {
                    turn++;
                    x=tictactoe_result(b);
                    delay(200);
                    if(x!=0 || turn==9)
                        break;
                    // computers turn
                    tictactoe_computer(b,turn);
                    turn++;
                    x=tictactoe_result(b);
                }
            }
        }
    }
    cout<<"Thank You !!";
    if(x==1)
    {
        settextstyle(8,0,3);
        int w=textwidth("You Win !!");
        outtextxy((400-w)/2,500,"You Win !!");
    }
    else if(x==2)
    {
        settextstyle(8,0,3);
        int w=textwidth("Computer Wins !!");
        outtextxy((400-w)/2,500,"Computer Wins !!");
    }
    else if(x==0)
    {
        settextstyle(10,0,3);
        int w=textwidth("It's a Draw !!");
        outtextxy((400-w)/2,500,"It's a Draw !!");
    }
    //getch();
}


// TicTacToe Graphics Design
void tictactoe_design()
{
    settextstyle(8,0,6);
    int w=textwidth("Tic Tac Toe");
    outtextxy((400-w)/2,80,"Tic Tac Toe");
    line(160,220,160,460);
    line(160+1,220,160+1,460);
    line(160-1,220,160-1,460);

    line(80,300,320,300);
    line(80,300+1,320,300+1);
    line(80,300-1,320,300-1);

    line(80,380,320,380);
    line(80,380+1,320,380+1);
    line(80,380-1,320,380-1);

    line(240,220,240,460);
    line(240+1,220,240+1,460);
    line(240-1,220,240-1,460);

}

// Displays Marker Using Graphics
void dis(int turn, int p)
{
    settextstyle(8,0,6);
    int w=0,h=0;
    if(turn==1)
    {
        h=textheight("X");
        w=textwidth("X");
    }
    else
    {
        h=textheight("O");
        w=textwidth("O");
    }
    int x=(80-w)/2;
    int y=(80-h)/2;
    switch(p)
    {
    case 1:
        if(turn==1)
            outtextxy(x+80,y+220,"X");
        else
            outtextxy(x+80,y+220,"O");
        break;
    case 2:
        if(turn==1)
            outtextxy(x+160,y+220,"X");
        else
            outtextxy(x+160,y+220,"O");
        break;
    case 3:
        if(turn==1)
            outtextxy(x+240,y+220,"X");
        else
            outtextxy(x+240,y+220,"O");
        break;
    case 4:
        if(turn==1)
            outtextxy(x+80,y+300,"X");
        else
            outtextxy(x+80,y+300,"O");
        break;
    case 5:
        if(turn==1)
            outtextxy(x+160,y+300,"X");
        else
            outtextxy(x+160,y+300,"O");
        break;
    case 6:
        if(turn==1)
            outtextxy(x+240,y+300,"X");
        else
            outtextxy(x+240,y+300,"O");
        break;
    case 7:
        if(turn==1)
            outtextxy(x+80,y+380,"X");
        else
            outtextxy(x+80,y+380,"O");
        break;
    case 8:
        if(turn==1)
            outtextxy(x+160,y+380,"X");
        else
            outtextxy(x+160,y+380,"O");
        break;
    case 9:
        if(turn==1)
            outtextxy(x+240,y+380,"X");
        else
            outtextxy(x+240,y+380,"O");
        break;

    }
}

// Result
int tictactoe_result(char *a)
{
    // return || 0 for no result || 1 for player 1 || 2 for player 2

    //diagonal check
    if((a[0]==a[4] && a[0]==a[8] && a[0]=='X') || (a[2]==a[4] && a[2]==a[6] && a[2]=='X'))
    {
        return 1;
    }
    else if((a[0]==a[4] && a[0]==a[8] && a[0]=='O') || (a[2]==a[4] && a[2]==a[6] && a[2]=='O'))
    {
        return 2;
    }

    // horizontal check
    if((a[0]==a[1] && a[1]==a[2] && a[0]=='X') || (a[3]==a[4] && a[4]==a[5] && a[3]=='X') || (a[6]==a[7] && a[7]==a[8] && a[6]=='X'))
    {
        return 1;
    }
    else if((a[0]==a[1] && a[1]==a[2] && a[0]=='O') || (a[3]==a[4] && a[4]==a[5] && a[3]=='O') || (a[6]==a[7] && a[7]==a[8] && a[6]=='O'))
    {
        return 2;
    }

    //vertical check
    if((a[0]==a[3] && a[3]==a[6] && a[0]=='X') || (a[1]==a[4] && a[4]==a[7] && a[1]=='X') || (a[2]==a[5] && a[5]==a[8] && a[2]=='X'))
    {
        return 1;
    }
    else if((a[0]==a[3] && a[3]==a[6] && a[0]=='O') || (a[1]==a[4] && a[4]==a[7] && a[1]=='O') || (a[2]==a[5] && a[5]==a[8] && a[2]=='O'))
    {
        return 2;
    }

    return 0;
}

// Computer decision
void tictactoe_computer(char *a,int turn)
{
    int cnt[8],p[8];
    for(int i=0; i<8; i++)
    {
        cnt[i]=0;
        p[i]=-1;
    }
    // attack
    for(int i=0; i<9; i++)
    {
        if(a[i]=='O')
        {
            cnt[i/3]++;
            cnt[3+i%3]++;
            if(i%4==0)
                cnt[6]++;
            if(i==2 || i==4 || i==6)
                cnt[7]++;
        }
        else if(a[i]==0)
        {
            p[i/3]=i;
            p[3+i%3]=i;
            if(i%4==0)
                p[6]=i;
            if(i==2 || i==4 || i==6)
                p[7]=i;
        }
    }
    for(int i=0; i<8; i++)
    {
        if(cnt[i]==2 && p[i]!=-1)
        {
            dis(0,p[i]+1);
            a[p[i]]='O';
            return;
        }
        p[i]=-1;
        cnt[i]=0;
    }
    // defend
    for(int i=0; i<9; i++)
    {
        if(a[i]=='X')
        {
            cnt[i/3]++;
            cnt[3+i%3]++;
            if(i%4==0)
                cnt[6]++;
            if(i==2 || i==4 || i==6)
                cnt[7]++;
        }
        else if(a[i]==0)
        {
            p[i/3]=i;
            p[3+i%3]=i;
            if(i%4==0)
                p[6]=i;
            if(i==2 || i==4 || i==6)
                p[7]=i;
        }
    }
    for(int i=0; i<8; i++)
    {
        if(cnt[i]==2 && p[i]!=-1)
        {
            dis(0,p[i]+1);
            a[p[i]]='O';
            return;
        }
        p[i]=-1;
        cnt[i]=0;
    }
    if(a[4]==0)
    {
        dis(0,5);
        a[4]='O';
        return;
    }
    if(turn==1)
    {
        dis(0,1);
        a[0]='O';
        return;
    }
    if(turn==3)
    {
        if(a[4]=='X')
        {
            dis(0,3);
            a[2]='O';
            return;
        }
        p[0]=p[1]=-1;
        int j=0;
        for(int i=0; i<9; i++)
            if(a[i]=='X')
                p[j++]=i;
        if((p[0]==3 && p[1]==5) || (p[0]==2 && p[1]==7))
        {
            dis(0,1);
            a[0]='O';
            return;
        }
        if(p[0]+p[1]==8)
        {
            dis(0,2);
            a[1]='O';
            return;
        }
        if(p[0]==0 || p[0]==1)
        {
            if(p[1]==5 || p[1]==8)
            {
                dis(0,3);
                a[2]='O';
                return;
            }
            else if(p[1]==3 || p[1]==6)
            {
                dis(0,1);
                a[0]='O';
                return;
            }
            else
            {
                dis(0,7);
                a[6]='O';
                return;
            }
        }
        else if(p[0]==1 || p[0]==2)
        {
            if(p[1]==3 || p[1]==6)
            {
                dis(0,1);
                a[0]='O';
                return;
            }
            else
            {
                dis(0,9);
                a[8]='O';
                return;
            }
        }
        else if(p[0]==3)
        {
            dis(0,7);
            a[6]='O';
            return;
        }
        dis(0,9);
        a[8]='O';
        return;
    }
    for(int i=0; i<9; i++)
    {
        if(a[i]==0)
        {
            dis(0,1+i);
            a[i]='O';
            return;
        }
    }
}

///================================================== Tic Tac Toe code ends here ===================================================

