#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#define RED 0.2126
#define GREEN 0.7152
#define BLUE 0.0722

using namespace std;

int main()
{
	string inputPath;
	string outputPath;
	int scaleX;
	string ascii = "@#$=+:. ";

	cout << "Input: ";
	cin >> inputPath;

	for (int i = 0; i < inputPath.length(); ++i)
	{
		if (inputPath[i] == '.') break;
		outputPath += inputPath[i];
	}

	outputPath += ".txt";

	cout << "Scale: ";
	cin >> scaleX;

	sf::Image img;
	img.loadFromFile(inputPath);
	sf::Image grayImg(img);
	int c;

	for (int i = 0; i < img.getSize().x; ++i)
	{
		for (int j = 0; j < img.getSize().y; ++j)
		{
			c = img.getPixel(i, j).r * RED + img.getPixel(i, j).g * GREEN + img.getPixel(i, j).b * BLUE;
			grayImg.setPixel(i, j, sf::Color(c, c, c));
		}
	}
	grayImg.saveToFile("grayImg.png");

	return 0;
}