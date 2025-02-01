# Gym Membership Application System

This repository contains the final project for our university course, developed collaboratively by **Aaliyah Barakatullah Asura**, **Alexandra Tabita Purnomo**, and **Ahmad Wildan Abdullah**. The project is titled **"Gym Membership Application System"** and is written in **C++**.

## 📋 Project Description

The **Gym Membership Application System** is a C++ console-based program designed to simulate the management of gym memberships and appointments. The system provides features for viewing schedules, trainers, making appointments, and performing admin login tasks. This project was developed as part of our final assessment to demonstrate our understanding of object-oriented programming and system design.

## ✨ Features

- **View Schedules**: Members can view the gym schedule.
- **View Trainers**: Members can explore available trainers.
- **Make Appointments**: Members can book appointments with trainers.
- **Admin Login**: Allows administrators to log in and manage gym operations.
- **User Validation**: Ensures only registered members can access certain features.

## 🛠️ System Requirements

- C++ Compiler (e.g., GCC, Clang, or Visual Studio)
- Standard C++ Libraries
- Console/Terminal to run the program

## 🚀 How to Run the Program

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/Gym-Membership-Application.git
2. Navigate to the project directory
   ```bash
   cd Gym-Membership-Application
3. Compile the program
    ```bash
    g++ -o gym_membership main.cpp admin.cpp user.cpp controller.cpp
4. run the program
   ```bash
   ./gym_membership

  ## Project Structure

- **main.cpp**: Contains the main program logic and controls the flow of the application.  
- **admin.h / admin.cpp**: Implements admin-related functionalities and operations.  
- **controller.cpp**: Manages user input and facilitates navigation through the menu.  
- **user.cpp**: Provides member functionalities, such as viewing schedules and trainers.  

## Usage Instructions

### Menu Navigation
The program offers a menu to select different functionalities:  
- View schedules  
- View trainers  
- Make appointments  
- Admin login  

### User Authentication
Members are required to provide their NIK for accessing appointment-related actions.  

### Admin Privileges
Only authenticated admins are allowed to access the admin menu and perform administrative tasks.  

### Appointments
Members can book an appointment with a selected trainer by entering the trainer's ID.  

## Learning Objectives

This project was developed to achieve the following learning outcomes:  
- Implement object-oriented programming (OOP) principles in C++.  
- Practice modular programming by organizing code into separate files and classes.  
- Develop a user-friendly, console-based interface with basic validation mechanisms.  

## Contributors

- **Aaliyah Barakatullah Asura**    
- **Alexandra Tabita Purnomo**  
- **Ahmad Wildan Abdullah**  

## Acknowledgments

This project was developed as part of the **Final Assessment** for the university course.  
We extend our gratitude to our instructor and peers for their valuable guidance and feedback.  

