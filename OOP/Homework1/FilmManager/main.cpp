#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>
#include <math.h>

using namespace std;

bool isLogged = false;
bool isSignedUp = false;
bool isLoggedAsAdmin = false;
int availableLoginTries = 3;
int numberOfLoginTries = 0;
int overallCounter = 0;

int intPow(int base, int power)
{
    int newNumber = 1;
    for (int i = 0; i < power; i++)
    {
        newNumber *= base;
    }

    return newNumber;
}

string encryptPassword(string plainPassword, string username)
{
    string encryptedPassword = "";

    for (int i = 0; i < (int)plainPassword.length(); i++)
    {
        encryptedPassword += (int)plainPassword[i] + 5;
    }

    return encryptedPassword;
}

class MovieStaff
{
    public:
        string id;
        string name;
        string birthDate;
        string participatedMovieAsString;
        string role;//Actor, Director, Producer

        MovieStaff ()
        {
        }

        MovieStaff (string id, string name, string birthDate, string participatedMovieAsString, string role)
        {
            this->id = id;
            this->name = name;
            this->birthDate = birthDate;
            this->participatedMovieAsString = participatedMovieAsString;
            this->role = role;
        }
};

class Producer : public MovieStaff
{
    public:
        Producer ()
        {
        }

        Producer (string id, string name, string birthDate, string participated)
            : MovieStaff(id, name, birthDate, participated, "Producer")
        {
        }
};

class Director : public MovieStaff
{
    public:
        Director ()
        {
        }

        Director (string id, string name, string birthDate, string participated)
            : MovieStaff(id, name, birthDate, participated, "Director")
        {
        }
};

class Actor : public MovieStaff
{
    public:
        Actor ()
        {
        }

        Actor (string id, string name, string birthDate, string participated)
            : MovieStaff(id, name, birthDate, participated, "Actor")
        {
        }
};

class Movie
{
    public:
        Movie ()
        {
        }

        Movie (string id, string movieName, Director director,
               string year, string rating, string votersCount, string isRemake, Actor *movieActors, string genre, int actorsCount)
        {
            this->id = id;
            this->movieName = movieName;
            this->director = director;
            this->year = year;
            this->rating = rating;
            this->isRemake = isRemake;
            this->actors = movieActors;
            this->genre = genre;
            this->actorsCount = actorsCount;
        }

        string id;
        string movieName;
        Director director;
        string year;
        string rating;
        string votersCount;
        string isRemake;
        Actor *actors;
        string genre;
        int actorsCount;
};


//Singleton Design pattern
class Administrator
{
    static Administrator *s_instance;

    public:
        static Administrator *instance()
        {
            if (!s_instance)
            {
                s_instance = new Administrator;
            }

            return s_instance;
        }

        void addMovie(Movie movieToAdd)
        {
            //TO DO
        }
};

Administrator *Administrator::s_instance;

Movie movies[100];
MovieStaff staff[1000];
int usersCount = 0;
int moviesCount = 0;
int staffCount = 0;

class User
{
    public:
        string username;
        string password;
        bool isAdmin;

        User ()
        {
        }

        User (string username, string password)
        {
            this->username = username;
            this->password = password;
        }

        void signUp (User *allUsers, int usersCount)
        {
            for (int i = 0; i < usersCount; i++)
            {
                if (this->username == allUsers[i].username)
                {
                    cout<<"User with username: "<<this->username<<" already exists"<<endl;
                    return;
                }
            }

            string encryptedPassword = encryptPassword(this->password, this->username);

            std::ofstream ofs;
            ofs.open("Users.txt", std::ofstream::out | std::ofstream::app);

            ofs<<this->username<<"|"<<encryptedPassword<<endl;

            ofs.close();
            cout<<"You have successfully registered!"<<endl;
            isSignedUp = true;
            numberOfLoginTries = 0;
        }

        void login (User *allUsers, int usersCount)
        {
            string encryptedPassword = encryptPassword(this->password, this->username);

            for (int i = 0; i < usersCount; i++)
            {
                if (this->username == allUsers[i].username && encryptedPassword == allUsers[i].password)
                {
                    cout<<"Successfully logged in!"<<endl;
                    isLogged = true;
                    if(allUsers[i].isAdmin)
                    {
                        isLoggedAsAdmin = true;
                        cout<<"You are an Admin!"<<endl;
                    }

                    return;
                }
            }

            if (!isLogged)
            {
                cout<<"Could not log in! Wrong username/password!"<<endl;
                numberOfLoginTries++;
                if (numberOfLoginTries >= 3)
                {
                    exit(0);
                }

                cout<<"You have "<<availableLoginTries - numberOfLoginTries<<" more login tries!"<<endl;
            }
        }

        void giveRating(Movie selectedMovie, double rating)
        {
            //TO DO
        }

        void giveReview(Movie selectedMovie, string reviewText)
        {
            //TO DO
        }

        Movie* getMoviesByRating(string rating)//Must be optional
        {
            Movie newMovies[1000];
            overallCounter = 0;

            for (int i = 0; i < moviesCount; i++)
            {
                if (movies[i].rating == rating)
                {
                    newMovies[overallCounter] = movies[i];
                    overallCounter++;
                }
            }

            if (overallCounter != 0)
            {
                return newMovies;
            }

            throw exception();
        }

        Movie getMovieBy(double rating, Actor actor, int year, Director director, string genre)//Must be optional
        {
            //TO DO
            Movie newMovie;

            return newMovie;
        }

        Movie* sortMoviesByRating(string rating)
        {
            //TO DO
            Movie *newMovies;



            return newMovies;
        }

        Movie sortMoviesByRatingAfterYear(int startYear)
        {
            //TO DO
            Movie newMovie;

            return newMovie;
        }

        Movie* getMoviesByActorAndDirector(Actor movieActor, Director movieDirector)
        {
            //TO DO
            Movie *newMovies;

            return newMovies;
        }

        Movie* getAllRemakes(Movie movie)
        {
            //TO DO
            Movie *newRemakes;

            return newRemakes;
        }

        Director getDirector(Movie movie)
        {
            //TO DO
            Director director;

            return director;
        }

        Actor* getActors(Movie movie)
        {
            //TO DO
            Actor *actors;

            return actors;
        }

        string* getAllReviews(Movie movie)
        {
            //TO DO
            string *reviews;

            return reviews;
        }
};

User users[1000];

string extractValue(string *line, int *index)
{
    string extractedValue = "";
    int boundary = (*line).find("|");

    if (boundary == -1)
    {
        boundary = (*line).length();
    }

    for (int i = *index + 1; i < boundary; i++)
    {
        if ((*line)[i] != '\n' && (*line)[i] != '\r')
        {
            extractedValue += (*line)[i];
            (*line)[i] = '\0';
        }
    }

    (*line)[boundary] = '\0';
    *index = boundary;

    return extractedValue;
}

void getUsersFromFile()
{
    string line;
    ifstream myfile ("Users.txt");
    string currentUsername;
    string currentPassword;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (line != "")
            {
                currentUsername = "";
                currentPassword = "";

                int index = line.find("|");

                if (index == -1)
                {
                    cout<<"Problem with users data rendering!"<<endl;
                    break;
                }
                else
                {
                    size_t n = std::count(line.begin(), line.end(), '|');

                    if (n > 1)
                    {
                        users[usersCount].isAdmin = true;
                    }
                    else
                    {
                        users[usersCount].isAdmin = false;
                    }

                    for (int i = 0; i < index; i++)
                    {
                        currentUsername += line[i];
                        line[i] = '\0';
                    }

                    line[index] = '\0';
                    currentPassword = extractValue(&line, &index);
                }

                users[usersCount].username = currentUsername;
                users[usersCount].password = currentPassword;

                usersCount++;
            }
        }
        myfile.close();
    }
    else
    {
        cout <<"Unable to open file!"<<endl;
    }
}

void getStaffFromFile()
{
    string line;
    ifstream myfile ("Staff.txt");
    string id;
    string name;
    string birthDate;
    string moviesParticipated;
    string role;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (line != "")
            {
                id = "";
                name = "";
                birthDate = "";
                moviesParticipated = "";
                role = "";

                int index = line.find("|");

                if (index == -1)
                {
                    cout<<"Problem with staff data rendering!"<<endl;
                    break;
                }
                else
                {
                    for (int i = 0; i < index; i++)
                    {
                        id += line[i];
                        line[i] = '\0';
                    }

                    line[index] = '\0';

                    name = extractValue(&line, &index);
                    birthDate = extractValue(&line, &index);
                    moviesParticipated = extractValue(&line, &index);
                    role = extractValue(&line, &index);
                    //cout<<id<<" "<<name<<" "<<birthDate<<" "<<moviesParticipated<<" "<<role;
                    if (role == "Actor")
                    {
                        staff[staffCount] = Actor(id, name, birthDate, moviesParticipated);
                    }
                    else if (role == "Director")
                    {
                        staff[staffCount] = Director(id, name, birthDate, moviesParticipated);
                    }
                    else if (role == "Producer")
                    {
                        staff[staffCount] = Producer(id, name, birthDate, moviesParticipated);
                    }

                    staffCount++;
                }
            }
        }
    }
}

Actor getActorById(string id)
{
    for (int i = 0; i < staffCount; i++)
    {
        //cout<<staff[i].id<<" "<<staff[i].name<<" "<<staff[i].birthDate<<" "<<staff[i].participatedMovieAsString<<" "<<staff[i].role;
        if (staff[i].id == id && staff[i].role == "Actor")
        {
            return Actor(staff[i].id, staff[i].name, staff[i].birthDate,
                         staff[i].participatedMovieAsString);
        }
    }

    throw exception();
}

Director getDirectorById(string id)
{
    for (int i = 0; i < staffCount; i++)
    {
        //cout<<staff[i].id<<" "<<staff[i].name<<" "<<staff[i].birthDate<<" "<<staff[i].participatedMovieAsString<<" "<<staff[i].role;
        if (staff[i].id == id && staff[i].role == "Director")
        {
            return Director(staff[i].id, staff[i].name, staff[i].birthDate,
                         staff[i].participatedMovieAsString);
        }
    }

    throw exception();
}

void getMoviesFromFile()
{
    string line;
    ifstream myfile ("Movies.txt");
    string id;
    string movieName;
    string directorId;
    string year;
    string rating;
    string allVoters;
    string isRemake;
    string genre;
    int actorCounter = 0;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (line != "")
            {
                id = "";
                movieName = "";
                directorId = "";
                year = "";
                rating = "";
                allVoters = "";
                isRemake = "";
                Actor *actors;
                actors = new Actor[1000];
                genre = "";
                actorCounter = 0;

                int index = line.find("|");

                if (index == -1)
                {
                    cout<<"Problem with movies data rendering!"<<endl;
                    break;
                }
                else
                {
                    for (int i = 0; i < index; i++)
                    {
                        id += line[i];
                        line[i] = '\0';
                    }

                    line[index] = '\0';

                    movieName = extractValue(&line, &index);
                    directorId = extractValue(&line, &index);
                    year = extractValue(&line, &index);
                    rating = extractValue(&line, &index);
                    allVoters = extractValue(&line, &index);
                    isRemake = extractValue(&line, &index);

                    string actorsIdsAsString = extractValue(&line, &index);
                    int boundary = actorsIdsAsString.find(",");
                    int actorsIdsAsStringStartingIndex = 0;

                    while(boundary != -1)
                    {
                        string actorId = "";
                        for (int i = actorsIdsAsStringStartingIndex; i < boundary; i++)
                        {
                            if (actorsIdsAsString[i] != '\n' && actorsIdsAsString[i] != '\r')
                            {
                                actorId += actorsIdsAsString[i];
                                actorsIdsAsString[i] = '\0';
                            }
                        }

                        actorsIdsAsString[boundary] = '\0';
                        actorsIdsAsString[boundary + 1] = '\0';

                        actors[actorCounter] = getActorById(actorId);
                        actorsIdsAsStringStartingIndex = boundary + 2;
                        boundary = actorsIdsAsString.find(",");
                        actorCounter++;
                    }

                    string lastActorId = "";
                    for (int i = actorsIdsAsStringStartingIndex; i < (int)actorsIdsAsString.length(); i++)
                    {
                        if (actorsIdsAsString[i] != '\n' && actorsIdsAsString[i] != '\r')
                        {
                            lastActorId += actorsIdsAsString[i];
                        }
                    }

                    actors[actorCounter] = getActorById(lastActorId);

                    genre = extractValue(&line, &index);

                    movies[moviesCount] = Movie(id, movieName, getDirectorById(directorId), year, rating, allVoters,
                                                isRemake, actors, genre, actorCounter);

                    moviesCount++;
                }
            }
        }

        myfile.close();
    }
    else
    {
        cout <<"Unable to open file!"<<endl;
    }
}

void input(string *username, string *password)
{
    cout<<"Username: ";
    cin>>*username;

    while((*username).length() < 3)
    {
        cout<<"Your username length should be bigger or equal to 3 symbols!"<<endl;
        cout<<"Username: ";
        cin>>*username;
    }

    cout<<"Password: ";
    cin>>*password;

    while((*password).length() < 3)
    {
        cout<<"Your password length should be bigger or equal to 3 symbols!"<<endl;
        cout<<"Password: ";
        cin>>*password;
    }
}

void login(User *users, int userCount, string username, string password)
{
    cout<<"Login-"<<endl;

    input(&username, &password);

    User user(username, password);
    user.login(users, userCount);
}

void signUp(User *users, int userCount, string username, string password)
{
    cout<<"Sign up-"<<endl;

    input(&username, &password);

    User user(username, password);
    user.signUp(users, userCount);
}

void showAvailableOptions()
{
    cout<<endl;
    cout<<"You can choose from these commands:"<<endl;

    if (isLoggedAsAdmin)
    {
        cout<<"Add a movie: am"<<endl;
    }

    cout<<"Give rating to a movie: rate"<<endl;
    cout<<"Write review for a movie: review"<<endl;
    cout<<"Search movie by rating: smbr"<<endl;
    cout<<"Search movie by actor: smba"<<endl;
    cout<<"Search movies by year: smby"<<endl;
    cout<<"Search movie by director: smbd"<<endl;
    cout<<"Search movie by genre: smbg"<<endl;
    cout<<"Sort movies by rating: sbr"<<endl;
    cout<<"Sort movies from year: smfy"<<endl;
    cout<<"Search movies by actor and director: smbad"<<endl;
    cout<<"Search main actor in a movie: sma"<<endl;
    cout<<"Search main director in a movie: smd"<<endl;
    cout<<"Search all reviews of a movie: sar"<<endl;
}

string getNewId()
{
    string newIdAsString = "";
    string lastMovieId = movies[moviesCount - 1].id;
    int newId = 0;
    int multiply = intPow(10, (lastMovieId.length() - 1));
    int multiplyCopy = multiply;
    for (int i = (int)lastMovieId.length() - 1; i >= 0; i--)
    {
        if (i == (int)lastMovieId.length() - 1 && ((int)lastMovieId[i] - 48) == 9)
        {
            newId += ((int)lastMovieId[i] - 48 + 1) * multiplyCopy;
        }
        else
        {
            newId += ((int)lastMovieId[i] - 48) * multiplyCopy;
        }

        multiplyCopy /= 10;
    }
    newId += multiply;

    int currentSymbol = 0;
    while (newId > 0)
    {
        newIdAsString += (char)((newId % 10) + 48);
        newId /= 10;
    }

    return newIdAsString;
}

class Dispatcher
{
    public:
        void run()
        {
            while(true)
            {
                getUsersFromFile();
                getStaffFromFile();
                getMoviesFromFile();

                string username, password;

                int loginOrRegisterCode = 0;
                cout<<"Enter 1 for login or 2 for registration: ";
                cin>>loginOrRegisterCode;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(256,'\n');
                }

                while(loginOrRegisterCode != 1 && loginOrRegisterCode != 2)
                {
                    cout<<"Invalid code"<<endl;
                    cout<<"Enter 1 for login or 2 for registration: ";
                    cin>>loginOrRegisterCode;

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(256,'\n');

                        loginOrRegisterCode = 0;
                    }
                }

                if (loginOrRegisterCode == 1)
                {
                    login(users, usersCount, username, password);
                }
                else if (loginOrRegisterCode == 2)
                {
                    signUp(users, usersCount, username, password);
                    if (isSignedUp)
                    {
                        usersCount = 0;
                        getUsersFromFile();
                        login(users, usersCount, username, password);
                        isSignedUp = false;
                    }
                }

                if (isLogged)
                {
                    if (isLoggedAsAdmin)
                    {
                        Administrator user;
                    }
                    else
                    {
                        User user;
                    }

                    showAvailableOptions();

                    while(true)
                    {
                        string command;
                        cout<<"Type command-"<<endl;
                        cin>>command;

                        if (command == "am")
                        {
                            if(!isLoggedAsAdmin)
                            {
                                cout<<"You are not an administrator!"<<endl;
                            }
                            else
                            {
                                //Add the film
                                string movieName, directorId, year, rating, allVoters, isRemake, actors, genre;

                                cout<<"Movie name: ";
                                cin>>movieName;
                                cout<<"Director id: ";
                                cin>>directorId;
                                cout<<"Year: ";
                                cin>>year;
                                cout<<"Rating: ";
                                cin>>rating;
                                cout<<"All voters: ";
                                cin>>allVoters;
                                cout<<"isRemake: ";
                                cin>>isRemake;
                                cout<<"Actors ids: ";
                                cin>>actors;
                                cout<<"Genre: ";
                                cin>>genre;

                                string newIdAsString = getNewId();

                                string writeToFile = newIdAsString + "|" + movieName + "|" + directorId +
                                "|" + year + "|" + rating + "|" + allVoters + "|" + isRemake + "|" + actors + "|" + genre;

                                std::ofstream ofs;
                                ofs.open("Movies.txt", std::ofstream::out | std::ofstream::app);

                                ofs<<endl<<writeToFile<<endl;

                                ofs.close();
                                cout<<"You have successfully added a movie!"<<endl;

                                /*Actor *actorsForMovie;
                                int currentActorCounter = 0;
                                string actorsIdsAsString = actors;
                                int boundary = actorsIdsAsString.find(",");
                                int actorsIdsAsStringStartingIndex = 0;

                                while(boundary != -1)
                                {
                                    string actorId = "";
                                    for (int i = actorsIdsAsStringStartingIndex; i < boundary; i++)
                                    {
                                        if (actorsIdsAsString[i] != '\n' && actorsIdsAsString[i] != '\r')
                                        {
                                            actorId += actorsIdsAsString[i];
                                            actorsIdsAsString[i] = '\0';
                                        }
                                    }

                                    actorsIdsAsString[boundary] = '\0';
                                    actorsIdsAsString[boundary + 1] = '\0';
                                    actorsForMovie[currentActorCounter] = getActorById(actorId);
                                    actorsIdsAsStringStartingIndex = boundary + 2;
                                    boundary = actorsIdsAsString.find(",");
                                    currentActorCounter++;
                                }

                                string lastActorId = "";
                                for (int i = actorsIdsAsStringStartingIndex; i < (int)actorsIdsAsString.length(); i++)
                                {
                                    if (actorsIdsAsString[i] != '\n' && actorsIdsAsString[i] != '\r')
                                    {
                                        lastActorId += actorsIdsAsString[i];
                                    }
                                }
                                cout<<lastActorId;
                                actorsForMovie[currentActorCounter] = getActorById(lastActorId);

                                //movies[moviesCount] = Movie(newIdAsString, movieName, getDirectorById(directorId), year, rating, allVoters, isRemake, );
                                //moviesCount++;*/
                            }
                        }
                        else if (command == "rate")
                        {
                        }
                        else if (command == "review")
                        {
                        }
                        else if (command == "smbr")
                        {
                            string rating;
                            cout<<"Rating: ";
                            cin>>rating;

                            User currentUser;

                            try
                            {
                                Movie *moviesByRating = currentUser.getMoviesByRating(rating);

                                for (int i = 0; i < overallCounter; i++)
                                {
                                    cout<<moviesByRating[i].movieName<<endl;
                                }

                                overallCounter = 0;
                            }
                            catch (exception e)
                            {
                                cout<<"Didn't found movie with rating "<<rating<<endl;
                            }

                        }
                        else if (command == "smba")
                        {
                        }
                        else if (command == "smby")
                        {
                        }
                        else if (command == "smbd")
                        {
                        }
                        else if (command == "smbg")
                        {
                        }
                        else if (command == "sbr")
                        {
                        }
                        else if (command == "smfy")
                        {
                        }
                        else if (command == "smbad")
                        {
                        }
                        else if (command == "sma")
                        {
                        }
                        else if (command == "smd")
                        {
                        }
                        else if (command == "sar")
                        {
                        }
                    }
                }
            }
        }
};

int main()
{
    Dispatcher dispatcher;
    dispatcher.run();

    return 0;
}
