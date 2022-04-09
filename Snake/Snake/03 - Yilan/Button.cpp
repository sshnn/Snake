#include "Button.hpp"
#include "Window.hpp"
#include <iostream>
Button::Button()
{
    m_state = &m_Normal;
    m_position = sf::Vector2f(0, 0);
    m_title = std::make_shared<Title>();
    m_title->setTitleSize(20);
    m_widgetList.push_back(m_title);
    
}

void Button::title(const sf::String& newtitle)
{
    m_title->setFont(m_font);
    m_title->setTitle(newtitle);

}

void Button::mouseClick(sf::Event::MouseButtonEvent event)
{
    m_state = &m_mouseClick;
    Widget::mouseClick(event);
}

void Button::mouseRelase(sf::Event::MouseButtonEvent event)
{
    if (this->isInside(event.x, event.y))
        m_state = &m_mouseOn;
    else
        m_state = &m_Normal;
}

void Button::draw(Window& window)
{
    m_state->setPosition(m_position);
    window.draw(*m_state);
    for (auto next : m_widgetList)
        next->draw(window);
}

void Button::isMouseOn(bool isMouseOn)
{
    if (m_state == (&m_mouseClick))
        return;

    if (isMouseOn)
    {
        m_state = &m_mouseOn;
    }
    else
        m_state = &m_Normal;
}

void Button::setSize(const sf::Vector2f& size)
{
    m_size = size;
    float texHeight = m_mouseOn.getTextureRect().height;
    float texWidth = m_mouseOn.getTextureRect().width;

    float sizeX = size.x / texWidth;
    float sizeY = size.y / texHeight;

    m_mouseClick.scale(sf::Vector2f(sizeX, sizeY));
    m_mouseOn.scale(sf::Vector2f(sizeX, sizeY));
    m_Normal.scale(sf::Vector2f(sizeX, sizeY));

    auto titleSize = m_title->getPos();
    float x = (m_size.x - titleSize.x) / 2;
    float y = (m_size.y - titleSize.y) / 2;
    m_title->setPosition(sf::Vector2f(x, y));
}
