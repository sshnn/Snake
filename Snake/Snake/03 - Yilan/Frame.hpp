#pragma once

#include "Drawable.hpp"
#include<SFML/Graphics.hpp>
class Frame :public Drawable
{
public:
	Frame();

	void set(float frameSize, float distanceSize);


	// Inherited via Cizilebilir
	virtual void draw(Window& window) override;



	sf::RectangleShape m_horizontal_line;
	sf::RectangleShape m_vertical_line;
	int		m_lineNumber;
	float	m_distance;
};
