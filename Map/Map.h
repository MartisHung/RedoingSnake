
#ifndef __MAP_H__
#define __MAP_H__

#define MAX_OF_MAP_X 0x42

#define MAX_OF_MAP_1_Y 0x17
#define MAX_OF_MAP_2_Y 0x15
#define MAX_OF_MAP_3_Y 0x17
#define MAX_OF_MAP_4_Y 0x17

#include "../ForCrossPlatform.h"
#include "../ForTypeDef.h"
#include "../Snake/Snake.h"
class Map {
    void debug()const;
    public:
        Map();
        ~Map();
        void GameLoop();
        /// @param MapUsing the map rn using
        char** MapUsing = nullptr;
    private:
        Snake *Player=nullptr, *Enemy[0xA]={nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};
        ///@param MapSelect
        ///@brief 0b0000 0000 @n
        ///@brief high 4 bit elder map selected | low 4 bit rn map selected
        bool_array MapSelect = 0b00000000;
        int8 enemyExist = 0;
        void MapTransfer    ();
        void MapSelecting   ();
        void enemyGenerate  ();
        void foodGenerate   ();
        void ShowMap        ()          const;
        void MapCoping      (int8 i);
        void ShowMap        (_nullptr_t)const;
        static void delay   ();
        inline static void  clearScreem () __attribute__((__always_inline__)) {printf("\033[2J\033[H");}
        //Map reference Map1/Map2/Map3/Map4 | 0x0 0x1 0x2 0x3
        inline static constexpr char Map1[MAX_OF_MAP_1_Y][MAX_OF_MAP_X]={
            "################################################################\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "################################################################\n"
        };
        inline static constexpr char Map2[MAX_OF_MAP_2_Y][MAX_OF_MAP_X]={
            "################################################################\n",
            "#                                                              #\n",
            "#   ##   ##      ##########       ##########      ##   ##      #\n",
            "#                #        #       #        #                   #\n",
            "#   ##   ##      #  ####  #       #  ####  #      ##   ##      #\n",
            "#                #  #T #  #       #  #F #  #                   #\n",
            "#   #  ####  #   #  #  #  #########  #  #  #   #  ####  #      #\n",
            "#   #        #   #  #                   #  #   #        #      #\n",
            "#   #  ####  #   #  #####################  #   #  ####  #      #\n",
            "#   #        #   #                         #   #        #      #\n",
            "#      ####      ###########################      ####         #\n",
            "#                                                              #\n",
            "#      ####      ####    ####   ####    ####      ####         #\n",
            "#                  #                     #                     #\n",
            "#   ##   ##        #  ####   ###   ####  #        ##   ##      #\n",
            "#                     #T      #      F#                        #\n",
            "#   ##   ##           #  #    #    #  #           ##   ##      #\n",
            "#                        #         #                           #\n",
            "#   ####  ####           #         #           ####  ####      #\n",
            "#                  #                     #                     #\n",
            "################################################################\n"
        };
        inline static constexpr char Map3[MAX_OF_MAP_3_Y][MAX_OF_MAP_X]={
            "################################################################\n",
            "#                                                              #\n",
            "#   ####   ##################    #####   ####                  #\n",
            "#   #                                                          #\n",
            "#   #  ######    ###########     #####                         #\n",
            "#   #                                                          #\n",
            "#   #######       ##########     #####   #####       #######   #\n",
            "#                 #                                            #\n",
            "#   #######       #               ####   ####        #######   #\n",
            "#   #             #                                            #\n",
            "#   #   ###    ####             ######   ######      ########  #\n",
            "#   #                                                          #\n",
            "#   #######    #######       #########   #########   ###########\n",
            "#                                                              #\n",
            "#   #######    #######      ##########   ##########            #\n",
            "#                                                              #\n",
            "#   ##########        ################                         #\n",
            "#                                                              #\n",
            "#   ###########          ###########        ###########        #\n",
            "#   #                                                          #\n",
            "#   #   ###############################   #################    #\n",
            "#   #                                                          #\n",
            "################################################################\n"
        };
        inline static constexpr char Map4[MAX_OF_MAP_4_Y][MAX_OF_MAP_X]={
            "################################################################\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "#    ##                                                        #\n",
            "#     #                                                        #\n",
            "#     ##           ###################C                #       #\n",
            "#     ##         #####################                #        #\n",
            "#      ##       #########                            #         #\n",
            "#      ##      #######                              #          #\n",
            "#       ##    ######                    ############           #\n",
            "#       #################         ########################     #\n",
            "#        #    C#########T         ##D                #  B#     #\n",
            "#        ##     #########         ##                 #   #     #\n",
            "#        ##        T####          ##                 #   #     #\n",
            "#        ################         ##                 #   #     #\n",
            "#                ##               ##                 #   #     #\n",
            "#                ##               ##                 #  D#     #\n",
            "#              ######             ########################     #\n",
            "#             ##    ##            B#######################     #\n",
            "#                                                              #\n",
            "#                                                              #\n",
            "################################################################\n"
        };
};

#endif//__Map_H__