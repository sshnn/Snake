#include "Snake.hpp"
#include "Window.hpp"

Snake::Snake(float size)
{
	m_size = size;
	m_speed = size / 10;
	m_lapTimer = 0.0f;
	squarePtr newSquare = Square::makeSquare(size);
	newSquare->m_speed = m_speed;
	m_squareList.push_back(newSquare);
	addToTail();
	addToTail();
	addToTail();
	addToTail();
	addToTail();
	m_nextDirection = DIRECTION::DIRECTION_RIGHT;
}

void Snake::draw(Window& window)
{
	for (auto next : m_squareList)
		next->draw(window);
}

void Snake::changeDirection(DIRECTION newDirection)
{
	auto basYon = m_squareList.front()->m_direction;

	if (newDirection == DIRECTION::DIRECTION_RIGHT && basYon == DIRECTION::DIRECTION_LEFT)
		return;
	if (newDirection == DIRECTION::DIRECTION_LEFT && basYon == DIRECTION::DIRECTION_RIGHT)
		return;
	if (newDirection == DIRECTION::DIRECTION_UP && basYon == DIRECTION::DIRECTION_DOWN)
		return;
	if (newDirection == DIRECTION::DIRECTION_DOWN && basYon == DIRECTION::DIRECTION_UP)
		return;
	m_nextDirection = newDirection;
		
}

void Snake::move()
{
	if (m_lapTimer == m_size)
	{
		for (int i = m_squareList.size() - 1; i > 0; i--)
		{
			m_squareList[i]->m_direction = m_squareList[i - 1]->m_direction;
		}
		m_squareList.front()->m_direction = m_nextDirection;
		m_lapTimer = 0.0f;
	}

	m_lapTimer += m_speed;
	for (auto siradaki : m_squareList)
		siradaki->move();
	
}

void Snake::addToTail()
{
	if (m_squareList.empty())
		return;
	auto yon = m_squareList.back()->m_direction;
	auto konum = m_squareList.back()->m_position;
	switch (yon)
	{
	case DIRECTION::DIRECTION_LEFT:
		konum.x += m_size;
		break;
	case DIRECTION::DIRECTION_RIGHT:
		konum.x -= m_size;
		break;
	case DIRECTION::DIRECTION_UP:
		konum.y += m_size;
		break;
	case DIRECTION::DIRECTION_DOWN:
		konum.y -= m_size;
		break;
	}
	auto newSquare = Square::makeSquare(m_size);
	newSquare->m_direction = yon;
	newSquare->m_position = konum;
	newSquare->m_speed = m_speed;
	m_squareList.push_back(newSquare);
}

bool Snake::collision()
{
	auto headPos = m_squareList.front()->m_position;

	for (int i = 1; i < m_squareList.size(); i++)
	{
		if (headPos == m_squareList[i]->m_position)
			return true;
	}
	return false;
}

bool Snake::isBeat(const sf::Vector2f& beatPos)
{
	auto headPos = m_squareList.front()->m_position;

	return headPos == beatPos;
}
