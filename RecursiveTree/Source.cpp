#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <cstdlib>
#include <cmath>
#include <iostream>

//in the standard namespace
using namespace std;

//variables
const int width{ 1920 }; //1080=dalton, 1080=cal, 720=caleb
const int height{ 1080 }; //2340=dalton, 2400=cal, 1600=caleb

int max_levels = 7;
double angle = 0;
int starting_length = 400;
double offset = 0.1;



class Branch
{
public:
	sf::Vector2f pointA;
	sf::Vector2f pointB;
	int length;
	double angle;

	Branch(sf::Vector2f pointA, int length, double angle)
	{
		this->pointA = pointA;
		this->length = length;
		this->angle = angle;
		//set pointB
		pointB.x = pointA.x + length * cos(angle - 1.57);
		pointB.y = pointA.y + length * sin(angle - 1.57);
	}

	void draw(sf::RenderWindow &window)
	{
		//draw a line from pointA to pointB
		sf::Vertex line[] = { sf::Vertex(pointA),sf::Vertex(pointB) };
		window.draw(line, 2, sf::Lines);
	}
};

vector<Branch> tree;

int main()
{
	//set up window
	sf::RenderWindow window(sf::VideoMode(width, height), "tree", sf::Style::Fullscreen);
	sf::Event event;

	
	

	
	//look for events while the window is open
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
				//if space is pressed, angle++
				if (event.key.code == sf::Keyboard::Space)
				{
					
					
					
					
				}
				
				if (event.key.code == sf::Keyboard::Up)
				{
					offset -= .01;
					
				}
				
				if (event.key.code == sf::Keyboard::Down)
				{
					offset += .01;
				}

				if (event.key.code == sf::Keyboard::Right)
				{
					max_levels++;
					max_levels++;
					
				}
				
				if (event.key.code == sf::Keyboard::Left)
				{
					max_levels--;
					max_levels--;
				}
			}
		}
		//clear the window
		window.clear();
		offset -= .01;
		tree.clear();
		//add the first branch
		tree.push_back(Branch(sf::Vector2f(width / 2, height), starting_length, 0));
		//add the rest of the branches
		for (int i = 0; i < max_levels; i++)
		{
			for (int j = 0; j < pow(2, i); j++)
			{
				tree.push_back(Branch(tree[j].pointB, tree[j].length / 1.5, tree[j].angle + offset));
				tree.push_back(Branch(tree[j].pointB, tree[j].length / 1.5, tree[j].angle - offset));
			}
		}
		
		
		for (int i = 0; i < tree.size(); i++)
		{
			tree[i].draw(window);
		}







		
		//draw the window
		window.display();
	}

	
	

	//return okay if the program exits properly
    return 0;
}