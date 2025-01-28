
#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <iostream>


const sf::Color defaultColor = sf::Color(255,255,255);
const sf::Color defaultHover = sf::Color(191, 191, 191);
const sf::Color defaultPress = sf::Color(153, 153, 153);
const sf::Color disabled = sf::Color(60,60,60);

struct ColorSet
{
    public:

        sf::Color color;
        sf::Color hover;
        sf::Color press;
        
        ColorSet();
        ColorSet(sf::Color color);
        ColorSet(sf::Color color, sf::Color hover, sf::Color press);


    private:

        void init(sf::Color color, sf::Color hover, sf::Color press);


};




class Button
{
    public:

        virtual void getButtonStatus(sf::RenderWindow& window, sf::Event& event) = 0;
        virtual void draw(sf::RenderWindow& window) = 0;
        virtual void setButtonLabel(float charsize, std::string label) = 0;
        virtual void setButtonLabel(float charsize) = 0;
        virtual void setButtonFont(sf::Font& font);
        void setButtonColor(sf::Color color);
        void setButtonColor(sf::Color color, sf::Color hover, sf::Color press);
        void setLabelColor(sf::Color color);
        void setLabelColor(sf::Color color, sf::Color hover, sf::Color press);

        bool isHover = false;
        bool isPressed = false;
        bool isActive = true;
        bool isLabelVisible = true;
        static unsigned int count;

    //end of public

    protected:

        bool autoSize = false;
        sf::Text buttonLabel;
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;
        sf::Vector2f buttonPos;
        sf::FloatRect labelRect;
        std::string label;
        ColorSet buttonColorSet;
        ColorSet labelColorSet = ColorSet(sf::Color::Black) ;

    //end of protected
};

#endif // BUTTON_HPP_INCLUDED