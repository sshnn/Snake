#include "Title.hpp"
#include "Window.hpp"
void Title::setTitle(const sf::String& str)
{
	m_title.setString(str);
	m_title.setFont(*m_font);
	auto yaziBoyut = m_title.getLocalBounds();
	m_title.setFillColor(sf::Color::Red);
	m_size.x = yaziBoyut.width+yaziBoyut.left;
	m_size.y = yaziBoyut.height+yaziBoyut.top;
}

void Title::setTitleSize(int size)
{
	m_title.setCharacterSize(size);

}

void Title::isMouseOn(bool isMouseOn)
{
}

void Title::draw(Window& window)
{
	m_title.setPosition(m_position);
	window.draw(m_title);
}
