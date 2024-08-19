# curves-task
curves-task is a small C++ program that implements support of a few 3D curves.

## Installation
### Prerequisites
- C++20 compatible compiler
- CMake 3.20 or higher
- Intel TBB library

### Building from source
1. Clone the repository:
    ```sh
    git clone git@github.com:theseChains/curves-task.git
    cd curves-task
    ```

2. Install dependencies:
    - **Ubuntu**:
        ```sh
        sudo apt-get install libtbb2 libtbb-dev
        ```
    - **macOS**:
        ```sh
        brew install tbb
        ```

3. Build the project:
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```
    
### Usage

1. Navigate to the build directory:
    ```sh
    cd build
    ```
2. Navigate to the executable directory:
    ```sh
    cd curves_executable
    ```


3. Run the executable:
    ```sh
    ./curves_executable
    ```
