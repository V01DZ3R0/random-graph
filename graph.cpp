#include <SFML/Graphics.hpp>
#include <cmath>
#include <random>
// g++ graph.cpp -lsfml-graphics -lsfml-window -lsfml-system && ./a.out  
int main()
{
    std::random_device rand;
    std::mt19937 mt(rand());

    sf::RenderWindow window(sf::VideoMode(1280, 720), "nEHiC", sf::Style::Titlebar);

    window.clear(sf::Color::White);
    // Draw x-axis line

    std::uniform_real_distribution<double> xdistr(0, window.getSize().x);
    std::uniform_real_distribution<double> ydistr(0, window.getSize().y);
    int y;
    int r = 3;
    sf::CircleShape dot(r);
    dot.setFillColor(sf::Color::Red);
    sf::VertexArray graph(sf::LineStrip);
    bool refreshFlag = true;
    while (1488)
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                window.clear(sf::Color::White);
                graph.clear();
                refreshFlag = true;
            }
        }
        //
        sf::VertexArray xAxis(sf::Lines);
        xAxis.append(sf::Vertex(sf::Vector2f(0, window.getSize().y / 2), sf::Color::Cyan));
        xAxis.append(sf::Vertex(sf::Vector2f(window.getSize().x, window.getSize().y / 2), sf::Color::Cyan));
        window.draw(xAxis);

        sf::VertexArray yAxis(sf::Lines);
        yAxis.append(sf::Vertex(sf::Vector2f(window.getSize().x / 2, 0), sf::Color::Cyan));
        yAxis.append(sf::Vertex(sf::Vector2f(window.getSize().x / 2, window.getSize().y), sf::Color::Cyan));
        window.draw(yAxis);

        graph.clear();
        if (refreshFlag)
        {
            for (int i = 0; i < window.getSize().x; i += 5)
            {

                y = ydistr(rand);

                graph.append(sf::Vertex(sf::Vector2f(i, y), sf::Color::Black));
                dot.setPosition(i - r, y - r);
                window.draw(dot);
                window.draw(graph);
                window.display();
               sf::sleep(sf::milliseconds(12));
            }
             refreshFlag = false;
        }
        //
    }
    return 0;
}