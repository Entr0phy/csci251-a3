#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>

#include "Point2D.h"
#include "Line2D.h"
#include "Point3D.h"
#include "Line3D.h"
#include "MyTemplates.h"

// declaring vector of inputs
std::vector<Point2D> point2d;
std::vector<Point3D> point3d;
std::vector<Line2D> line2d;
std::vector<Line3D> line3d;

bool inputfile = false;

std::vector<std::string> stringTokenize(std::string input, std::string delimiter)
{
    size_t pos = 0;
    std::string token;
    std::vector<std::string> result;

    while ((pos = input.find(delimiter)) != std::string::npos)
    {
        token = input.substr(0, pos);
        result.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    result.push_back(input);
    return result;
}
// method to read in file name and store the data of the file
void readFile()
{
    std::cout << "Please enter filename:";
    std::string filename;
    std::cin >> filename;

    std::ifstream myFile;
    bool checker;
    myFile.open(filename);
    if (!myFile) // error opening file
    {
        std::cout << "Error opening: " << filename << ". Try again" << std::endl
                  << std::endl;
        readFile();
    }
    if (myFile.is_open()) // file able to open
    {
        std::string line;
        while (getline(myFile, line))
        {
            if (line.empty())
                break;
            checker = true;

            // point 2d
            if (line.find("Point2D") != std::string::npos)
            {
                std::vector<std::string> firstToken = stringTokenize(line, ", [");
                std::vector<std::string> secondToken = stringTokenize(firstToken[1], ", ");
                int x = std::stoi(secondToken[0]);
                secondToken[1].pop_back();
                int y = std::stoi(secondToken[1]);
                Point2D temp = Point2D(x, y); // create new temporary points

                // checking for duplicates
                for (int i = 0; i < point2d.size(); i++)
                {
                    if (equals(temp, point2d[i]))
                    {
                        checker = false;
                        break;
                    }
                }

                if (checker == true)
                {
                    point2d.push_back(temp);
                }

                // clear vectors
                firstToken.clear();
                secondToken.clear();
            }

            else if (line.find("Point3D") != std::string::npos)
            {
                std::vector<std::string> firstToken = stringTokenize(line, ", [");
                std::vector<std::string> secondToken = stringTokenize(firstToken[1], ", ");
                secondToken[2].pop_back();
                int x = std::stoi(secondToken[0]);
                int y = std::stoi(secondToken[1]);
                int z = std::stoi(secondToken[2]);
                Point3D temp = Point3D(x, y, z); // create new temporary points

                // checking for duplicates
                for (int i = 0; i < point3d.size(); i++)
                {
                    if (equals(temp, point3d[i]))
                    {
                        checker = false;
                        break;
                    }
                }

                if (checker == true)
                {
                    point3d.push_back(temp);
                }

                // clear vectors
                firstToken.clear();
                secondToken.clear();
            }

            else if (line.find("Line2D") != std::string::npos)
            {
                std::vector<std::string> firstToken = stringTokenize(line, ", [");
                std::vector<std::string> secondToken = stringTokenize(firstToken[1], ", ");
                std::vector<std::string> thirdToken = stringTokenize(firstToken[2], ", ");
                secondToken[1].pop_back();
                thirdToken[1].pop_back();
                int x1 = std::stoi(secondToken[0]);
                int y1 = std::stoi(secondToken[1]);
                int x2 = std::stoi(thirdToken[0]);
                int y2 = std::stoi(thirdToken[1]);

                Point2D temp1 = Point2D(x1, y1); // create new temporary points
                Point2D temp2 = Point2D(x2, y2);
                Line2D temp = Line2D(temp1, temp2);
                // checking for duplicates
                for (int i = 0; i < line2d.size(); i++)
                {
                    if (equals(temp, line2d[i]))
                    {
                        checker = false;
                        break;
                    }
                }

                if (checker == true)
                {
                    line2d.push_back(temp);
                }

                // clear vectors
                firstToken.clear();
                secondToken.clear();
                thirdToken.clear();
            }

            else if (line.find("Line3D") != std::string::npos)
            {
                std::vector<std::string> firstToken = stringTokenize(line, ", [");
                std::vector<std::string> secondToken = stringTokenize(firstToken[1], ", ");
                std::vector<std::string> thirdToken = stringTokenize(firstToken[2], ", ");
                secondToken[2].pop_back();
                thirdToken[2].pop_back();
                int x1 = std::stoi(secondToken[0]);
                int y1 = std::stoi(secondToken[1]);
                int z1 = std::stoi(secondToken[2]);
                int x2 = std::stoi(thirdToken[0]);
                int y2 = std::stoi(thirdToken[1]);
                int z2 = std::stoi(thirdToken[2]);

                Point3D temp1 = Point3D(x1, y1, z1); // create new temporary points
                Point3D temp2 = Point3D(x2, y2, z2);
                Line3D temp = Line3D(temp1, temp2);
                // checking for duplicates
                for (int i = 0; i < line3d.size(); i++)
                {
                    if (equals(temp, line3d[i]))
                    {
                        checker = false;
                        break;
                    }
                }

                if (checker == true)
                {
                    line3d.push_back(temp);
                }

                // clear vectors
                firstToken.clear();
                secondToken.clear();
                thirdToken.clear();
            }
        }
        int counter = point2d.size() + point3d.size() + line2d.size() + line3d.size();
        counter > 0 ? inputfile = true : inputfile = false;
        std::cout << counter;
    }
}
int main()
{
    /*Point2D test1 = Point2D(-99, -99);
    Point2D test2 = Point2D(-99, -99);
    Line2D test = Line2D(test1, test2);
    Line2D test4 = Line2D(test1, test2);
    std::cout << test.getScalarValue() << std::endl;
    std::cout << equals(test, test4);
    std::cout << point3d.size();*/
    readFile();
    return 0;
}