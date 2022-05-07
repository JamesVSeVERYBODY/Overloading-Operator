#include <iostream>
#include <cmath>
#include "include/rectangular.hpp"

void rectangular::output()
{
    float length, width;
    length = this->x_maks - this->x_min;
    length = abs(length);
    width = this->y_maks - this->y_min;
    width = abs(width);
    std::cout << "Tengah x   : " << (this->x_maks - this->x_min) * 0.5 + this->x_min;
    std::cout << std::endl;
    std::cout << "Tengah y   : " << (this->y_maks - this->y_min) * 0.5 + this->y_min;
    std::cout << std::endl;
    std::cout << "Panjang (Length)          : " << length;
    std::cout << std::endl;
    std::cout << "Lebar (Width)           : " << width;
    std::cout << std::endl;
    
    std::cout << "Nilai X min      : " << this->x_min;
    std::cout << std::endl;
    std::cout << "Nilai X max      : " << this->x_maks;
    std::cout << std::endl;
    std::cout << "Nilai Y min      : " << this->y_min;
    std::cout << std::endl;
    std::cout << "Nilai Y maks     : " << this->y_maks;
    std::cout << std::endl;
}

rectangular::rectangular(float xmid, float ymid, float length, float width)
{
    this->x_min = (float)xmid - ((float)length * 0.5);
    this->x_maks = (float)xmid + ((float)length * 0.5);
    this->y_min = (float)ymid - ((float)width * 0.5);
    this->y_maks = (float)ymid + ((float)width * 0.5);
}

bool rectangular::operator==(rectangular const &new_var) const
{
    if (this->x_maks > new_var.x_min && this->x_min<new_var.x_maks &&this->y_maks> new_var.y_min && this->y_min < new_var.y_maks)
    {
        return true;
    }
    else
    {
        return false;
    }
}

rectangular rectangular::operator+(rectangular const &new_var)
{
    rectangular temp(0, 0, 0, 0);
    if (*this == new_var)
    {
        temp.x_min = std::min(this->x_min, new_var.x_min);
        temp.y_min = std::min(this->y_min, new_var.y_min);
        temp.x_maks = std::max(this->x_maks, new_var.x_maks);
        temp.y_maks = std::max(this->y_maks, new_var.y_maks);
    }
    else
    {
        std::cout << "Tidak Beririsan" << std::endl;
    }
    return temp;
}

rectangular rectangular::operator-(rectangular const &new_var)
{
    rectangular temp(0, 0, 0, 0);
    if (*this == new_var)
    {
        temp.x_min = std::max(this->x_min, new_var.x_min);
        temp.x_maks = std::min(this->x_maks, new_var.x_maks);
        temp.y_min = std::max(this->y_min, new_var.y_min);
        temp.y_maks = std::min(this->y_maks, new_var.y_maks);
    }
    else
    {
        std::cout << "Tidak Beririsan" << std::endl;
    }
    return temp;
}

void rectangular::operator++()
{
    float length = 0;
    float width = 0;
    float xmid = 0;
    float ymid = 0;

    length = this->x_maks - this->x_min;
    length = abs(length);
    width = this->y_maks - this->y_min;
    width = abs(width);

    xmid = this->x_min + length * 0.5;
    ymid = this->y_min + width * 0.5;

    length = length * 2;
    width = width * 2;

    this->x_min = xmid - length * 0.5;
    this->y_min = ymid - width * 0.5;
    this->x_maks = xmid + length * 0.5;
    this->y_maks = ymid + width * 0.5;
}

void rectangular::operator--()
{
    float length = 0;
    float width = 0;
    float xmid = 0;
    float ymid = 0;

    length = this->x_maks - this->x_min;
    length = abs(length);
    width = this->y_maks - this->y_min;
    width = abs(width);
    xmid = this->x_min + length * 0.5;
    ymid = this->y_min + width * 0.5;

    length = length * 0.5;
    width = width * 0.5;

    this->x_min = xmid - length * 0.5;
    this->y_min = ymid - width * 0.5;
    this->x_maks = xmid + length * 0.5;
    this->y_maks = ymid + width * 0.5;
}

float rectangular::operator[](int i)
{
    switch (i)
    {
    case 1:
        return this->x_min;
        break;
    case 2:
        return this->x_maks;
        break;
    case 3:
        return this->y_min;
        break;
    case 4:
        return this->y_maks;
        break;
    }
    return 0;
}