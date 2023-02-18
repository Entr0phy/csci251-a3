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

// global variables
bool inputfile = false;
std::string filter = "Point2D";
std::string sortCriteria = "x-ordinate";
std::string sortOrder = "ASC";

// method to de allocate memory
void clear()
{
    point2d.clear();
    point3d.clear();
    line2d.clear();
    line3d.clear();
}
// method to tokenize a string by taking in a delimiter and input
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
        std::cout << counter << " records read in successfully!" << std::endl
                  << std::endl;

        std::cout << "Going back to main menu" << std::endl;
    }
}

// method to toggle the filtering criteria
void specifyFilteringCriteria()
{
    char option;
    std::cout << " " << std::endl
              << std::endl;
    std::cout << "[ Specifying filtering criteria (current: " << filter << ")]" << std::endl
              << std::endl;

    std::cout << "a)\t Point2D records" << std::endl;
    std::cout << "b)\t Point3D records" << std::endl;
    std::cout << "c)\t Line2D records" << std::endl;
    std::cout << "d)\t Line3D records" << std::endl
              << std::endl;
    std::cout << "Please enter your criteria (a-d): ";

    std::cin >> option;

    switch (option)
    {
    case 'a':
        filter = "Point2D";
        break;

    case 'b':
        filter = "Point3D";
        break;

    case 'c':
        filter = "Line2D";
        sortCriteria = "Pt1"; // default sort criteria for line
        break;

    case 'd':
        filter = "Line3D";
        sortCriteria = "Pt1"; // default sort criteria for line
        break;

    default:
        std::cout << "Invalid choice entered, please enter valid option" << std::endl;
        std::cin.clear();
        specifyFilteringCriteria();
        break;
    }

    std::cout << "Filter criteria successfully set to " << filter << "!" << std::endl
              << std::endl;
}

// method to filter based off sorting criteria
void specifySortingCriteria()
{
    char option;
    std::cout << " " << std::endl
              << std::endl;
    std::cout << "[ Specifying sorting criteria (current: " << sortCriteria << std::endl
              << std::endl;

    // filter options for point 2d
    if (filter == "Point2D")
    {
        std::cout << "a)\t X ordinate value" << std::endl;
        std::cout << "b)\t Y ordinate value" << std::endl;
        std::cout << "c)\t Dist. Fr Origin value" << std::endl;
        std::cout << "Please enter your criteria (a-c): ";
        std::cin >> option;

        switch (option)
        {
        case 'a':
            sortCriteria = "x-ordinate";
            break;

        case 'b':
            sortCriteria = "y-ordinate";
            break;

        case 'c':
            sortCriteria = "dist fr origin";
            break;

        default:
            std::cout << "Invalid option please enter again" << std::endl;
            std::cin.clear();
            specifySortingCriteria();
            break;
        }
    }

    // filter options for point 3d
    else if (filter == "Point3D")
    {
        std::cout << "a)\t X ordinate value" << std::endl;
        std::cout << "b)\t Y ordinate value" << std::endl;
        std::cout << "c)\t Z ordinate value" << std::endl;
        std::cout << "d)\t Dist. Fr Origin value" << std::endl;
        std::cout << "Please enter your criteria (a-d): ";
        std::cin >> option;

        switch (option)
        {
        case 'a':
            sortCriteria = "x-ordinate";
            break;

        case 'b':
            sortCriteria = "y-ordinate";
            break;

        case 'c':
            sortCriteria = "z-ordinate";
            break;

        case 'd':
            sortCriteria = "dist fr origin";
            break;

        default:
            std::cout << "Invalid option please enter again" << std::endl;
            std::cin.clear();
            specifySortingCriteria();
            break;
        }
    }

    // filter options for line2d and line3d
    else
    {
        std::cout << "a)\t X and Y coordinate values of Pt1" << std::endl;
        std::cout << "b)\t X and Y coordinate values of Pt2" << std::endl;
        std::cout << "c)\t Length value" << std::endl;
        std::cout << "Please enter your criteria (a-c): ";
        std::cin >> option;

        switch (option)
        {
        case 'a':
            sortCriteria = "pt1";
            break;

        case 'b':
            sortCriteria = "pt2";
            break;

        case 'c':
            sortCriteria = "length";
            break;

        default:
            std::cout << "Invalid option please enter again" << std::endl;
            std::cin.clear();
            specifySortingCriteria();
            break;
        }
    }

    std::cout << "Filter criteria successfully set to " << sortCriteria << std::endl;
}

// method to specify sorting order
void specifySortingOrder()
{
    char option;

    std::cout << " " << std::endl
              << std::endl;

    std::cout << "[Specifying sorting order (current: " << sortOrder << ")]" << std::endl
              << std::endl;

    std::cout << "a)\t ASC (Ascending order)" << std::endl;
    std::cout << "b)\t DSC (Descending order)" << std::endl
              << std::endl;

    std::cout << "Please enter your criteria(a-b):";
    std::cin >> option;

    switch (option)
    {
    case 'a':
        sortOrder = "ASC";
        break;

    case 'b':
        sortOrder = "DSC";
        break;

    default:
        std::cout << "Invalid option entered, please enter valid option";
        std::cin.clear();
        specifySortingOrder();
        break;
    }
    std::cout << "Sorting order successfully set to " << sortOrder << std::endl;
}

// method to view the data
void viewData()
{
    std::cout << "" << std::endl
              << std::endl;

    std::cout << "Filtering criteria: " << filter << std::endl;
    std::cout << "Sorting criteria: " << sortCriteria << std::endl;
    std::cout << "Sorting order: " << sortOrder << std::endl;

    if (filter == "Point2D")
    {
        // setting the sort criteria
        for (int i = 0; i < point2d.size(); i++)
            point2d[i].setSortCrit(sortCriteria);

        // setting the sort order
        if (sortOrder == "ASC")
            std::sort(point2d.begin(), point2d.end(), ASC<Point2D>);

        else
            std::sort(point2d.begin(), point2d.end(), DSC<Point2D>);

        // printing the header
        std::cout << std::setw(5) << "X" << std::setw(5) << "Y"
                  << "    Dist. Fr Origin" << std::endl;
        std::cout << "- - - - - - - - - - - - - - - - - - - " << std::endl;

        // printing the value based off ostream
        for (int i = 0; i < point2d.size(); i++)
            std::cout << point2d[i];
        std::cout << std::endl;
    }

    else if (filter == "Point3D")
    {
        // setting the sort criteria
        for (int i = 0; i < point3d.size(); i++)
            point3d[i].setSortCrit(sortCriteria);

        // setting the sort order
        if (sortOrder == "ASC")
            std::sort(point3d.begin(), point3d.end(), ASC<Point3D>);

        else
            std::sort(point3d.begin(), point3d.end(), DSC<Point3D>);

        // printing the header
        std::cout << std::setw(5) << "X" << std::setw(5) << "Y" << std::setw(5) << "Z"
                  << "    Dist. Fr Origin" << std::endl;
        std::cout << "- - - - - - - - - - - - - - - - - - - " << std::endl;

        // printing the value based off ostream
        for (int i = 0; i < point3d.size(); i++)
            std::cout << point3d[i];
        std::cout << std::endl;
    }

    else if (filter == "Line2D")
    {
        // setting the sorting criteria
        for (int i = 0; i < line2d.size(); i++)
        {
            line2d[i].setSortCrit(sortCriteria);
        }

        // setting the sort order
        if (sortOrder == "ASC")
            std::sort(line2d.begin(), line2d.end(), ASC<Line2D>);

        else
            std::sort(line2d.begin(), line2d.end(), DSC<Line2D>);

        // printing the header
        std::cout << std::setw(5) << "P1-X" << std::setw(5) << "P1-Y" << std::setw(9) << "P2-X"
                  << std::setw(5) << "P2-Y"
                  << "   Length" << std::endl;
        std::cout << "- - - - - - - - - - - - - - - - - - - " << std::endl;

        for (int i = 0; i < line2d.size(); i++)
        {
            std::cout << line2d[i];
        }
        std::cout << std::endl;
    }

    else
    {
        // setting the sorting criteria
        for (int i = 0; i < line3d.size(); i++)
        {
            line3d[i].setSortCrit(sortCriteria);
        }

        // setting the sort order
        if (sortOrder == "ASC")
            std::sort(line3d.begin(), line3d.end(), ASC<Line3D>);

        else
            std::sort(line3d.begin(), line3d.end(), DSC<Line3D>);

        // printing the header
        std::cout << std::setw(5) << "P1-X" << std::setw(5) << "P1-Y" << std::setw(5) << "P1-Z" << std::setw(9) << "P2-X"
                  << std::setw(5) << "P2-Y" << std::setw(5) << "P2-Z"
                  << "   Length" << std::endl;
        std::cout << "- - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;

        for (int i = 0; i < line3d.size(); i++)
        {
            std::cout << line3d[i];
        }
        std::cout << std::endl;
    }
}

// method to save the file
void saveData()
{
    int counter = 0; // counter to store the number of variables stored in new file
    std::string name;

    std::cout << "Please enter filename: ";
    std::cin >> name;
    std::ofstream myFile(name.c_str());

    if (!myFile)
        std::cout << "Error creating" << name << ". Please try again" << std::endl;

    else if (filter == "Point2D")
    {
        // setting the sort criteria
        for (int i = 0; i < point2d.size(); i++)
            point2d[i].setSortCrit(sortCriteria);

        // setting the sort order
        if (sortOrder == "ASC")
            std::sort(point2d.begin(), point2d.end(), ASC<Point2D>);

        else
            std::sort(point2d.begin(), point2d.end(), DSC<Point2D>);

        // printing the header
        myFile << std::setw(5) << "X" << std::setw(5) << "Y"
               << "    Dist. Fr Origin" << std::endl;
        myFile << "- - - - - - - - - - - - - - - - - - - " << std::endl;

        // printing the value based off ostream
        for (int i = 0; i < point2d.size(); i++)
        {
            myFile << point2d[i];
            counter++;
        }
        std::cout << std::endl;
    }

    else if (filter == "Point3D")
    {
        // setting the sort criteria
        for (int i = 0; i < point3d.size(); i++)
            point3d[i].setSortCrit(sortCriteria);

        // setting the sort order
        if (sortOrder == "ASC")
            std::sort(point3d.begin(), point3d.end(), ASC<Point3D>);

        else
            std::sort(point3d.begin(), point3d.end(), DSC<Point3D>);

        // printing the header
        myFile << std::setw(5) << "X" << std::setw(5) << "Y" << std::setw(5) << "Z"
               << "    Dist. Fr Origin" << std::endl;
        myFile << "- - - - - - - - - - - - - - - - - - - " << std::endl;

        // printing the value based off ostream
        for (int i = 0; i < point3d.size(); i++)
        {
            myFile << point3d[i];
            counter++;
        }
        std::cout << std::endl;
    }

    else if (filter == "Line2D")
    {
        // setting the sorting criteria
        for (int i = 0; i < line2d.size(); i++)
        {
            line2d[i].setSortCrit(sortCriteria);
        }

        // setting the sort order
        if (sortOrder == "ASC")
            std::sort(line2d.begin(), line2d.end(), ASC<Line2D>);

        else
            std::sort(line2d.begin(), line2d.end(), DSC<Line2D>);

        // printing the header
        myFile << std::setw(5) << "P1-X" << std::setw(5) << "P1-Y" << std::setw(9) << "P2-X"
               << std::setw(5) << "P2-Y"
               << "   Length" << std::endl;
        myFile << "- - - - - - - - - - - - - - - - - - - " << std::endl;

        for (int i = 0; i < line2d.size(); i++)
        {
            myFile << line2d[i];
            counter++;
        }
        std::cout << std::endl;
    }

    else
    {
        // setting the sorting criteria
        for (int i = 0; i < line3d.size(); i++)
        {
            line3d[i].setSortCrit(sortCriteria);
        }

        // setting the sort order
        if (sortOrder == "ASC")
            std::sort(line3d.begin(), line3d.end(), ASC<Line3D>);

        else
            std::sort(line3d.begin(), line3d.end(), DSC<Line3D>);

        // printing the header
        myFile << std::setw(5) << "P1-X" << std::setw(5) << "P1-Y" << std::setw(5) << "P1-Z" << std::setw(9) << "P2-X"
               << std::setw(5) << "P2-Y" << std::setw(5) << "P2-Z"
               << "   Length" << std::endl;
        myFile << "- - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;

        for (int i = 0; i < line3d.size(); i++)
        {
            myFile << line3d[i];
            counter++;
        }
        std::cout << std::endl;
    }
    myFile.close();
    std::cout << counter << " records output successfully!" << std::endl
              << std::endl;
    std::cout << "Going back to main menu..." << std::endl;
}

// method to display the main menu
void printMenu()
{
    std::cout << "Student ID\t :7432707" << std::endl;
    std::cout << "Student Name\t: Lim Pei Ming" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Welcome to Assn3 program!" << std::endl
              << std::endl;

    std::cout << "1)\t Read in data" << std::endl;
    std::cout << "2)\t Specify filtering criteria (current: " << filter << ")" << std::endl;
    std::cout << "3)\t Specify sorting criteria (current: " << sortCriteria << ")" << std::endl;
    std::cout << "4)\t Specify sorting order (current: " << sortOrder << std::endl;
    std::cout << "5)\t View data" << std::endl;
    std::cout << "6)\t Store data" << std::endl;
    std::cout << "7)\t Exit" << std::endl;
}
int main()
{
    int exit = 0;
    int selection = 0;

    while (exit == 0)
    {
        printMenu();
        std::cout << "Please enter your selection";
        std::cin >> selection;
        // if user select exits
        if (selection == 7)
        {
            std::cout << "Application will be closing" << std::endl;
            clear();
            exit = 1;
        }

        // if user enters valid selection
        else if (selection > 0 && selection < 7)
        {
            switch (selection)
            {
            case 1:
                readFile();
                break;

            case 2:
                specifyFilteringCriteria();
                break;

            case 3:
                specifySortingCriteria();
                break;

            case 4:
                specifySortingOrder();
                break;

            case 5:
                viewData();
                break;

            case 6:
                saveData();
                break;

            default:
                break;
            }
        }

        // if user enters invalid selection
        else
        {
            std::cout << "Please enter valid input" << std::endl;
            std::cin.clear();
            std::string discard;
            getline(std::cin, discard);
        }
    }
    return 0;
}