#include <WiFi.h>
#include <ESPAsyncWebServer.h>

const char *ssid = "your-ssid";      // Change it to your WiFi SSID
const char *password = "your-password";  // Change it to your WiFi password

const char *htmlContent = R"(
  <!DOCTYPE html>
  <html lang="en">
  <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Home | Filippo Berti</title>
      <meta name="author" content="Filippo Berti">
      <meta name="description" content="Personal Website Portfolio">
      <link href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.3/css/all.min.css" rel="stylesheet">
      <style>
          body {
              background-color: white;
              font-family: "Helvetica Neue", Helvetica, Arial, sans-serif;
              display: flex;
              flex-direction: column;
              align-items: center;
              text-align: center;
              padding: 20px;
              max-width: 560px; /* Set the maximum width for the centered content */
              margin: 0 auto; /* Center the content horizontally */
          }
  
          h1, h2 {
              color: #222;
          }
  
          h1 {
              font-size: 2.6rem;
              font-weight: 700;
          }
  
          h2 {
              font-size: 1.4rem;
          }
          h3 {
              font-weight: 500;
              color: #9a9a9a;
          }
  
          p {
              line-height: 1.7;
              color: #666;
              font-weight: 300;
              margin-bottom: 20px;
              letter-spacing: .4px;
              font-size: 0.8rem;
          }
          li {
              line-height: 1.7;
              color: #666;
              font-weight: 300;
              letter-spacing: .4px;
              font-size: 0.8rem;
              margin-bottom: 3px;
          }
          a {
              text-decoration: none;
              color: #222;
              font-weight: 500;
          }
          .profile-image {
              width: 125px;
              height: 125px;
              border-radius: 50%;
              overflow: hidden;
              margin-bottom: 20px;
              margin-top: 70px;
          }
          .profile-image img {
              width: 100%;
              height: 100%;
              object-fit: cover;
          }
          footer {
              margin-top: 10px;
              margin-bottom: 10px;
          }
      </style>
  </head>
  <body>
      <div class="profile-image">
          <!-- Please replace "githubimageurllink" with the URL of your profile image(You can upload it on the repository and copy the link) -->
          <img src="githubimageurllink" alt="Profile Image">
      </div>
      <h1>Filippo Berti</h1>
      <h3 style="margin-top: 0;">Software Developer</h3>
      <div style="display: inline;">
          <!-- Social Icons -->
          <i class="fab fa-twitter" style="  margin: 0 10px;"></i>
          <i class="fab fa-linkedin-in" style="  margin: 0 10px;"></i>
          <i class="fab fa-github" style="  margin: 0 10px;"></i>
      </div>
      <section style="margin-top: 50px;">
          <h2>About</h2>
          <hr> 
          <p style="text-align: left;">
              Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.
          </p>
      </section>
  
      <section style="width:100%;">
          <h2>Skills</h2>
          <hr> 
          <div style="text-align: left;">
          <ul>
              <li>HTML, Jade</li>
              <li>CSS (Stylus, Sass, Less)</li>
              <li>Javascript, NodeJS</li>
              <li>AngularJS, ReactJS</li>
              <li>Java, Android</li>
              <li>Python</li>
              <li>MySQL - MongoDB</li>
              <li>Git</li>
          </ul>
          </div>
      </section>
  
      <section>
          <h2>Projects</h2>
          <hr> 
          <div style="text-align: left;">
              <div>
                  <a href="https://docs.searxng.org/"><h3>Eve</h3></a>
                  <p>Ultra Minimal Single-page Jekyll Template for Building Personal Portfolio Websites</p>
              </div>
              <div>
                  <a href="https://docs.searxng.org/"><h3>World Cup History</h3></a>
                  <p>npm package for FIFA World cup historical data</p>
              </div>
              <div>
                  <a href="https://docs.searxng.org/"><h3>Tweeter</h3></a>
                  <p>A Twitter inspired web application built with Angular 5</p>
              </div>
              <div>
                  <a href="https://docs.searxng.org/"><h3>Transcend</h3></a>
                  <p>An android app for meditation and mindfulness</p>
              </div>
          </div>
          <hr> 
      </section>
  
      <footer>
          <p>&copy; 2024 Filippo Berti. All Rights Reserved.</p>
      </footer>
  </body>
  </html>
)";

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Route for the root page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", htmlContent);
  });

  // Start server
  server.begin();
}

void loop() {
  // Nothing to do here
}
