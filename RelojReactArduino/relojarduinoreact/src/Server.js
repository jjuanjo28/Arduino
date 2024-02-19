import express from "express"
import {SerialPort, ReadlineParser} from "serialport";
import { Server } from "socket.io"
import http from "http"


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


const portName = "COM3";

io.on("connection",(socket)=>{
   console.log("a user connected")
   socket.on("01",()=>{arduino.write("1")})
   socket.on("02",()=>{arduino.write("2")})
   socket.on("03",()=>{arduino.write("3")})
   socket.on("04",()=>{arduino.write("4")})
   socket.on("05",()=>{arduino.write("5")})
   socket.on("06",()=>{arduino.write("6")})
   socket.on("07",()=>{arduino.write("7")})
   socket.on("08",()=>{arduino.write("8")})
   socket.on("09",()=>{arduino.write("9")})
   socket.on("10",()=>{arduino.write("10")})
   socket.on("11",()=>{arduino.write("11")})
   socket.on("12",()=>{arduino.write("12")})
   socket.on("13",()=>{arduino.write("13")})
   socket.on("14",()=>{arduino.write("14")})
   socket.on("15",()=>{arduino.write("15")})
   socket.on("16",()=>{arduino.write("16")})
   socket.on("17",()=>{arduino.write("17")})
   socket.on("18",()=>{arduino.write("18")})
   socket.on("19",()=>{arduino.write("19")})
   socket.on("20",()=>{arduino.write("20")})
   socket.on("21",()=>{arduino.write("21")})
   socket.on("22",()=>{arduino.write("22")})
   socket.on("23",()=>{arduino.write("23")})
   socket.on("24",()=>{arduino.write("24")})
   socket.on("25",()=>{arduino.write("25")})
   socket.on("26",()=>{arduino.write("26")})
   socket.on("27",()=>{arduino.write("27")})
   socket.on("28",()=>{arduino.write("28")})
   socket.on("29",()=>{arduino.write("29")})
   socket.on("30",()=>{arduino.write("30")})
   socket.on("31",()=>{arduino.write("31")})
   socket.on("32",()=>{arduino.write("32")})
   socket.on("33",()=>{arduino.write("33")})
   socket.on("34",()=>{arduino.write("34")})
   socket.on("35",()=>{arduino.write("35")})
   socket.on("36",()=>{arduino.write("36")})
   socket.on("37",()=>{arduino.write("37")})
   socket.on("38",()=>{arduino.write("38")})
   socket.on("39",()=>{arduino.write("39")})
   socket.on("40",()=>{arduino.write("40")})
   socket.on("41",()=>{arduino.write("41")})
   socket.on("42",()=>{arduino.write("42")})
   socket.on("43",()=>{arduino.write("43")})
   socket.on("44",()=>{arduino.write("44")})
   socket.on("45",()=>{arduino.write("45")})
   socket.on("46",()=>{arduino.write("46")})
   socket.on("47",()=>{arduino.write("47")})
   socket.on("48",()=>{arduino.write("48")})
   socket.on("49",()=>{arduino.write("49")})
   socket.on("50",()=>{arduino.write("50")})
   socket.on("51",()=>{arduino.write("51")})
   socket.on("52",()=>{arduino.write("52")})
   socket.on("53",()=>{arduino.write("53")})
   socket.on("54",()=>{arduino.write("54")})
   socket.on("55",()=>{arduino.write("55")})
   socket.on("56",()=>{arduino.write("56")})
   socket.on("57",()=>{arduino.write("57")})
   socket.on("58",()=>{arduino.write("58")})
   socket.on("59",()=>{arduino.write("59")})
   socket.on("60",()=>{arduino.write("60")})
   socket.on("61",()=>{arduino.write("61")})
   socket.on("62",()=>{arduino.write("62")})
   socket.on("63",()=>{arduino.write("63")})
   socket.on("64",()=>{arduino.write("64")})
   socket.on("65",()=>{arduino.write("65")})
   socket.on("66",()=>{arduino.write("66")})
   socket.on("67",()=>{arduino.write("67")})
   socket.on("68",()=>{arduino.write("68")})
   socket.on("69",()=>{arduino.write("69")})
   socket.on("70",()=>{arduino.write("70")})
   socket.on("71",()=>{arduino.write("71")})
   socket.on("72",()=>{arduino.write("72")})
   socket.on("73",()=>{arduino.write("73")})
   socket.on("74",()=>{arduino.write("74")})
   socket.on("75",()=>{arduino.write("75")})
   socket.on("76",()=>{arduino.write("76")})
   socket.on("77",()=>{arduino.write("77")})
   socket.on("78",()=>{arduino.write("78")})
   socket.on("79",()=>{arduino.write("79")})
   socket.on("80",()=>{arduino.write("80")})
   socket.on("81",()=>{arduino.write("81")})
   socket.on("82",()=>{arduino.write("82")})
   socket.on("83",()=>{arduino.write("83")})
   socket.on("84",()=>{arduino.write("84")})
   socket.on("85",()=>{arduino.write("85")})
   socket.on("86",()=>{arduino.write("86")})
   socket.on("87",()=>{arduino.write("87")})
   socket.on("88",()=>{arduino.write("88")})
   socket.on("89",()=>{arduino.write("89")})
   socket.on("90",()=>{arduino.write("90")})
   socket.on("91",()=>{arduino.write("91")})
   socket.on("92",()=>{arduino.write("92")})
   socket.on("93",()=>{arduino.write("93")})
   socket.on("94",()=>{arduino.write("94")})
   socket.on("95",()=>{arduino.write("95")})
   socket.on("96",()=>{arduino.write("96")})
   socket.on("97",()=>{arduino.write("97")})
   socket.on("98",()=>{arduino.write("98")})
   socket.on("99",()=>{arduino.write("99")})
   socket.on("100",()=>{arduino.write("100")})
   socket.on("101",()=>{arduino.write("101")})
   socket.on("102",()=>{arduino.write("102")})
   socket.on("103",()=>{arduino.write("103")})
   socket.on("104",()=>{arduino.write("104")})
   socket.on("105",()=>{arduino.write("105")})
   socket.on("106",()=>{arduino.write("106")})
   socket.on("107",()=>{arduino.write("107")})
   socket.on("108",()=>{arduino.write("108")})
   socket.on("109",()=>{arduino.write("109")})
   socket.on("110",()=>{arduino.write("110")})
   socket.on("111",()=>{arduino.write("111")})
   socket.on("112",()=>{arduino.write("112")})
   socket.on("113",()=>{arduino.write("113")})
   socket.on("114",()=>{arduino.write("114")})
   socket.on("115",()=>{arduino.write("115")})
   socket.on("116",()=>{arduino.write("116")})
   socket.on("117",()=>{arduino.write("117")})
   socket.on("118",()=>{arduino.write("118")})
   socket.on("119",()=>{arduino.write("119")})
   socket.on("120",()=>{arduino.write("120")})



   // socket.on("121",()=>{arduino.write("121")
   //                      console.log("me esta pidiendo la 1!!!!")})
   // socket.on("122",()=>{arduino.write("122")
   //                      console.log("me esta pidiendo las 2")})
   // socket.on("123",()=>{arduino.write("123")})
   // socket.on("124",()=>{arduino.write("124")})
   // socket.on("125",()=>{arduino.write("125")})
   // socket.on("126",()=>{arduino.write("126")})
   // socket.on("127",()=>{arduino.write("127")})
   // socket.on("128",()=>{arduino.write("128")})
   // socket.on("129",()=>{arduino.write("129")})
   // socket.on("130",()=>{arduino.write("130")})
   // socket.on("131",()=>{arduino.write("131")})
   // socket.on("132",()=>{arduino.write("132")})


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

app.get("laUna", ()=>{
   console.log("accedi")
   arduino.write("121")
})

app.get("lasDos", ()=>{
   arduino.write("122")
})

app.get("lasTres", ()=>{
   arduino.write("123")
})

app.get("lasCuatro", ()=>{
   arduino.write("124")
})