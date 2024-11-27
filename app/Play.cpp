#include <fstream>
#include <string>
#include <ncurses/curses.h>
#include <windows.h>
#include <cstdlib>
#include "define.h"



void Play() {
    initscr();
    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x); 
    int x = max_x / 2;      
    int y = max_y / 2;

    std::string teks[] = {
        " _____   ____   __   __  __  __  _____  _   _   _____    _____   ____    ____   _   _ ",
        "/ ____| / __ \\ | \\// || \\/  ||_   _||\\ | | / ____|  / ____| / __ \\ / __\\ |\\ | |",
        "| |     | |  | || \\  /|| \\  /|  | |  | \\| || |  __  | (___  | |  | || |  | || \\| |",
        "| |     | |  | || |\\/||| |\\/||  | |  | . ` || | |_ | \\___\\ | |  | || |  | || . ` |",
        "| |____ | |__| || |  | || |  | | _| |_ | |\\ || |__| |  ____) || |__| || |__| || |\\ |",
        "\\_____|\\____/ |_|  |_||_|  |_||_____||_| \\|\\_____| |_____/ \\____/ \\____/ |_|\\_|"
    };
                                                 
    typeWriting(x,y, "Comming Soon...", "Babay");

    getch();
    endwin();
    exit(0);
}