#include "Frame.hpp"
#include "Window.hpp"
Frame::Frame()
{
	
}

void Frame::set(float frameSize, float distanceSize)
{
	m_distance = distanceSize;

	m_lineNumber = (int)frameSize / distanceSize;
	
	m_horizontal_line.setSize(sf::Vector2f(frameSize, 1));
	m_vertical_line.setSize(sf::Vector2f(1, frameSize));
}
void Frame::draw(Window& window)
{
	sf::Vector2f nextPos;
	for (int i = 0; i < m_lineNumber; i++)
	{

		nextPos.x = m_position.x;
		nextPos.y = m_position.y + i * m_distance;
		


		m_horizontal_line.setPosition(nextPos);
		window.draw(m_horizontal_line);

		nextPos.x = m_position.x+ i * m_distance;
		nextPos.y = m_position.y;
		m_vertical_line.setPosition(nextPos);
		window.draw(m_vertical_line);
	}

}
