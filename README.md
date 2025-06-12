# QCalculator

QCalculator is a configurable calculator application that can be built with GUI and/or CLI support.

## Build the project

There are two ways to build the project: using the `install.sh` script or manual CMake configuration.

### 1. Build with `install.sh`

Use the provided Bash script to configure and generate the build system.

```bash
bash install.sh BUILD_GUI=ON BUILD_CLI=ON
```

Available options:

- `BUILD_GUI=ON` — enables the graphical user interface
- `BUILD_CLI=ON` — enables the command-line interface

You must enable at least one of the two components.

### 2. Manual build with CMake

Alternatively, configure and build the project manually:

```bash
mkdir build
cd build
cmake .. -DBUILD_GUI=ON -DBUILD_CLI=OFF
make -j$(nproc)
```

Pass any combination of the following flags to `cmake`:

- `-DBUILD_GUI=ON`
- `-DBUILD_CLI=ON`

At least one of these must be set to `ON`.

