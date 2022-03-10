#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Baha Jiyan Yılmaz

using namespace std;

class Movie{
private:
    int id;
    string name;
    float point;
    int year;

public:
    Movie(){}
    Movie(int id,string name,float point,int year)
    {
        this->id=id;
        this->name=name;
        this->point=point;
        this->year=year;
    }
    int getId() const {
        return id;
    }

    const string &getName() const {
        return name;
    }

    float getPoint() const {
        return point;
    }

    int getYear() const {
        return year;
    }

    void setPoint(float point) {
        Movie::point = point;
    }

    void PrintMovie()
    {
        cout <<"ID: "<<id<<" Name: "<<name<<" Point: "<< point<<" Year: "<<year<<endl;
    }
};

int main()
{
    ifstream read_file;
    read_file.open("../movies.txt"); // File opener

    if (!read_file.is_open())
    {
        cerr << "File could not opened successfully." << endl; // If file could not open this "if"  will print it
        exit(1);
    }
    cout << "File opened" << endl;

    string line;
    string mName;
    string mPoint;  // all this strings will keep the data.
    string mYear;

    Movie movie[250]; // array that will keep movie details
    int idNo = 0; //counter for id

    while (getline(read_file, line))
    {
        stringstream line_stream(line);

        getline(line_stream, mPoint, ';'); // After the every movie point there is ";"
        getline(line_stream, mName, '(');  // After the every movie name there is "("
        getline(line_stream, mYear, ')');  // After the every movie year there is ")"

        float poi = stof(mPoint);
        int yearOf = stoi(mYear);
        movie[idNo] = {idNo, mName, poi, yearOf};
        idNo = idNo + 1;
    }
    read_file.close(); // Close the file after read.

    int options = 0;

    cout << "Welcome to the Movie Market. Please select an option." << endl; //Menu
    cout << "1 - Get movie details by ID" << endl;
    cout << "2 - List movies between the years entered" << endl;
    cout << "3 - Change the point of a movie" << endl;
    cout << "4 - Get movie details starting with the entered letter" << endl;
    cout << "5 - Exit" << endl;

    cout << "Enter the option you want to make" << endl;
    cin >> options;

    if (options < 6 && options > 0) //Option must be between 0-5
    {
        switch (options)
        {
            case 1:
            {
                cout << "Please enter the movie id:" << endl;
                cin >> idNo;

                for (int i = 0; i < 250; ++i)
                {
                    if (movie[i].getId() == idNo) //If movie id's match,this will print the movie with that id.
                    {
                        movie[i].PrintMovie();
                    }
                }
                break;
            }

            case 2:
            {
                int firstYear;
                int secondYear;

                cout << "Please enter the first year" << endl;
                cin >> firstYear;
                cout << "Please enter the second year" << endl;
                cin >> secondYear;

                for (int i = 0; i < 250; i++) {
                    if (movie[i].getYear() >= firstYear && movie[i].getYear() <= secondYear)

                    {
                        movie[i].PrintMovie();
                    }
                }
                break;
            }


            case 3:
            {
                cout << "Please enter the id of the movie " << endl;
                cin >> idNo;
                float newPoint; //This float will be the new point of the movie
                cout << "Please enter the point that you want to change  " << endl;
                cin >> newPoint;

                for (int i = 0; i < 250; i++)
                {
                    if (movie[i].getId() == idNo)
                    {
                        movie[i].setPoint(newPoint); // setter for point
                        cout << "Point of the " << movie[i].getName() << "changed to " << newPoint << endl;
                    }
                }
                break;
            }


            case 4:
            {
                string firstLetter="";
                cout << "Please enter a letter:" << endl;
                cin >> firstLetter;

                for (int i = 0; i < 250; ++i) {
                    string letter = movie[i].getName();
                    string fLetter = " ";
                    fLetter[0] = letter[0];

                    if (firstLetter.compare(fLetter) == 0) // string comparison,if strings are equal it will go into if
                    {
                        cout << letter << endl;
                    }
                }
                break;
            }
            case 5:
            {
                return 0; //exit
            }
        }
    }
    else
        cout<<"This is not an option."<<endl; return 0; //options beside 0-5 will not work.
}


