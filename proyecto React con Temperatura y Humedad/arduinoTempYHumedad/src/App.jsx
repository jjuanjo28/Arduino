import { useState, useEffect } from "react";
import io from "socket.io-client";
import backgroundImage from "../src/images/arduinoFondo.jpg"
const socket = io("http://localhost:4000");

function App() {
  const [ledRedOn, setLedRedOn] = useState(false);
  const [ledYellowOn, setLedYellowOn] = useState(false);
  const [temperatura, setTemperatura] = useState(0);
  const [humedad, setHumedad] = useState(0);
  const [temperaturaCorte, setTemperaturaCorte] = useState(25)
  const [humedadCorte, setHumedadCorte] = useState(25)
  const [connected, setConnected] = useState(false)

  useEffect(() => {
   

  }, []);

  const styleBoxDanger = {color:"red", border:"solid 2px", backgroundColor:"white", borderRadius:"10px", height:"100px", width:"100%", padding:"25px"}
  const styleBoxNomal = {color:"blue", border:"solid 2px", backgroundColor:"#5ae3f9", borderRadius:"10px", height:"100px", padding:"25px"}
  const styleDataNormal = {color:"green", border:"solid 2px", backgroundColor:"white", borderRadius:"10px", height:"100px", width:"100%", padding:"25px"}
  const styleDataDanger = {color:"white", border:"solid 2px", backgroundColor:"Red", borderRadius:"10px", height:"100px", padding:"15px", textAlign:"center"}

  function prenderRedLed() {
    setLedRedOn(true);
    socket.emit("enciendoRojo");
    console.log("enciendoRojo");
  }

  function apagarRedLed() {
    setLedRedOn(false);
    socket.emit("apagoRojo");
    console.log("apagoRojo");
  }
  function prenderYellowLed() {
    setLedYellowOn(true);
    socket.emit("enciendoAmarillo");
    console.log("enciendoAmarillo");
  }
  function apagarYellowLed() {
    setLedYellowOn(false);
    socket.emit("apagoAmarillo");
    console.log("apagoAmarillo");
  }

  function apagarAmbosLed() {
    setLedRedOn(false);
    setLedYellowOn(false);
    apagarRedLed();
    apagarYellowLed();
  }
  function prenderAmbosLed() {
    prenderRedLed();
    prenderYellowLed();
  }

  function conectarArduino() {
    socket.on("text", (text) => {
          text.length == 20 ? setTemperatura(parseFloat(text.slice(12))) : setHumedad(parseFloat(text.slice(9)));
   });
   setConnected(true)
  }

  function cargaTemp(e) {
   e.preventDefault();
   setTemperaturaCorte(parseFloat(temperaturaCorte))
   let formulario = document.getElementById("formulTemp")
   formulario.addEventListener('submit', function() {
    formulario.reset();
  });
    
  }
  function cargaHumed(e) {
    e.preventDefault()
    setHumedad(parseFloat(humedadCorte))

    let formulario = document.getElementById("formulHumed")
    formulario.addEventListener('submit', function() {
     formulario.reset();
   });
 
  }
 
  <br/>
  return (
    <div style={{ backgroundImage: `url(${backgroundImage})`,
                       width: "205vh",
                       height: "100vh",
                       backgroundPosition: "center",
                       border: "solid 1px",
                       display:"flex",
                       flexDirection:"column",
                       alignItems:"center"
                       }}>
                   <div style={{    
                  backgroundColor: "green",
                  width:"600px",
                  textAlign:"center",
                  color:"white",
                  marginTop:"50px",
                  borderRadius:"15px",
                  border:"solid 2px black"
                  }}>
    <h1>Proyecto Arduino</h1>
  </div>        

   
    <div className="container">
     <div class="row m-2">
    
    <div class="col-md-4 p-4"style={{backgroundColor:"black", borderRadius:"5px" }} >
    
      <form id="formulTemp" onSubmit={cargaTemp}>
        <div className="m-2 p-2" style={{backgroundColor:"orange", borderRadius:"5px", textAlign:"center"}}>

          <h3 >Ajuste alarma de Temperatura</h3>

                <input
                onChange={(e) => setTemperaturaCorte(e.target.value)}
                type="range"
                min={0}
                max={60}
                className="form-range"
              />
              <h3 style={{backgroundColor:"red"}} >{temperaturaCorte}°</h3>
        </div>
      </form>
    
      <form onSubmit={cargaHumed} id="formulHumed">
        <div className="m-2 p-2" style={{backgroundColor:"orange", borderRadius:"5px", textAlign:"center"}}>

          <h3  >Ajuste alarma de Humedad </h3>
        <input
                onChange={(e) => setHumedadCorte(e.target.value)}
                type="range"
                min={0}
                max={100}
                className="form-range"
              />
          <h3 style={{backgroundColor:"red"}}>{humedadCorte}%</h3>

        </div>

      </form>
      <div className="d-flex">

      <div >
           <button onClick={prenderYellowLed} className="btn btn-warning m-2 p-2">Prender Yellow Led</button>
           <button onClick={apagarYellowLed} className="btn btn-dark m-2 p-2 ">Apagar Yellow Led</button>
          </div>
       <br/>
       
         <div>
           <button onClick={prenderRedLed} className="btn btn-danger p-2 m-2">Prender RED Led</button>
           <button onClick={apagarRedLed} className="btn btn-dark m-2 p-2">Apagar RED Led</button>
           </div>
         <br/>
      
       <div>
       <button onClick={prenderAmbosLed} className="btn btn-primary m-2 p-2">Prender Ambos Led</button>
       <button onClick={apagarAmbosLed} className="btn btn-dark m-2 p-2">Apagar Ambos Led</button>
       </div> 

      </div>

     </div>
    <div class="col-md-4">
     

            <div style={{marginTop: "40px"}}>
      {temperatura > temperaturaCorte ? <h2 id="temperature" style={styleBoxDanger}>Soy la temperatura: {temperatura}</h2>
              : <h2 id="temperature" style={styleDataNormal}>Soy la temperatura: {temperatura}</h2>}
           </div>
           {temperatura > temperaturaCorte ? <h2 id="temperature" style={styleDataDanger}>¡Exceso de Temperatura!</h2>
              :<h2 id="temperature" style={styleBoxNomal} >Temperatura Normal</h2>}
    
       <div>
       {humedad > humedadCorte ? 
       <h2 id="temperature" style={styleBoxDanger}>Soy la humedad: {humedad} %</h2>
              : <h2 id="temperature" style={styleDataNormal}>Soy la humedad: {humedad} %</h2>}
              {humedad > humedadCorte ? <h2 id="temperature" style={styleDataDanger}>¡Exceso de Humedad!</h2>
              :<h2 id="temperature" style={styleBoxNomal} >Humedad Normal</h2>}      
            
       </div>
  

 <br/>

        
  



    </div>
    <div class="col">
    <div className="row align-items-end">

   <div style={{display:"flex", flexDirection:"column", alignItems:"center"}}>
   {temperatura != 0 && humedad != 0 ? 
   <h3 style={{backgroundColor:"green" }}>Arduino conectado</h3> 
   
   :
    <h3 style={{backgroundColor:"red" }}>Arduino desconectado</h3>}
    {ledYellowOn && connected ? (
             <i
               className="bi bi-lightbulb-fill "
              style={{ color: "yellow", fontSize: "75px",margin:"10px" }}
            ></i>
          ) : <i
               className="bi bi-lightbulb-fill "
              style={{ color: "black", fontSize: "75px",margin:"10px" }}
            ></i>}
            <h3  style={{ color: "yellow", backgroundColor: "grey", width:"150px", textAlign:"center"}}>Yellow Led</h3>
   </div>
  
   <div style={{display:"flex", flexDirection:"column", alignItems:"center"}}>
          {ledRedOn && connected ? (
             <i
               className="bi bi-lightbulb-fill m-1 "
               style={{ color: "red", fontSize: "75px"}}
             ></i>
           ) : <i
               className="bi bi-lightbulb-fill m-1 "
               style={{ color: "black", fontSize: "75px"}}
             >
             </i>}
              <h3  style={{ color: "red", backgroundColor:"grey"}}>Red Led</h3>
             

   </div>
   <div className="row align-items-center m-3">
   <button onClick={conectarArduino} type="button" className="btn btn-success m-2">Conectar Arduino</button>
    <br></br>
   
   </div>
   
   
    </div>
    </div>

  </div>
     
    </div>
    </div>
  )

}

export default App;