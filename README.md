# lib_netsockets
C++ light wrapper for POSIX and Winsock sockets with implementation of TCP client/server using JSON messages,and HTTP, FTP clients

Dependencies (included)
------------

[GASON++](https://github.com/azadkuh/gason--)
<br /> 


Building from source
------------

Get source:
<pre>
git clone https://github.com/pedro-vicente/lib_netsockets.git
</pre>

Makefile for most Unix systems
------------
Build and test with:
<pre>
make -f makefile
make -f makefile test
</pre>

Building with CMake in Unix
------------
On most Unix systems, the Jansson library is found on the default location with
<pre>
cd build
cmake ..
</pre>

Building with CMake in Windows
------------

For a Windows Visual Studio build a statically build runtime library can be set with. 
<pre>
cmake .. -DSTATIC_CRT:BOOL=ON
</pre>

Visual Studio projects
------------
Available at /msvc

# Usage
lib_netsockets is C++ light wrapper for POSIX and Winsock sockets with implementation of TCP client/server using JSON messages,and HTTP, FTP clients.

# TCP server example
```c++
tcp_server_t server(2000);
while (true)
{
 socket_t socket = server.accept_client();
 handle_client(socket);
 socket.close();
}
server.close();
```

# TCP client example
```c++
tcp_client_t client("127.0.0.1", 2000);
client.open();
client.write(buf, strlen(buf));
client.read_some(buf, sizeof(buf));
client.close();
```

# HTTP client example
```c++
http_t client("www.mysite.com", 80);
client.get("/my/path/to/file", true);
```

# FTP client example
Get file list from FTP server and first file in list
```c++
ftp_t ftp("my.ftp.site", 21);
ftp.login("my user", "anonymous");
ftp.get_file_list();
ftp.get_file(ftp.m_file_nslt.at(0).c_str());
ftp.logout();
```



