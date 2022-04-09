#include "Window.hpp"

Window::Window()
{
	
}
void Window::create(unsigned int w, unsigned int h, sf::String title)
{
	m_window.create(sf::VideoMode(w, h), title);
}

void Window::startDrawing()
{
	m_window.clear();
}

void Window::endDrawing()
{
	m_window.display();
}

bool Window::isOpen()
{
	return m_window.isOpen();
}

void Window::eventControl()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();

		if (event.type == sf::Event::MouseMoved)
		{
			for (auto siradaki : m_addMoveFuncList)
				siradaki(event.mouseMove.x, event.mouseMove.y);
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			for (auto siradaki : addMouseClickList)
				siradaki(event.mouseButton);
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
			for (auto siradaki : m_addMouseRelaseList)
				siradaki(event.mouseButton);
		}

		if (event.type == sf::Event::KeyPressed)
		{
			for (auto siradaki : m_addKeyPressList)
				siradaki(event.key.code);
		}
	}
}
void Window::draw(sf::Drawable& shape)
{
	m_window.draw(shape);
}

void Window::addMoveFunc(mouseMoveFunc newFunc)
{
	m_addMoveFuncList.push_back(newFunc);
}

void Window::addMouseClick(mouseClickFunc newFunc)
{
	addMouseClickList.push_back(newFunc);
}

void Window::addMouseRelase(mouseClickFunc newFunc)
{
	m_addMouseRelaseList.push_back(newFunc);
}

void Window::addKeyPress(KeyFunc newFunc)
{
	m_addKeyPressList.push_back(newFunc);
}

void Window::close()
{
	m_window.close();
}
