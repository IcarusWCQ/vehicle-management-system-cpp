/*
Icarus Wong Chii Quan (1221201504)
Shazreen Binti Sheridan (1221202269)
Vinoth Naidu A/L Sri Padmanathan (1221203357)
Muhammad Imran Danial Bin Azhar (1221201917)
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>

class Vehicle 
{
protected:
    std::string name;
    int year;
    std::string engineType;
    int weight;
    int seatingCapacity;
    int cargoCapacity;
    double condition;
    double price;

public:
    Vehicle() : name(""), year(0), engineType(""), weight(0), seatingCapacity(0), cargoCapacity(0), condition(0.0), price(0.0) {}

    Vehicle(std::string name, int year, std::string engineType, double weight, int seatingCapacity, double cargoCapacity, double condition, double price)
        : name(name), year(year), engineType(engineType), weight(weight), seatingCapacity(seatingCapacity), cargoCapacity(cargoCapacity), condition(condition), price(price) {}

    virtual ~Vehicle() {}

    virtual void display()
    {
        std::cout << "                                                                     Name: " << name << std::endl;
        std::cout << "                                                                     Manufacturing Year: " << year << std::endl;
        std::cout << "                                                                     Engine Type: " << engineType << std::endl;
        std::cout << "                                                                     Weight: " << weight << std::endl;
        std::cout << "                                                                     Seating Capacity: " << seatingCapacity << " seat(s)" << std::endl;
        std::cout << "                                                                     Cargo Capacity: " << cargoCapacity << " kg" << std::endl;
        std::cout << "                                                                     Condition: " << condition << "%" << std::endl;
        std::cout << "                                                                     Price: RM" << std::fixed << std::setprecision(2) << price << std::endl;
    }

    const std::string& getName() const // Getter for name
    {  
        return name;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);
};

std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle) 
{
    os << "                                                                     Name: " << vehicle.name << std::endl;
    os << "                                                                     Manufacturing Year: " << vehicle.year << std::endl;
    os << "                                                                     Engine Type: " << vehicle.engineType << std::endl;
    os << "                                                                     Weight: " << vehicle.weight << " kg" << std::endl;
    os << "                                                                     Seating Capacity: " << vehicle.seatingCapacity << " seat(s)" << std::endl;
    os << "                                                                     Cargo Capacity: " << vehicle.cargoCapacity << " kg" << std::endl;
    os << "                                                                     Condition: " << vehicle.condition << "%" << std::endl;
    os << "                                                                     Price: RM" << std::fixed << std::setprecision(2) << vehicle.price << std::endl;
    return os;
}

class AirVehicle : public Vehicle 
{
private:
    int maxAltitude;

public:
    AirVehicle(std::string name, int year, std::string engineType, double weight, int seatingCapacity, double cargoCapacity, double condition, double price, int maxAltitude)
        : Vehicle(name, year, engineType, weight, seatingCapacity, cargoCapacity, condition, price), maxAltitude(maxAltitude) {}    

    void display() override {
        std::cout << "                                                                     Type: Air" << std::endl;
        Vehicle::display();
        std::cout << "                                                                     Max Altitude: " << maxAltitude << " meter" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const AirVehicle& airVehicle);
};

std::ostream& operator<<(std::ostream& os, const AirVehicle& airVehicle) {
    os << "                                                                     Type: Air" << std::endl;
    os << static_cast<const Vehicle&>(airVehicle);
    os << "                                                                     Max Altitude: " << airVehicle.maxAltitude << " meter" << std::endl;
    return os;
}


class LandVehicle : public Vehicle 
{
private:
    int numWheels;

public:
    LandVehicle(std::string name, int year, std::string engineType, double weight, int seatingCapacity, double cargoCapacity, double condition, double price, int numWheels)
        : Vehicle(name, year, engineType, weight, seatingCapacity, cargoCapacity, condition, price), numWheels(numWheels) {}

    void display() override 
    {
        std::cout << "                                                                     Type: Land" << std::endl;
        Vehicle::display();
        std::cout << "                                                                     Number of Wheels: " << numWheels << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const LandVehicle& landVehicle);
};

std::ostream& operator<<(std::ostream& os, const LandVehicle& landVehicle)
{
    os << "                                                                     Type: Land" << std::endl;
    os << static_cast<const Vehicle&>(landVehicle);
    os << "                                                                     Number of Wheels: " << landVehicle.numWheels << std::endl;
    return os;
}

class SeaVehicle : public Vehicle 
{
private:
    int displacement;

public:
    SeaVehicle(std::string name, int year, std::string engineType, double weight, int seatingCapacity, int cargoCapacity, double condition, double price, int displacement)
        : Vehicle(name, year, engineType, weight, seatingCapacity, cargoCapacity, condition, price), displacement(displacement) {}

    void display() override 
    {
        std::cout << "                                                                     Type: Sea" << std::endl;
        Vehicle::display();
        std::cout << "                                                                     Displacement: " << displacement << " kg" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const SeaVehicle& seaVehicle);
};

std::ostream& operator<<(std::ostream& os, const SeaVehicle& seaVehicle) 
{
    os << "                                                                     Type: Sea" << std::endl;
    os << static_cast<const Vehicle&>(seaVehicle);
    os << "                                                                     Displacement: " << seaVehicle.displacement << " kg" << std::endl;
    return os;
}


int main() 
{
    const int MAX_VEHICLES = 100;
    Vehicle* vehicles[MAX_VEHICLES];
    int numVehicles = 1;
    FILE *fptr;
	char c, choice;
    system("cls");
    system("color 0B");
    fptr=fopen("Description.txt","r");
	c = fgetc(fptr);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(fptr);
	}
	fclose(fptr);
    system("pause");

    do {
        system("cls");
        fptr=fopen("MainMenu.txt","r");
		c = fgetc(fptr);
		while (c != EOF)
		{
			printf("%c", c);
			c = fgetc(fptr);
		}
		fclose(fptr);
        std::cin >> choice;

        switch (choice) {
            case '1': 
            {
                system("cls");
                fptr=fopen("Group8.txt","r");
                c = fgetc(fptr);
                while (c != EOF)
                {
                    printf("%c", c);
                    c = fgetc(fptr);
                }
                fclose(fptr);
                std::cout << "\n                                                                     ====================== Enter Vehicle Information =====================" << std::endl;
                if (numVehicles >= MAX_VEHICLES) 
                {
                    std::cout << "                                                                     Invalid vehicle type!" << std::endl;
                    std::cout << "                                                                     ";
                    system("pause");
                    break;
                }

                std::cout << "                                                                     Enter vehicle type (A for Air, L for Land, S for Sea): ";
                char vehicleType;
                std::cin >> vehicleType;

                if (vehicleType!='A'&&vehicleType!='a'&&vehicleType!='L'&&vehicleType!='l'&&vehicleType!='S'&&vehicleType!='s') 
                {
                    std::cout << "                                                                     Maximum number of vehicles reached!" << std::endl;
                    break;
                    
                }

                std::cout << "                                                                     Enter Name: ";
                std::string name;
                std::cin.ignore();
                std::getline(std::cin, name);

                std::cout << "                                                                     Enter Manufacturing Year: ";
                int year;
                std::cin >> year;

                std::cout << "                                                                     Enter Engine Type: ";
                std::string engineType;
                std::cin >> engineType;

                std::cout << "                                                                     Enter Weight(in kilograms): ";
                double weight;
                std::cin >> weight;

                std::cout << "                                                                     Enter Seating Capacity(seats): ";
                int seatingCapacity;
                std::cin >> seatingCapacity;

                std::cout << "                                                                     Enter Cargo Capacity(in kilograms): ";
                double cargoCapacity;
                std::cin >> cargoCapacity;

                std::cout << "                                                                     Enter Condtion(in percentage): ";
                double condition;
                std::cin >> condition;

                if(condition>100)
                {
                    std::cout << "                                                                     Invalid Percentage Value: ";
                    std::cout << "                                                                     ";
                    system("pause");
                    break;
                }         

                std::cout << "                                                                     Enter Price: RM";
                double price;
                std::cin >> price;

                if (vehicleType == 'A' || vehicleType == 'a') 
                {  
                    std::cout << "                                                                     Enter Max Altitude(in meters): ";
                    int maxAltitude;
                    std::cin >> maxAltitude;
                    vehicles[numVehicles] = new AirVehicle(name, year, engineType, weight, seatingCapacity, cargoCapacity, condition, price, maxAltitude);
                } 
                else if (vehicleType == 'L' || vehicleType == 'l') 
                {
                    std::cout << "                                                                     Enter Number of Wheels: ";
                    int numWheels;
                    std::cin >> numWheels;
                    vehicles[numVehicles] = new LandVehicle(name, year, engineType, weight, seatingCapacity, cargoCapacity, condition, price, numWheels);
                } 
                else if (vehicleType == 'S' || vehicleType == 's') 
                {
                    std::cout << "                                                                     Enter Displacement(in kilograms): ";
                    int displacement;
                    std::cin >> displacement;
                    vehicles[numVehicles] = new SeaVehicle(name, year, engineType, weight, seatingCapacity, cargoCapacity, condition, price, displacement);
                }
                else 
                {
                    std::cout << "                                                                     Invalid vehicle type!" << std::endl;
                    break;
                }
                numVehicles++;
                std::cout << "                                                                     Vehicle added successfully!" << std::endl;
                std::cout << "                                                                     ";
                system("pause");
                break;
            }
            case '2': 
            {
                system("cls");
                fptr=fopen("Group8.txt","r");
                c = fgetc(fptr);
                while (c != EOF)
                {
                    printf("%c", c);
                    c = fgetc(fptr);
                }
                fclose(fptr);
                std::cout << "\n                                                                     ======================= Edit Vehicle Information =====================" << std::endl;
                std::cout << "                                                                     Enter vehicle index to edit (1-" << numVehicles - 1 << "): ";
                int index;
                std::cin >> index;
                std::cout << std::endl;

                if (index >= 0 && index < numVehicles) 
                {
                    vehicles[index]->display();

                    std::cout << std::endl << "\n                                                                     Enter new Name: ";
                    std::string name;
                    std::cin.ignore();
                    std::getline(std::cin, name);

                    std::cout << "                                                                     Enter new Manufacturing Year: ";
                    int year;
                    std::cin >> year;

                    std::cout << "                                                                     Enter new Engine Type: ";
                    std::string engineType;
                    std::cin >> engineType;

                    std::cout << "                                                                     Enter new Weight(in kilograms): ";
                    double weight;
                    std::cin >> weight;

                    std::cout << "                                                                     Enter new Seating Capacity(seats): ";
                    int seatingCapacity;
                    std::cin >> seatingCapacity;

                    std::cout << "                                                                     Enter new Cargo Capacity(in kilograms): ";
                    double cargoCapacity;
                    std::cin >> cargoCapacity;

                    std::cout << "                                                                     Enter new Condtion(in percentage): ";
                    double condition;
                    std::cin >> condition;

                    if(condition>100)
                    {
                        std::cout << "                                                                     Invalid Percentage Value: ";
                        std::cout << "                                                                     ";
                        system("pause");
                        break;
                    }


                    std::cout << "                                                                     Enter new Price: RM";
                    double price;
                    std::cin >> price;

                    if (dynamic_cast<AirVehicle*>(vehicles[index])) 
                    {
                        std::cout << "                                                                     Enter new Max Altitude(in meters): ";
                        int maxAltitude;
                        std::cin >> maxAltitude;
                        delete vehicles[index];
                        vehicles[index] = new AirVehicle(name, year, engineType, weight, seatingCapacity, cargoCapacity, condition, price, maxAltitude);
                    } 
                    else if (dynamic_cast<LandVehicle*>(vehicles[index])) 
                    {
                        std::cout << "                                                                     Enter new Number of Wheels: ";
                        int numWheels;
                        std::cin >> numWheels;
                        delete vehicles[index];
                        vehicles[index] = new LandVehicle(name, year, engineType, weight, seatingCapacity, cargoCapacity, condition, price, numWheels);
                    } 
                    else if (dynamic_cast<SeaVehicle*>(vehicles[index])) 
                    {
                        std::cout << "                                                                     Enter new Displacement(in kilograms): ";
                        int displacement;
                        std::cin >> displacement;
                        delete vehicles[index];
                        vehicles[index] = new SeaVehicle(name, year, engineType, weight, seatingCapacity, cargoCapacity, condition, price, displacement);
                    }
                    std::cout << "                                                                     Vehicle edited successfully!" << std::endl;
                } 
                else 
                {
                    std::cout << "                                                                     Invalid vehicle index!" << std::endl;
                }
                std::cout << "                                                                     ";
                system("pause");
                break;
            }
            case '3': 
            {
                system("cls");
                fptr=fopen("Group8.txt","r");
                c = fgetc(fptr);
                while (c != EOF)
                {
                    printf("%c", c);
                    c = fgetc(fptr);
                }
                fclose(fptr);
                std::cout << "\n                                                                     =========================== Delete Vehicle ==========================" << std::endl;
                std::cout << "                                                                     Enter vehicle index to delete (1-" << numVehicles - 1 << "): ";
                int index;
                std::cin >> index;

                if (index >= 0 && index < numVehicles) 
                {
                    delete vehicles[index];
                    vehicles[index] = nullptr;

                    // Shift remaining vehicles to fill the gap
                    for (int i = index; i < numVehicles - 1; i++) 
                    {
                        vehicles[i] = vehicles[i + 1];
                    }
                    numVehicles--;
                    std::cout << "                                                                     Vehicle deleted successfully!" << std::endl;
                } 
                else 
                {
                    std::cout << "                                                                     Invalid vehicle index!" << std::endl;
                }
                std::cout << "                                                                     ";
                system("pause");
                break;
            }
            case '4': 
            {
                system("cls");
                fptr=fopen("Group8.txt","r");
                c = fgetc(fptr);
                while (c != EOF)
                {
                    printf("%c", c);
                    c = fgetc(fptr);
                }
                fclose(fptr);
                std::cout << "\n                                                                     ======================= Displaying All Vehicles ======================" << std::endl;
                for (int i = 1; i < numVehicles; i++) 
                {
                    std::cout << "                                                                     Vehicle " << i << ":" << std::endl;
                    vehicles[i]->display();
                    std::cout << std::endl;
                }
                std::cout << "                                                                     ";
                system("pause");
                break;
            }
            case '5': 
            {
                system("cls");
                fptr = fopen("Group8.txt", "r");
                c = fgetc(fptr);
                while (c != EOF) {
                    printf("%c", c);
                    c = fgetc(fptr);
                }
                fclose(fptr);
                std::cout << "\n                                                                     ======================= Search Vehicles By Name ======================" << std::endl;
                if (numVehicles > 0) {
                    std::cout << "                                                                     Enter vehicle name to search: ";
                    std::string name;
                    std::cin.ignore();
                    std::getline(std::cin, name);

                    std::vector<Vehicle*> matchingVehicles;
                    for (int i = 1; i < numVehicles; i++) {
                        if (vehicles[i]->getName() == name) 
                        {
                            matchingVehicles.push_back(vehicles[i]);
                        }
                    }
                    int i=0;
                    if (!matchingVehicles.empty()) {
                        for (Vehicle* vehicle : matchingVehicles) 
                        {
                            i++;
                            std::cout << std::endl;
                            std::cout << "                                                                     Vehicle " << i << ":" << std::endl;
                            vehicle->display();
                            std::cout << std::endl;
                        }
                    } else {
                        std::cout << "                                                                     Vehicle not found." << std::endl;
                    }
                } else {
                    std::cout << "                                                                     No vehicles available." << std::endl;
                }
                std::cout << "                                                                     ";
                system("pause");
                break;
            }
            case '6': 
            {
                system("cls");
                fptr=fopen("Group8.txt","r");
                c = fgetc(fptr);
                while (c != EOF)
                {
                    printf("%c", c);
                    c = fgetc(fptr);
                }
                fclose(fptr);
                std::cout << "\n                                                                     ===================== Search Vehicles By Filter ======================" << std::endl;
                if (numVehicles > 0) 
                {
                    char vehicleType;
                    std::cout << "                                                                     Enter vehicle type to filter (A for Air, L for Land, S for Sea): ";
                    std::cin >> vehicleType;

                    bool found = false;
                    for (int i = 1; i < numVehicles; i++) 
                    {
                        std::cout << std::endl;
                        if (vehicleType == 'A'||vehicleType == 'a' && dynamic_cast<AirVehicle*>(vehicles[i])) 
                        {
                            vehicles[i]->display();
                            found = true;
                        }
                        else if (vehicleType == 'L'||vehicleType == 'l' && dynamic_cast<LandVehicle*>(vehicles[i]))
                        {
                            vehicles[i]->display();
                            found = true;
                        } 
                        else if (vehicleType == 'S'||vehicleType == 's' && dynamic_cast<SeaVehicle*>(vehicles[i])) 
                        {
                            vehicles[i]->display();
                            found = true;
                        }
                    }
                    if (!found) 
                    {
                        std::cout << "                                                                     No vehicles of the specified type found." << std::endl;
                    }
                } 
                else 
                {
                    std::cout << "                                                                     No vehicles available." << std::endl;
                }
                std::cout << std::endl << "                                                                     ";
                system("pause");
                break;
            }
            case '0':
            {
                system("cls");
                fptr=fopen("Exit.txt","r");
                c = fgetc(fptr);
                while (c != EOF)
                {
                    printf("%c", c);
                    c = fgetc(fptr);
                }
                fclose(fptr);
                system("pause");
                break;
            default:
                std::cout << "                                                                     Invalid choice!" << std::endl;
                std::cout << "                                                                     ";
                system("pause");
                break;
            }
        }
        std::cout << std::endl;
    } while (choice != '0');

    // Clean up allocated memory
    for (int i = 0; i < numVehicles; i++) 
    {
        delete vehicles[i];
    }

    return 0;
}