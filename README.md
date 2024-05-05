# Ride Management System

## Overview

The Ride Management System is a C++ application designed to facilitate the management of ride-sharing services. It enables passengers to book rides, drivers to fulfill them, and administrators to oversee operations.

# Demo
![Demo](https://github.com/abawan7/ride-management-system/blob/main/Demo.gif)

## Prerequisites

- A C++ compiler (e.g., GCC).
- A compatible development environment.

## Key Features

1. **Booking Management**:
   - Add or retrieve ride booking information.
   - Set or update booking statuses.

2. **Service Class**:
   - Source and destination locations.
   - Distance traveled.
   - Booking date and time.
   - Status (pending/completed).
   - Customer, driver, and vehicle IDs.

3. **Ride Class**:
   - Derived from `Service`.
   - Adds ride type, passenger count, and rankings.

4. **Other Utilities**:
   - Name, Date, and Time classes to manage respective attributes.
   - Streamlined input/output with overloaded operators.

## Setup & Usage

1. **Clone the Repository**
   ```sh
   git clone https://github.com/abawan7/ride-management-system.git
   ```

2. **Compilation**: Make sure a C++ compiler is installed. Compile using:

    ```bash
    g++ -o ride_management TMS.cpp
    ```

3. **Execution**: Run the compiled program:

    ```bash
    ./ride_management
    ```

3. **Interaction**: Follow the interactive prompts to add drivers, passengers, book rides, and view ride statuses.

## License

This project is licensed under the MIT License.
