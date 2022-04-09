#pragma once
#include "Drawable.hpp"
#include "BasicTypes.hpp"
class Square :public Drawable
{
public:
	Square(float size);
	static std::shared_ptr<Square> makeSquare(float boyut);
	void move();
	virtual void draw(Window& window) override;

	float m_size;
	float m_speed;
	DIRECTION	m_direction;
	sf::RectangleShape m_shape;


};
using  squarePtr = std::shared_ptr<Square>;
using squarePtrList = std::vector<squarePtr>;