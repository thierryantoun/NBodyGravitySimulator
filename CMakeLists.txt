# Définir la version minimale de CMake requise
cmake_minimum_required(VERSION 3.10)

# Définir le nom du projet
project(NBodySimulation)

# Spécifier la version de C++ (par exemple C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajouter l'exécutable
add_executable(NBodySimulation main.cpp)

# Inclure les dossiers si nécessaire (par exemple, si vous avez un dossier include)
# include_directories(include)
