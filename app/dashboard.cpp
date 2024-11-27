#include <fstream>
#include <string>
#include <ncurses/curses.h>
#include <windows.h>
#include "define.h"

void dashboard() {
    std::string NamaFile = "./app/data/Akun.txt";
    std::string menu[2] = {"     Main     ", "     Exit     "};
    std::ifstream bacaFile(NamaFile);

    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    init_pair(2, COLOR_WHITE, COLOR_RED);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);

    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x); 
    int x = max_x / 2;      
    int y = max_y / 2;

    typeWriting(x, y,"Hi,","WELCOME TO OUR PROJECT");
    clear();

    int key;
    int active = 1;
    curs_set(0);
    do {
        keypad(stdscr, true);
        switch (key) {
            case KEY_UP:
                if(active == 1) active = 3;
                active--;
            break;
            case KEY_DOWN:
                active++;
                if(active == 3) active = 1;
            break;
            case 10:
                clear();
                endwin();
                if(active == 1) {
                    Play();
                    break;
                } else if(active == 2) {
                    Login_Register();
                    dashboard();
                    break;
                }
            break;
        }

        for(int i = 0; i < 2; i++) {
            std::string huruf = menu[i];

            if(active == (i + 1)) {
                attron(COLOR_PAIR(i + 1));
                mvprintw((y - 2) + i, x - (huruf.length() / 2), "%s", huruf.c_str());
                attroff(COLOR_PAIR(i + 1));
            } else {
                attron(COLOR_PAIR(3));
                mvprintw((y - 2) + i, x - (huruf.length() / 2), "%s", huruf.c_str());
                attroff(COLOR_PAIR(3));
            }
        }
    } while(key = getch());
    clear();
    endwin();
    // if(bacaFile.is_open()) {
    //     std::string baris;
    //     int index = 10;
    //     mvprintw(10,10, "%s", "Data User");
    //     while(std::getline(bacaFile, baris)) {
    //         mvprintw(++index , 10, "%s", baris.c_str());
    //         refresh();
    //     }
    //     bacaFile.close();
    // }
}