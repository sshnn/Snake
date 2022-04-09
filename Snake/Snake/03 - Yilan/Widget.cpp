#include "Widget.hpp"

void Widget::mouseMove(int x, int y)
{
	for (auto next : m_widgetList)
	{
		if (next->isInside(x, y))
		{
			next->isMouseOn(true);
			next->mouseMove(x, y);
		}
		else
		{
			next->isMouseOn(false);
		}
	}
}

bool Widget::isInside(int x, int y)
{
	if (m_position.x <= x &&
		m_position.x + m_size.x >= x &&
		m_position.y <= y &&
		m_position.y + m_size.y >= y)
	{
		return true;
	}
	return false;
}



void Widget::setPosition(const sf::Vector2f& newPos)
{
	for (auto next : m_widgetList)
	{
		auto localPos = next->getPos() - m_position;
		next->setPosition(localPos + newPos);
	}
	m_position = newPos;
}



sf::Vector2f Widget::getPos()
{
	return m_position;
}

sf::Vector2f Widget::getSize()
{
	return m_size;
}

void Widget::visibility(bool isVisable)
{
	m_Isvisibale = isVisable;
}

void Widget::setFont(FontPtr font)
{
	for (auto next : m_widgetList)
	{
		next->setFont(font);
	}
	m_font = font;
}

void Widget::addClickFunc(clickFunc newFunc)
{
	m_clickFuncs.push_back(newFunc);
}

void Widget::mouseClick(sf::Event::MouseButtonEvent event)
{
	int x = event.x;
	int y = event.y;

	for (auto next : m_widgetList)
	{
		if (next->isInside(x, y))
			next->mouseClick(event);
	}
	for (auto next : m_clickFuncs)
		next();
}

void Widget::mouseRelase(sf::Event::MouseButtonEvent event)
{
	int x = event.x;
	int y = event.y;
	for (auto next : m_widgetList)
	{
		//if (next->icerdemi(x, y))
		{

			next->mouseRelase(event);
		}
	}
}

void Widget::setSize(const sf::Vector2f& size)
{

	m_size = size;
}
