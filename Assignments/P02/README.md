## P01 - Parse JSON file, and use getch to get the input from the use and search the data from the dictionary
### Sangam Lamichhane
### Description:

- Read JSON files and collect all data JsonData in vector JsonDataList
- Allowing the user to input the initials from the console and search the available words from the dictionary and display the results.
- This program uses a "getch" function which means "get character". However, getch does not print the character to the terminal, it lets you decide what to do based on what character you are pressing. You can test which characters are being pressed using their ascii values.
  
### Key Features
- **Dynamic Input Handling:** Uses `getch` to handle real-time input without requiring the Enter key.
- **Interactive Search:** Updates search results as the user types.
- **Visual Feedback:** Uses console formatting to highlight matches and provide a visually engaging interface.

### Technologies Used
- C++
- JSON for Modern C++
- Custom console and formatting libraries (`rang`)

## Getting Started
To run this program, you need to have a C++ compiler that supports C++11 or later, and the JSON for Modern C++ library must be included in the project.

### Prerequisites
- A modern C++ compiler (e.g., GCC, Clang)
- JSON for Modern C++ library
- Make sure all custom header files (`console.hpp`, `json.hpp`, `rang.hpp`) are correctly placed in the project directory.
