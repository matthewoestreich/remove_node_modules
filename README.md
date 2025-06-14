# remove_node_modules

Removes **node_modules** folders inside each directory within a specified path.

For example, if you keep your Node.js projects under:

```bash
# "Root" directory
/projects/node/
# Projects inside their own directories
/projects/node/ProjectFoo/...
/projects/node/ProjectBar/...
# etc...
```

You can remove all `node_modules` folders inside each project folder by running:

```bash
remove_node_modules ~/projects/node
```

## Dry Run

To see what would be deleted without actually deleting anything:

```bash
remove_node_modules ~/projects/node --dry-run
```

# How to Compile

You will need:

- CMake (>= 4.0)
- Make

## Configure

From the project root, run one of the following to configure the build (choose your compiler):

```bash
# Configure with clang++
cmake --preset clang

# Configure with g++/gcc
cmake --preset gcc

# Configure with MSVC (Windows)
cmake --preset msvc
```

## Build

After configuring, build with the matching preset:

```bash
# Build with clang++
cmake --build --preset clang

# Build with g++/gcc
cmake --build --preset gcc

# Build with MSVC (Windows)
cmake --build --preset msvc
```
