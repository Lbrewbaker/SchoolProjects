		var appid = "f441ead2b2ed7fa271a09a1e638fc11c";
		document.addEventListener('DOMContentLoaded', bindButtons);
		function bindButtons(){
			
		document.getElementById("submit").addEventListener("click", function(event){
		var req = new XMLHttpRequest();
		var zipCode = document.getElementById("zipSubmit").value;
		var cityName = document.getElementById("citySubmit").value;
      
	  if(zipCode != ""){
	  
		req.open("GET", "http://api.openweathermap.org/data/2.5/weather?zip=" + zipCode + ",us&appid=" + appid, true);
	  }
	  
	  else if(cityName != ""){
	  
	  	req.open("GET", "http://api.openweathermap.org/data/2.5/weather?q=" + cityName + ",us&appid=" + appid, true);
	  }
	  
	  else{
	  
		alert("No zip code or city name");
	  }
	  
	  req.addEventListener("load", function(){
		if(req.status >= 200 && req.status < 400){
			var response = JSON.parse(req.responseText);
			console.log(response);
			document.getElementById("cityName").textContent = response.name;
			document.getElementById("countryName").textContent = response.sys.country;				//there was no output for state name, unless I missed that somewhere?
			var sunriseTime = new Date(response.sys.sunrise*1000);
			document.getElementById("sunrise").textContent = sunriseTime;										//times are set according to computers local time not the locations local time.
			var sunsetTime = new Date(response.sys.sunset*1000);
			document.getElementById("sunset").textContent = sunsetTime;
			var date = new Date(response.dt*1000);
			document.getElementById("date").textContent = date;
			document.getElementById("lon").textContent = response.coord.lon;
			document.getElementById("lat").textContent = response.coord.lat;
			var impTemp = response.main.temp;
			impTemp *= 9;
			impTemp /= 5;																													//temperature calculations to convert to farenheight
			impTemp -= 459.67;			
			document.getElementById("temp").textContent = impTemp;
			document.getElementById("humidity").textContent = response.main.humidity;
			document.getElementById("windSpeed").textContent = response.wind.speed;
			document.getElementById("windAngle").textContent = response.wind.deg;
			document.getElementById("clouds").textContent = response.clouds.all;			// I couldn't figure out how to access the description text for the clouds.  The text is located in response.weather.description but that doesn't seem to print anything.
          }
		  
		else{
		console.log("Error in network request: " + request.statusText);
		alert("Network response error!");
		}});
	  
	req.send(null);
	event.preventDefault();
        })
      }