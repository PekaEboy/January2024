#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf; 
using namespace std;
int main()
{
    Clock t;
    int Height = 600;
    int Width = Height * 4 / 3;
    RenderWindow window(VideoMode(Width, Height), "SFML works!");
    CircleShape shape(10.f);
    shape.setFillColor(Color::Green);
    Time tm = t.getElapsedTime();

    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::W)) {
            shape.move(0.f, -1.f);
        }
        if (Keyboard::isKeyPressed(Keyboard::S)) {
            shape.move(0.f, 1.f);
        }
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            shape.move(-1.f, 0.f);
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            shape.move(1.f, 0.f);
        }
        window.clear();
        window.draw(shape);
        window.display();
        sleep(milliseconds(15));
        Int32 t1 = tm.asMilliseconds();
        tm = t.getElapsedTime();
        Int32 t2 = tm.asMilliseconds();
        Int32 delta = abs(t1 - t2);
        cout << "FPS: " << (int) (1000/(float)delta) << endl;
        
    }
    return 0;
}