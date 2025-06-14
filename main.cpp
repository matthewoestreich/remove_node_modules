#include <iostream>
#include <string>

#include "remove_node_modules.hpp"

namespace fs = std::filesystem;

int main(int argc, char *argv[]) {
  if (argc < 2 || argc > 3) {
    std::cerr << "Usage: ./remove_node_modules <directory_path> [--dry-run]" << std::endl;
    return 1;
  }

  fs::path base_path(argv[1]);
  bool dry_run = false;

  if (argc == 3) {
    std::string option(argv[2]);
    if (option == "--dry-run") {
      dry_run = true;
    } else {
      std::cerr << "Unknown option: " << option << std::endl;
      return 1;
    }
  }

  remove_node_modules(base_path, dry_run);
  return 0;
}
