#ifndef FIGURE_HPP_INCLUDED
#define FIGURE_HPP_INCLUDED

#include "Vector.h" 
#include "/com.docker.devenvironments.code/src/lab0/Vector.cpp" 
#include "Point.h"  
#include <iostream>  

class Figure {  //объявление абстрактного базового класса Figure
protected:
    Vector<Point> coordinates;  //поле coordinates типа Vector<Point> для хранения координат фигуры

public:
    virtual operator double() const = 0;  //виртуальная функция преобразования объекта фигуры в тип double
    virtual Point geom_center() const = 0;  //виртуальная функция для вычисления геометрического центра фигуры
    
};

#endif 
