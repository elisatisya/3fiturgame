#include <ncurses/curses.h>
#include <string>

using namespace std;

#define KEY_ESC 27

int main(){

    string arr[2] = {"\t\tRegister       ", "\t\tLogin          ",};

    initscr();

    noecho();

    curs_set(0);

    start_color();

    init_pair(1, COLOR_RED, COLOR_WHITE);
    init_pair(2, COLOR_BLUE, COLOR_GREEN);

    clear();

    int baris_awal = 16;
    int kolom = 70;

    attron(COLOR_PAIR(1));
    mvprintw(baris_awal, kolom, "%s", arr[0].c_str());
    mvprintw(baris_awal + 2, kolom, "%s", arr[1].c_str());

    keypad(stdscr, TRUE);

    int menu = 0;
    int menu_awal = 0;
    int menu_akhir = 1;
    int baris = baris_awal;
    int baris_akhir = baris_awal + 2;

    attron(COLOR_PAIR(2));
    mvprintw(baris_awal, kolom, "%s", arr[0].c_str());

    int tombol;
    while(tombol != KEY_ESC){
        if((tombol = getch()) == ERR);

        if(tombol == KEY_UP){
            baris -= 2;
            menu -= 1;

            if(menu == -1){
                baris = baris_akhir;
                menu = 1;
            }

            attron(COLOR_PAIR(2));
            mvprintw(baris, kolom, "%s", arr[menu].c_str());

            attron(COLOR_PAIR(1));
            if(menu == 1){
                mvprintw(baris_awal, kolom, "%s", arr[menu_awal].c_str());
            } else {
                mvprintw(baris + 2, kolom, "%s", arr[menu + 1].c_str());
            }

        }
        else if(tombol == KEY_DOWN){
            baris += 2;
            menu += 1;

            if(menu == 2){
                baris = baris_awal;
                menu = 0;
            }

            attron(COLOR_PAIR(2));
            mvprintw(baris, kolom, "%s", arr[menu].c_str());

            attron(COLOR_PAIR(1));
            if(menu == 0){
                mvprintw(baris_akhir, kolom, "%s", arr[menu_akhir].c_str());
            } else {
                mvprintw(baris - 2, kolom, "%s", arr[menu - 1].c_str());
            }
        }
    }

    endwin();
}