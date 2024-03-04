#include <iostream>
#include <yaml-cpp/yaml.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <name> <filename>" << std::endl;
        return 1;
    }

    std::string name = argv[1];
    std::string filename = argv[2];

    try {
        // Load YAML file
        YAML::Node config = YAML::LoadFile("../" + filename);

        // Search for data of the person with given name
        YAML::Node personData = config[name];

        if (personData) {
            // Read person's data
            std::string name = personData["name"].as<std::string>();
            int age = personData["age"].as<int>();

            // Print person's data
            std::cout << "Name: " << name << std::endl;
            std::cout << "Age: " << age << std::endl;
        } else {
            std::cerr << "Person with name '" << name << "' not found in the file." << std::endl;
            return 1;
        }
    } catch(const YAML::Exception& e) {
        std::cerr << "Error reading YAML file: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
