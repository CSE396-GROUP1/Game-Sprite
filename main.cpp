#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <unistd.h>

using namespace std;

int main(int argc, char ** argv){

    enum Direction { Up, Left, Down, Right};

    sf::Vector2i source(1, Down);
    sf::Clock frameClock;

    sf::Music music;
    if(!music.openFromFile("11.flac")){
            cout<<"error"<<endl;
        }

    music.play();
    music.setLoop(true);

    sf::RenderWindow Window;
    Window.create(sf::VideoMode(800,600),"load image example");
    Window.setKeyRepeatEnabled(false);

    sf::Texture pTexture;
    sf::Sprite playerImage;
    if(!pTexture.loadFromFile("1.png")){
        cout<<"error file"<<endl;
    }
    playerImage.setTexture(pTexture);

    while(Window.isOpen()){

        Window.clear();

        source.x++;
        if(source.x * 64 >= pTexture.getSize().x){
            source.x =0;
        }


        playerImage.setTextureRect(sf::IntRect(source.x*64, source.y*64,64,64));
        Window.draw(playerImage);
        Window.display();


        sf::Event event;
        sf::Time elapsedTime;
        while(Window.pollEvent(event)){

            if ((event.type == sf::Event::Closed))
                    Window.close();
            }
            if( event.type == event.KeyPressed){
                if(event.key.code == sf::Keyboard::Up){
                    source.y= Up;
                    //playerImage.move(0, playerVelocity*elapsedTime.asSeconds());
                }
                else if(event.key.code == sf::Keyboard::Down){
                    source.y= Down;

                }
                else if(event.key.code == sf::Keyboard::Right){
                    source.y= Right;
                    playerImage.move(10, 0);
                }
                else if(event.key.code == sf::Keyboard::Left){
                    source.y= Left;
                    playerImage.move(-10, 0);
                }
            }
        }
}
