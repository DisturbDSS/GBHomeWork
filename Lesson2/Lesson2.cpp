#include <iostream>

int main()
{
    std::cout << "HomeWork2" << std::endl;

    //task1
    {
        bool flag{ false };
        char chr = 'A';
        short int var1 = -32768;
        int var2 = 100;
        long long var3 = 9999999999999999999;
        float var4 = 7.77f;
        double var5 = 7.1E-5;
        std::cout << chr << sizeof(chr) << std::endl;
        std::cout << var1 << " size is:" << sizeof(var1) << std::endl;
    };
    //task2
    {
        enum XO { CROSS = 'x', ZERO = 'o', NONE = 'n' };

        //task3
        const unsigned int FieldSize = 3;
        XO array[FieldSize][FieldSize] = { {NONE, NONE, NONE}, {NONE, NONE, NONE}, {NONE, NONE, NONE} };

        std::cout << array[0][0] << ' ' << array[0][1] << ' ' << array[0][2] << std::endl;
        std::cout << array[1][0] << ' ' << array[1][1] << ' ' << array[1][2] << std::endl;
        std::cout << array[2][0] << ' ' << array[2][1] << ' ' << array[2][2] << std::endl;



        //task4

        struct XOStruct
        {

            XO array[FieldSize][FieldSize];
            bool is_game_end;
            bool is_player1_won;
            long long Player1ID, player2ID;
            XO cPlayer1, cPlayer2;


        };    

    };


    //task5
   
    union Data { int a; float b; char c; };

    struct Variant
    {
        Data U1;
        unsigned int flag : 1;
        unsigned int flag : 2;
        unsigned int flag : 3;
    };
    Variant A, B, C;
    C.U1.b = 2.1;
    B.flag = true;
    A.U1.a = 34;



    return 0;
}