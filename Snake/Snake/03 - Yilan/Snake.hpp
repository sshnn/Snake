#pragma once
#include "Square.hpp"
class Snake :public Drawable
{
public:
	Snake(float size);
	// Inherited via Cizilebilir
	virtual void draw(Window& window) override;
	void changeDirection(DIRECTION newDirection);
	void move();
	void addToTail();
	bool collision(); // yýlan kendine çarptý mý
	bool isBeat(const sf::Vector2f& yemKonum); // yem yendi mi

	squarePtrList	m_squareList;
	float		m_size;
	float		m_speed;
	float		m_lapTimer; // tur sayacý
	DIRECTION			m_nextDirection;
};

using snakePtr = std::shared_ptr<Snake>;
