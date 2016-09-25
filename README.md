# ardu8266crypo

Some crypto stuff with Arduino on esp8266

1. Diffie–Hellman key exchange

![Diffie–Hellman key exchange](https://upload.wikimedia.org/wikipedia/commons/thumb/1/13/Diffie-Hellman-Schl%C3%BCsselaustausch.svg/400px-Diffie-Hellman-Schl%C3%BCsselaustausch.svg.png)

you need the bcmath module for php
```
sudo apt-get install php-bcmath
```
run the PHP script with the build in Server:
```
php -S 0.0.0.0:8080 src/diffhell_http.php
```
