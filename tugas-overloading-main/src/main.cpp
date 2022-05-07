#include <iostream>
#include <string>
#include "include/rectangular.hpp"

void end();
void start();
void clear();
int optionthis();

int main()
{
    while (1)
    {
        start();
        float length;
        float width;
        float xmid;
        float ymid;

        std::string option_str;

        int option_int;
        std::cout << "INPUT DATA PERSEGI PANJANG : " << std::endl;

        std::cout << "Persegi panjang ke-1" << std::endl;
        std::cout << "Panjang        : ";
        std::cin >> length;
        std::cout << "Lebar          : ";
        std::cin >> width;
        std::cout << "Titik tengah x : ";
        std::cin >> xmid;
        std::cout << "Titik tengah y : ";
        std::cin >> ymid;
        std::cout << std::endl;
        rectangular square1(xmid, ymid, length, width);

        std::cout << "Persegi panjang ke-2" << std::endl;
        std::cout << "Panjang        : ";
        std::cin >> length;
        std::cout << "Lebar          : ";
        std::cin >> width;
        std::cout << "Titik tengah x : ";
        std::cin >> xmid;
        std::cout << "Titik tengah y : ";
        std::cin >> ymid;
        rectangular square2(xmid, ymid, length, width);

        rectangular newobj(0, 0, 0, 0);
        clear();

        std::cout << "Persegi panjang 1" << std::endl;
        square1.output();
        std::cout << std::endl;
        std::cout << "Persegi panjang 2" << std::endl;
        square2.output();
        std::cout << std::endl;
        std::cout << "Pastikan data yang telah dimasukkan adalah benar : ";
        std::cin >> option_str;
        if (option_str == "n" || option_str == "N")
        {
            main();
        }
        clear();

        while (1)
        {
            clear();
            std::cout << std::endl;
            option_int = optionthis();
            switch (option_int)
            {
            case 0:
            {
                // operator tambah (+)
                newobj = square1 + square2;
                if (square1 == square2)
                {
                    newobj.output();
                }
            }
            break;
            case 1:
            {
                std::cout << std::endl;
                // operator min (-)
                newobj = square1 - square2;
                if (square1 == square2)
                {
                    newobj.output();
                }
            }
            break;
            case 2:
            {
                std::cout << std::endl;
                // Operator ++ (persegi 1)
                ++square1;
                square1.output();
                --square1;
            }
            break;
            case 3:
            {
                std::cout << std::endl;
                // Operator -- (persegi 1)
                ++square2;
                square1.output();
                --square2;
            }
            break;
            case 4:
            {
                std::cout << std::endl;
                // Operator ++ (persegi 2)
                --square1;
                square1.output();
                ++square1;
            }
            break;
            case 5:
            {
                std::cout << std::endl;
                // Operator -- (persegi 2)
                --square2;
                square1.output();
                ++square2;
            }
            break;

            case 6:
            {
                std::cout << "Nilai X Maksimum persegi panjang 1 : " << square1[2] << std::endl;
                std::cout << "Nilai X Maksimum persegi panjang 2 : " << square2[2] << std::endl;
                if (square1[2] > square2[2])
                {
                    std::cout << "X Maks Persegi Panjang 1 > X Maks Persegi Panjang 2";
                }
                else if (square1[2] < square2[2])
                {
                    std::cout << "X Maks Persegi Panjang 2 > X Maks Persegi Panjang 1";
                }
                else
                {
                    std::cout << "X Maks Persegi Panjang 1 = X Maks Persegi Panjang 2";
                }
            }
            break;
            case 7:
            {
                std::cout << std::endl
                          << std::endl;
                std::cout << "-------------------------------------------------" << std::endl;
                if (square1 == square2)
                {
                    std::cout << "Beririsan" << std::endl;
                }
                else
                {
                    std::cout << "Tidak beririsan" << std::endl;
                }
                return 0;
            }
            break;
            }
        }
        clear();
        // untuk mengulang program dengan objek baru
        std::cout << std::endl;
        std::cout << "Mulai program dengan objek baru ? (y/n) :";
        std::cin >> option_str;
        if (option_str == "N" || option_str == "n")
        {
            break;
        }
    }
}

void clear()
{
    system("CLS");
}

void start()
{
    std::cout << std::endl;
    std::cout << "TUGAS PEMOGRAMAN LANJUT";
    std::cout << "OVERLOADING OPERATOR";
    std::cin.get();
    clear();
}

void end()
{
    std::cout << std::endl;
    std::cout << "Apakah anda ingin melakukan operasi lagi (y/n), tekan enter...";
    std::cin.get();
}

int optionthis()
{
    int option_fungsi;
    std::cout << "Operasi : \n 0. Operator + \n 1. Operator - \n 2. Operator ++ Objek 1 \n 3. Operator -- Objek 1 \n 4. Operator ++ Objek 2 \n 5. Operator -- Objek 2 \n 6. Operator []  \n 7. Operator == \n Masukan pilihan anda : ";
    std::cin >> option_fungsi;
    return option_fungsi;
    return 1;
}