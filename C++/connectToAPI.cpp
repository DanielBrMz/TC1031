#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <curl/curl.h>

size_t write_callback(char *ptr, size_t size, size_t nmemb, std::string *userdata) {
    userdata->append(ptr, size * nmemb);
    return size * nmemb;
}

std::vector<int> sort_vector(std::vector<int> unsortedVector, std::string endPoint) {
    // Set up curl
    CURL *curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize curl" << std::endl;
        exit(1);
    }

    // Set up the URL and headers
    struct curl_slist *headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    // Set up the POST data
    std::string post_data = "{\"vector\": [";
    for (size_t i = 0; i < unsortedVector.size(); i++) {
        post_data += std::to_string(unsortedVector[i]);
        if (i != unsortedVector.size() - 1) {
            post_data += ", ";
        }
    }
    post_data += "]}";

    // Set up the response buffer
    std::string response;

    // Set up the curl options
    curl_easy_setopt(curl, CURLOPT_URL, endPoint.c_str());
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
    std::vector<int> sortedVector;
    size_t start = response.find('[');
    size_t end = response.find(']');
    if (start != std::string::npos && end != std::string::npos && start < end) {
        std::string numbers = response.substr(start + 1, end - start - 1);
        size_t pos = 0;
        while ((pos = numbers.find(',')) != std::string::npos) {
            sortedVector.push_back(std::stoi(numbers.substr(0, pos)));
            numbers.erase(0, pos + 1);
        }
        sortedVector.push_back(std::stoi(numbers));
    }

    return sortedVector;
}

std::vector<int> readInput(std::string path){
  // read in.txt
  std::ifstream file(path);
  std::string line;

  // first line is the number of elements that vector contains
  std::getline(file, line);
  int numberOfElements = std::stoi(line);

  // vector to store the elements read until the number of elements is equal to numberOfElements
  std::vector<int> unsortedVector;
  for (int i = 0; i < numberOfElements; i++){
    std::getline(file, line);
    unsortedVector.push_back(std::stoi(line));
  }

  return unsortedVector;
}

int main() {    
    const std::string endPoint = "http://127.0.0.1:8080/ordenamientoIntercambio";
    std::vector<int> unsortedVector = readInput("in.txt");

    // Print the unsorted vector
    std::cout << "Unsorted vector: [";
    for (size_t i = 0; i < unsortedVector.size(); i++) {
        std::cout << unsortedVector[i];
        if (i != unsortedVector.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    // Sort the vector
    std::vector<int> sortedVector = sort_vector(unsortedVector, endPoint);

     // Print the sorted vector
     std::cout << "Sorted vector: [";
     for (size_t i = 0; i < sortedVector.size(); i++) {
         std::cout << sortedVector[i];
         if (i != sortedVector.size() - 1) {
             std::cout << ", ";
         }
     }
     std::cout << "]" << std::endl;

     return 0;
}
