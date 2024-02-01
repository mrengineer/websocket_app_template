# Websocket linux application template
Template for linux websocket application

* Reconnect on brocken webcocket
* Fast graph is supported (same author)

Use websocketd

sudo apt install websocketd

1. cmake .
2. make
3. websocketd --port=8080 ./app
4. make app file executable
5. open index.html