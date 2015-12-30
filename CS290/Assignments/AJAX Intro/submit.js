document.addEventListener('DOMContentLoaded', bindButtons);
function bindButtons(){
document.getElementById('postSubmit').addEventListener('click', function(event){
	var textinputed = document.getElementById('input').value;
    var req = new XMLHttpRequest();
    var payload = {input:null};
    payload.input = document.getElementById('input').value;
    req.open('POST', 'http://httpbin.org/post',  true);    								//creates an asynchronus request
    req.setRequestHeader('Content-Type', 'application/json');
	
    req.addEventListener('load',function(){
      if(req.status >= 200 && req.status < 400){
        var response = JSON.parse(req.responseText); 								//this will set variable response to the response requested from the server.
		var feedback = JSON.parse(response.data)
		console.log(response);																		//print the full response text to console															
		document.getElementById("inputPrint").textContent = textinputed;	//shows the user the inputed text enterred by the user
		document.getElementById("returned").textContent = feedback.input;		//displays the response data
      } 
	  
	  else {
        console.log("Error in network request: " + req.statusText);
      }
	  });
	  
    req.send(JSON.stringify(payload));
    event.preventDefault();
	});
  }
  