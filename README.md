# 🚗✈️🚢 Vehicle Management System in C++

## 📌 **⚠️ This project was developed as part of a University Assignment. ⚠️**  
This project is a **menu-driven Vehicle Management System** built in **C++** that allows users to **add, edit, delete, search, and filter vehicles**.  

It supports **Air, Land, and Sea vehicles**, each with unique attributes such as **altitude, number of wheels, and displacement**.  

---

## 📌 Description
This system enables efficient **management of vehicle records** using a structured **class-based design**. Users can:  
✅ Add new vehicles (Air, Land, or Sea)  
✅ Edit vehicle details  
✅ Delete existing vehicles  
✅ Search by name  
✅ Filter by type (Air, Land, or Sea)  
✅ View all stored vehicles  

The program also enhances **user experience** with:  
🔹 **ASCII Art UI** – Displays styled text from external files  
🔹 **File Handling** – Reads descriptions and menu elements from files  

---

## ✨ Features
🔹 **Object-Oriented Design** – Uses **C++ classes** and **inheritance** for modularity  
🔹 **Multi-Type Vehicle System** – Supports **Air, Land, and Sea** vehicle types  
🔹 **Dynamic Memory Allocation** – Vehicles are stored using **pointers** for flexibility  
🔹 **File Handling** – Reads ASCII art and descriptions from text files for UI improvement  
🔹 **Interactive Menu System** – User-friendly menu with structured navigation  
🔹 **Search & Filter System** – Easily find vehicles by name or type  
🔹 **Data Validation** – Ensures valid input (e.g., condition percentage, price, vehicle type)  
🔹 **Sound Feedback** – Plays **beep sounds** when keys are pressed 🔊  

---

## 🛠️ Technical Details
### 🔹 **Object-Oriented Programming (OOP)**
- Uses **base class (`Vehicle`)** with **derived classes (`AirVehicle`, `LandVehicle`, `SeaVehicle`)**  
- **Encapsulation**: Vehicle attributes are private/protected  
- **Polymorphism**: Uses **virtual functions** for `display()`  

### 🔹 **Dynamic Memory Management**
- Vehicles are **stored using pointers** (`Vehicle* vehicles[MAX_VEHICLES]`)  
- **Allocated dynamically** using `new` and cleaned up with `delete`  

### 🔹 **File Handling**
- Reads ASCII art, descriptions, and menu text from `.txt` files using `fopen()`, `fgetc()`, and `fclose()`  
- Example:
  ```cpp
  FILE *fptr = fopen("Description.txt", "r");
  char c;
  while ((c = fgetc(fptr)) != EOF) { printf("%c", c); }
  fclose(fptr);
  ```

### 🔹 **Search & Filter Mechanism**
- Searches **by name** using a loop over `vehicles[]`  
- Filters **by type** using `dynamic_cast<>`  

### 🔹 **Menu Navigation & Sound Feedback**
- Uses `system("cls")` for a smooth **UI refresh**  
- Plays **beep sounds** when navigating the menu using `Beep(1000, 100);` (Windows only)  

---

## 🚀 How to Run
### 🔹 Compile the Program:
```sh
g++ Group8.cpp -o vehicle_manager.exe
```
### 🔹 Run the Executable:
```sh
vehicle_manager.exe
```

---

## 🎮 Controls
🎯 **1** – Add a new vehicle  
🎯 **2** – Edit an existing vehicle  
🎯 **3** – Delete a vehicle  
🎯 **4** – View all vehicles  
🎯 **5** – Search by name  
🎯 **6** – Filter by type  
🎯 **0** – Exit program  

---

## 📜 Example Main Menu Output:
```
                    ____________________________________________________________________
                   |  ________________________________________________________________  |
                   | |                                                                | |
                   | |  Hello! Welcome to Motor Manage Deluxe, the ultimate solution  | |
                   | |  for efficient vehicle management! Say goodbye to tedious      | |
                   | |  paperwork and manual tracking.                                | |
                   | |                                                                | |
                   | |  <Enter (1) to Add Vehicle>                                    | |
                   | |  <Enter (2) to Edit Vehicle>                                   | |
                   | |  <Enter (3) to Delete Vehicle>                                 | |
                   | |  <Enter (4) to Display All Vehicles>                           | |
                   | |  <Enter (5) to Search Vehicle>                                 | |
                   | |  <Enter (6) to Filter Vehicles by Type>                        | |
                   | |  <Enter (0) to Exit>                                           | |
                   | |________________________________________________________________| |
                   |____________________________________________________________________|

                        Enter Choice: 
```

---

## 📄 Sample Vehicle Display:
```
---------------------------------
Vehicle 1:
---------------------------------
Type: Land
Name: Toyota Hilux
Manufacturing Year: 2019
Engine Type: Diesel
Weight: 2100 kg
Seating Capacity: 5 seats
Cargo Capacity: 900 kg
Condition: 85%
Price: RM120,000.00
Number of Wheels: 4
---------------------------------

---------------------------------
Vehicle 2:
---------------------------------
Type: Air
Name: Boeing 737
Manufacturing Year: 2015
Engine Type: Jet
Weight: 41000 kg
Seating Capacity: 200 seats
Cargo Capacity: 20000 kg
Condition: 75%
Price: RM75,000,000.00
Max Altitude: 12,000 meters
---------------------------------

---------------------------------
Vehicle 3:
---------------------------------
Type: Sea
Name: Titanic
Manufacturing Year: 1912
Engine Type: Steam
Weight: 52310 kg
Seating Capacity: 3300 seats
Cargo Capacity: 40000 kg
Condition: 30%
Price: RM1,200,000.00
Displacement: 52,310 kg
---------------------------------

```




---

## 📌 License
This project is open-source. Feel free to use and modify it as needed.
