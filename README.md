# 🗨️ Chat Client-Server Application in C++ (WinSock)

This is a basic TCP-based Chat Client and Server application written in C++ using the Windows Sockets API (WinSock). The client connects to the server, sends a message, and the server receives and prints it.

---

## 📁 Project Structure

```
Chat-App/
├── Chat-App-Client.cpp   # Client-side code
├── Chat-App-Server.cpp   # Server-side code
├── README.md             # Documentation
```

---

## 🛠️ Prerequisites

- Windows OS
- Visual Studio (any version that supports C++)
- Basic understanding of sockets and networking

---

## 🚀 How to Run

### 1. Build the Server

- Open **Chat-App-Server.cpp** in Visual Studio.
- Build the project (`Ctrl+Shift+B`).
- Run the executable (`Ctrl+F5` or click **Start Without Debugging**).

You should see:
```
Server has started listening on port: 12345
```

---

### 2. Build the Client

- Open **Chat-App-Client.cpp** in another Visual Studio project.
- Build and run the client.

You should see:
```
Connection with server is successful
client code
```

And on the server side:
```
Message from client: Hello there
```

---

## 🧠 How It Works

### 🔌 Server

1. Initializes WinSock.
2. Creates a listening socket on port `12345`.
3. Binds to `127.0.0.1` (loopback).
4. Listens and accepts incoming connections.
5. Receives message from the client and prints it.

### 📤 Client

1. Initializes WinSock.
2. Connects to server at `127.0.0.1:12345`.
3. Sends a message (`"Hello there"`).
4. Closes the connection.

---

## 📄 Sample Output

### Server Console:
```
Server has started listening on port: 12345
Message from client: Hello there
```

### Client Console:
```
Connection with server is successful
client code
```

---

## ⚠️ Troubleshooting

- **Run server before client.**
- Make sure firewall or antivirus isn't blocking connections.
- Use correct IP and port (`127.0.0.1`, `12345`).
- If connection fails, print `WSAGetLastError()` for debugging.
- Always call `WSACleanup()` after closing sockets.

---

## ✅ Future Improvements

- Add message exchange in both directions (bi-directional chat).
- Use threads to handle multiple clients.
- Add proper UI using Win32 or Qt.
- Integrate encryption or authentication.

---

## 📜 License

This project is for educational purposes only.

---

## ✍️ Author

**Aditi Jain**
