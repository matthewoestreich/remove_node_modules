#include <iostream>
#include <string>

#include "remove_node_modules.hpp"

namespace fs = std::filesystem;

int main(int argc, char *argv[]) {
  if (argc < 2 || argc > 3) {
    std::cerr << "Usage: `remove_node_modules <directory_path> [--dry-run]`\n";
    return 1;
  }

  fs::path base_path(argv[1]);
  bool dry_run = false;

  if (argc == 3) {
    std::string option(argv[2]);
    if (option != "--dry-run") {
      std::cerr << "Unknown option: " << option << "\n";
      return 1;
    }
    dry_run = true;
  }

  remove_node_modules(base_path, dry_run);
  return 0;
}
