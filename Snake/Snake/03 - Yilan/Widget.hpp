#pragma once
#include<SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "BasicTypes.hpp"
class Window;
class Widget
{
public:

	typedef std::shared_ptr<Widget> widgetPtr;
	typedef std::vector<widgetPtr> widgetList;

	virtual void mouseMove(int x, int y);
	virtual bool isInside(int x, int y); // içinde mi
	virtual void setSize(const sf::Vector2f& size);
	virtual void setPosition(const sf::Vector2f& pos);
	virtual void addClickFunc(clickFunc newFunc);
	virtual void mouseClick(sf::Event::MouseButtonEvent event) ;
	virtual void mouseRelase(sf::Event::MouseButtonEvent event) ;
	virtual void isMouseOn(bool isMouseOn) = 0;
	virtual void draw(Window& window) = 0;

	sf::Vector2f	getPos();
	sf::Vector2f	getSize();
	void			visibility(bool isVisable);
	void			setFont(FontPtr font);
	
protected:

	bool			m_Isvisibale;
	sf::Vector2f	m_position;
	FontPtr			m_font;
	sf::Vector2f	m_size;
	widgetList		m_widgetList;
	clickFuncList m_clickFuncs; // týkla fonksiyonlarý
	
};
