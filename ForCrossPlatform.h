#ifndef __FOR_CROSS_PLATFORM_H__
#define __FOR_CROSS_PLATFORM_H__
    #if defined(_WIN32) || defined(_WIN64)
        #include<io.h>
        #include <conio.h>
        #include <windows.h>
        inline void TemporyKeyboardSetting() {
            HKL hkl = LoadKeyboardLayoutW(L"00000409", KLF_ACTIVATE);
        }
        
    #elif defined(__linux__) || defined(__APPLE__)
        #include <fcntl.h>
        #include <termios.h>
        #include <unistd.h>
        #include <stdio.h>
        #include <stdlib.h>
        
        inline int _getch() {
            struct termios oldt, newt;
            int ch;
            tcgetattr(STDIN_FILENO, &oldt);
            newt = oldt;
            newt.c_lflag &= ~(ICANON | ECHO);
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);
            ch = getchar();
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            return ch;
        }
        inline int _kbhit() {
            struct termios oldt, newt;
            int ch, oldf;
            tcgetattr(STDIN_FILENO, &oldt);
            newt = oldt;
            newt.c_lflag &= ~(ICANON | ECHO);
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);
            oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
            fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
            ch = getchar();
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            fcntl(STDIN_FILENO, F_SETFL, oldf);
            if (ch != EOF) {
                ungetc(ch, stdin);
                return 1;
            }
            return 0;
        }
        inline void TemporyKeyboardSetting() {
            bool result = system("setxkbmap us");
            (result)?printf("success\n"):printf("failed\n");
        }
        #define _write write
    #endif

#endif // __FOR_CROSS_PLATFORM_H__