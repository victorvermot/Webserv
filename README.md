# Webserv
Webserv is a project that simulates the behaviour of Web servers receiving HTTP requests.
<br>
<br>
<h1>HTTP</h1>
HTTP (Hypertext Transfer Protocol) is the way used by the World Wide Web to send informations to a client. It is a layer of the Internet protocol suite (TPC/IP), the set of communication protocols of the internet. Those protocoles specify how data are packetized, addressed, transmitted, routed and reiceived. The protocol is separated in four different layers.
(TODO: Faire un repo pour approfondir les notions sur les layers)

## TPC/IP layers

  1. The Link Layer
  2. The Internet Layer
  3. The Transport Layer
  4. The application layer (**HTTP**)


Web Browsers are clients sending HTTP request to Web servers. The servers receive the requests and proccess them.
<br>Here is an example of HTTP request:

    GET /hello.htm HTTP/1.1
    User-Agent: Mozilla/4.0 (compatible; MSIE5.01; Windows NT)
    Host: www.tutorialspoint.com
    Accept-Language: en-us
    Accept-Encoding: gzip, deflate
    Connection: Keep-Alive
