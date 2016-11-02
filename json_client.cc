#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <jansson.h>
#include "socket.hh"

///////////////////////////////////////////////////////////////////////////////////////
//main
//TCP client that writes and reads JSON messages 
///////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
  //make JSON
  json_t *request = json_object();
  json_object_set_new(request, "start_year", json_integer(2016));

  json_dump_file(request, "request.json", JSON_PRESERVE_ORDER);

  tcp_client_t client("127.0.0.1", 2000);

  /////////////////////////////////////////////////////////////////////////////////////////////////////
  //create socket and open connection
  /////////////////////////////////////////////////////////////////////////////////////////////////////

  client.open();

  /////////////////////////////////////////////////////////////////////////////////////////////////////
  //write request
  /////////////////////////////////////////////////////////////////////////////////////////////////////

  client.write(request);

  /////////////////////////////////////////////////////////////////////////////////////////////////////
  //read response
  /////////////////////////////////////////////////////////////////////////////////////////////////////

  json_t *response = client.read();

  //parse JSON
  json_t *json_obj;
  json_obj = json_object_get(response, "next_year");
  json_int_t next_year = json_integer_value(json_obj);
  std::cout << "client received: " << std::endl;
  std::cout << "next_year: " << next_year << std::endl;

  /////////////////////////////////////////////////////////////////////////////////////////////////////
  //close connection
  /////////////////////////////////////////////////////////////////////////////////////////////////////

  client.close();

  return 0;
}


