#include "Map.hpp"

Map::Map(){
    write(1,(char*)"press the arrow to select the Map\nAnd press enter to play",58);
    const char* Map1[] = {
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
    const char* Map2[] = {
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
    const char* Map3[] = {
        "################################################################\n",
        "#                                                              #\n",
        "#   ####   ##################    #####   ####                  #\n",
        "#   #                                                          #\n",
        "#   #  ######    ###########     #####                         #\n",
        "#   #                                                          #\n",
        "#   #######        #########     #####   #####       #######   #\n",
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
    const char*Map4[]={
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
        "#                ##               ##                 #D  #     #\n",
        "#              ######             ########################     #\n",
        "#             ##    ##            B#######################     #\n",
        "#                                                              #\n",
        "#                                                              #\n",
        "################################################################\n"
    };
}

void Map::MapTransfer(char** MapUsing,int8 MapSelected) const {
    if(MapUsing!=nullptr){
        switch(MapSelected>>4){
            case 0b00: for(int8 i=0;i<MAX_OF_MAP_1_Y;i++) {delete[] MapUsing[i];} break;
            case 0b01: for(int8 i=0;i<MAX_OF_MAP_2_Y;i++) {delete[] MapUsing[i];} break;
            case 0b10: for(int8 i=0;i<MAX_OF_MAP_3_Y;i++) {delete[] MapUsing[i];} break;
            case 0b11: for(int8 i=0;i<MAX_OF_MAP_4_Y;i++) {delete[] MapUsing[i];} break;
        }
    }

    switch( MapSelected & 0b1111){
        case 0b00:
            for(int8 i=0;i<MAX_OF_MAP_1_Y;i++){MapUsing[i] = new char [MAX_OF_MAP_X+1]; MapCoping(Map1[i],MapUsing[i]);}break;
        case 0b01:
            for(int8 i=0;i<MAX_OF_MAP_2_Y;i++){MapUsing[i] = new char [MAX_OF_MAP_X+1]; MapCoping(Map2[i],MapUsing[i]);}break;
        case 0b10:
            for(int8 i=0;i<MAX_OF_MAP_3_Y;i++){MapUsing[i] = new char [MAX_OF_MAP_X+1]; MapCoping(Map3[i],MapUsing[i]);}break;
        case 0b11:
            for(int8 i=0;i<MAX_OF_MAP_4_Y;i++){MapUsing[i] = new char [MAX_OF_MAP_X+1]; MapCoping(Map4[i],MapUsing[i]);}break;
    }
    
    return;
}

void Map::ShowMap(char** MapUsing,int8 MapSelect)const{
    switch(MapSelect){
        case 0:for(int8 i=0;i<MAX_OF_MAP_1_Y;i++)write(1,MapUsing[i],MAX_OF_MAP_X);break;
        case 1:for(int8 i=0;i<MAX_OF_MAP_2_Y;i++)write(1,MapUsing[i],MAX_OF_MAP_X);break;
        case 2:for(int8 i=0;i<MAX_OF_MAP_3_Y;i++)write(1,MapUsing[i],MAX_OF_MAP_X);break;
        case 3:for(int8 i=0;i<MAX_OF_MAP_4_Y;i++)write(1,MapUsing[i],MAX_OF_MAP_X);break;
    }
}

void Map::MapSelecting(int8* MapSelected)const{
    printf("press '0' to select \nleft / right to switch map");
    char ch;
    while(ch!='0'){
        if(_kbhit()){
            ch = _getch();
            switch(ch){
                case 'a':{if(MapSelected==(void*)0b00){MapSelected=(int8*)3;}else{MapSelected--;} break;}
                case 'd':{if(MapSelected==(void*)0b11){MapSelected=(int8*)0;}else{MapSelected++;} break;}
                case '-32':{
                    ch = _getch();
                    switch(ch){
                        case 75:if(MapSelected==(void*)0b00){MapSelected=(int8*)3;}else{MapSelected--;}break;
                        case 77:if(MapSelected==(void*)0b11){MapSelected=(int8*)0;}else{MapSelected--;}break;
                    }
                }
            }
        }
    }
}

//(Asm) MOV map2,map1
void Map::MapCoping(const char* map1,char*map2)const {
    for(int8 i=0;i<MAX_OF_MAP_X;i++) map2[i]=map1[i];
}

Map::~Map() {
    write(1,"finish",7);
    for(int8 i=0;i<MAX_OF_MAP_1_Y;i++) delete[] Map1[i];
    for(int8 i=0;i<MAX_OF_MAP_2_Y;i++) delete[] Map2[i];
    for(int8 i=0;i<MAX_OF_MAP_3_Y;i++) delete[] Map3[i];
    for(int8 i=0;i<MAX_OF_MAP_4_Y;i++) delete[] Map4[i];
    delete[] Map1;
    delete[] Map2;
    delete[] Map3;
    delete[] Map4;
}