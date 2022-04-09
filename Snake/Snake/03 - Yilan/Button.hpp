#pragma once
#include "Widget.hpp"
#include "Title.hpp"
class WidgetPanel;

class Button : public Widget
{
public:
	Button();
	void title(const sf::String& title);
private:

	sf::Sprite* m_state; // aktif durum
	sf::Sprite m_Normal;
	sf::Sprite m_mouseOn; // fare üzerinde
	sf::Sprite m_mouseClick; // farebasildi
	sf::Sprite m_lock; // kilitli

	titlePtr   m_title;

	virtual void mouseClick(sf::Event::MouseButtonEvent event) override;
	virtual void mouseRelase(sf::Event::MouseButtonEvent event) override;
	virtual void draw(Window& window) override;
	virtual void isMouseOn(bool isMouseOn) override;
	virtual void setSize(const sf::Vector2f& size)override;
	friend class WidgetPanel;

};

typedef std::shared_ptr<Button> ButtonPtr;