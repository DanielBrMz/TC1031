#include <iostream>
#include <vector>
#include <string>
#include <curl/curl.h>

size_t write_callback(char *ptr, size_t size, size_t nmemb, std::string *userdata) {
    userdata->append(ptr, size * nmemb);
    return size * nmemb;
}

std::vector<int> sort_vector(std::vector<int> unsorted_vector) {
    // Set up curl
    CURL *curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize curl" << std::endl;
        exit(1);
    }

    // Set up the URL and headers
    std::string url = "http://127.0.0.1:8080/ordenamientoIntercambio";
    struct curl_slist *headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    // Set up the POST data
    std::string post_data = "{\"vector\": [";
    for (size_t i = 0; i < unsorted_vector.size(); i++) {
        post_data += std::to_string(unsorted_vector[i]);
        if (i != unsorted_vector.size() - 1) {
            post_data += ", ";
        }
    }
    post_data += "]}";

    // Set up the response buffer
    std::string response;

    // Set up the curl options
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    // Perform the request
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "Failed to perform request: " << curl_easy_strerror(res) << std::endl;
        exit(1);
    }

    // Clean up
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    // Convert response to vector
    std::vector<int> sorted_vector;
    size_t start = response.find('[');
    size_t end = response.find(']');
    if (start != std::string::npos && end != std::string::npos && start < end) {
        std::string numbers = response.substr(start + 1, end - start - 1);
        size_t pos = 0;
        while ((pos = numbers.find(',')) != std::string::npos) {
            sorted_vector.push_back(std::stoi(numbers.substr(0, pos)));
            numbers.erase(0, pos + 1);
        }
        sorted_vector.push_back(std::stoi(numbers));
    }

    return sorted_vector;
}

int main() {
    std::vector<int> unsorted_vector = {5, 42, 7, 13, 9, 87, 63, 22};
    
    // Print the unsorted vector
    std::cout << "Unsorted vector: [";
    for (size_t i = 0; i < unsorted_vector.size(); i++) {
        std::cout << unsorted_vector[i];
        if (i != unsorted_vector.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    // Sort the vector
    std::vector<int> sorted_vector = sort_vector(unsorted_vector);

     // Print the sorted vector
     std::cout << "Sorted vector: [";
     for (size_t i = 0; i < sorted_vector.size(); i++) {
         std::cout << sorted_vector[i];
         if (i != sorted_vector.size() - 1) {
             std::cout << ", ";
         }
     }
     std::cout << "]" << std::endl;

     return 0;
}
