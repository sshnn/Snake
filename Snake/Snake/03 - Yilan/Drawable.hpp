#pragma once
#include<SFML/Graphics.hpp>
class Window;

class Drawable
{
public:
	virtual void draw(Window& pencere) = 0;
	sf::Vector2f m_position;
};
