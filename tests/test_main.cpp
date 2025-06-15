#define CATCH_CONFIG_MAIN

#include <catch2/catch_all.hpp>
#include <filesystem>
#include <fstream>

#include "remove_node_modules.hpp"

namespace fs = std::filesystem;

const fs::path TEMP_DIRECTORY_PATH = "./";

TEST_CASE("Removal") {
  fs::path tmp_dir = TEMP_DIRECTORY_PATH / "test_project";
  fs::create_directories(tmp_dir / "ProjectA" / "node_modules");
  fs::create_directories(tmp_dir / "ProjectB" / "node_modules");
  // create some dummy files inside
  std::ofstream(tmp_dir / "ProjectA" / "node_modules" / "dummy.txt").put('a');

  SECTION("should remove node_modules") {
    REQUIRE(fs::exists(tmp_dir / "ProjectA" / "node_modules"));
    REQUIRE(fs::exists(tmp_dir / "ProjectB" / "node_modules"));
    remove_node_modules(tmp_dir, /*dry_run=*/false);
    REQUIRE_FALSE(fs::exists(tmp_dir / "ProjectA" / "node_modules"));
    REQUIRE_FALSE(fs::exists(tmp_dir / "ProjectB" / "node_modules"));
  }

  fs::remove_all(tmp_dir);
}
