#include <iostream>
#include <yaml-cpp/yaml.h> // You'll need to install yaml-cpp library. Use `sudo apt-get install libyaml-cpp-dev` on Ubuntu.

int main() {
    try {
        // Load YAML file
        YAML::Node config = YAML::LoadFile("../config.yaml");

        // Read configuration settings
        std::string name = config["name"].as<std::string>();
        int age = config["age"].as<int>();

        // Print configuration settings
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
    } catch(const YAML::Exception& e) {
        std::cerr << "Error reading YAML file: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
