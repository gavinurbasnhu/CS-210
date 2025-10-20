Module 7 Project 3 for CS-210-10268-M01 Programming Languages 2025 at SNHU.

# Reflection
### Summarize the project and what problem it was solving.
Corner Grocer wants to rearrange their produce departement. To create the most effective layout for their customers, they need a program that analyzes the sales records that the store generates throughout the day.

### What did you do particularly well?
I believe the greatest strength of my program is the efficiency of the code. Even with comments and gaps for readability, the entire program has less than 200 lines of code, largely in part due to the use of maps.
This project served as my introduction to maps and it took a lot of trial and error for me to fully understand how this functionality of C++ worked. I view the efficiency of this program to be a reflection of how well I was able to teach myself C++.

### Where could you enhance your code?
Removing the case-sensitivity when searching for an item's name is the first improvement I would like to make to this program. If the user enters a valid item name but does not capitalize the first letter, the program will display 'Invalid search." More than being tedious, requiring the user to capitalize the first letter of an item's name can cause confussion since "apple" is invalid but "Apple" is accepted. Removing this unnecessary restriction on input would be a quality-of-life improvement and make my program easier to use.

### Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
I found the process of iterating through map elements to be the most challenging pieces of code to write. In fact, most of the time I spent on this program was focused on understanding maps. Given my lack of experience with tradtiional arrays and vectors, learning map also required me to improve my understanding of data structures in C++. Through resources like C++'s documentation, w3schools examples, and GeeksforGeeks articles, I was able to break down the concepts and fully grasp the power of storing data in maps.

### What skills from this project will be particularly transferable to other projects or course work?
This project gave me valuable experience with fundamental OPP principals, header files, and classes. While simple, the knowledge I gained from working on this program serve as the foundation that future projects will be built upon. Understanding abstraction and how to use seperate files are key skills that any programer need to create complex software. 

### How did you make this program maintainable, readable, and adaptable?
Consistent formatting and clear comments throughout the code makes it easier for other programmers to read and maintain this program. The implmentation of a class in the operations of this program ensure that this code is adaptable. For example, each element pair in the map stores an object instead of an integer. This allows for additional information to be stored about each item without requiring extensive modifications to made to the program's functions. 
