#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>

using namespace std;

class Ship
{
    private:
        char *name = new char;
        int *releaseDate;
        int *gunsCount;

    public:
        Ship ()
        {
        }

        Ship (char *name, int releaseDate, int gunsCount)
        {
            setName(name);
            setReleaseDate(releaseDate);
            setGunsCount(gunsCount);
        }

        ~Ship ()
        {
            delete this->name;
            delete this->releaseDate;
            delete this->gunsCount;
        }

        char* getName ()
        {
            return this->name;
        }

        void setName (char *name)
        {
            this->name = name;
        }

        int getReleaseDate ()
        {
            return *(this->releaseDate);
        }

        void setReleaseDate (int releaseDate)
        {
            this->releaseDate = new int(releaseDate);
        }

        int getGunsCount ()
        {
            return *(this->gunsCount);
        }

        void setGunsCount (int gunsCount)
        {
            this->gunsCount = new int(gunsCount);
        }
};

struct less_than_guns_count
{
    inline bool operator() (Ship struct1, Ship struct2)
    {
        return (struct1.getGunsCount() < struct2.getGunsCount());
    }
};

class Navy
{
    private:
        char *country = new char;
        vector<Ship> ships;

    public:
        Navy ()
        {
        }

        Navy (char *country, vector<Ship> ships)
        {
            setCountry(country);
            setShips(ships);
        }

        ~Navy ()
        {
            delete this->country;
        }

        char* getCountry()
        {
            return this->country;
        }

        void setCountry (char *country)
        {
            this->country = country;
        }

        vector<Ship> getShips ()
        {
            return this->ships;
        }

        void setShips(vector<Ship> ships)
        {
            this->ships = ships;
        }

        int getShipsCount ()
        {
            return this->ships.size();
        }

        void addShip(Ship newShip)
        {
            bool found = false;
            for (int i = 0; i < getShipsCount(); i++)
            {
                if (newShip.getName() == this->ships[i].getName())
                {
                    found = true;
                }
            }

            if (!found)
            {
                this->ships.push_back(newShip);
                cout<<"Added ship with name "<<newShip.getName()<<endl;
            }
            else
            {
                cout<<"Already contains ship with name "<<newShip.getName()<<endl;
            }
        }

        void removeShip(char *shipName)
        {
            int shipIndex = -1;
            for (int i = 0; i < getShipsCount(); i++)
            {
                if (shipName == this->ships[i].getName())
                {
                    shipIndex = i;
                }
            }

            if (shipIndex != -1)
            {
                this->ships.erase(this->ships.begin() + shipIndex);
                cout<<"Deleted ship with name "<<shipName<<endl;
            }
            else
            {
                cout<<"Didn't find ship with name "<<shipName<<endl;
            }
        }

        void sortShipsByGunsCount()
        {
            sort(this->ships.begin(), this->ships.end(), less_than_guns_count());
        }
};

int main()
{
    vector<Ship> ships;

    ships.reserve(100);

    Ship shipBlackPerl;
    shipBlackPerl.setName("gosho");
    shipBlackPerl.setGunsCount(10);
    shipBlackPerl.setReleaseDate(2000);

    Ship shipAlaska;
    shipAlaska.setName("kiro");
    shipAlaska.setGunsCount(5);
    shipAlaska.setReleaseDate(2000);

    Ship shipBlackViper;
    shipBlackViper.setName("pesho");
    shipBlackViper.setGunsCount(8);
    shipBlackViper.setReleaseDate(2000);

    ships.push_back(shipBlackPerl);
    ships.push_back(shipAlaska);
    ships.push_back(shipBlackViper);

    Navy navy ("Germany", ships);

    Ship shipToAdd;
    shipToAdd.setName("pesho2");
    shipToAdd.setGunsCount(10);
    shipToAdd.setReleaseDate(2000);

    cout<<"Adding ship with name: pesho2"<<endl;
    navy.addShip(shipToAdd);

    Ship shipToAddAlreadyExists;
    shipToAddAlreadyExists.setName("pesho2");
    shipToAddAlreadyExists.setGunsCount(10);
    shipToAddAlreadyExists.setReleaseDate(2000);

    cout<<"Adding ship with name: pesho2"<<endl;
    navy.addShip(shipToAddAlreadyExists);

    cout<<"Removing ship with name: pesho2"<<endl;
    navy.removeShip("pesho2");

    Ship shipToAddAgain;
    shipToAddAgain.setName("pesho2");
    shipToAddAgain.setGunsCount(10);
    shipToAddAgain.setReleaseDate(2000);

    cout<<"Adding ship with name: pesho2"<<endl;
    navy.addShip(shipToAddAgain);

    return 0;
}












