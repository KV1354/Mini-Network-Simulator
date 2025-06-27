#include "week2.cpp"

class Canvas{
    private:
        int windowX, windowY;
        vector<Shape*> shapes;

    public:
        Canvas(vector<Shape*> shapes, int X = 800, int Y = 600): windowX(X), windowY(Y), shapes(shapes){}
        void addShape(Shape* shape){
            shapes.push_back(shape);
        }
        void displayCanvas(){
            sf::RenderWindow window(sf::VideoMode(windowX, windowY), "Canvas");
            while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

                window.clear(sf::Color::Black);
                for(auto shape: shapes){
                    shape->display(window);
                }
                window.display();
            }
        }
};

int main()
{
    int c1[] = {200, 150}, c2[] = {0, 0}, c3[] = {500, 500}, c4[] = {400, 100};
    Rectangle rec(c1, 100, 50, sf::Color::Red);
    Square sq(c2, 50, sf::Color::Blue);
    Ellipse el(c3, 100, 50, sf::Color::Yellow);
    Circle cir(c4, 50, sf::Color::Green);
    vector<Shape*> x = {&rec, &sq, &el, &cir};
    Canvas canvas(x);
    canvas.displayCanvas();
}
