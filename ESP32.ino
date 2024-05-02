#include <WiFi.h>
#include <WebServer.h>
#define RXD2 16
#define TXD2 17

const char* ssid = "1234";
const char* password = "06102004";

WebServer server(80);
String data = "";
String lcdMessage = "";

void handleRoot() {
  String webpage = "<html><head><script> \
                    function updateSensorData() { \
                      var xhttp = new XMLHttpRequest(); \
                      xhttp.onreadystatechange = function() { \
                        if (this.readyState == 4 && this.status == 200) { \
                          document.getElementById('sensor-data').innerHTML = this.responseText; \
                        } \
                      }; \
                      xhttp.open('GET', '/sensor', true); \
                      xhttp.send(); \
                    } \
                    setInterval(updateSensorData, 1000); \
                    </script></head><body> \
                    <h1>Sensor Data</h1> \
                    <p id='sensor-data'>Loading...</p> \
                    </body></html>";
  server.send(200, "text/html", webpage);
}

void handleSensor() {
  server.send(200, "text/plain", data);
}

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());

  // Set up routes
  server.on("/", handleRoot);
  server.on("/sensor", handleSensor);

  // Start server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // Receive data from Arduino
  if (Serial2.available() > 0) {
    data = Serial2.readStringUntil('\n');
    Serial.print("Data Received :");
    Serial.print(data);
    Serial.print("\n");
    // server.send(200, "text/plain", data);
  }

  server.handleClient();
}
