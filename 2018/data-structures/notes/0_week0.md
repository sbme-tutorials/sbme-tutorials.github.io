---
layout: page
title:  "RPC is Not Dead: Rise, Fall and the Rise of Remote Procedure Calls"
by: "Muzammil Abdul Rehman and Paul Grosu"
---

## Introduction

```XML
POST /RPC2 HTTP/1.0
User-Agent: Frontier/5.1.2 (WinNT)
Host: betty.userland.com
Content-Type: text/xml
Content-length: 181

<?xml version="1.0"?>
<methodCall>
  <methodName>examples.getStateName</methodName>
  <params>
    <param>
      <value><i4>41</i4></value>
    </param>
  </params>
</methodCall>
```

The response to a request will have the `methodResponse` with `params` and values, or a `fault` with the associated `faultCode` in the case of an error {% cite Wiener --file data-structures %}:

```XML
HTTP/1.1 200 OK
Connection: close
Content-Length: 158
Content-Type: text/xml
Date: Fri, 17 Jul 1998 19:55:08 GMT
Server: UserLand Frontier/5.1.2-WinNT

<?xml version="1.0"?>
<methodResponse>
  <params>
    <param>
      <value><string>South Dakota</string></value>
    </param>
  </params>
</methodResponse>
```

SOAP (Simple Object Access Protocol) is a successor of XML-RPC as a web-services protocol for communicating between a client and server. It was initially designed by a group at Microsoft {% cite soaparticle1 --file data-structures %}. The SOAP message is an XML-formatted message composed of an envelope inside which a header and a payload are provided(just like XML-RPC). The payload of the message contains the request and response of the message, which is transmitted over HTTP or SMTP (unlike XML-RPC).

SOAP can be viewed as the superset of XML-RPC that provides support for more complex authentication schemes {% cite soapvsxml --file data-structures %} as well as its support for WSDL (Web Services Description Language), allowing easier discovery and integration with remote web services {% cite soapvsxml --file data-structures %}.


```Scala
import com.twitter.finagle.{Http, Service}
import com.twitter.finagle.http
import com.twitter.util.{Await, Future}

object Server extends App {
  val service = new Service[http.Request, http.Response] {
    def apply(req: http.Request): Future[http.Response] =
      Future.value(
        http.Response(req.version, http.Status.Ok)
      )
  }
  val server = Http.serve(":8080", service)
  Await.ready(server)
}
```

A Filter object transforms requests for further processing in case additional customization is required from a request. These provide program-independent operations like, timeouts, etc. They take in a Service and provide a new Service object with the applied Filter. Aggregating multiple Filters is also possible in Finagle.

A sample timeout Filter that takes in a service and creates a new service with timeouts is shown below. This example is taken from the Finagle documentation {% cite finagletut --file data-structures %}

```Scala
import com.twitter.finagle.{Service, SimpleFilter}
import com.twitter.util.{Duration, Future, Timer}

class TimeoutFilter[Req, Rep](timeout: Duration, timer: Timer)
  extends SimpleFilter[Req, Rep] {

  def apply(request: Req, service: Service[Req, Rep]): Future[Rep] = {
    val res = service(request)
    res.within(timer, timeout)
  }
}
```

<blockquote>
<p align="center">
<em>**RPC is not dead, long live RPC!**</em>
</p>
</blockquote>

## References

{% bibliography --file data-structures --cited %}
