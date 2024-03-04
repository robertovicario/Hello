#include <iostream>
#include <yaml-cpp/yaml.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <name> <configuration>" << std::endl;
        return 1;
    }

    std::string algo = argv[1];
    std::string config = argv[2];

    try {
        YAML::Node yaml_file = YAML::LoadFile("../config.yaml");
        if (yaml_file["balance"][config]) {
            YAML::Node yaml_config = yaml_file["balance"][config];

            int anchor_set = yaml_config["anchor_set"].as<int>();
            int num_keys = yaml_config["num_keys"].as<int>();
            int num_removals = yaml_config["num_removals"].as<int>();
            int working_set = yaml_config["working_set"].as<int>();


            if (algo == "dx") {
                std::cout << "dx :\n" << std::endl;
                std::cout << "anchor_set: " << anchor_set << std::endl;
                std::cout << "num_keys: " << num_keys << std::endl;
                std::cout << "num_removals: " << num_removals << std::endl;
                std::cout << "working_set: " << working_set << std::endl;
            } else {
                std::cerr << "Algorithm <" << algo << "> not found." << std::endl;
                return 1;
            }
        } else {
            std::cerr << "Configuration <" << config << "> not found." << std::endl;
            return 1;
        }
    } catch(const YAML::Exception& e) {
        std::cerr << "Error reading YAML file: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
