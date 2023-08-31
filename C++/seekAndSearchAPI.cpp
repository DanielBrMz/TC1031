#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "crow.h"

std::vector<int> ordenamientoIntercambio(std::vector<int> vector){
  int aux;
  for (std::vector<int>::size_type i = 0; i < vector.size() - 1; i++){
    for (std::vector<int>::size_type  j = i + 1; j < vector.size(); j++){
      if (vector[i] > vector[j]){
        aux = vector[i];
        vector[i] = vector[j];
        vector[j] = aux;
      }
    }
  }
  return vector;
}

int main() {
    crow::SimpleApp app;

   
    CROW_ROUTE(app, "/ordenamientoIntercambio").methods("POST"_method)
        ([](const auto& req)
          {
            auto body = crow::json::load(req.body);
            if (!body) {
                return crow::response(400);
            }
          std::vector<int> vector;
          for (const auto& element : body["vector"]) {
              vector.push_back(element.i());
          }
          std::vector<int> result = ordenamientoIntercambio(vector);
          crow::json::wvalue response;
          response["result"] = result;
          return crow::response(response);
        });

    app.bindaddr("127.0.0.1").port(8080).run();
}