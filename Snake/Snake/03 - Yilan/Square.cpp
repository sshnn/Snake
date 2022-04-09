#include "Square.hpp"
#include "Window.hpp"
Square::Square(float size)
{
	m_size = size;
	m_shape.setSize(sf::Vector2f(size, size));
	m_direction = DIRECTION::DIRECTION_RIGHT;
	m_speed = size /10;
	m_shape.setOutlineThickness(2);
	m_shape.setOutlineColor(sf::Color::Red);
	m_shape.setFillColor(sf::Color::Green);
}

squarePtr Square::makeSquare(float boyut)
{
	return std::make_shared<Square>(boyut);

}

void Square::move()
{
	switch (m_direction)
	{
	case DIRECTION::DIRECTION_LEFT:
		m_position.x -= m_speed;
		break;
	case DIRECTION::DIRECTION_RIGHT:
		m_position.x += m_speed;
		break;
	case DIRECTION::DIRECTION_UP:
		m_position.y -= m_speed;
		break;
	case DIRECTION::DIRECTION_DOWN:
		m_position.y += m_speed;
		break;
	}
}

void Square::draw(Window& window)
{
	m_shape.setPosition(m_position);
	window.draw(m_shape);
}
