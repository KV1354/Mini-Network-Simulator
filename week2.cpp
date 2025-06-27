#include<iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Shape{
    private:
        int* coordinates;
        
    protected:
        int id;
        sf::Color color;
    public:
        Shape(int* coordinates_, sf::Color color): color(color){
            coordinates = new int[2];
            coordinates[0] = coordinates_[0];
            coordinates[1] = coordinates_[1];
        }
        int* get_coordinates(){
            return coordinates;
        }
        void moveX(int distance){
            coordinates[0] += distance;
        }
        void moveY(int distance){
            coordinates[1] += distance;
        }
        int getShape(){return id;}
        virtual void display(sf::RenderWindow &){
            // window.clear();
            return;
        }
        ~Shape(){
            free(coordinates);
        }
};

class Rectangle : public Shape{
    private:
        int length, breadth;
    public:
        Rectangle(int* coordinates, int length, int breadth, sf::Color color = sf::Color::Green): Shape(coordinates, color), length(length), breadth(breadth){
            id = 0;
        }
        int getLength(){return length;}
        int getBreadth(){return breadth;}
        void display(sf::RenderWindow & window){
            int * coordinates = get_coordinates();
            sf::RectangleShape rec(sf::Vector2f(getLength(), getBreadth()));
            rec.setFillColor(color);
            rec.setPosition(coordinates[0], coordinates[1]);
            window.draw(rec);
        }
};

class Square: public Rectangle{
    public:
        Square(int* coordinates, int side, sf::Color color = sf::Color::Green): Rectangle(coordinates, side, side, color){
            id = 1;
        }
        int getSide(){
            return getLength();
        }
        
};

class Ellipse: public Shape{
    int a, b;
    public:
        Ellipse(int* coordinates, int a, int b, sf::Color color = sf::Color::Green): Shape(coordinates, color), a(a), b(b){
            id = 3;
        }
        int getXlength(){return a;}
        int getYlength(){return b;}
        void display(sf::RenderWindow & window){
            int * coordinates = get_coordinates();
            sf::CircleShape ellipse(1.f);
            ellipse.setScale(getXlength(), getYlength());
            ellipse.setPosition(coordinates[0], coordinates[1]);
            ellipse.setFillColor(color);
            window.draw(ellipse);
        }
};

class Circle: public Ellipse{
    public:
        Circle(int* coordinates, int radius, sf::Color color = sf::Color::Green): Ellipse(coordinates, radius, radius, color){
            id = 2;
        }
        int getRadii(){return getXlength();}
};

// int main(){
//     int coordinates[] = {1, 2};
//     Rectangle rec(coordinates, 10, 5);
//     Square sq(coordinates, 5);
//     Ellipse el(coordinates, 10, 5);
//     Circle cir(coordinates, 5);
//     cout << cir.getXlength() << " " << rec.get_coordinates()[0] << endl;
// }