
socket.on("temp", function (data) {
  console.log(data)
  let temp = document.getElementById("temperature")
  let humidity = document.getElementById("humidity") 

  if(data.length == 19){
    temp.innerHTML = data + "C°"
  } else {
    humidity.innerHTML = data + "%"
  }
})