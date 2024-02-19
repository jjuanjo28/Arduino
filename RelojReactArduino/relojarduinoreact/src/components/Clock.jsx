import { useState, useEffect } from "react";
import io from "socket.io-client";
import axios from "axios";
const socket = io("http://localhost:4000");
const URI = "http://localhost:4000"

export default function Clock() {
const algo = new Date()
  const [clockState, setClockState] = useState(algo.toLocaleTimeString())
  const [seconds, setSeconds] = useState(algo.toLocaleTimeString().slice(6))
  const [minutes, setMinutes] = useState(parseInt(algo.toLocaleTimeString().slice(3,-3)) + 60)
  const [hours, setHours] = useState(parseInt(algo.toLocaleTimeString().slice(0,-6)) + 120)


  useEffect(() => {

    console.log("hora completea: ",clockState)
    console.log("segundos:",seconds)
    console.log("minutos:", minutes)
    console.log("horas: ",hours)

    if(hours >= 133 ){
      console.log("estoy viendo si es mayor", hours-12)
      ajusteReloj(hours-12)
     
    } 
    if(hours < 133) {
      console.log("estoy viendo si es menor", hours)
    
    }
   
  // const ODate = new Date()
    // const Osegundos = parseInt(date.toLocaleTimeString().slice(6,0)) + 120 
    // const Ominutos = parseInt(date.toLocaleTimeString().slice(3,-3)) + 60
    // const Ohoras = parseInt(date.toLocaleTimeString().slice(0,-6)) + 120 
    
    // console.log(Osegundos)
    
    
    setInterval(()=>{
      
      const date = new Date()
      const minutos = parseInt(date.toLocaleTimeString().slice(3,-3)) + 60
      const horas = parseInt(date.toLocaleTimeString().slice(0,-6)) + 120 
     
      setClockState(date.toLocaleTimeString())

      setSeconds(date.toLocaleTimeString().slice(6))
      
      if(minutos.length == 1){
        setMinutes(0+minutos)
      } else {
        setMinutes(minutos)
      }
      if(horas >= 133 ){
        console.log("ajusté la hora desde mas de las 12 useEffect []", horas-12)
        setHours(horas-12)
      } 
      if(horas < 133) {
        console.log("ajusté la hora desde useEffect []", horas)
        setHours(horas)
      }
      ajusteReloj(date.toLocaleTimeString().slice(6))
      console.log(date.toLocaleTimeString().slice(6))
      
    }, 1000)

    
  }, [])

  useEffect(() => {
    console.log("cambie los minutos")
   ajusteReloj(minutes)
  }, [minutes])
  
  useEffect(() => {
    console.log("cambie la hora")
    console.log(hours-12)
    ajusteReloj(hours)
  }, [hours])

function ajusteReloj(data) {
     socket.emit(data)
}
function laUna() {
  axios.get("http://localhost:4000/laUna")
}

   
  return (
    <div>
      Hola soy tu Reloj
      <h1>{clockState}</h1>

      <h2>{hours-120}:{minutes-60}:{seconds}</h2>
      <button onClick={laUna}>la Una</button>
      <button>las Dos</button>
      <button>la Tres</button>
      <button>la Cuatro</button>
 
    </div>
  )
}
