#include <iostream>
#include <ncurses/curses.h>
#include <windows.h>
using namespace std;

int main(){
    initscr();
    curs_set(0);
    start_color();
    
    string titik = "....";
    string huruf1 = "SELAMAT DATANG KAWAN";
    string huruf2 = "semoga menang xixi";

    int a = 0;
    int b = 0;
    int c = 0;

    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);

    
    for(int i=25; i<= COLS - 25; i++){
        mvprintw(5,i, "=");
        mvprintw(LINES - 5,i, "=");
        refresh();
        Sleep(50);
    }
    for(int i=5; i <= LINES - 5; i++ ){
        mvprintw(i,25, "#");
        mvprintw(i, COLS - 25, "#");
        refresh();
        Sleep(50);
    }

    for (int i = 1; i <= 50; i++){
        if(b == 20) b = 0;
        if(b == 0) mvprintw(10,52, " ");

        attron(COLOR_PAIR(3));

        mvprintw(LINES/2 - 1, COLS/2 - 11 + b, "%c", huruf1[b]);
        if(c == 18) c = 0;
        if(c == 0) mvprintw(13,52, " ");
        mvprintw(LINES/2 + 1, COLS/2 - 10 + c, "%c", huruf2[c]);
        attroff(COLOR_PAIR(3));

        refresh();
        Sleep(50);
        b++;
        c++;
    }
    mvprintw(LINES/2 - 1, COLS/2 - 11,"                                 ");
    mvprintw(LINES/2 + 1, COLS/2 - 10,"                                 ");

    for (int i = 1; i <= 100; i++){
        if(a == 4) a = 0;
        if(a == 0) mvprintw(LINES/2 + 3, COLS/2 + 7, "                   ");
        attron(COLOR_PAIR(1));
        mvprintw(LINES/2 - 2,COLS/2 - 12, "-----------------------");
        mvprintw(LINES/2 + 2,COLS/2 - 12, "-----------------------");
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(2));
        mvprintw(LINES/2 - 1,COLS/2 - 6, "L O A D I N G ");
        mvprintw(LINES/2 + 1, COLS/2 - 1, "   %%");
        mvprintw(LINES/2 + 1, COLS/2 - 1, "%d", i);
        mvprintw(LINES/2 + 3, COLS/2 - 11, "tunggu sebentar ya");
        mvprintw(LINES/2 + 3, COLS/2 + 8 + a, "%c", titik[a]);
        attroff(COLOR_PAIR(2));
        
        refresh();
        Sleep(50);
        a++;
    }
    clear();

    endwin();
}