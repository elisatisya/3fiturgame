#include <ncurses/curses.h>
#include <string>
#include <windows.h>

void typeWriting(int x, int y, std::string teks1, std::string teks2) {
    cbreak();
    noecho();
    std::string text[2] = {teks1, teks2}; 

    for(int i = 0; i < 2; i++) {
        std::string huruf = text[i];
        for(int j = 0; j < huruf.length(); j++) {
            mvprintw(y, x - (huruf.length() / 2) + j,  "%c", huruf[j]);
            Sleep(200);
            refresh();
        }

        if(i != 2 - 1) {
            Sleep(2000);
            for(int k = huruf.length() - 1; k > -1; k--) {
                mvprintw(y, x - (huruf.length() / 2) + k, " ");
                Sleep(200);
                refresh();
            }  
        }
    }
    Sleep(2000);
}