


const { Server } = require("socket.io")
const express = require("express")
const http = require("http")

const cors = require("cors")




const app = express()
const server = http.createServer(app);
const io =new Server(server)

app.use(express.static("public"))
app.use(cors())

server.listen(3000, function(){
   console.log("server listening on port", 3000) 
})



const {SerialPort , ReadlineParser} = require("serialport")

const port = new SerialPort({
    path:"COM12", 
    baudRate: 115200,
    dataBits: 8,
    stopBits: 1,
    parity: 'none',
});

const parser = new ReadlineParser()

port.pipe(parser)

parser.on("open", function () {
    console.log("conection is openend")
})



io.on("connection", function (socket) {
  console.log("client connected")
  
  parser.on("data", (line)=>{
      io.emit("temp",line)
      console.log("soy temp:",line)
      io.emit("text",line)
      console.log("soy text:",line)
   })
    socket.on("encender", function () {
      port.write("1")
      
    })
  
    socket.on("apagar", function () {
      port.write("2")
     
    })
    socket.on("enciendeAmarillo", function(){
      port.write("3")
      
    })
    socket.on("apagaAmarillo", function(){
      port.write("4")
     
    })
    socket.on("enciendeRojo", function(){
      port.write("5")
     
    })
    socket.on("apagaRojo", function(){
      port.write("6")
     
    })
  })







