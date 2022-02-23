#include <iostream>
class Point2D {
    private:
        int x;
        int y;
    public:
        Point2D(int, int);
        int getX();
        int getY();

};

Point2D::Point2D(int x, int y){
    this->x=x;
    this->y=y;
}

int Point2D::getX(){
    return x;
}

int Point2D::getY(){
    return y;
} 
