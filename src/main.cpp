#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <DiffieHellman.h>

MDNSResponder mdns;

const char* ssid     = "WLAN";
const char* password = "PWD";

IPAddress host(172,23,1,112);
const int httpPort = 8080;

ESP8266WebServer server(80);

const int led = D0;

void handleRoot() {
  digitalWrite(led, 1);
  server.send(200, "text/plain", "hello from esp8266!");
  digitalWrite(led, 0);
}

void handleDH(){
  Serial.print("connecting to ");
  Serial.println(host.toString());

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  client.setTimeout(10000);

  if (client.connect(host, httpPort)) {

    DiffieHellman dh;
    // We now create a URI for the request
    char * s = dh.getB().toString();
    String msgString(s);

    String url = "/?B=";
    url += s;
    free (s);

    Serial.print("Requesting URL: ");
    Serial.println(url);

    // This will send the request to the server
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                        "Host: " + host + "\r\n" +
                        "Connection: close\r\n\r\n");
    int i=0;
    while((!client.available()) && (i<1000)){
      delay(100);
      Serial.print(".");
      digitalWrite(led, !digitalRead(led));
      i++;
    }

    // Read all the lines of the reply from server and print them to Serial
    String lines = "";
    while(client.available()){
      Serial.print(".");
      digitalWrite(led, !digitalRead(led));
      lines += client.readStringUntil('\r');
    }
    digitalWrite(led, 1);

    Serial.println();
    Serial.println("closing connection");
    server.send(200, "text/plain", "done");

    Serial.print("A:");
    Serial.println(lines);
    Serial.println("exchange...");

    //dh.exchange(lines);

    //Serial.print("K:");
    //char * k = dh.getK().toString ();
    //Serial.println (k);
    //free (k);
  }
  else{
    Serial.println("connection failed");
    return;
  }
}


void handleNotFound(){
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}

void setup(void){
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);
  server.on("/dh/", handleDH);

  server.on("/inline", [](){
    server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
