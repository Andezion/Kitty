#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

void setWindowTransparency(sf::RenderWindow& window, COLORREF colorKey)
{
    HWND hwnd = window.getSystemHandle();
    LONG style = GetWindowLong(hwnd, GWL_EXSTYLE);
    SetWindowLong(hwnd, GWL_EXSTYLE, style | WS_EX_LAYERED);
    SetLayeredWindowAttributes(hwnd, colorKey, 0, LWA_COLORKEY);
}

int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktop, "work", sf::Style::Fullscreen);
    setWindowTransparency(window, RGB(255, 255, 255));

    bool what_color_we_have_now = false;
    bool do_we_pressed = false;

    sf::Vector2f currentPos(window.getSize().x / 2, window.getSize().y / 2);

    std::vector<sf::Texture> texture_left;
    std::vector<std::string> filename_left = { "kot/left1.png", "kot/left2.png" };
    for (const auto& filename : filename_left)
    {
        sf::Texture texture;
        texture.loadFromFile(filename);
        texture_left.push_back(texture);
    }
    std::vector<sf::Sprite> sprite_left;
    for (const auto& texture : texture_left)
    {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite_left.push_back(sprite);
    }

    std::vector<sf::Texture> texture_right;
    std::vector<std::string> filename_right = { "kot/right1.png", "kot/right2.png" };
    for (const auto& filename : filename_right)
    {
        sf::Texture texture;
        texture.loadFromFile(filename);
        texture_right.push_back(texture);
    }
    std::vector<sf::Sprite> sprite_right;
    for (const auto& texture : texture_right)
    {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite_right.push_back(sprite);
    }

    std::vector<sf::Texture> texture_up;
    std::vector<std::string> filename_up = { "kot/up1.png", "kot/up2.png" };
    for (const auto& filename : filename_up)
    {
        sf::Texture texture;
        texture.loadFromFile(filename);
        texture_up.push_back(texture);
    }
    std::vector<sf::Sprite> sprite_up;
    for (const auto& texture : texture_up)
    {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite_up.push_back(sprite);
    }

    std::vector<sf::Texture> texture_down;
    std::vector<std::string> filename_down = { "kot/down1.png", "kot/down2.png" };
    for (const auto& filename : filename_down)
    {
        sf::Texture texture;
        texture.loadFromFile(filename);
        texture_down.push_back(texture);
    }
    std::vector<sf::Sprite> sprite_down;
    for (const auto& texture : texture_down)
    {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite_down.push_back(sprite);
    }

    std::vector<sf::Texture> texture_downleft;
    std::vector<std::string> filename_downleft = { "kot/downleft1.png", "kot/downleft2.png" };
    for (const auto& filename : filename_downleft)
    {
        sf::Texture texture;
        texture.loadFromFile(filename);
        texture_downleft.push_back(texture);
    }
    std::vector<sf::Sprite> sprite_downleft;
    for (const auto& texture : texture_downleft)
    {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite_downleft.push_back(sprite);
    }

    std::vector<sf::Texture> texture_downright;
    std::vector<std::string> filename_downright = { "kot/downright1.png", "kot/downright2.png" };
    for (const auto& filename : filename_downright)
    {
        sf::Texture texture;
        texture.loadFromFile(filename);
        texture_downright.push_back(texture);
    }
    std::vector<sf::Sprite> sprite_downright;
    for (const auto& texture : texture_downright)
    {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite_downright.push_back(sprite);
    }

    std::vector<sf::Texture> texture_upleft;
    std::vector<std::string> filename_upleft = { "kot/upleft1.png", "kot/upleft2.png" };
    for (const auto& filename : filename_upleft)
    {
        sf::Texture texture;
        texture.loadFromFile(filename);
        texture_upleft.push_back(texture);
    }
    std::vector<sf::Sprite> sprite_upleft;
    for (const auto& texture : texture_upleft)
    {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite_upleft.push_back(sprite);
    }

    std::vector<sf::Texture> texture_upright;
    std::vector<std::string> filename_upright = { "kot/upright1.png", "kot/upright2.png" };
    for (const auto& filename : filename_upright)
    {
        sf::Texture texture;
        texture.loadFromFile(filename);
        texture_upright.push_back(texture);
    }
    std::vector<sf::Sprite> sprite_upright;
    for (const auto& texture : texture_upright)
    {
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite_upright.push_back(sprite);
    }

    int what_part = 0;

    int current_for_left = 0;
    int current_for_right = 0;
    int current_for_up = 0;
    int current_for_down = 0;
    int current_for_downleft = 0;
    int current_for_downright = 0;
    int current_for_upleft = 0;
    int current_for_upright = 0;

    sf::Clock clock;
    sf::Time switchTime = sf::seconds(0.5f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q))
            {
                window.close();
            }
        }

        sf::Vector2i pos = sf::Mouse::getPosition(window);
        if (pos.x > currentPos.x && pos.y == currentPos.y)
        {
            what_part = 0;
        }
        else if(pos.x < currentPos.x && pos.y == currentPos.y)
        {
            what_part = 1;
        }
        else if (pos.y < currentPos.y && pos.x == currentPos.x)
        {
            what_part = 2;
        }
        else if (pos.y > currentPos.y && pos.x == currentPos.x)
        {
            what_part = 3;
        }
        else if (pos.x < currentPos.x && pos.y > currentPos.y)
        {
            what_part = 4;
        }
        else if (pos.x > currentPos.x && pos.y > currentPos.y)
        {
            what_part = 5;
        }
        else if (pos.x < currentPos.x && pos.y < currentPos.y)
        {
            what_part = 6;
        }
        else if (pos.x > currentPos.x && pos.y < currentPos.y)
        {
            what_part = 7;
        }

        sf::Vector2f circle_pos(static_cast<float>(pos.x), static_cast<float>(pos.y));

        float speed = 0.0005f;
        currentPos = currentPos + (circle_pos - currentPos) * speed;

        switch (what_part)
        {
        case 0:
            sprite_right[current_for_right].setPosition(currentPos);
            break;
        case 1:
            sprite_left[current_for_left].setPosition(currentPos);
            break;
        case 2:
            sprite_up[current_for_up].setPosition(currentPos);
            break;
        case 3:
            sprite_down[current_for_down].setPosition(currentPos);
            break;
        case 4:
            sprite_downleft[current_for_downleft].setPosition(currentPos);
            break;
        case 5:
            sprite_downright[current_for_downright].setPosition(currentPos);
            break;
        case 6:
            sprite_upleft[current_for_upleft].setPosition(currentPos);
            break;
        case 7:
            sprite_upright[current_for_upright].setPosition(currentPos);
            break;
        }

        if (clock.getElapsedTime() > switchTime)
        {
            if (what_part == 0)
            {
                current_for_right = (current_for_right + 1) % sprite_right.size();
            }
            else if (what_part == 1)
            {
                current_for_left = (current_for_left + 1) % sprite_left.size();
            }
            else if (what_part == 2)
            {
                current_for_up = (current_for_up + 1) % sprite_up.size();
            }
            else if (what_part == 3)
            {
                current_for_down = (current_for_down + 1) % sprite_down.size();
            }
            else if (what_part == 4)
            {
                current_for_downleft = (current_for_downleft + 1) % sprite_downleft.size();
            }
            else if (what_part == 5)
            {
                current_for_downright = (current_for_downright + 1) % sprite_downright.size();
            }
            else if (what_part == 6)
            {
                current_for_upleft = (current_for_upleft + 1) % sprite_upleft.size();
            }
            else if (what_part == 7)
            {
                current_for_upright = (current_for_upright + 1) % sprite_upright.size();
            }
            clock.restart();
        }

        window.clear();

        switch (what_part)
        {
        case 0:
            window.draw(sprite_right[current_for_right]);
            break;
        case 1:
            window.draw(sprite_left[current_for_left]);
            break;
        case 2:
            window.draw(sprite_up[current_for_up]);
            break;
        case 3:
            window.draw(sprite_down[current_for_down]);
            break;
        case 4:
            window.draw(sprite_downleft[current_for_downleft]);
            break;
        case 5:
            window.draw(sprite_downright[current_for_downright]);
            break;
        case 6:
            window.draw(sprite_upleft[current_for_upleft]);
            break;
        case 7:
            window.draw(sprite_upright[current_for_upright]);
            break;
        }

        window.display();
    }

    return 0;
}
