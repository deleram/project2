#include "httplib.h"
#include <iostream>
using namespace std;
using namespace httplib;


int main(){
  Server svr;
  string the_matrix[11][11]={{" O "," O "," O "," O "," O "," O "," O "," O "," O "," O "," O "},{" O "," O "," O "," O "," O "," O "," O "," O "," O "," O "," O "},{" O "," O "," O "," O "," O "," O "," O "," O "," O "," O "," O "},{" O "," O "," O "," O "," O "," O "," O "," O "," O "," O "," O "},{" O "," O "," O "," O "," O "," O "," O "," O "," O "," O "," O "},{" O "," O "," O "," O "," O "," O "," O "," O "," O "," O "," O "},{" O "," O "," O "," O "," O "," O "," O "," O "," O "," O "," O "},{" O "," O "," O "," O "," O "," O "," O "," O "," O "," O "," O "},{" O "," O "," O "," O "," O "," O "," O "," O "," O "," O "," O "},{" O "," O "," O "," O "," O "," O "," O "," O "," O "," O "," O "},{" O "," O "," O "," O "," O "," O "," O "," O "," O "," O "," O "}};

  svr.Get("/hi", [](const Request & req , Response &res) {
    res.set_content("Hi", "text/plain");
  });


  svr.Get(R"(/numbers/(\d+))", [&](const Request& req, Response& res) {
    auto numbers = req.matches[1];
    res.set_content(numbers, "text/plain");
  });



   svr.Get("/body-header-param", [](const Request& req, Response& res) {
    if (req.has_header("Content-Length")) {
      auto val = req.get_header_value("Content-Length");
    }
    if (req.has_param("key")) {
      auto val = req.get_param_value("key");
    }
    res.set_content(req.body, "text/plain");
  });


  svr.listen("localhost", 8080);



}


