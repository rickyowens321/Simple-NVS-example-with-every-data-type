# ESP32 NVS (Non-Volatile Storage) Basic Example

This project demonstrates the basic usage of the NVS on the ESP32. It's primarily aimed at beginners and those looking to understand how to store and retrieve values from the NVS.

## Overview:
The Non-Volatile Storage (NVS) on the ESP32 is a way to store data between resets. This example showcases:

* Initializing NVS
* Storing different types of data to NVS:
    + Integers of varying sizes
    + Characters and Strings
    + Float and Double values
* Retrieving the stored data from NVS
* Displaying logs for storage and retrieval operations

## Dependencies:
To run this project, you'll need the following libraries:

* nvs_flash.h: For NVS operations
* nvs.h: For data type definitions related to NVS
* esp_log.h: To display logs
* esp_system.h: For system functions

## Getting Started:
1. Setup: Ensure that you've set up the ESP-IDF environment correctly.
2. Clone & Build: Clone this repository and build the project.
    ```
    idf.py build
    ```
3. Run: Flash the binary to your ESP32.
    ```
    idf.py -p PORT flash monitor
    ```
4. Logs: Monitor the logs to see storage and retrieval operations.
    ```
    idf.py monitor
    ```

## Output:
```
I (405) NVS: The NVS handle was opened sucessfully
I (405) NVS_Storing: The Storing was Successfull of 8-bit
I (405) NVS_Storing: The Storing was Successfull of 16-bit
I (415) NVS_Storing: The Storing was Successfull of 32-bit
I (415) NVS_Storing: The Storing was Successfull of 64-bit
I (425) NVS_Storing: The Storing was Successfull of char
I (425) NVS_Storing: The Storing was Successfull of string
I (435) NVS_Storing: The Storing was Successfull of float
I (445) NVS_Storing: The Storing was Successfull of double
I (445) NVS_Getting: Retrieved int8_t: 127
I (455) NVS_Getting: Retrieved int16_t: 32767
I (455) NVS_Getting: Retrieved int32_t: 2147483647
I (465) NVS_Getting: Retrieved int64_t: 9223372036854775807
I (465) NVS_Getting: Retrieved float: 3.141593
I (475) NVS_Getting: Retrieved double: 3.141593
I (475) NVS_Getting: Retrieved char: A
I (485) NVS_Getting: Retrieved string is: This is the string i am going to store.
```

# Note:
The project contains constant tags like NVS, NVS_Storing, and NVS_Getting which are used in the log messages to identify the source or category of the message.

If you face any issues or errors in NVS operations, they will be displayed in the logs.