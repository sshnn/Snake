#include "WidgetPanel.hpp"
#include "Window.hpp"
#include<iostream>
WidgetPanel::WidgetPanel()
{
	m_position = sf::Vector2f(0, 0);
	m_size = sf::Vector2f(40, 40);
}



void WidgetPanel::widgetImg(TexturePtr img)
{
	m_widgetImg = img;
}

void WidgetPanel::setBackground(TexturePtr img, sf::IntRect rect)
{
	m_background.setTexture(*img);
	m_background.setTextureRect(rect);
	m_background.scale(sf::Vector2f(0.5, 0.5));
	m_size.x = m_background.getGlobalBounds().width;
	m_size.y = m_background.getGlobalBounds().height;
}

ButtonPtr WidgetPanel::addButton(sf::String title, float w , float h )
{
	ButtonPtr newButton = std::make_shared<Button>();
	newButton->setFont(m_font);
	newButton->title(title);
	newButton->m_Normal.setTexture(*m_widgetImg);
	newButton->m_mouseOn.setTexture(*m_widgetImg);
	newButton->m_mouseClick.setTexture(*m_widgetImg);
	newButton->m_lock.setTexture(*m_widgetImg);

	newButton->m_Normal.setTextureRect(sf::IntRect(sf::Vector2i(177, 201), sf::Vector2i(362, 177)));
	newButton->m_mouseOn.setTextureRect(sf::IntRect(sf::Vector2i(561, 201), sf::Vector2i(362, 177)));
	newButton->m_mouseClick.setTextureRect(sf::IntRect(sf::Vector2i(945, 201), sf::Vector2i(362, 177)));
	newButton->m_lock.setTextureRect(sf::IntRect(sf::Vector2i(1332, 201), sf::Vector2i(362, 177)));
	

	newButton->setSize(sf::Vector2f(w, h));
	
	float buttonX = (m_size.x - w) / 2;
	m_widgetList.push_back(newButton);
	int widget_count = m_widgetList.size();
	float localY = (m_size.y - h * widget_count -20 * (widget_count - 1)) / 2;
	
	for (int i = 0; i < widget_count; i++)
	{
		float buttonY = localY + h * i  + 20 * i;
		m_widgetList[i]->setPosition(sf::Vector2f(buttonX, buttonY));
	}

	return newButton;
}




void WidgetPanel::isMouseOn(bool isMouseOn)
{

}


void WidgetPanel::draw(Window& window)
{
	if (!m_Isvisibale)
		return;
	m_background.setPosition(m_position );
	window.draw(m_background);

	for (auto next : m_widgetList)		
		next->draw(window);
}
