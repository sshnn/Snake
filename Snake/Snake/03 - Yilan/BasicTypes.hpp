#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include<functional>
typedef std::shared_ptr<sf::Texture> TexturePtr;
typedef std::map<sf::String, TexturePtr> textureMap; // KaplamaHaritasi
typedef std::shared_ptr<sf::Font>	FontPtr;

typedef std::function<void(int, int)> mouseMoveFunc;
typedef std::function<void(sf::Event::MouseButtonEvent)> mouseClickFunc;
typedef std::function<void()> clickFunc;
typedef std::function<void(sf::Keyboard::Key)> KeyFunc;

typedef std::vector<mouseMoveFunc> mouseMoveFuncList;
typedef std::vector<mouseClickFunc> mouseClickFuncList;
typedef std::vector<clickFunc>	clickFuncList;
typedef std::vector<KeyFunc>	KeyFuncList;
enum class DIRECTION
{
	DIRECTION_LEFT,
	DIRECTION_RIGHT,
	DIRECTION_UP,
	DIRECTION_DOWN
};

