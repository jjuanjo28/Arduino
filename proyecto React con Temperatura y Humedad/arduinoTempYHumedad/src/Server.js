import express from "express"
import {SerialPort, ReadlineParser} from "serialport";
import { Server } from "socket.io"
import http from "http"

import serveStatic from "serve-static"
import cors from "cors"


const app = express();
const port = 4000;

const server = http.createServer(app)
const io =new Server(server, {
   cors: {
      origin:"*"
   }
})

app.use(cors())

const portName = "COM13";

io.on("connection",(socket)=>{
   console.log("a user connected")
   socket.on("enciendeAmarillo",()=>{arduino.write("1")
             console.log("enciendeAmarillo")})
   socket.on("apagaAmarillo",()=>{arduino.write("2")})
   socket.on("enciendoRojo",()=>{arduino.write("3")})
   socket.on("apagoRojo",()=>{arduino.write("4")})
 
     const parser = new ReadlineParser()
     arduino.pipe(parser)
     arduino.on("data",data=>{
      const text = data.toString("utf-8")
      socket.emit("text",text)
     } )

})

server.listen(port, () => {
   console.log("Servidor escuchando en http//:", port);
})


const arduino = new SerialPort({
    path: portName,
    baudRate: 9600,
    dataBits:8,
    stopBits:1,
    parity: "none",
  })



