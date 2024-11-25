#include "crow/http_response.h"
#include "crow/json.h"
#include <optional>

#define CROW_MAIN

#include "crow.h"

crow::json::wvalue error2json(const std::string &errstring) {
  crow::json::wvalue r;
  r["error"] = errstring;
  return r;
}

int main() {
  crow::SimpleApp app;

  CROW_ROUTE(app, "/hello").methods(crow::HTTPMethod::Get)
      ([]() {

        return "hello";
      });

  CROW_ROUTE(app, "/hello/json").methods(crow::HTTPMethod::Get)
      ([]() {
        crow::json::wvalue response;
        response["msg"] = "hello";
        return response;
      });

  CROW_ROUTE(app, "/add/<int>/<int>").methods(crow::HTTPMethod::Get)
      ([](const crow::request & /*req*/, int a, int b) {
        int c = a + b;
        crow::json::wvalue response;
        response["result"] = c;
        return response;
      });

  CROW_ROUTE(app, "/hello/<string>").methods(crow::HTTPMethod::Get)
      ([](const crow::request & /*req*/, std::string name) {

        crow::json::wvalue response;
        response["result"] = name;
        return response;
      });

  app.port(18080).run();

}
