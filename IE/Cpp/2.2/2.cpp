#include <iostream>

class Point2D {
    private:
        int x;
        int y;
    public:
        Point2D(int, int);
        Point2D(const Point2D&);
        int getX();
        int getY();

};

Point2D::Point2D(int x, int y){
    this->x=x;
    this->y=y;
}

Point2D::Point2D(const Point2D& other){
   *this=other;
   std::cout<<"Copy constructor called for point("<<other.x<<","<<other.y<<")\n";
}

int Point2D::getX(){
    return x;
}

int Point2D::getY(){
    return y;
} 
