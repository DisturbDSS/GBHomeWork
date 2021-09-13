
#include <iostream>

int main()
{   //task1
    {
        int a, b, c, d;
        a = 2;
        b = 3;
        c = 4;
        d = 5;
        
        float f = a * (b + (static_cast<float>(c) / d));

        std::cout << "used static_cast: " << f << std::endl;
    };

    //task2
    {
       int a, b;
       std::cout << "enter value: "; 
       std::cin >> a;
       b = (a <= 21) ? a - 21 : (a - 21) << 1;

       std::cout << "(? :): " << b << std::endl;      
    };

    //task3
    {
         int array[3][3][3] = { 5 };
         int* ptr = nullptr;


    };
    


 

    //task 4
    {
        extern const int a, b, c, d;
        float f = a * (b + ((float)c / d));

        std::cout << "used C-style cast, extern var: " << f << std::endl;
    };

    //examples ///////////////////////////////////////////////////////
    {
        int c = 10, d = 20;

        ++c;
        d = c++;
        std::cout << c << " " << d << std::endl; // d=11 c=12
    };

    {
        unsigned char flags = 3; //0011
        unsigned char mask = 2;  //0010
        if ((flags&mask) == mask)
            std::cout << "bit 2 is ON" << std::endl;
        else
            std::cout << "bit 2 is OFF" << std::endl;
        flags &= ~mask;
        std::cout << (int)flags << std::endl;
    };

    {
        int e, f = 0;
        int j = 0b0000'1111; //15
        e = f | j;
        std::cout << e << std::endl;
    };

    return 0;
}



