# Catalog
Here are the steps to run the code in VS Code:


Step 1: Install the nlohmann/json library

1. Open the terminal in VS Code by pressing Ctrl+` or navigating to View > Terminal.
2. Run the command: `git clone (link unavailable)
3. Navigate to the cloned repository: cd json
4. Run the command: cmake .
5. Run the command: cmake --build .

Step 2: Create a new project in VS Code

1. Open VS Code.
2. Create a new folder for your project.
3. Open the folder in VS Code.

Step 3: Add the code to your project

1. Create a new file main.cpp in your project folder.
2. Copy the provided code and paste it into main.cpp.

Step 4: Configure VS Code

1. Open the Command Palette in VS Code by pressing Ctrl+Shift+P.
2. Search for "C/C++: Edit Configurations" and select it.
3. Update the c_cpp_properties.json file to include the library path:



{
    "configurations": [
        {
            "name": "Win32",
            "includePath": ["${workspaceFolder}/**", "${workspaceFolder}/json/src/**"],
            "defines": ["_DEBUG"],
            "compilerPath": "C:/MinGW/bin/gcc.exe",
            "cStandard": "c11",
            "cppStandard": "c++14",
            "intelliSenseMode": "clang-x86"
        }
    ],
    "version": 4
}


Step 5: Compile and Run

1. Open the terminal in VS Code.
2. Navigate to your project folder.
3. Compile the code using: g++ -std=c++14 main.cpp json/src/json.cpp -o main
4. Run the executable using: ./main

Now you should see the output:



Constant term (c): 3
Constant term (c): 28735619723837

Note: Make sure to update the compilerPath and includePath in the c_cpp_properties.json file according to your system configuration.
