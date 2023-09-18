/* This exmaple is the basic example of NVS in ESP32 and i show how we can used.
This example is made from ESP32 examples and chatgpt. (Since, i am still in learnig phase.)
So, i read differnt examples and try to build my own one.

This example is just simple use of NVS to store values and reading them.
 */

// these two Libaraies are used to store the values in NVS.
#include "nvs_flash.h"
#include "nvs.h"

// These are esp_Log (to display logs) and esp_system (provide system fucntions like restarting etc)
#include "esp_log.h"
#include "esp_system.h"

static const char* Tag = "NVS";
static const char* Tag1 = "NVS_Storing";
static const char* Tag2 = "NVS_Getting";

void app_main(void)
{
    // Initialize NVS
    esp_err_t err = nvs_flash_init(); // This will init the NVS storge and
    // the return type is the "esp_error" so, we use the "esp_err_t"
    if(err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND)
    // The if statement check if there are no free free or a new version then erase the the nvs storage.
    {
        ESP_ERROR_CHECK(nvs_flash_erase()); // The inner function is used to erase the data and the outer one is used to check
                                            // if any error occurs during erasing.
        err = nvs_flash_init(); // This is again used to re init the NVS stoarge.
    }
    ESP_ERROR_CHECK(err); // The is again used used to check for error during reinit of NVS.

    // These steps are important. because,we need to make sure the NVS is working and will not show any error during writing/reading.

    // Here we will first create a handle. (This will help us to control the NVS better.)

    nvs_handle_t my_nvs_handle; // basiclly, A handler is nothing but a pointer. (its like a pointer to a structure.)
    err = nvs_open("my_storge", NVS_READWRITE, &my_nvs_handle); // the "my_storge" is the namespace, the NVS_READWRITE is the mode we
                                                                // want to open in it. and the last we give it a handle.
    if(err != ESP_OK)
    {
        ESP_LOGE(Tag,"There was a error in the opening the Tag storage");
        return; // we use return to stop the working of esp. so, further error does not pop on screen.
    }
    else
    {
        ESP_LOGI(Tag,"The NVS handle was opened sucessfully");
    }

//-----------------------------------------------------------------------------------------------------------------------
    // Here we will tell u how to write every data type in NVS:
    char my_char_0 = 'A'; // Example of char
    const char* my_char_1 = "This is the string i am going to store."; // Exmaple of String

    int8_t my_value_0 = 127; // Example of 8-bit intergar
    int16_t my_value_1 = 32767; // Example of 16-bit integar 
    int32_t my_value_2 = 2147483647; // Exmaple of 32-bit integar
    int64_t my_value_3 = 9223372036854775807LL; // Exmaple of 64-bit

    float my_float_0 = 3.1415926;
    double my_double_0 = 3.14159265358979323846;

    // This is how u store a int8_t value: 
    err = nvs_set_i8(my_nvs_handle, "my_8-bit",my_value_0); // use nvs_set_i8 to store 8-bit interages and char
    if(err != ESP_OK)
    {
        ESP_LOGE(Tag1,"There was a Error during storing of the 8-bit");
    }
    else
    {
        ESP_LOGI(Tag1, "The Storing was Successfull of 8-bit");
        nvs_commit(my_nvs_handle); // you need to commit to the storage (This is like github commit).
    }

    // This is how u store a int16_t value:
    err = nvs_set_i16(my_nvs_handle, "my_16-bit",my_value_1); // use nvs_set_i16 to store 16-bit
    if(err != ESP_OK)
    {
        ESP_LOGE(Tag1,"There was a Error during storing of the 16-bit");
    }
    else
    {
        ESP_LOGI(Tag1, "The Storing was Successfull of 16-bit");
        nvs_commit(my_nvs_handle);
    }

    // This is how u store a int32_t value:
    err = nvs_set_i32(my_nvs_handle, "my_32-bit",my_value_2); // use nvs_set_i32 to store 32-bit
    if(err != ESP_OK)
    {
        ESP_LOGE(Tag1,"There was a Error during storing of the 32-bit");
    }
    else
    {
        ESP_LOGI(Tag1, "The Storing was Successfull of 32-bit");
        nvs_commit(my_nvs_handle);
    }

    // This is how u store a int64_t or long long value:
    err = nvs_set_i64(my_nvs_handle, "my_64-bit",my_value_3); // use nvs_set_i64 to store 64-bit/long long
    if(err != ESP_OK)
    {
        ESP_LOGE(Tag1,"There was a Error during storing of the 64-bit");
    }
    else
    {
        ESP_LOGI(Tag1, "The Storing was Successfull of 64-bit");
        nvs_commit(my_nvs_handle);
    }

    // This is how u store a char: 
    err = nvs_set_i8(my_nvs_handle, "my_char",my_char_0); // use nvs_set_i8 to store char
    if(err != ESP_OK)
    {
        ESP_LOGE(Tag1,"There was a Error during storing of the char");
    }
    else
    {
        ESP_LOGI(Tag1, "The Storing was Successfull of char");
        nvs_commit(my_nvs_handle); 
    }

    // This is how u store a string:
    err = nvs_set_str(my_nvs_handle, "my_string",my_char_1); // use nvs_set_str to store strings
    if(err != ESP_OK)
    {
        ESP_LOGE(Tag1,"There was a Error during storing of the Storing");
    }
    else
    {
        ESP_LOGI(Tag1, "The Storing was Successfull of string");
        nvs_commit(my_nvs_handle); 
    }

    // This is how u store a float value:
    // The storeing of float and double is kinda different.
    err = nvs_set_blob(my_nvs_handle, "my_float",&my_float_0, sizeof(my_float_0)); // use nvs_set_blob to store float
    if(err != ESP_OK)
    {
        ESP_LOGE(Tag1,"There was a Error during storing of the float");
    }
    else
    {
        ESP_LOGI(Tag1, "The Storing was Successfull of float");
        nvs_commit(my_nvs_handle);
    }

    // This is how u store a double value:
    err = nvs_set_blob(my_nvs_handle, "my_double",&my_double_0, sizeof(my_double_0)); // use nvs_set_blob to store double.
    if(err != ESP_OK)
    {
        ESP_LOGE(Tag1,"There was a Error during storing of the double");
    }
    else
    {
        ESP_LOGI(Tag1, "The Storing was Successfull of double");
        nvs_commit(my_nvs_handle);
    }

//-----------------------------------------------------------------------------------------------------------------------
// Here i will tell u how to read every data type in NVS:

// Note: we can use the same variables to get the values or we can create new ones. Since, creating new will take more
//       memory and we are working with small memory so we will reuse them. (the values will be reasigned to the same variables)

int8_t temp_char;
size_t float_size = sizeof(my_float_0); // the fourth argument needs to be a 
size_t double_size = sizeof(my_double_0); 
size_t length = 0; // this is rquired to get the length of the string first.

// This is how u get a int8_t value: 
    err = nvs_get_i8(my_nvs_handle, "my_8-bit", &my_value_0); // use nvs_get_i8 to get the 8-bit value
    if(err != ESP_OK)
    {
        ESP_LOGE(Tag2,"There was a Error during getting of the 8-bit");
    }
    else
    {
        ESP_LOGI(Tag2, "Retrieved int8_t: %d", my_value_0);
    }

    // This is how u get a int16_t value:
    err = nvs_get_i16(my_nvs_handle, "my_16-bit", &my_value_1); // use nvs_get_i16 to get the 16-bit value
    if(err != ESP_OK)
    {
        ESP_LOGE(Tag2,"There was a Error during getting of the 16-bit");
    }
    else
    {
        ESP_LOGI(Tag2, "Retrieved int16_t: %d",my_value_1);
    }

    // This is how u get a int32_t value:
    err = nvs_get_i32(my_nvs_handle, "my_32-bit", &my_value_2); // use nvs_get_i32 to get the 32-bit value
    if(err != ESP_OK)
    {
        ESP_LOGE(Tag2,"There was a Error during getting of the 32-bit");
    }
    else
    {
        ESP_LOGI(Tag2, "Retrieved int32_t: %d",my_value_2);
    }

    //This is how u get a int64_t or long long value::
    err = nvs_get_i64(my_nvs_handle, "my_64-bit",&my_value_3); // use nvs_get_i64 to get the 64-bit value/long long
    if(err != ESP_OK)
    {
        ESP_LOGE(Tag2,"There was a Error during getting of the 64-bit");
    }
    else
    {
        ESP_LOGI(Tag2,"Retrieved int64_t: %lld", my_value_3);
    }

    // This is how u get a float value:
    err = nvs_get_blob(my_nvs_handle, "my_float",&my_float_0, &float_size); // use nvs_get_blob to get float
    if(err != ESP_OK)
    {
        ESP_LOGE(Tag2,"There was a Error during getting of the float");
    }
    else
    {
        ESP_LOGI(Tag2, "Retrieved float: %f",my_float_0);
    }

    // This is how u get a double value:
    err = nvs_get_blob(my_nvs_handle, "my_double",&my_double_0, &double_size); // use nvs_get_blob to get double.
    if(err != ESP_OK)
    {
        ESP_LOGE(Tag2,"There was a Error during getting of the double");
    }
    else
    {
        ESP_LOGI(Tag2, "Retrieved double: %lf",my_double_0);
    }

    // This is how u get a char: 
    err = nvs_get_i8(my_nvs_handle, "my_char", &temp_char); // use nvs_get_i8 to get the char
    if(err != ESP_OK)
    {
        ESP_LOGE(Tag2,"There was a Error during getting of the char");
    }
    else
    {
        my_char_0 = temp_char;
        ESP_LOGI(Tag2, "Retrieved char: %c", my_char_0);
    }

    // This is how u store a string:
    // we first get the length of the string and them we get the actual string
    err = nvs_get_str(my_nvs_handle, "my_string",  NULL, &length); // use nvs_get_str to get strings
    if (err != ESP_OK) 
    {
        ESP_LOGE(Tag2, "Error getting string length");
        return;
    }

    char* retrieved_str = malloc(length+1);
    if (!retrieved_str)  // checking if there is a error during mallocing the space.
    {
        ESP_LOGE(Tag2, "Memory allocation failed for string retrieval");
        return;
    }

    err = nvs_get_str(my_nvs_handle, "my_string", retrieved_str, &length);
    if (err != ESP_OK) 
    {
        ESP_LOGE(Tag2, "Error reading the string");
        free(retrieved_str);  // Free memory if there was an error
    } 
    else 
    {
        ESP_LOGI(Tag2,"Retrieved string is: %s", retrieved_str);
    }

    free(retrieved_str); // To free up the storage of string in heap.
    nvs_close(my_nvs_handle); // closing the handle

    return;
}
